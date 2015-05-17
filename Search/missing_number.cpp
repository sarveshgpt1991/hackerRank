#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void func(int A[], int B[], int n, int m){
	int helper[100] = {0};
	int min = INT_MAX;
	for (int i = 0; i < m; ++i){
		if(min > B[i])
			min = B[i];
	}
	for (int i = 0; i < m; ++i)
		helper[B[i]-min]++;
	for (int i = 0; i < n; ++i)
		helper[A[i]-min]--;
	for (int i = 0; i < 100; ++i) {
		if(helper[i] > 0)
			cout<<min+i<<" ";
	}
}

int main(){
	freopen("../input.in", "r", stdin);
	int n, m;
	cin>>n;
	int A[n];
	for (int i = 0; i < n; ++i)
		cin>>A[i];
	cin>>m;
	int B[m];
	for (int i = 0; i < m; ++i)
		cin>>B[i];
	func(A, B, n, m);
	return 0;
}