#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int data;
	int index;
	int neigh1;
	int neigh2;
	int neigh3;
	bool visited;
};

void bfs(node *B[], int i, int N, int &sum, int &sum1, int &min){
	if(i==-1 || B[i]->visited == true)
		return;
	B[i]->visited = true;
	sum -= B[i]->data;
	sum1 += B[i]->data;
	int tmp = abs(sum-sum1);
	if(min > tmp){
		min = tmp;
		cout<<min<<" ";
	}
	bfs(B, B[i]->neigh1, N, sum, sum1, min);
	bfs(B, B[i]->neigh2, N, sum, sum1, min);
	bfs(B, B[i]->neigh3, N, sum, sum1, min);
}

void func(int A[], int edges[][2], int N){
	int sum=0;
	for(int i=1; i<=N; i++){
		sum += A[i];
	}
	node *B[N+1];
	for (int i = 1; i <= N; ++i){
		B[i] = new node;
		B[i]->data = A[i];
		B[i]->index = i;
		B[i]->neigh1 = -1;
		B[i]->neigh2 = -1;
		B[i]->neigh3 = -1;
		B[i]->visited = false;
	}
	for (int i = 0; i < N-1; ++i){
		if(B[edges[i][0]]->neigh1 == -1)
			B[edges[i][0]]->neigh1 = edges[i][1];
		else if(B[edges[i][0]]->neigh2 == -1)
			B[edges[i][0]]->neigh2 = edges[i][1];
		else
			B[edges[i][0]]->neigh3 = edges[i][1];
		if(B[edges[i][1]]->neigh1 == -1)
			B[edges[i][1]]->neigh1 = edges[i][0];
		else if(B[edges[i][1]]->neigh2 == -1)
			B[edges[i][1]]->neigh2 = edges[i][0];
		else
			B[edges[i][1]]->neigh3 = edges[i][0];
	}
	int min = INT_MAX;
	int ptr = edges[0][0];
	int sum1 = 0;
	bfs(B, edges[0][0], N, sum, sum1, min);
	cout<<min<<'\n';
}

int main(){
	freopen("../input.in", "r", stdin);
	int N;
	cin>>N;
	int A[N+1];
	A[0] = -1;
	int sum=0;
	for(int i=1; i<=N; i++){
		cin>>A[i];
		sum += A[i];
	}
	int edge[N-1][2];
	for (int i = 0; i < N; ++i)
		cin>>edge[i][0]>>edge[i][1];
	func(A, edge, N);
	return 0;
}