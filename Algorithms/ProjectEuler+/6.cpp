// https://www.hackerrank.com/contests/projecteuler/challenges/euler006

#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;

void calculateSum(vector<LL> &v){
	v.resize(10001);
	int sum = 1;
	v[1] = 1;
	for(int i=2; i<10001; i++){
		sum += i;
		v[i] = sum;
	}
}

void calculateSquareSum(vector<LL> &v){
	v.resize(10001);
	LL sum = 1;
	v[1] = 1;
	for(int i=2; i<10001; i++){
		LL tmp = i;
		tmp *= i;
		sum += tmp;
		v[i] = sum;
	}
}

void funct(int N, vector<LL> sum, vector<LL> sq){
	LL tmp;
	tmp = sum[N];
	tmp *= sum[N];
	tmp -= sq[N];
	cout<<tmp<<'\n';
}

int main(){
	int T;
	vector<LL> sum, square;
	calculateSum(sum);
	calculateSquareSum(square);
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		funct(N, sum, square);
	}
	return 0;
}

