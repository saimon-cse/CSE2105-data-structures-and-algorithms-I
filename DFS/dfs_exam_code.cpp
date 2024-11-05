#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int color[100];
stack<int>st;

void dfs(int s){
    color[s] = 1;
    for(auto i : adj[s]){
        if(color[i]==0)dfs(i);
    }
    st.push(s);
}

void topSort(){
        while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void dsf2(int s){
    color[s] = 1;
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(color[i]==0) dfs(i);
    }

    // cout <<
    topSort();
}

/*


*/