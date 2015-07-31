// https://www.hackerrank.com/challenges/caesar-cipher-1

#include <iostream>
#include <cstdio>
using namespace std;

void funct(string str, int N, int k){
	string res = "";
	int a = int('a');
	int A = int('A');
	for(int i=0; i<N; i++){
		if(int(str[i])-a >= 0 && int(str[i])-a <26){
			res = res + char(a + (int(str[i])-a + k)%26);
		}
		else if(int(str[i])-A >= 0 && int(str[i])-A <26){
			res = res + char(A + (int(str[i])-A + k)%26);
		}
		else{
			res += str[i];
		}
	}
	cout<<res;
}

int main(){
	freopen("../input.txt", "r", stdin);
	int N, k;
	string str;
	cin>>N>>str>>k;
	funct(str, N, k);
	return 0;
}

