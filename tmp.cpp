#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
//#include <string>
using namespace std;

int funct (string s) {
	int count =0;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (s[i] == s[len-1]) {
			int l = len-1;
			int j = i;
			while(s[j] == s[l] and j <= l){
				j++;
				l--;
			}
			if (j == l){
				return count;				
			}
		}
		else {
			cout<<i<<"@";
			count++;
		}
	}
	return count;
}

int main() {
	string s = "aabbabb";
	//cin>>s;
	cout<<funct(s);
}


