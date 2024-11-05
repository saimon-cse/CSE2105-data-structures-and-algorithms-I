#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}

void printAdjacencyMatrix(const vector<vector<int>>& adjMatrix) {
    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
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

    return 0;
}
