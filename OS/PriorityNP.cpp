// Write a program to implement Priority Scheduling - Non-preemptive algorithm. 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Process{
	int pid, at, bt, ct, tat, wt, prio, status;
} P[100];
queue<int> gantt;
int MAX, i;
bool compAt( Process a, Process b ){ return a.at < b.at; }
bool compPrio( Process a, Process b ){ return a.prio < b.prio; }
bool compPid( Process a, Process b ){ return a.pid < b.pid; }
void getdata(){
	cout << "Enter no of process: "; cin >> MAX;
	cout << "Enter arival times: ";
	for( i = 0; i < MAX; i ++ ) { cin >> P[i].at; P[i].pid = i; }
	cout << "Enter burst times: ";
	for( i = 0; i < MAX; i ++ ) cin >> P[i].bt; 
	cout << "Enter priorities: ";
	for( i = 0; i < MAX; i ++ ) cin >> P[i].prio;
}
void pnp_algorithm(){
	int t = 0, in = 0, c = 1, aborti = -1;
	sort(P, P+MAX, compAt);
	for( i = 1; i < MAX; i ++ ) if( P[i].at == P[0].at ) c ++;
	sort(P, P+c, compPrio);
	t = P[0].at;
	sort(P, P+MAX, compPrio);
	do{
		for( i = 0; i < MAX; i ++ ){
			if( P[i].status != 1 ){
				if( P[i].at <= t ){
					if( aborti != -1 ){ aborti = -1; break; }
					P[i].status = 1;
					P[i].ct = t + P[i].bt;
					P[i].tat = P[i].ct - P[i].at;
					P[i].wt = P[i].tat - P[i].bt;
					t += P[i].bt;
					gantt.push(P[i].pid+1);
					in ++;
				}
				else if( in!=0 ) aborti = i;
			}
		}	
		i = 0;
	} while( in != MAX );
	sort(P, P+MAX, compPid);
}
int main(){
	float stat = 0, swt = 0;
	getdata();
	pnp_algorithm();
	cout << "\nGantt Chart: " << gantt.front(); 
	gantt.pop();
	while( !gantt.empty() ){
		cout << " --> " << gantt.front(); 
		gantt.pop();
	}
	cout << "\n\nPID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\n";
	for( int i = 0; i < MAX; i ++ ){
		cout << P[i].pid + 1 << "\t" << P[i].at << "\t" << P[i].bt << "\t" << P[i].ct << "\t" << P[i].tat << "\t" << P[i].wt << "\n";
		stat += P[i].tat;
	 	swt += P[i].wt;
	}
	cout << "\nAvg. TAT = " << (stat / MAX) << ", Avg. WT = " << (swt / MAX);
} 
