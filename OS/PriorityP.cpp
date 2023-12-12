// Write a program to implement Priority Scheduling - Preemptive algorithm. 
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Process{
	int pid, at, tbt, bt, ct, tat, wt, prio;
} P[100];
queue<int> gantt;
int MAX, i; 
bool compAt( Process p1, Process p2 ){ return p1.at < p2.at; }
bool compPrio( Process p1, Process p2 ){ return p1.prio < p2.prio; }
bool compPid( Process p1, Process p2 ){ return p1.pid < p2.pid; }
void getdata(){
	cout << "Enter no of process: "; cin >> MAX;
	cout << "Enter arival times: ";
	for( int i = 0; i < MAX; i ++ ){
		cin >> P[i].at;
		P[i].pid = i;
	} 
	cout << "Enter burst times: ";
	for( int i = 0; i < MAX; i ++ ){ cin >> P[i].bt; P[i].tbt = P[i].bt; } 
	cout << "Enter priorities: ";
	for( int i = 0; i < MAX; i ++ ) cin >> P[i].prio; 
}
void pp_algorithm(){
	int t = 0, in = 0, c = 1, pi = -1;
	sort(P, P+MAX, compAt);
	for( i = 1; i < MAX; i ++ ) if( P[i].at == P[0].at ) c ++;
	sort(P, P+c, compPrio);
	t = P[0].at;
	while( in != MAX ){
		for( i = 0; i < MAX  && P[i].at <= t; i ++ ){
			if( P[i].tbt != 0 ){
				pi = i;
				break;
			}
		}
		if( pi != -1 ){
			P[i].tbt = P[i].tbt - 1;
			gantt.push(P[i].pid+1);
			t += 1;
			pi = -1;
		}
		if( P[i].tbt == 0 ){
			P[i].ct = t;
			P[i].tat = t - P[i].at;
			P[i].wt = P[i].tat - P[i].bt;
			in ++;
		}
		c = 0;
		sort(P, P+MAX, compAt);
		for( i = 0; i < MAX; i ++ ) if( P[i].at <= t ) c ++;
		sort(P, P+c, compPrio);
	}
	sort(P, P+MAX, compPid);
}
int main(){
	float stat = 0, swt = 0;
	getdata();
	pp_algorithm();
	cout << "\nGantt Chart: " << gantt.front(); 
	gantt.pop();
	while( !gantt.empty() ){
		cout << " --> " << gantt.front(); 
		gantt.pop();
	}
	cout << "\n\nPID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\n";
	for( int i = 0; i < MAX; i ++ ){
		cout << i+1 << "\t" << P[i].at << "\t" << P[i].bt << "\t" << P[i].ct << "\t" << P[i].tat << "\t" << P[i].wt << "\n";
		stat += P[i].tat;
		swt += P[i].wt;
	}
	cout << "\nAvg. TAT = " << (stat / MAX) << ", Avg. WT = " << (swt / MAX);
} 
