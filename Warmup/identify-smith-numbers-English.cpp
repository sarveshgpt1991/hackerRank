#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int sumOfDigits(int N) {
	int res = 0;
	while (N){
		res += N%10;
		N /= 10;
	}
	return res;
}

bool isSmith(int N) {
	int sumInit = sumOfDigits(N);
	int sum = 0;
	int tmp = 2;
	while (N != 1) {
		if(N%tmp == 0) {
			sum += sumOfDigits(tmp);
			N /= tmp;
		}
		else
			tmp++;
	}
	if (sum == sumInit)
		return 1;
	else
		return 0;
}

int main(){
	freopen("../input.in", "r", stdin);
	int N;
	cin>>N;
	cout<<isSmith(N);
	return 0;
}