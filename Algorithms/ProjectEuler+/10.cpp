// https://www.hackerrank.com/contests/projecteuler/challenges/euler010

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define N 1000001
typedef long long int LL;

void calculateSum(vector<bool> p, vector<LL> &sum){
	LL s = 0;
	for(int i=2; i < N; i++){
		if(p[i]){
			s += i;
		}
		sum[i] = s;
	}
}

void calculateSieve(vector<bool> &v){
	for(int i=2; i<N; i++){
		int j = 2;
		while(i*j < N){
			v[i*j] = 0;
			j++;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	vector<bool> p (N, 1);
	vector<LL> sum (N, 0);
	calculateSieve(p);
	calculateSum(p, sum);
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		cout<<sum[n]<<'\n';
	}
	return 0;
}

