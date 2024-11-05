#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100];


void bfs(int s){
    queue<int> q;
    // int u = adj[s].front();
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v]==0){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}


int main(){

    int n, e;
    cin >> n >> e;

    for(int i=1; i<=e; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int componenet = 0;
    for(int i = 0; i < n; i++){
        if(visited[i]==0){
            bfs(i);
            componenet++;
        }
    }
    cout << componenet << endl;


}

/*

7 5
3 1
1 4
3 4
4 5
0 6


*/