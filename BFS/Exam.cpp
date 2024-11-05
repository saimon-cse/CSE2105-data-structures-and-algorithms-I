#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
map<string, int>c;
map<int, string>r_c;
int par[100];
int cnt=0;
int dis[100];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    par[s] = -1;
    dis[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v]==0){
                q.push(v);
                visited[v] = 1;
                par[v] = u;
                dis[v] = dis[u] + 1;
            }
        }
    }

    // return dis[d];
}


void pathTrack(int d){
    if(par[d]==-1) return;
    pathTrack(par[d]);
    cout << r_c[d] << "\\" << "\\";
}


int main(){
    int e; cin >> e;
    for(int i=0; i<e; i++){
        int u, v;
        string x, y;
        cin >> x >> y;

        if(c[x]==0) cnt++; 
        if(c[y]==0) cnt++;
        
        
        u = c[x];
        v = c[y];
        adj[u].push_back(v);       
    }

    int src = c["C:"];
    bfs(src);

    int n; cin >> n;
    while(n--){
        string ss; cin >> ss;
        int tmp = c[ss];
        
        pathTrack(tmp); 
        cout << endl;
        cout  << dis[tmp]*2 << endl;
    }




    
}


/*
9
Photos Maldives
C: Photos
Videos Memories
C: Videos
Memories sunset.mp4
Maldives Sea.jpg
Videos tour.mp4
C: Result.pdf
Photos Download
5
Sea.jpg
Memories
tour.mp4
photos
Codes

*/