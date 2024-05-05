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
	string name;
	int arrival_time;
	int burst_time;
    int waiting_time;
	vector <int> event;
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

void SJF_non_preemptive(vector<Process> &process, int &n){

	sort(process.begin(), process.end(), comp_by_arrival);

	priority_queue <Process, vector<Process>, Compare> que; 
	vector <bool> selected(n, false);
    for (int i = 0; i < n; i++){
        if (process[i].arrival_time == process[0].arrival_time){
            que.push(process[i]);
            selected[i] = true;
        }
    }
	int pre_end = process[0].arrival_time;

	vector <Process> res;
	while (!que.empty()){
        
		Process temp = que.top(); que.pop();
		temp.event.push_back(temp.arrival_time);
		temp.event.push_back(pre_end);

		for (int i = 0; i < n; i++){
			if (selected[i]) continue;
			if (process[i].arrival_time <= temp.burst_time){
				que.push(process[i]);
				selected[i] = true;
			} else break;
		}

		pre_end += temp.burst_time;
		temp.event.push_back(pre_end);
		res.push_back(temp);
	}

	vector <vector<int>> trace(n, vector<int>(pre_end + 1));
	for (int i = 0; i < n; i++){
		for (int j = res[i].event[0]; j < res[i].event[1]; j++){
			trace[i][j] = res[i].burst_time;
		}
		for (int j = res[i].event[1]; j <= res[i].event[2]; j++){
			trace[i][j] = res[i].burst_time - (j - res[i].event[1]);
		}	
	}

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
	for (auto &it:process){
		fout << setw(col_width) << left << it.name;
		fout << setw(col_width * 3) << left << it.arrival_time;
		fout << setw(col_width * 3) << left << it.burst_time;
		fout << endl;
	}
	fout << endl;	

	// TRACE CHART
	write_title("TRACE CHART", line_length);
	fout << setw(col_width) << left << "";
	for (int j = 0; j <= pre_end; j++){
		fout << setw(col_width) << left << j;
	}
	fout << endl;
	for (int j = 0; j <= pre_end + 1; j++){
		write_line(col_width - 1, '-');	fout << " ";
	}
	fout << endl;

	for (int i = 0; i < n; i++){
		fout << setw(col_width) << left << res[i].name;
		for (int j = 0; j <= pre_end; j++){
			fout << setw(col_width) << left << trace[i][j];
		}
		fout << endl;		
	}
	fout << endl;

	// GANTT CHART
	write_title("GANTT CHART", line_length);

	fout << setw(col_width) << left << "";
	for (int j = 0; j <= pre_end; j++){
		fout << setw(col_width) << left << j;
	}
	fout << endl;

	fout << setw(col_width) << left << "";
	int pro_end = 0;
	for (int i = 0; i < n; i++){
		if (pro_end < res[i].event[0]){
			fout << setw(col_width * (res[i].event[0] - pro_end)) << left << "|...";
		}
		int time = res[i].event[2] - res[i].event[1];
		fout << "| ";
		fout << setw(col_width * time - 2) << left << res[i].name;
		pro_end = res[i].event[2] + 1;
	}
	fout << "|" << endl;
	fout << endl;

	// WAITING TIME
	write_title("WAITING TIME", line_length);
	int waiting_time = 0;
	for (auto &it:res){
		it.waiting_time = it.event[1] - it.event[0];
		waiting_time += it.waiting_time;
	}
	for (auto &it:res){
		fout << "Waiting time of " << it.name << " : " << it.waiting_time << endl;
	}
	fout << "--------------------\n";
	fout << "Waiting time Average : ";
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
	}

	SJF_non_preemptive(inp, n);

    finp.close(); fout.close();

    return 0;
}