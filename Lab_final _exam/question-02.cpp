#include<bits/stdc++.h>
using namespace std;

int visited[100000];

void bfs(vector<int> adj[], int s){
    queue<int> q;
    q.push(s);
    visited[s]=1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(visited[v]==0){
                visited[v]=1;
                q.push(v);
            }
        }
    }    
}


int main(){
    int n, e;
    cin >> n >> e;

    vector<int>adj[n];

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int component = 0;

    for(int i=0; i<n; i++){
        if(visited[i]==0){
            visited[i]=1;
            component++;
            bfs(adj, i);
        }
    }

    cout << component << endl;

}


/*

5 3
0 1
1 2
3 4

*/