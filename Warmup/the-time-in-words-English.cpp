#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

string noToword(int n) {
	switch(n) {
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		case 10:
			return "ten";
		case 11:
			return "eleven";
		case 12:
			return "twelve";
		case 13:
			return "thirteen";
		case 14:
			return "fourteen";
		case 16:
			return "sixteen";
		case 17:
			return "seventeen";
		case 18:
			return "eighteen";
		case 19:
			return "nineteen";
		case 20:
			return "twenty";
		case 21:
			return "twenty one";
		case 22:
			return "twenty two";
		case 23:
			return "twenty three";
		case 24:
			return "twenty four";
		case 25:
			return "twenty five";
		case 26:
			return "twenty six";
		case 27:
			return "twenty seven";
		case 28:
			return "twenty eight";
		case 29:
			return "twenty nine";
	}
}

void func(int H, int M){
	if(M == 0) {
		cout<<noToword(H)<<" o' clock";
	}
	else if(M == 1) {
		cout<<"one minute past "<<noToword(H);
	}
	else if(M == 59) {
		cout<<"one minute to "<<noToword((H+1)%12);
	}
	else if(M == 15){
		cout<<"quarter past "<<noToword(H);
	}
	else if(M == 30){
		cout<<"half past "<<noToword(H);
	}
	else if(M == 45){
		cout<<"quarter to "<<noToword((H+1)%12);
	}
	else if (M < 30){
		cout<<noToword(M)<<" minutes past "<<noToword(H);
	}
	else {
		cout<<noToword(60-M)<<" minutes to "<<noToword((H+1)%12);
	}
}

int main(){
	freopen("../input.in", "r", stdin);
	int H, M;
	cin>>H>>M;
	func(H, M);
	return 0;
}