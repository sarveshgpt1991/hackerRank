// https://www.hackerrank.com/challenges/alternating-characters

#include <iostream>
#include <cstdio>
using namespace std;

int alternatingCharacters(string str){
	if (str == "")
		return 0;
	int count=0;
	char last = str[0];
	for (int i=1; i<str.length(); i++) {
		if (last == str[i]) {
			count += 1;
		}
		last = str[i];
	}
	return count;
}

int main(){
//	freopen("tmp.in", "r", stdin);
	int T;
	cin>>T;
	string a;
	for (int i=0; i<T; i++) {
		cin>>a;
		cout<<alternatingCharacters(a)<<'\n';
	}
	return 0;
}
