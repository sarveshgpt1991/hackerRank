#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int func(string a){
	int indi = -1;
	int indj = -1;
	int len = a.length();
	int i, j;
	for(i=0, j=len-1; i<j; i++, j--) {
		if (a[i] != a[j]) {
			indi = i;
			indj = j;
			break;
		}
	}
	j--;
	while (i<j) {
		if(a[i] != a[j])
			return indi;
		i++;
		j--;
	}
	return indj;
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++) {
		string str;
		cin>>str;
		cout<<func(str)<<'\n';
	}
	return 0;
}