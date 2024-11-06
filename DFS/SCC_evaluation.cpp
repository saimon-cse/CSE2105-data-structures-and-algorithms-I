#include <bits/stdc++.h>
using namespace std;

map<string, int> graph;
map<int, string> rev_graph;
int visited[100];
int id = 1;
vector<int> adj[100], rev_adj[100];
stack<int> st;
queue<int> q;

void dfs(int s)
{
    visited[s] = 1;
    for (auto v : adj[s])
        if (visited[v] == 0)      
            dfs(v);
       
    st.push(s);
}

void dfs2(int s)
{
    visited[s] = 1;
    cout << rev_graph[s] << " ";
    for (auto v : rev_adj[s])
        if (visited[v] == 0)
            dfs2(v);
}
void resetArray()
{
    for (int i = 0; i < 100; i++)
    {
        visited[i] = 0;
    }
}

int main()
{
    int edge;
    cin >> edge;

    for (int i = 0; i < edge; i++)
    {
        string us, vs;
        cin >> us >> vs;

        if (graph[us] == 0)
            graph[us] = id, rev_graph[id++] = us;
        if (graph[vs] == 0)
            graph[vs] = id, rev_graph[id++] = vs;

        int u = graph[us];
        int v = graph[vs];

        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for (int i = 1; i < id; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    resetArray();

    int cnt = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (visited[u] == 0)
        {
            cout << "SCC " << cnt + 1 << ": ";
            dfs2(u);
            cout << endl;
            cnt++;
        }
    }

    cout << "Total strongly connected components: " << cnt << endl;
}

/*

14
Dhaka Chattagram
Rajshahi Dhaka
Chattagram Rajshahi
Chattagram Delhi
Delhi Chennai
Chennai Bali
Chennai Delhi
Phuket Bali
Phuket Bangkok
Bangkok Phuket
Rajshahi Bangkok
Chattagram Bangkok
NewYork California
California NewYork

*/