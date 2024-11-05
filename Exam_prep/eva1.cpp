#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
queue<int> q;
int parent[100];
map<string, int> c;
map<int, string> r_c;
int cnt = 1;
int dis[100];

void bfs(int s){
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    dis[s]=0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v : adj[u]){
            if(visited[v]==0){
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
}

void path_track(int s){
    if (parent[s] == -1) {
        cout << r_c[s]; 
        return;
    }
    path_track(parent[s]);
    cout << "//" << r_c[s];
}


int main(){
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        string us, vs;
        cin >> us >> vs;

        if(c[us]==0) c[us] = cnt, r_c[cnt++] = us;
        if(c[vs]==0) c[vs] = cnt, r_c[cnt++] = vs ;

        int u = c[us];
        int v = c[vs];

        adj[u].push_back(v);
    }

    bfs(c["C:"]);

    int queary;
    cin >> queary;

    while(queary--){
        string inp; cin >> inp;
        int tmp = c[inp];
        if(tmp == 0){
            cout << "File not found!\n";
            cout << "click: " << 0 <<endl;
            continue;
        }
        
            path_track(tmp);
            cout << endl;
            cout <<"click: "<< 2 * dis[tmp] << endl;
        
        
    }

}

/*


9
Photos Maldives
C: Photos
Videos Memories
C: Videos
Memories sunset.mp4
Maldives Sea.jpg
Videos tour.mp4
C: Result.pdf
Photos Download
5
Sea.jpg
Memories
tour.mp4
Photos
Codes

*/