// https://www.hackerrank.com/challenges/library-fine

#include <iostream>
#include <cstdio>
using namespace std;

int funct(int ad, int am, int ay, int ed, int em, int ey){
	if(ay > ey)
		return 10000;
	else if(ay < ey)
		return 0;
	if(am > em)
		return (am-em)*500;
	else if(am < em)
		return 0;
	if(ad <= ed)
		return 0;
	else
		return (ad-ed)*15;
}

int main(){
	freopen("../input.txt", "r", stdin);
	int aD, aM, aY, eD, eM, eY;
	cin>>aD>>aM>>aY>>eD>>eM>>eY;
	cout<<funct(aD, aM, aY, eD, eM, eY);
	return 0;
}

