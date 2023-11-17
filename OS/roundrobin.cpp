// Write a program to implement RR ( Round Robin ) algorithm. 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Process{
	int pid, at, tbt, bt, ct, tat, wt;
}P[100], tP[100], cp;

queue<Process> ready; 
queue<int> gantt;
int tq, MAX; 

bool sortAt( Process p1, Process p2 ){ return p1.at < p2.at; }

void getdata(){
	cout << "Enter no of process: "; cin >> MAX;
	cout << "Enter time quantum: "; cin >> tq;
	cout << "Enter arival times: ";
	for( int i = 0; i < MAX; i ++ ) cin >> P[i].at;
	cout << "Enter burst times: ";
	for( int i = 0; i < MAX; i ++ ){ cin >> P[i].bt; P[i].tbt = P[i].bt; } 
	for( int i = 0; i < MAX; i ++ ){
		P[i].pid = i;
		tP[i] = P[i];
	}
}

void rr_algorithm(){
	int i, start = 0, t, flg = 0;
	sort(tP, tP+MAX, sortAt);
	t = tP[0].at;
	do{
		for( i = start ; i < MAX; i ++ ){
			if( tP[i].at <= t && tP[i].tbt != 0 ){
				ready.push(tP[i]);
				start ++;
			}	
		}
		if( flg ){
			ready.push(cp);
			flg = 0;
		}
		cp = ready.front();
		ready.pop();
		if( cp.tbt <= tq ){
			t += cp.tbt;
			cp.tbt = 0;	
		}
		else{
			cp.tbt -= tq;
			flg = 1;
			t += tq;
		}
		if( cp.tbt == 0 ){
			P[cp.pid].ct = t;
			P[cp.pid].tat = t - P[cp.pid].at;
			P[cp.pid].wt = P[cp.pid].tat - P[cp.pid].bt;
		}
		gantt.push(cp.pid+1);
	}
	while( !(ready.empty() && start == MAX) );
}

int main(){
	float stat = 0, swt = 0;
	
	getdata();
	rr_algorithm();
	
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
