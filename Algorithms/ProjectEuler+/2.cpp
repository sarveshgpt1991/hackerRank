// https://www.hackerrank.com/contests/projecteuler/challenges/euler002

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long int LL;

void addEven(LL N, vector<LL> v){
	LL res = 0;
	for(int i=2; i<v.size() && v[i]<N; i++){
		if(v[i]%2 == 0){
			res += v[i];
		}
	}
	cout<<res<<'\n';
}

void funct(LL N, vector<LL> &v){
	if(N < v.size()){
		addEven(N, v);
		return;
	}
	LL i = v[v.size()-1];
	LL j = v[v.size()-2];
	while(i < N){
		LL tmp = i;
		tmp += j;
		v.push_back(tmp);
		j = i;
		i = tmp;
	}
	addEven(N, v);
}

int main(){
	int T;
	cin>>T;
	vector<LL> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	for(int i=0; i<T; i++){
		LL N;
		cin>>N;
		funct(N, v);
	}
}

