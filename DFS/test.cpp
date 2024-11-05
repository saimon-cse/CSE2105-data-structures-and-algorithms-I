#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int color[100];
int start[100];
int finish[100];

int Time=0;

void bfs(int s){
    color[s] = 1;
    start[s] = Time++;
    
    for(auto i : adj[s]){
        if(color[i]==0){
            bfs(i);
        }
    }

    finish[s] = Time++;
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        if(color[i]==0){
            bfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;
}
