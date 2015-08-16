// https://www.hackerrank.com/contests/projecteuler/challenges/euler013

#include <iostream>
#include <cstdio>
using namespace std;

int toInt(char a){
	return int(a)-int('0');
}

char toChar(int x){
	return char(int('0')+x);
}

void funct(string *a, int N){
    string res = "";
    int carry = 0;
    for(int i=49; i>=0; i--){
        int sum = 0;
        for(int j=0; j<N; j++){
		    sum += toInt(a[j][i]);
        }
		sum += carry;
        res = toChar(sum%10) + res;
        carry = sum/10;
    }
    if(carry){
        while(carry){
            res = toChar(carry%10) + res;
            carry /= 10;
        }
    }
    cout<<res.substr(0, 10);
}

int main(){
	freopen("input.txt", "r", stdin);
	int N;
	cin>>N;
	string arr[N];
    for(int i=0; i<N; i++)
		cin>>arr[i];
	funct(arr, N);
	return 0;
}

