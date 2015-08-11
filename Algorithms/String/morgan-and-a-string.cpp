// https://www.hackerrank.com/challenges/morgan-and-a-string

#include<iostream>
#include <vector>
#include <cstdio>
using namespace std;

string mergeSimilar(string str){
	string res;
	string a = str;
	int len = str.length();
	int i=0, j=0;
	while(i < len && j < len){
		if(a[i] <= str[j]){
			res = res + a[i];
			i++;
		}
		else if(a[i] > str[j]){
			res = res+ str[j];
			j++;
		}
	}
	if(i<len)
		res = res + a.substr(i, len-i+1);
	if(j<len)
		res = res + str.substr(j, len-j+1);
	return res;
}

void funct(string a, string b){
	string res = "";
	int i=0, j=0;
	int lenA = a.length();
	int lenB = b.length();

	while(i < lenA && j < lenB){
		if(a[i] < b[j]){
			res = res + a[i];
			i++;
		}
		else if(a[i] > b[j]){
			res = res + b[j];
			j++;
		}
		else {
			string str="";
			while(i<lenA && j<lenB && a[i] == b[j]){
				str = str + a[i];
				i++;
				j++;
			}
			res = res + mergeSimilar(str);
		}
	}
	if(i<lenA)
		res = res + a.substr(i, lenA-i+1);
	if(j<lenB)
		res = res + b.substr(j, lenB-j+1);
	cout<<res<<'\n';
}

int main(){
	freopen("./input.txt", "r", stdin);
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		string a, b;
		cin>>a>>b;
		funct(a, b);
	}
	return 0;
}

