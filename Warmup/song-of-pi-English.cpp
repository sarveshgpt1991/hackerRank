#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
#include <string>
#include <sstream>
using namespace std;

string pi = "31415926535897932384626433833";

bool func(string sentence){
	string word;
	stringstream strm(sentence);
	int i=0;
	while(strm>>word){
		int ch = stoi(pi.substr(i, 1));
		if (word.length() != ch) {
			return false;
		}
		i++;
	}
	return true;
}

int main(){
	freopen("../input.in", "r", stdin);
	int T;
	cin>>T;
	for(int i=0; i<=T; i++) {
		string sentence;
		getline(cin, sentence);
		if (sentence != "") {
			if(func(sentence)){
				cout<<"It's a pi song."<<'\n';
			}
			else
				cout<<"It's not a pi song."<<'\n';
		}
	}
	return 0;
}