// https://www.hackerrank.com/contests/projecteuler/challenges/euler011

#include <iostream>
#include <cstdio>
using namespace std;

int calculate(int **arr, int N, int i, int j){
	int res = 0;
	if(i<= N-4)
		res = arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j];
	if(j <= N-4)
		res = max(res, arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3]);
	if(i<= N-4 && j<=N-4)
		res = max(res, arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3]);
	if(i<=N-4 && j-3 >= 0)
		res = max(res, arr[i][j]*arr[i+1][j-1]*arr[i+2][j-2]*arr[i+3][j-3]);
	return res;
}

int funct(int **arr, int N){
	int M = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			M = max(M, calculate(arr, N, i, j));
	}
	return M;
}

int main(){
	freopen("input.txt", "r", stdin);
	int N=20;
	int **arr;
	arr = new int*[N];
	for(int i=0; i<N; i++){
		arr[i] = new int[N];
		for(int j=0; j<N; j++)
			cin>>arr[i][j];
	}
	cout<<funct(arr, N)<<'\n';
	return 0;
}

