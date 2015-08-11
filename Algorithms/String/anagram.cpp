#include <iostream>
#include <climits>
#include <cstdio>
#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int func(string s){
	int len = s.length();
	if (len%2 != 0)
		return -1;
	int i=0;
	int help[26] = {0};
	for (; i < len/2; ++i) {
		help[int(s[i])-int('a')] += 1;
		help[int(s[i+len/2])-int('a')] -=1;
	}
	int count = 0;
	for (i = 0; i < 26; ++i) {
		count += abs(help[i]);
	}
	return count/2;
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++) {
		string s;
		cin>>s;
		cout<<func(s)<<'\n';
	}
	return 0;
}