#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void commonSubStr(string A, string B){
	bool help[256] = {0};
	for (int i = 0; i < A.length(); ++i)
		help[int(A[i])] = true;
	for (int i = 0; i < B.length(); ++i) {
		if (help[int(B[i])] == true) {
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

int main(){
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i) {
		string A, B;
		cin>>A>>B;
		commonSubStr(A, B);
	}
	return 0;
}