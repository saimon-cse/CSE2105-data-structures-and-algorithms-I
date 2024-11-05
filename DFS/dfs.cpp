#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int color[100];

void dfs(int s, int n){
    color[s] = 1;
    for(auto i : adj[s]){
        if(color[i]==0) dfs(i, n);
    }
    
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

    int count = 0;
    for(int i=0; i<n; i++){
        if(color[i]==0){
            dfs(i, n);
            count++;

        }
    }

    cout << count << endl;
}


/*

7 5
3 1
1 4
3 4
4 5
0 6

*/