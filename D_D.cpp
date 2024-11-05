    #include<bits/stdc++.h>
    using namespace std;
    // #define int lo 
    // #define int long long
    vector<int> adj[100009];
    int vis[100009];
    int dis[100009];

    int bfs(int n, int m){
        queue<int>q;
        q.push(n);
        vis[n]=1;
        dis[n]=1;

        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i];
                if(dis[v]==0){
                    vis[v]=1;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }

        return dis[m];
        
    }


    signed main(){
        int n, m;
        cin >> n >> m;

        for(int i=1; i< (m+n)*2; i++){
            int u = i*2;
            adj[i].push_back(u);
            adj[i].push_back(i-1);
        }

        cout << bfs(n,m) -1 << endl;

        for(int i=n; i< (m+n)*2; i++){
            adj[i].clear();
        dis[i]=0;
        vis[i]=0;
        }

    }