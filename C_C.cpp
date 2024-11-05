#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visited[1001];
int loc[1001];
int dis[1001];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]++;
    dis[s]++;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v] == 0){
                visited[v]++;
                dis[v]++;
                q.push(v);
            }
        }
    }
}

int main(){
    int tc; cin >> tc;
    for(int cn = 1; cn <= tc; cn++){
        int people, city, edge;
        cin >> people >> city >> edge;

        for(int i = 1; i <= people; i++){
            cin >> loc[i];
        }

        for(int i = 1; i <= edge; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for(int i = 1; i <= people; i++){
            bfs(loc[i]);
            memset(visited, 0, sizeof(visited)); 
        }
        
        int result = 0;
        for(int i = 1; i <= city; i++){
            // // result += dis[i];
            // cout << dis[i] << " ";
            if(dis[i]==people) result++;
        }

        cout << "Case " << cn << ": " << result << endl;

        for(int i = 1; i <= city; i++){
            adj[i].clear();
            dis[i] = 0;
        }
    }

}

