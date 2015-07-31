// https://www.hackerrank.com/challenges/extra-long-factorials

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

void funct(int k){
	if(k == 1){
		cout<<1;
		return;
	}
	int n = 10000;
	int res[n];
	memset(res, 0, sizeof(res));
	res[n-1] = 1;
	int j=n-1;
	for(int i=2; i<=k; i++){
		int carry = 0;
		int m = n-1;
		while(m>=j){
			int num = res[m]*i+carry;
			res[m] = num%10;
			carry = num/10;
			m--;
		}
		while(carry){
			j--;
			res[j] = carry%10;
			carry /=10;
		}
	//	cout<<res[n-1];
	}
	for(int i=j; i<n; i++){
		cout<<res[i];
	}
}

int main(){
	freopen("../input.txt", "r", stdin);
	int n;
	cin>>n;
	funct(n);
	return 0;
}

