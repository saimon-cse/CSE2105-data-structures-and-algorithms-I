#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& adjMatrix, int startNode,
         vector<bool>& visited)
{
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor = 0; neighbor < adjMatrix[currentNode].size(); neighbor++) {
            if (adjMatrix[currentNode][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adjMatrix, int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}

void printAdjacencyMatrix(const vector<vector<int>>& adjMatrix)
{
    for (int i = 0; i < adjMatrix.size(); i++) {
        for (int j = 0; j < adjMatrix[i].size(); j++) {
            int val = adjMatrix[i][j];
            cout << val << " ";
        }
    
    cout << endl;
    
    }
}


int main()
{
    int vertices = 5;

    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 3, 4);

    cout << "Adjacency Matrix:" << endl;
    printAdjacencyMatrix(adjMatrix);

    vector<bool> visited(vertices, false);

    cout << "\nBreadth First Traversal starting from vertex 0: ";
    bfs(adjMatrix, 0, visited);

    return 0;
}

