// https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

bool isPalin(int N){
	int d = 0;
	int tmp = N;
	while(tmp){
		d++;
		tmp /= 10;
	}
	while(N && d > 1){
		int one = N%10;
		int tmp = pow(10, d-1);
		int msb = N / tmp;
		if(one != msb)
			return false;
		N /= 10;
		d--;
		tmp = pow(10, d-1);
		N %= tmp;
		d--;
	}
	return true;
}

int funct(int N){
	int res = 0;
	for(int i = 999; i >= 100; i--){
		for(int j=999; j >= i; j--){
			int tmp = j*i;
            if(tmp < N && tmp > res && isPalin(tmp)){
				res = tmp;
			}
		}
	}

	return res;
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		cout<<funct(N)<<'\n';
	}
	getchar();
}
