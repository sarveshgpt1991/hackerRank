#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
#include <cstring>
using namespace std;

int func(string A, string B){
	int help[26];
	memset(help, 0, sizeof(help));
	for (int i = 0; i < A.length(); ++i) {
		help[A[i]-int('a')]++;
	}
	for (int i = 0; i < B.length(); ++i) {
		help[B[i]-int('a')]--;
	}
	int res = 0;
	for (int i = 0; i < 26; ++i){
		res += abs(help[i]);
	}
	return res;
}

int main(){
	freopen("../input.in", "r", stdin);
	string A, B;
	cin>>A>>B;
	cout<<func(A, B);
	return 0;
}