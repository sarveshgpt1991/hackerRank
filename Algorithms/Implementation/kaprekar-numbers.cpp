// https://www.hackerrank.com/challenges/kaprekar-numbers

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long int LL;

int addDigit(int d){
	int sum = 0;
	while(d){
		sum += d%10;
		d /=10;
	}
	return sum;
}

bool isKaprekar(int n){
	LL sqr = n;
	sqr *= n;
	int digit = 1;
	LL tens = 10;
	while(int(sqr/tens)){
		tens *=10; 
		digit++;
	}
	int a = pow(10, int((digit+1)/2));
	if(n == sqr%a + sqr/a){
		return true;
	}
	return false;
}

int main(){
	freopen("../input.txt", "r", stdin);
	int p, q;
	cin>>p>>q;
	int count =0;
	bool flag = false;
	for(int i=p; i<=q; i++){
		if(isKaprekar(i)){
			flag = true;
			cout<<i<<" ";
		}
	}
	if(!flag)
		cout<<"INVALID RANGE";
	return 0;
}

