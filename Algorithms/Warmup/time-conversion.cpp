// https://www.hackerrank.com/challenges/time-conversion

#include <iostream>
#include <cstdio>
using namespace std;

void funct(string str){
	string hr = str.substr(0, 2);
	string min = str.substr(3, 2);
	string sec = str.substr(6,2);
	string a = str.substr(8, 2);
	if(hr == "12"){
		if(a == "AM"){
			cout<<"00:";
		}
		else{
			cout<<"12:";
		}
	}
	else if(a == "AM"){
		cout<<hr<<":";
	}
	else{
		cout<<stoi(hr)+12<<":";
	}
	cout<<min<<":"<<sec;
}

int main(){
	freopen("../input.txt", "r", stdin);
	string str;
	cin>>str;
	funct(str);
	return 0;
}

