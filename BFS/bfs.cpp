#include<bits/stdc++.h>
using namespace std;

map<string, int> G;
map<int, string>rG;
vector<int> adj[100];
int visited[100];
int level[100]; // find level 
int dis[100];   // distance calculation shortest path
int parent[100]; 

int cnt=1;
void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    dis[s] = 0;
    parent[s] = -1;
    level[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto i : adj[u]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
                dis[i] = dis[u] + 1;
                parent[i] = u;
                level[i] = level[u]+1;
            }
        }
    }
}

void path(int d){
    if(d==-1) return;
    
    path(parent[d]);
    cout << rG[d] << " ";
}

// void levelFind(int s){
//     queue<int> q;
//     q.push(s);
//     visited[s]=1;
//     level[s] = 0;
    
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         for(auto i : adj[u]){
//             if(visited[i]==0){
//                 q.push(i);
//                 visited[i]=1;
//                 level[i] = level[u] + 1;;
//             }
//         }
//     }
// }

int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++){

        string us, vs;
        cin >> us >> vs;

        if(G[us]==0)   G[us] = cnt++, rG[cnt-1] = us;
        if(G[vs]==0)    G[vs] = cnt++, rG[cnt-1] = vs;

        int u = G[us];
        int v = G[vs];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    string source, destination;
    cin >> source >> destination;
    
    int s = G[source];
    int d = G[destination];
    bfs(s);
    path(d);
    cout << endl;

     int componenet = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]==0){
            bfs(i);
            componenet++;
        }
    }
    cout << componenet << endl;

    // for(auto i:visited)  cout << i << " ";
    
}