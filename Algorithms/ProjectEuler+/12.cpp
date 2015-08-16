// https://www.hackerrank.com/contests/projecteuler/challenges/euler012

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

#define N 100001

int calculate(int n, vector<int> &v){
	if(n < 2)
		return 1;
	if(v[n])
		return v[n];
	int tmp = n;
	int factor = 1;
	
	int i=2;
	int count = 0;
	while(n%i == 0){
		count++;
		n /= 2;
	}
	factor *= (count+1);
	i=3;
	while(i<=n){
		count = 0;
		while(n%i == 0){
			count++;
			n /= i;
		}
		factor *= (count+1);
		i += 2;
    }
    v[tmp] = factor;
    return factor;
}

int calculateFactor(int n, vector<int> &v){
	for(int i=n; i < N; i++){
		if(i%2 == 1 && calculate(i, v)*calculate((i+1)/2, v) > n){
			return (i*(i+1))/2;
		}
		if(i%2 == 0 && (calculate(i/2, v)*calculate(i+1, v) > n))
			return (i*(i+1))/2;
	}
	return -1;
}

int main(){
	freopen("input.txt", "r", stdin);
	vector<int> v(N, 0);
	v[0] = 1;
	v[1] = 1;
	v[2] = 2;
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		cout<<calculateFactor(n, v)<<'\n';
	}
	return 0;
}

