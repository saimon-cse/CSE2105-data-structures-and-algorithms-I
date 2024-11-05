#include<bits/stdc++.h>
using namespace std;
int visited[101];
vector<int>adj[101];
stack<int>st;
stack<int>stt;
int dfs(int s)
{
    visited[s]=1;
    for(int i=0; i<adj[s].size(); i++)
    {
        int v=adj[s][i];
        if(visited[v]==0)
        {
            dfs(v);
        }
    }
    st.push(s);
    stt.push(s);

}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            cout<<"they are SCC:"<<endl;
            while(!stt.empty())
            {
                cout<<stt.top()<<" ";
                stt.pop();
                //cout<<endl;
            }


            cout<<endl;
        }
    }
    // cout << end
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
/*
8 9
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4 
6 7

*/
