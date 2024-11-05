#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100];
vector<int> rev_adj[100];
stack<int> st;

void dfs1(int s){
    visited[s] = 1;
    for(auto i: adj[s])
        if(!visited[i])
            dfs1(i);
    st.push(s);
}

void dfs2(int s){
    visited[s] = 1;
    cout << s << " ";
    for(auto i: rev_adj[s])
        if(!visited[i])
            dfs2(i);
}

void SCC(int n){
    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs1(i);    
    }

    for(int i = 0; i<=n; i++) visited[i]=0;

    for(int i = 0; i < n; i++){
        for(auto j: adj[i]){
            rev_adj[j].push_back(i);
        } 

    }

    while(!st.empty()){
        int s = st.top();
        st.pop();
        if(!visited[s]){

            dfs2(s);
            cout << endl;
        }
    }
}

int main(){
    int n, e; 
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << "Strongly Connected components are:\n";
    SCC(n);
    return 0;
}

/*

test case 1:

5 5
1 3
1 4
2 1
3 2
4 5


test case 2:

8 9
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4 
6 7


*/