#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100];
int dis[100];
map<string, int>c;
map<int, string>cc;
int cnt = 1;
int parent[100];

int bfs(int s, int d){
    queue<int> q;
    q.push(s);
    visited[s] = 1;     
    dis[s] = 0;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v]==0){
                q.push(v);
                visited[v] = 1;
                dis[v] = dis[u]+1;
                parent[v] = u;
            }
        }
    }

    return dis[d];
}

void pathTrack(int d){
    if(d==-1) return;
    pathTrack(parent[d]);
    cout << d << " ";
}

int main(){
    
    int n, e;
    cin >> n >> e;
    
    for(int i=0; i<e; i++){
        int u, v;
        string us, vs;
        cin >> us >> vs;
        
        if(c[us]==0) c[us] = cnt++;
        if(c[vs]==0) c[vs] = cnt++;

        u = c[us];
        v = c[vs];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string source, destination;
    cin >> source >> destination;
    
    int s = c[source];
    int d = c[destination];

    int result = bfs(s, d);
    cout << result << endl;

    pathTrack(d);

}

/*

8 9
DAC CTG
DAC RJH
DAC COM
RJH CTG
COM PRJ
CTG DNJ
GOP SHY
SHY DNJ
GOP RJH
DAC DNJ

*/