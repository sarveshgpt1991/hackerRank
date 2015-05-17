//4879 Vs 9999 ->check
#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int count(int n) {
	int res = 0;
	while(n){
		n /= 10;
		res++;
	}
	return res;
}

bool func(int n){
	long int sqN = n;
	sqN *= n;
	long int tmp = 0;
	long int i=1;
	int count_sqN = count(sqN);
	while(sqN) {
		tmp = (sqN%10)*i + tmp;
		sqN /= 10;
		i *= 10;
		if(tmp+sqN == n && tmp>0 && count_sqN == count(tmp)+count(sqN)) {
			//cout<<tmp<<" "<<sqN<<'\n';
			return true;
		}
	}
	return false;
}

int main(){
	freopen("../input.in", "r", stdin);
	int p, q;
	cin>>p>>q;
	string a = "INVALID RANGE";
	for(int i=p; i<=q; i++) {
		if(func(i)) {
			a = "";
			cout<<i<<" ";
		}
	}
	cout<<a;
	return 0;
}