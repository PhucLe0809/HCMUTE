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
    int waiting_time;
	vector <pair<int, int>> event;
};
struct Compare{
    bool operator() (const Process &a, const Process &b){
        if (a.burst_time == b.burst_time) return !(a.arrival_time < b.arrival_time);
        else return !(a.burst_time < b.burst_time);
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

void SJF_preemptive(vector<Process> &process, int &n){
	
	vector <Process> inp = process;
	sort(process.begin(), process.end(), comp_by_arrival);

	priority_queue <Process, vector<Process>, Compare> que;
	for (int i = 0; i < n; i++){
		if (process[i].arrival_time == 0) que.push(process[i]);
	}
	vector <vector<int>> scan(1, vector<int>(n));
	Process cpu;
	if (!que.empty()){
		cpu = que.top(); que.pop();
		scan[0][cpu.id] = cpu.burst_time;
	}

	int t = 0;
	set <int> completed;
	vector <int> temp(n, 0);
	while (completed.size() < n){
		t++; 
		// cout << t << endl;
		// cout << cpu.id+1 << " " << cpu.burst_time << " " << que.size() << " " << completed.size() << " ";
		// for (auto &it:completed) cout << it << " "; cout << endl;
		
		for (int i = 0; i < n; i++) temp[i] = scan[t-1][i];

		bool pushed = false;
		for (int i = 0; i < n; i++){
			if (process[i].arrival_time == t){
				que.push(process[i]);
				temp[process[i].id] = process[i].burst_time;
				pushed = true;
			}
		}
		
		if (pushed == false){
			if (cpu.burst_time != 0){
				// cout << 1 << endl;
				cpu.burst_time--;
				temp[cpu.id] = cpu.burst_time;
				scan.push_back(temp);
				continue;
			}
			if (cpu.burst_time == 0){
				// cout << 2 << endl;
				if (cpu.id != -1){
					completed.insert(cpu.id);
				}
				if (!que.empty()){
					cpu = que.top(); que.pop();
					temp[cpu.id] = --cpu.burst_time;
					scan.push_back(temp);	
				}else{
					temp[cpu.id] = cpu.burst_time;
					scan.push_back(temp);
				}
				continue;
			}
		}
		if (pushed == true){
			if (cpu.burst_time != 0){
				// cout << 3 << endl;
				cpu.burst_time--;
				temp[cpu.id] = cpu.burst_time;
				Process cmp = que.top();
				if (cmp.burst_time < cpu.burst_time){
					que.pop();
					que.push(cpu); cpu = cmp;
				    temp[cpu.id] = cpu.burst_time;
				}
				scan.push_back(temp);
				continue;
			}
			if (cpu.burst_time == 0){
				// cout << 4 << endl;
				if (cpu.id != -1){
					completed.insert(cpu.id);
					cpu = que.top(); que.pop();
					temp[cpu.id] = --cpu.burst_time;
					scan.push_back(temp);
				}else{
					cpu = que.top(); que.pop();
					temp[cpu.id] = cpu.burst_time;
					scan.push_back(temp);
				}
				continue;	
			}
		}
		// cout << cpu.id+1 << " " << cpu.burst_time << " " << completed.size() << endl;
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
	fout << setw(col_width * 3) << left << "Burst time" << endl;
	write_line(col_width - 1, '-');	fout << " ";
	write_line(col_width * 3 - 1, '-');	fout << " ";
	write_line(col_width * 3 - 1, '-');	fout << " ";
	fout << endl;
	for (auto &it:inp){
		fout << setw(col_width) << left << it.name;
		fout << setw(col_width * 3) << left << it.arrival_time;
		fout << setw(col_width * 3) << left << it.burst_time;
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
    
	int n; finp >> n;
	vector <Process> inp(n);
	for (int i = 0; i < n; i++){
		finp >> inp[i].name;
		finp >> inp[i].arrival_time;
		finp >> inp[i].burst_time;
		inp[i].id = i;
	}

	SJF_preemptive(inp, n);

    finp.close(); fout.close();

    return 0;
}