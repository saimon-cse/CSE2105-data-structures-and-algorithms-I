#include <bits/stdc++.h>
using namespace std;

vector<int> adj[201];
int visited[201];
int color[201];
// vector<int> coul[201];

int flag=0;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    // color[s] = 1;
    int col = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;
                color[v] = !color[u];
            }
            else if (color[u] == color[v])
            {
                flag = 1;
                // cout << "NOT ";
                return;
            }
        }
    }
}

int main()
{
    // int tc; 
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0) break;
       
        int e; cin >> e;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

       
        bfs(0);
        
        cout << ((flag==1) ? "NOT " : "") <<  "BICOLORABLE.\n";

        for(int i=0; i<n; i++){
            visited[i]=0;
            adj[i].clear();
            color[i]=0;
            flag=0;
        }
    }
}