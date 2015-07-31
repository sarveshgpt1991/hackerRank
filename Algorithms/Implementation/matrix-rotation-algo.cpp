// https://www.hackerrank.com/challenges/matrix-rotation-algo

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void printArray(int **mat, int M, int N){
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			cout<<mat[i][j]<<" ";
		cout<<'\n';
	}
}

void func(int **mat, int startC, int endC, int startR, int endR, int R){
	if(startC >= endC || startR >= endR)
		return;
	int n = 2*(endC-startC+1) + 2*(endR-startR+1) -4;
	int K = R%n;
	for(int k=0; k<K; k++){
		int i=startR+1, j=startC;
		int pre = mat[startR][startC];
		while(i <= endR ){
			int tmp = mat[i][j];
			mat[i][j] = pre;
			pre = tmp;
			i++;
		}
		i--;
		j++;
		while(j <= endC){
			int tmp = mat[i][j];
			mat[i][j] = pre;
			pre = tmp;
			j++;
		}
		j--;
		i--;
		while(i >= startR){
			int tmp = mat[i][j];
			mat[i][j] = pre;
			pre = tmp;
			i--;
		}
		i++;
		j--;
		while(j >= startC){
			int tmp = mat[i][j];
			mat[i][j] = pre;
			pre = tmp;
			j--;
		}
	}
	func(mat, startC+1, endC-1, startR+1, endR-1, R);
}

int main(){
	freopen("../../input.in", "r", stdin);
	int M, N, R;
	cin>>M>>N>>R;
	int **mat;
	mat = new int*[M];
	for(int i=0; i<M; i++){
		mat[i] = new int[N];
		for(int j=0; j<N; j++)
			cin>>mat[i][j];
	}
	func(mat, 0, N-1, 0, M-1, R);
	printArray(mat, M, N);
	return 0;
}