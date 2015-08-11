// https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <iostream>
using namespace std;

void sum3or5(int N){
	long sum = 0;
	long n = (N-1)/3;
	long tmp = 3;
	tmp *= n;
	tmp *= (n+1);
	tmp /= 2;
	sum += tmp;

	n = (N-1)/5;
	tmp = 5;
	tmp *= n;
	tmp *= (n+1);
	tmp /= 2;
	sum += tmp;
	
	n = (N-1)/15;
	tmp = 15;
	tmp *= n;
	tmp *= (n+1);
	tmp /= 2;
	sum -= tmp;

	cout<<sum<<'\n';
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		sum3or5(N);
	}
	return 0;
}

