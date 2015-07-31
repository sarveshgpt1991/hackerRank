// https://www.hackerrank.com/challenges/plus-minus

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

void funct(int *a, int N){
	int plus=0, minus=0, zero=0;
	for(int i=0; i<N; i++){
		if(a[i]==0)
			zero++;
		else if(a[i]>0)
			plus++;
		else
			minus++;
	}
	cout<<setprecision(3)<<float(plus)/N<<'\n';
	cout<<setprecision(3)<<float(minus)/N<<'\n';
	cout<<setprecision(3)<<float(zero)/N;
}

int main(){
	freopen("../input.txt", "r", stdin);
	int N;
	cin>>N;
	int arr[N];
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}
	funct(arr, N);
	return 0;
}

