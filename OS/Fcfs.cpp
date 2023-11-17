// Write a program to implement FCFS ( First Come First Serve ) algorithm. 

#include <iostream>
#define MAX 5
using namespace std;

struct Process{
	int si, at, bt, ct, tat, wt;
};

Process prc[MAX];

void getdata(){
	for( int i = 0; i < MAX; i ++ ) prc[i].si = i+1;
	cout << "Enter arival times: ";
	for( int i = 0; i < MAX; i ++ ) cin >> prc[i].at;
	cout << "Enter burst times: ";
	for( int i = 0; i < MAX; i ++ ) cin >> prc[i].bt;
}

void fcfs_algorithm(){
	prc[0].ct = prc[0].at + prc[0].bt;
	prc[0].tat = prc[0].ct - prc[0].at;
	prc[0].wt = prc[0].tat - prc[0].bt;
	for( int i = 1; i < MAX; i ++ ){
		if( prc[i].at < prc[i-1].ct ) prc[i].ct = prc[i].bt + prc[i-1].ct;		
		else prc[i].ct = prc[i].at + prc[i].bt;	
		prc[i].tat = prc[i].ct - prc[i].at;
		prc[i].wt = prc[i].tat - prc[i].bt;	
	}
}

int main(){
	float atat, awt;
	int stat = 0, swt = 0;
	getdata();
	fcfs_algorithm();
	cout << "\nPno\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\n";
	for( int i = 0; i < MAX; i ++ ){
		cout << prc[i].si << "\t" << prc[i].at << "\t" << prc[i].bt << "\t" << prc[i].ct << "\t" << prc[i].tat << "\t" << prc[i].wt << "\n";
		stat += prc[i].tat;
		swt += prc[i].wt;
	}
	atat = (float)stat / MAX;
	awt = (float)swt / MAX;
	cout << "\nAvg. TAT = " << atat << ", Avg. WT = " << awt;
} 
