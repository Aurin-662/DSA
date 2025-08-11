// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int ssize[N];
multiset<int> sizes;
void make(int i){
	parent[i]=i;
	ssize[i]=1;
	sizes.insert(1);
}
void merge(int a,int b){
	sizes.erase(sizes.find(ssize[a]));
	sizes.erase(sizes.find(ssize[b]));

	sizes.insert(ssize[a]+ssize[b]);
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
        merge(a,b);
		parent[b]=a;
		ssize[a]+=ssize[b];
	}
}

int main() {
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		make(i);
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		uni(u,v);
		if(sizes.size()==1){
			cout<<0<<endl;
		}
		else{
			int mn=*(sizes.begin());
			int mx=*(--sizes.end());
			cout<<mx-mn<<endl;
		}
	}
	

	return 0;
}	