// https://www.hackerrank.com/challenges/diagonal-difference

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void funct(int **m, int N){
	int sum1 = 0, sum2=0;
	int j=0;
	for(int i=0; i<N; i++,j++){
		sum1 += m[i][j];
		sum2 += m[i][N-j-1];
	}
	cout<<abs(sum1-sum2);
}

int main(){
	freopen("../input.txt", "r", stdin);
	int N;
	cin>>N;
	int **mat;
	mat = new int*[N];
	for(int i=0; i<N; i++){
		mat[i] = new int[N];
		for(int j=0; j<N; j++){
			cin>>mat[i][j];
		}
	}
	funct(mat, N);
	return 0;
}

