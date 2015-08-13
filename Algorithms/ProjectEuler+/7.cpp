// https://www.hackerrank.com/contests/projecteuler/challenges/euler007

#include <iostream>
#include <vector>
using namespace std;

void funct(int N, vector<int> &v){
	if(v.size() >= N){
		cout<<v[N-1]<<'\n';
		return;
	}
	int num = v[v.size()-1];
	num += 2;
	while(v.size() < N){
		bool prime = true;
		for(int i=0; i<v.size(); i++){
			if(num%v[i] == 0){
				prime  = false;
				break;
			}
		}
		if(prime)
			v.push_back(num);
		num += 2;
	}
	cout<<v[N-1]<<'\n';
}

int main(){
	int T;
	vector<int> v;
	v.push_back(2); v.push_back(3); v.push_back(5); v.push_back(7);
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		funct(N, v);
	}
	return 0;
}

