#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int color[100];
stack<int>st;
map<char, int> mp;
map<int,char>r_mp;
char pri[100];
int cnt;

void dfs1(int s){
    color[s] = 1;
    for(auto i:adj[s])
        if(color[i]==0)
            dfs1(i);

    st.push(s);
}

void dfs2(int s){
    color[s]=1;
    // cout << s << " ";
    cout << r_mp[s] << " ";
    for(auto i:adj[s])
        if(color[i]==0) dfs2(i);
}


void SCC(int n){
    for(int i=0; i<n; i++)
}

int main(){
    int n, e;
    cin >> n >> e;
    for(int i =0 ; i<e ; i++){
        char us, vs;
        cin >> us >> vs;

        if(mp[us]==0){ 
            mp[us]=cnt++;
            r_mp[cnt-1] = us;
        }
        if(mp[us]==0) {
            mp[vs]=cnt++;
             r_mp[cnt-1] = vs;
        }

        int u = mp[us];
        int v = mp[vs];

        adj[u].push_back(v);        
    }

    SCC(n);
}