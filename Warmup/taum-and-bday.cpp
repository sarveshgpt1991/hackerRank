#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void func(int B, int W, int X, int Y, int Z){
	unsigned long int cost = 0;
	unsigned long int tmp;
	if (X + Z < Y) {
		B += W;
		tmp = Z;
		tmp *= W;
		cost += tmp;
		W = 0;
	}
	else if (Y + Z < X) {
		W += B;
		tmp = Z;
		tmp *= B;
		cost += tmp;
		B = 0;
	}
	tmp = B;
	tmp *= X;
	cost += tmp;
	tmp = W;
	tmp *= Y;
	cost += tmp;
	cout<<cost<<'\n';
}

int main(){
	freopen("../input.in", "r", stdin);
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)	{
		int B, W, X, Y,Z;
		cin>>B>>W>>X>>Y>>Z;
		func(B, W, X, Y, Z);
	}
	return 0;
}