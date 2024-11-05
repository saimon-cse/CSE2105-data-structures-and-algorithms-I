#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int> >& adjList, int startNode,
         vector<bool>& visited)
{
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int i = 0; i < adjList[currentNode].size(); ++i) {
            
            int neighbor = adjList[currentNode][i];
            
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

void printAdjacencyList(const vector<vector<int>>& adjList)
{
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << " -> ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int vertices = 5;

    vector<vector<int> > adjList(vertices);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);

    cout << "Adjacency List:" << endl;
    printAdjacencyList(adjList);


    vector<bool> visited(vertices, false);

    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    bfs(adjList, 0, visited);

    return 0;
}
