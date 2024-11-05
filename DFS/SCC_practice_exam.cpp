#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
vector<int> rev_adj[100];

int visited[100];
stack<int> st;

vector<int> curr_Adj;
void dfs(int s, bool isprint){
    visited[s] = 1;
    if(isprint){
        cout << s << " ";
    }
    curr_Adj = (isprint ? rev_adj[s] : adj[s]);

    for(auto i : curr_Adj){
        if(visited[i]==0){
            visited[i]=0;
            dfs(i, isprint);
        }
    }

    if(!isprint)
        st.push(s);
}

void Scc(int n){
    for(int i=0; i<n; i++){
        if(visited[i]==0)
            dfs(i, false);
    }

    for(int i=0; i<=n; i++) visited[i] = 0;

    while(!st.empty()){
        int s = st.top();
        st.pop();
        if(visited[s]==0){
            visited[s]=1;
            dfs(s, true);
            cout << endl;
        }
    }
}



int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    cout << "SCC Components are: \n";
    Scc(n);

}