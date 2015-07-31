// https://www.hackerrank.com/challenges/a-very-big-sum

#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

//void ()

int main(){
	freopen("../input.txt", "r", stdin);
	int N;
	long long sum = 0;
	cin>>N;
	for(int i=0; i<N; i++){
		int tmp;
		cin>>tmp;
		sum += tmp;
	}
	cout<<sum;
	return 0;
}

