#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
map<string, int> id;
string name[100];

int visited[100], dis[100], par[100];
int roll = 1;

void bfs(int s){
    queue<int> q;
    visited[s] = 1;
    dis[s] = 0;
    par[s] = -1;
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


void path(int s, int flag){
    if(s==-1)   return;
    path(par[s],1);
    if(flag==0){
        cout<<name[s];
    }
    else    cout<<name[s]<<"//";
}

int main(){

    int e;
    cin>>e;
    while(e--){
        string us, vs;
        cin>>us>>vs;

        if(id[us]==0)   {id[us]=roll; name[roll]=us; roll++;}
        if(id[vs]==0)   {id[vs]=roll; name[roll]=vs; roll++;}

        int u = id[us];
        int v = id[vs];

        adj[u].push_back(v);
    }

    int s = id["C:"];
    bfs(s);

    int q; cin>>q;

    while(q--){
        string h;
        cin>>h;
        int hid = id[h];
        if(hid==0){
            cout<<"-1\nFile not found"<<endl<<endl;
            continue;
        }
        cout<<dis[hid]*2<<endl;
        path(hid,0);
        cout<<endl<<endl;
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
