#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

bool isFunny(string str){
	int len = str.length();
	for(int i=1; i<len; i++) {
		if(abs(int(str[i])-int(str[i-1])) != abs(int(str[len-i])-int(str[len-i-1])))
			return false;
	}
	return true;
}

int main(){
	freopen("../input.in", "r", stdin);
	int T;
	cin>>T;
	for(int i=0; i<T; i++) {
		string str;
		cin>>str;
		if(isFunny(str)){
			cout<<"Funny"<<'\n';
		}
		else
			cout<<"Not Funny"<<'\n';
	}
	return 0;
}