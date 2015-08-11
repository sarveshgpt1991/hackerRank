// https://www.hackerrank.com/challenges/connected-cell-in-a-grid

#include <iostream>
#include <cstdio>
//#include <>
using namespace std;

int ai[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int aj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool islegal(int i, int j, int r, int c){
	if(i<0 || i>= r || j<0 || j>= c)
		return false;
	return true;
}

int funct(bool **arr, int r, int c, int i, int j){
	int count = 0;
	if(arr[i][j] == 0)
		return 0;
	count++;
	arr[i][j] = 0;
	for(int k=0; k<8; k++){
		int I = i+ai[k];
		int J = j+aj[k];
		if(islegal(I, J, r, c) && arr[I][J]){
			count += funct(arr, r, c, I, J);
		}
	}
	return count;
}

int main(){
	freopen("../input.txt", "r", stdin);
	int m, n;
	cin>>m>>n;
	bool **arr;
	arr = new bool*[m];
	for(int i=0; i<m; i++){
		arr[i] = new bool[n];
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	int Max = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			Max = max(Max, funct(arr, m, n, i, j));
	}
	cout<<Max;
	return 0;
}

