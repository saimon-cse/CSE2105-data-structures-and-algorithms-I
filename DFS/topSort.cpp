#include<bits/stdc++.h>
using namespace std;

int visited[100];
vector<int> adj[100];
stack<int> st;

void dfs(int s){
    visited[s] = 1;
    for(int i=0; i<adj[s].size(); i++){
        int v = adj[s][i];
        if(visited[v]==0){
            dfs(v);
        }
    }
    st.push(s);
}

int main(){
    int n, e;   cin>>n>>e;
    while(e--){
        int u, v;   cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            dfs(i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
/*
7 6
1 4
4 5
6 7
1 2
2 3
2 5
*/
