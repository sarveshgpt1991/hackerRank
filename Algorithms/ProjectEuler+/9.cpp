// https://www.hackerrank.com/contests/projecteuler/challenges/euler009

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*
b = (n2-2na)/(2n-2a);

*/
int funct(int N){
	if(N<12)
		return -1;
 int M = -1;
	int half = N/2 + 1;
	for(int i=4; i<half; i++){
		if((N*N-2*N*i)%(2*N-2*i)==0){
			for(int j=half-i; j<i && j>2; j++){
				float c = sqrt(i*i+j*j);
				if(c == int(c) && i + j + c == N){
					M = max(M, i*j*int(c));
				}
			}
		}
	}
	return M;
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		cout<<funct(N)<<'\n';
	}
	
	return 0;
}

