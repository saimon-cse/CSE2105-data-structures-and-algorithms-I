#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visit[100];
stack<int> st;
map<string, int> G;
map<int, string> rG;
int cnt=1;

void dfs(int s){
    visit[s] = 1;

    for(auto i : adj[s])
        if(visit[i]==0) 
            dfs(i);
    

    st.push(s);
}

int main(){
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        string us, vs;
        cin >> us >> vs;

        if(G[us]==0) G[us] = cnt, rG[cnt++] = us;
        if(G[vs]==0) G[vs] = cnt, rG[cnt++] = vs;

        int u = G[us];
        int v = G[vs];

        adj[u].push_back(v);
    }

    for(int i=1;i<=n; i++){
        if(visit[i]==0)
        dfs(i);
    }

    while(!st.empty()){
        cout << rG[st.top()] << " ";
        st.pop();
    }
}

/*

7 6
105 203
105 205
169 279
203 220
203 215
205 220

*/