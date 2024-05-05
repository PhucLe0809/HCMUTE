#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long
#define inf LLONG_MAX
#define endl '\n'

using namespace std;
ifstream finp ("process.inp");
ofstream fout ("process.out");
struct Process{
	string name = "pro";
	int id = -1;
	int arrival_time = 0;
	int burst_time = 0;
	int priority = 0;
    int waiting_time;
	vector <pair<int, int>> event;
};
struct Compare{
    bool operator() (const Process &a, const Process &b){
        return !(a.priority < b.priority);
    }
};
bool comp_by_arrival(const Process &a, const Process &b){
	if (a.arrival_time == b.arrival_time) return a.burst_time < b.burst_time;
    else return a.arrival_time < b.arrival_time;
}
void write_line(int len, char key){
	for (int i = 0; i < len; i++) fout << key;
}
void write_title(string title, int len){
	write_line((len - title.size()) / 2, '=');
	fout << " " << title << " ";
	int residual = ((len - title.size()) / 2)*2 + title.size() != len;
	write_line((len - title.size()) / 2 + residual, '=');
	fout << endl;
}

void Round_Robin(vector<Process> &process, int &n, int &quantum){
	
	vector <Process> inp = process;
	sort(process.begin(), process.end(), comp_by_arrival);

	vector <vector<int>> scan;
    priority_queue <Process, vector<Process>, Compare> que; que.push(process[0]);
    Process cpu = process[0];
    vector <int> temp(n, 0);
    for (int i = 0; i < cpu.arrival_time; i++) scan.push_back(temp);
    int t = cpu.arrival_time - 1;
    vector <vector<int>> record(quantum+1, vector<int>(n));
    bool flag = false;
    while (!que.empty()){
        t++;
        for (int j = 0; j < n; j++){
            for (int i = 0; i <= quantum; i++){
                record[i][j] = scan[t-1][j];
            }
        }

        cpu = que.top(); que.pop();
        if (cpu.burst_time >= quantum){
            for (int j = 1; j < n; j++){
                if (t <= process[j].arrival_time && process[j].arrival_time <= t + quantum){
                    que.push(process[j]);
                    for (int i = process[j].arrival_time - t; i <= quantum; i++){
                        record[i][process[j].id] = process[j].burst_time;
                    }
                }
            }
            for (int i = 0; i <= quantum; i++){
                record[i][cpu.id] = max(cpu.burst_time - i, 0LL);
            }

            cpu.burst_time -= quantum;
            if (cpu.burst_time != 0) que.push(cpu);
        }else{
            for (int j = 1; j < n; j++){
                if (t <= process[j].arrival_time && process[j].arrival_time <= t + cpu.burst_time){
                    que.push(process[j]);
                    for (int i = process[j].arrival_time - t; i <= quantum; i++){
                        record[i][process[j].id] = process[j].burst_time;
                    }
                }
            }
            for (int i = 0; i <= quantum; i++){
                record[i][cpu.id] = max(cpu.burst_time - i, 0LL);
            }

            for (int j = 1; j < n; j++){
                if (t + cpu.burst_time < process[j].arrival_time && process[j].arrival_time <= t + quantum){
                    que.push(process[j]);
                    for (int i = process[j].arrival_time - t; i <= quantum; i++){
                        record[i][process[j].id] = process[j].burst_time;
                    }
                }
            }
            int pre_burst = cpu.burst_time;
            cpu = que.top(); que.pop();
            for (int i = pre_burst + 1; i <= quantum; i++){
                record[i][cpu.id] = max(cpu.burst_time - (i - pre_burst), 0LL);
            }
            cpu.burst_time -= (quantum - pre_burst);
            if (cpu.burst_time != 0) que.push(cpu);        
        }
        for (int i = flag; i <= quantum; i++){
            scan.push_back(record[i]);
        }
        t += quantum - flag;
        flag = true;      
    }

	vector <vector<int>> trace(n, vector<int>(scan.size()));
	for (int i = 0; i < scan.size(); i++){
		for (int j = 0; j < n; j++){
			trace[j][i] = scan[i][j];
		}
	}

	int pre_end = trace[0].size();
	int col_width = 5;
	int line_length = (pre_end + 2) * col_width;

	// PROCESS LIST
	write_title("PROCESS LIST", line_length);
	fout << "Number of processes : " << n << endl;

	fout << setw(col_width) << left << "Name";
	fout << setw(col_width * 3) << left << "Arrival time";
	fout << setw(col_width * 3) << left << "Burst time";
	fout << setw(col_width * 3) << left << "Priority" << endl;
	write_line(col_width - 1, '-');	fout << " ";
	write_line(col_width * 3 - 1, '-');	fout << " ";
	write_line(col_width * 3 - 1, '-');	fout << " ";
	write_line(col_width * 3 - 1, '-');	fout << " ";
	fout << endl;
	for (auto &it:inp){
		fout << setw(col_width) << left << it.name;
		fout << setw(col_width * 3) << left << it.arrival_time;
		fout << setw(col_width * 3) << left << it.burst_time;
		fout << setw(col_width * 3) << left << it.priority;
		fout << endl;
	}
	fout << endl;	

	// TRACE CHART
	write_title("TRACE CHART", line_length);
	fout << setw(col_width) << left << "";
	for (int j = 0; j < pre_end; j++){
		fout << setw(col_width) << left << j;
	}
	fout << endl;
	for (int j = 0; j <= pre_end; j++){
		write_line(col_width - 1, '-');	fout << " ";
	}
	fout << endl;

	for (int i = 0; i < n; i++){
		fout << setw(col_width) << left << inp[i].name;
		for (int j = 0; j < pre_end; j++){
			fout << setw(col_width) << left << trace[i][j];
		}
		fout << endl;		
	}
	fout << endl;

	// GANTT CHART
	write_title("GANTT CHART", line_length);

	fout << setw(col_width) << left << "";
	for (int j = 0; j < pre_end; j++){
		fout << setw(col_width) << left << j;
	}
	fout << endl;

	fout << setw(col_width) << left << " ";
	int j = 1;
	while (j < pre_end){
		int i = 0; bool flag = false;
		while (i < n){
			if (!(trace[i][j-1] == trace[i][j] + 1)){
				i++; continue;
			}
			int t = j;
			while (t < pre_end && trace[i][t-1] == trace[i][t] + 1) t++;
			int len = t - j;
			fout << "| ";
			fout << setw(len * col_width - 2) << left << inp[i].name;
			j = t - 1; flag = true;
			break;
		}
		if (!flag) fout << setw(col_width) << left << "|...";
		j++;
	}
	fout << "|" << endl;
	fout << endl;

	// WAITING TIME
	write_title("WAITING TIME", line_length);
	int waiting_time = 0;
	for (int i = 0; i < n; i++){
		int j = 1;
		while (j < pre_end){
			if (trace[i][j] != trace[i][j-1] || trace[i][j] == 0){
				j++; continue;
			}
			int t = j;
			while (t < pre_end && trace[i][t] == trace[i][j]) t++;
			inp[i].waiting_time = t - j;
			inp[i].event.push_back({j - 1, t - 1});
			j = t;
		}
		
		waiting_time += inp[i].waiting_time;
	}
	for (auto &it:inp){
		fout << "Waiting time of " << it.name << " : ";
		if (it.event.empty()){
			fout << 0 << endl;
			continue;
		}
		for (int i = 0; i < it.event.size(); i++){
			fout << "(" << it.event[i].second << " - " << it.event[i].first << ")";
			if (i != it.event.size() - 1) fout << " + "; 
		}
		fout << " = " << it.waiting_time << endl;
	}
	fout << "--------------------\n";
	fout << "Waiting time Average : " << "(";
	for (int i = 0; i < n; i++){
		fout << inp[i].waiting_time;
		if (i != n-1) fout << " + ";
	}
	fout << ") / " << n << " = " << waiting_time << " / " << n << " = ";
	fout << fixed << setprecision(6) << (waiting_time * 1.0) / n << endl;
	fout << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
	int n, q; finp >> n >> q;
	vector <Process> inp(n);
	for (int i = 0; i < n; i++){
		finp >> inp[i].name;
		finp >> inp[i].arrival_time;
		finp >> inp[i].burst_time;
		finp >> inp[i].priority;
		inp[i].id = i;
	}

	Round_Robin(inp, n, q);

    finp.close(); fout.close();

    return 0;
}