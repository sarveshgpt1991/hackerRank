#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

bool func(string G[], int R, int C, string P[], int r, int c){
	bool res = true;
	for (int i = 0; i < R; ++i){
		int found = G[i].find(P[0]);
		if(found == -1)
			continue;
		res = true;
		for (int j = 1; j < r; ++j){
			if(P[j] != G[i+j].substr(found, c)) {
				res = false;
				break;
			}
		}
		if(res)
			return res;
	}
	return false;
}

int main(){
	freopen("../input.in", "r", stdin);
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i){
		int R, C, r, c;
		cin>>R>>C;
		string G[R];
		for (int i = 0; i < R; ++i)
			cin>>G[i];
		cin>>r>>c;
		string P[r];
		for (int i = 0; i < r; ++i)
			cin>>P[i];
		if(func(G, R, C, P, r, c))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}