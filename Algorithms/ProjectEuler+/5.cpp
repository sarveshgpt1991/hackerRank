// https://www.hackerrank.com/contests/projecteuler/challenges/euler005

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void calculateFactors(int N, vector<vector<int> > &v){
	v.resize(41);
	for(int i=2; i<=40; i++){
		int tmp = i;
		vector<int> vec;
		vec.resize(38);
		int count = 0;
		int num = 2;
		while(tmp%2 == 0){
			tmp /= 2;
			count++;
		}
		vec[num] = count;
		while(tmp>1){
			for(int num=3; num <= tmp; num+=2){
				count = 0;
				while(tmp%num == 0){
					tmp /= num;
					count++;
				}
				vec[num] = count;
			}
		}
		v[i] = vec;
	}
}

void funct(int N, vector<vector<int> > v){
	vector<int> vec;
	vec.resize(38);
	for(int i=2; i<=N; i++){
		for(int j=2; j<38 && j<=i; j++){
			if(vec[j] < v[i][j]){
				vec[j] = v[i][j];
			}
		}
	}
	int num = 1;
	for(int i=2; i<38; i++){
		if(vec[i] != 0)
			num *= pow(i, vec[i]);
	}
	cout<<num<<'\n';
}

int main(){
	int T;
	vector<vector<int> > v;
	calculateFactors(40, v);
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		funct(N, v);
	}

	return 0;
}

