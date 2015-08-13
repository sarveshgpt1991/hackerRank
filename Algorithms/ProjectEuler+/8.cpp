// https://www.hackerrank.com/contests/projecteuler/challenges/euler008

#include <iostream>
#include <string>
using namespace std;

#define Z int('0')

void funct(string s, int N, int k){
	int Max=1;
	int ptr = 1;
	for(int i=0; i<k; i++){
		int tmp = int(s[i])-Z;
		ptr *= tmp;
	}
	Max = ptr;
	int d;
	for(int i=k; i<N; i++){
		d = (int(s[i-k])-Z);
		int tmp = 1;
		if(d == 0){
			for(int j = i-k+1; j<=i; j++){
				tmp *= (int(s[j])-Z);
			}
		}
		else {
			tmp = ptr/d;
			tmp *= (int(s[i])-Z);
			
		}
		ptr = tmp;
		Max = max(Max, tmp);
	}
	cout<<Max<<'\n';
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N, K;
		cin>>N>>K;
		string a;
		cin>>a;
		funct(a, N, K);
	}
	return 0;
}

