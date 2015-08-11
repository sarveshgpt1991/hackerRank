// https://www.hackerrank.com/challenges/common-child

#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void commmonChild(string a, string b){
	int len = a.length();
	int **arr;
	arr = new int*[len+1];
	for(int i=0; i<len+1; i++){
		arr[i] = new int[len+1];
		arr[0][i] = 0;
		arr[i][0] = 0;
	}
	for(int i=1; i<=len; i++){
		for(int j = 1; j<=len; j++){
			if(a[i-1] == b[j-1]){
				arr[i][j] = arr[i-1][j-1]+1;
			}
			else{
				int m = max(arr[i-1][j], arr[i][j-1]);
				arr[i][j] = m;
			}
		}
	}
	cout<<arr[len][len];
}

int main(){
	freopen("./input.txt", "r", stdin);
	string a, b;
	cin>>a>>b;
	commmonChild(a, b);
	return 0;
}

