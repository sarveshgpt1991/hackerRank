#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void classCancelled(int *arr, int N, int K){
	int count = 0;
	for (int i = 0; i < N; ++i)	{
		if (arr[i] <= 0) {
			count++;
		}
	}
	if (count >= K) {
		cout<<"NO\n";
	}
	else
		cout<<"YES\n";
}

int main(){
	freopen("../input.in", "r", stdin);
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i) {
		int N, K;
		cin>>N>>K;
		int arr[N];
		for (int i = 0; i < N; ++i)
			cin>>arr[i];
		classCancelled(arr, N, K);
	}
	return 0;
}