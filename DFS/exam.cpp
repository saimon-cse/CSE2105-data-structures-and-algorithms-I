#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int color[100];
stack<int> st;
map<string, int> mp;
vector<int> rev_adj[100];
string str[100];
int cnt1;

void dfs1(int s){
    color[s]=1;
    for(auto i:adj[s])
        if(color[i]==0) 
            dfs1(i);
    st.push(s);
}

void dfs2(int s){
    color[s] = 1;
    cout << str[s] << ", ";
    for(auto i: rev_adj[s])
        if(color[i]==0)
            dfs2(i);
}


int SCCC(int n){
    for(int i=0; i<n; i++){
        if(color[i]==0) 
            dfs1(i);
    }

    for(int i=0; i<=n; i++) color[i]=0;

    int cnt=0;

    while(!st.empty()){
        int s = st.top();
        st.pop();

        for(auto i:rev_adj[s]){
            if(color[i]==0){
                cnt++;
                dfs2(i);
                cout << endl;
            }
        }  
    }

    return cnt;
}



int main(){

    int e; cin >> e;
    while(e--){
        string us, vs;
        cin >> us >> vs;

        if(mp[us]==0) str[cnt1]=us, mp[us]=cnt1++;
        if(mp[vs]==0) str[cnt1]=vs, mp[vs] = cnt1++;

        int u = mp[us];
        int v = mp[vs];
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    cout << SCCC(mp.size());


}


/*
12
Dhaka Chattagram
Rajshahi Dhaka
Chattagram Rajshahi
Chattagram Delhi
Delhi Chennai
Chennai Delhi
Chennai Bali
Phuket Bali
Phuket Bangkok
Bangkok Phuket
Rajshahi Bangkok
Chattagram Bangkok





*/

