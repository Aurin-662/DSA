#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int ssize[N];

void make(int i){
	parent[i]=i;
	ssize[i]=1;
}
int find(int v){
	if(parent[v]==v) return v;
	return parent[v]=find(parent[v]);
}
void uni(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(ssize[a]<ssize[b]){
			swap(a,b);
		}
		parent[b]=a;
		ssize[a]+=ssize[b];
	}
}

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		make(i);
	}
	while(k--){
		int u,v;
		cin>>u>>v;
		uni(u,v);
	}
	int c=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i) c++;
	}
	cout<<c<<endl;

	return 0;
}	