#include<bits/stdc++.h>
using namespace std;

const int Max = INT_MAX;
vector<int> adj[100007];
int visited[100007];


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

    int tc; cin >> tc;
    while(tc--){
        int n, e;
        cin >> n >> e;
        if(e==0){
         cout << n << endl;
         break;
        }

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
        // if(e==0) cout << n << endl;
        cout << componenet << endl;

        for(int i=0; i<n; i++){
            visited[i]=0;
            adj[i].clear();
        }
    }

}

/*

7 5
3 1
1 4
3 4
4 5
0 6


*/