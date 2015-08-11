// https://www.hackerrank.com/challenges/reverse-shuffle-merge

#include<iostream>
#include <string>
using namespace std;

string reverse(string s){
	int len = s.length();
	string res = "";
	for(int i=len-1; i>=0; i--){
		res = res + s[i];
	}
	return res;
}

void funct(string s){
	int help[26] = {0};
	int write[26] = {0};
	int a = int('a');
	for(int i=0; i<s.length(); i++){
		help[int(s[i])-a]++;
	}
	for(int i=0; i<26; i++){
		help[i] /= 2;
		write[i] = help[i];
	}
	int bottleneck[s.length()];
	string _s = reverse(s);
	for(int i=_s.length()-1; i>=0; i--){
		int tmp = write[int(_s[i])-a];
		bottleneck[i] = tmp;
		if(tmp>0)
			write[int(_s[i]-a)]--;
	}
	
	for(int i=0; i<_s.length(); i++)
		cout<<bottleneck[i]<<" ";
	for(int i=0; i<_s.length(); i++)
		cout<<_s[i]<<" ";	
	int detect[26] = {0};
	string res = "";
	for(int i=0; i<_s.length(); i++){
		int idx = int(_s[i])-a;
		if(write[idx] >= bottleneck[i]){
			detect[idx]++;
		}
		else {
			int j=0;
			while(idx > j){
				if(write[j] < help[j]){
					int m = min(detect[j]-write[j], help[j]-write[j]);
					res = res + string(m, char(j+a));
					write[j] += detect[j];	
				}
				j++;
			}
			int tmp = bottleneck[i]-write[j];
			res = res + string(tmp, char(j+a));
			write[j] += tmp;
			detect[idx]++;
		}
	}
	cout<<res;
}

int main() {
	string s;
	s = "bdabaceadaedaaaeaecdeadababdbeaeeacacaba";		//aaaaaabaaceededecbdb
	//cin>>s;
	funct(s);
	return 0;
}

