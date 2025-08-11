#include <bits/stdc++.h>

using namespace std;
//void bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int node,vector<int> &ans){
//    vis[node]=true;
//    queue<int> q;
//    q.push(node);
//    while(!q.empty()){
//        int f=q.front();
//        q.pop();
//
//        ans.push_back(f);
//        for(auto neighbour:adj[f]){
//            if(!vis[neighbour]){
//                q.push(neighbour);
//                vis[neighbour]=true;
//            }
//        }
//    }
//}
void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int node,vector<vector<int>> &anss,vector<int> &com){
    vis[node]=true;
    com.push_back(node);


        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                dfs(adj,vis,neighbour,anss,com);
            }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    vector<int> ans;
    vector<vector<int>>anss;
//    for(int i=0;i<n;i++){
//        if(!vis[i]){
//            bfs(adj,vis,i,ans);
//        }
//
//    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
                vector<int> com;
            dfs(adj,vis,i,anss,com);
            anss.push_back(com);

        }

    }
//    cout<<"bfs"<<endl;
//    for(auto i: ans){
//        cout<<i<<" ";
//    }

    cout<<"dfs"<<endl;
    for(auto comp : anss){
    for(auto node : comp){
        cout << node << " ";
    }
    cout << endl;
}

    return 0;
}
