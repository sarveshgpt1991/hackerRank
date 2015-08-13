// https://www.hackerrank.com/contests/projecteuler/challenges/euler010

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int calculateSum(int N, vector<int> v){
	int i = 0;
	int sum = 0;
	while(v[i] <= N && i<v.size()){
		sum += v[i];
		i++;
	}
	return sum;
}

/*
int funct(int N, vector<int> &v){
	int size = v.size();
	if(v[size-1] >= N)
		return calculateSum(N, v);
	int num = v[size-1];
	num += 2;
	bool prime = false;
	while(v[size-1] < N && num <= N){
		prime = 1;
		for(int i=0; i<v.size(); i++){
			if(num%v[i] == 0){
				prime = 0;
				break;
			}
		}
		if(prime){
			v.push_back(num);
			size++;
		}
		num += 2;
	}
	return calculateSum(N, v);
}*/

void calculate(vector<int> &v){
	int N = 1000001;
	int n = 100000;
	v.resize(n);
    v[0] = 0;
    v[1] = 0;
    v[2] = 2;
    int sum = 2;
    for(int i=3; i<n; i+=2){
        v[i] = i;
    }
    for(int i=3; i<n && sum<N; i++){
		if(i%2 == 0){
			v[i] = sum;
			continue;
		}
        sum += v[i];
        for(int j = i+2; j<n; j+=2){
            if(v[j]%i == 0){
				v[j] = 0;
			}
        }
        v[i] = sum;
    }
}

int main(){
	freopen("input.txt", "r", stdin);
	vector<int> p;
	calculate(p);
	int T;
	cin>>T;
	cout<<T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
	}
	return 0;
}

