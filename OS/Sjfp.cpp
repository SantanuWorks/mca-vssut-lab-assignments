// Write a program to implement SJF - Preemptive ( Shortest Job First ) algorithm. 

#include <iostream>
using namespace std;

struct Process{
	int at, bt, tbt, ct, tat, wt;
}P[100];

int MAX, i;

void getdata(){
	cout << "Enter no of process: "; cin >> MAX;
	cout << "Enter arival times: ";
	for( i = 0; i < MAX; i ++ ) cin >> P[i].at;
	cout << "Enter burst times: ";
	for( i = 0; i < MAX; i ++ ){
		cin >> P[i].bt;
		P[i].tbt = P[i].bt;	
	}
}
	
void sjfp_algorithm(){
	int art = 1000, but, pid, pc = 0, pseq[100], flg = 0, c = 0;
	
	for( i = 0; i < MAX; i ++ ){
		if( P[i].at == 0 ) c ++;
		if( c > 1 ){
			flg = 1;
			break;
		} 
	}
	
	c = -1;
	
	if( !flg ){
		for( i = 0; i < MAX; i ++ ){
			if( P[i].at <= art ){
				art = P[i].at;
				pid = i;
			}		
		}
		P[pid].tbt = P[pid].tbt - 1;
		art ++;
		if( P[pid].tbt == 0 ){
			pc ++;
			P[pid].ct = art;
			P[pid].tat = P[pid].ct - P[pid].at;
			P[pid].wt = P[pid].tat - P[pid].bt;
		}
		pseq[++c] = pid + 1;
	}
	
	if( flg ) art = 0;
	
	but = 1000;
	while( pc != MAX ){
		for( i = 0; i < MAX; i ++ ){
			if( P[i].at <= art && P[i].tbt ){
				if( P[i].tbt < but ){
					pid = i;
					but = P[i].tbt;
				}	
			}
		}
		P[pid].tbt = P[pid].tbt - 1;
		art = art + 1;
		if( P[pid].tbt == 0 ){
			pc ++;
			P[pid].ct = art;
			P[pid].tat = P[pid].ct - P[pid].at;
			P[pid].wt = P[pid].tat - P[pid].bt;
		}
		pseq[++c] = pid + 1;
		but = 10000;
	}
	
	cout << "\nGantt Chart: " << pseq[0]; 
	for( i = 1; i < c; i ++ ) cout << " --> " << pseq[i];
}

int main(){
	float stat = 0, swt = 0;
	
	getdata();
	sjfp_algorithm(); 
	
	cout << "\n\nPID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\n";
	for( i = 0; i < MAX; i ++ ){
		cout << i+1 << "\t" << P[i].at << "\t" << P[i].bt << "\t" << P[i].ct << "\t" << P[i].tat << "\t" <<  P[i].wt << endl;	
		stat += P[i].tat; swt += P[i].wt;
	}
	
	cout << "\nAvg. TAT = " << (stat/MAX) << ", Avg. WT = " << (swt/MAX);
}
