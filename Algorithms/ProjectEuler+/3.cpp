// https://www.hackerrank.com/contests/projecteuler/challenges/euler003

#include <iostream>
#include <cmath>
using namespace std;

typedef long long int LL;

void funct(LL N){
	LL a = 1;
	while(N%2 == 0){
		a = 2;
		N /= 2;
	}
	LL tmp= sqrt(N);
	for(int i=3; i<=sqrt(N); i+=2){
		while(N%i == 0){
			a = i;
			N /= i;
		}
	}
	cout<<max(a, N)<<'\n';
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		LL N;
		cin>>N;
		funct(N);
	}
}

