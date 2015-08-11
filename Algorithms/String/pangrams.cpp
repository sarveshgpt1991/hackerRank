// https://www.hackerrank.com/challenges/pangrams

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void isPangram(string s){
	bool help[26];
	for (int i = 0; i < 26; ++i)
		help[i] = false;
	for (int i = 0; i < s.length(); ++i){
		int tmp = int(s[i]); 
		if (tmp >= int('A') and tmp <= int('Z')) {
			help[tmp-int('A')] = true;
		}
		else if (tmp >= int('a') and tmp <= int('z')) {
			help[tmp-int('a')] = true;
		}
	}
	for (int i = 0; i < 26; ++i){
		if (help[i] == false) {
			cout<<"not pangram\n";
			return;
		}
	}
	cout<<"pangram\n";
}

int main(){
	string s;
	getline (cin, s);
	isPangram(s);
	return 0;
}
