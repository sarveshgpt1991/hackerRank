#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
//#include <cmath>
#include <vector>
//#include <string>
using namespace std;

string func(string s){
	string res;
	vector<char> a;
	char tmp = s[s.length()-1];
	a.push_back(int(tmp));
	int i;
	for (i = s.length()-2; i >= 0; i--) {
		a.push_back(int(s[i]));
		if (int(s[i]) >= int(tmp)) {
			tmp = s[i];
		}
		else {
			tmp = s[i];
			break;
		}
	}
	res = s.substr(0, i);
	i++;
	if (i==0)
		return "no answer";
	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); ++i) {
		if(a[i] > tmp) {
			res += a[i];
			a[i] = ' ';
			break;
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == ' ')
			continue;
		res += a[i];
	}
	return res;
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