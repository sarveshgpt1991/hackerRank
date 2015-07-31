// https://www.hackerrank.com/challenges/staircase

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void funct(int N){

	for(int i=1; i<=N; i++){
		string blank(N-i, ' ');
		string hash(i, '#');
		cout<<blank<<hash<<'\n';
	}
}

int main(){
	freopen("../input.txt", "r", stdin);
	int N;
	cin>>N;
	funct(N);
	return 0;
}

