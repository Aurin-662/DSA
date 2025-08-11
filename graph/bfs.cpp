#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
void bfs(int node,vector<int> &ans,unordered_map<int,list<int>> adj,unordered_map<int,bool> &vis){
    vis[node]=true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        ans.push_back(f);
        for(auto i:adj[f]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int ,int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});   
    }
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i,ans,adj,vis);
        }
    }
for(int node : ans) {
    cout << node << " ";
}
cout << endl;

return 0;
}