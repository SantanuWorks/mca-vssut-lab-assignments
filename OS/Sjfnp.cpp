// Write a program to implement SJF - Non-preemptive ( Shortest Job First ) algorithm. 

#include <iostream>
using namespace std;

struct Process{
	int at, bt, ct, tat, wt, rt, status;
}P[100];

int MAX, i;

void getdata(){
	cout << "Enter no of process: "; cin >> MAX;
	cout << "Enter arival times: ";
	for( i = 0; i < MAX; i ++ ) cin >> P[i].at;
	cout << "Enter burst times: ";
	for( i = 0; i < MAX; i ++ ) cin >> P[i].bt;
}

void sjfnp_algorithm(){
	int i, art = 100000, but, pid, pc = 0, pseq[MAX], flg = 0, c = 0;
	
	for( i = 0; i < MAX; i ++ ){
		if( P[i].at == 0 ) c ++;
		if( c > 1 ){
			flg = 1;
			break;
		} 
	}
	
	if( !flg ){
		for( i = 0; i < MAX; i ++ ){
			if( P[i].at <= art ){
				art = P[i].at;
				pid = i;
			}		
		}
		P[pid].ct = P[pid].at + P[pid].bt;
		P[pid].tat = P[pid].ct - P[pid].at;
		P[pid].wt = P[pid].tat - P[pid].bt;
		P[pid].rt = art - P[pid].at;
		P[pid].status = 1;
		pseq[pc] = pid + 1; pc ++;
		art = P[pid].ct;	
	}
	
	if( flg ) art = 0;
	
	but = 10000;
	while( pc != MAX ){
		for( i = 0; i < MAX; i ++ ){
			if( P[i].at <= art && !P[i].status ){
				if( P[i].bt < but ){
					pid = i;
					but = P[i].bt;
				}	
			}
		}
		P[pid].ct = art + P[pid].bt;
		P[pid].tat = P[pid].ct - P[pid].at;
		P[pid].wt = P[pid].tat - P[pid].bt;
		P[pid].rt = art - P[pid].at;
		P[pid].status = 1;
		pseq[pc] = pid + 1;
		art = P[pid].ct;
		pc ++;
		but = 10000;
	}	
	
	cout << "\nGantt Chart: " << pseq[0]; 
	for( i = 1; i < pc; i ++ ) cout << " --> " << pseq[i];
}

int main(){
	float stat = 0, swt = 0, srt = 0;
	
	getdata();
	sjfnp_algorithm();  
	
	cout << "\n\nPID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\t" << "RT\n";
	for( i = 0; i < MAX; i ++ ){
		cout << "P" << i+1 << "\t" << P[i].at << "\t" << P[i].bt << "\t" << P[i].ct << "\t" << P[i].tat << "\t" <<  P[i].wt << "\t" << P[i].rt << endl;	
		stat += P[i].tat; swt += P[i].wt; srt += P[i].rt;
	}
	
	cout << "\nAvg. TAT = " << (stat/MAX) << ", Avg. WT = " << (swt/MAX) << ", Avg. RT = " << (srt/MAX);
}
