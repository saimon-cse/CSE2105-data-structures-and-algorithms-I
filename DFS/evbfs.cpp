#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100], dis[100], par[100];

map<string, int> id;
string name[100];
int cnt = 1;

void bfs(int s){
    visited[s] = 1;
    dis[s] = 0;
    par[s] = -1;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v]==0){
                visited[v] = 1;
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void path(int s, int flag=0){
    if(s==-1)   return;
    path(par[s],flag+1);
    if(flag==0) cout<<name[s];
    else    cout<<name[s]<<"//";
}

int main(){
    int e;
    cin>>e;
    while(e--){
        int u, v;   string us, vs;  cin>>us>>vs;

        if(id[us]==0)   {id[us] = cnt; name[cnt] = us; cnt++; cout<<us<<": "<<id[us]<<endl;}
        if(id[vs]==0)   {id[vs] = cnt; name[cnt] = vs; cnt++; cout<<vs<<": "<<id[vs]<<endl;}

        u = id[us];
        v = id[vs];

        adj[u].push_back(v);
    }

    bfs(id["C:"]);

    int q;  cin>>q;

    while(q--){
        string s;  cin>>s;
        if(id[s]==0)    {cout<<"File not found\n-1"<<endl<<endl; continue;}
        path(id[s]); cout<<endl;
        cout<<dis[id[s]]*2<<endl<<endl;
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
Photos
Codes
*/
