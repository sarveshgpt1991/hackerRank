#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int func(string s) {
	int len = s.length();
	bool flag = false;
	int res = 0;
	bool palindrome = true;
	for(int i=0; i<len/2; i++) {
		if(s[i] == s[len-i-1]) {
			res++;
			if(flag == true)
				res++;
			flag = true;
		}
		else {
			flag = false;
			palindrome = false;
		}
	}
	if (palindrome)
		res++;
	return res;
}

int main(){
	freopen("../input.in", "r", stdin);
	int T;
	cin>>T;
	for(int i=0; i<T; i++) {
		string s;
		cin>>s;
		cout<<func(s)<<'\n';
	}
	return 0;
}