#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void print(int arr[], int N, int M) {
	int a=0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			cout<<arr[a]<<" ";
			a++;
		}
		cout<<'\n';
	}
}

void dp(string arr[], int N, int M, int i, int j, int memorize[]){
	if (i<0 || j<0 || i>=N || j>=M)
        return;
	if(memorize[i*M + j] != -1 || arr[i][j] == 'X')
		return;
    int count = 0;
    int max = 0;
    if(i>0){
        if(arr[i-1][j] != 'X')
            count++;
        if(max < memorize[(i-1)*M+j])
        	max = memorize[(i-1)*M+j];
    }
    if(j>0){
        if(arr[i][j-1] != 'X')
            count++;
        if(max < memorize[i*M+j-1])
        	max = memorize[i*M+j-1];
    }
    if(j<M-1){
        if(arr[i][j+1] != 'X')
            count++;
        if(max < memorize[i*M+j+1])
        	max = memorize[i*M+j+1];
    }
    if(i<N-1){
        if(arr[i+1][j] != 'X')
            count++;
        if(max < memorize[(i+1)*M+j])
        	max = memorize[(i+1)*M+j];
    }
    if (arr[i][j] == '*') {
//    	print(memorize, N, M);
  	    memorize[i*M+j] = max;
    	return;
    }
    if(count > 1){
    	max++;
    }
    memorize[i*M+j] = max;
    arr[i][j] = 'X';
    dp(arr, N, M, i-1, j, memorize);
    dp(arr, N, M, i, j-1, memorize);
    dp(arr, N, M, i, j+1, memorize);
    dp(arr, N, M, i+1, j, memorize);
}

int func(string arr[], int N, int M){
    int startX, startY, endX, endY;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 'M'){
                startX = i;
                startY = j;
            }
            else if(arr[i][j] == '*'){
                endX = i;
                endY = j;
            }
        }
    }
    int memorize[N*M];
    memset(memorize, -1, sizeof(memorize));
    dp(arr, N, M, startX, startY, memorize);
    return memorize[endX*M + endY];
}

int main() {
	freopen("../input.in", "r", stdin);
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int N, M, K;
        cin>>N>>M;
        string arr[N];
        for (int j=0; j<N; j++){
            cin>>arr[j];
        }
        cin>>K;
        int tmp = func(arr, N, M);
        if(tmp == K)
            cout<<"Impressed\n";
        else
            cout<<"Oops!\n";
    }
    return 0;
}