

#include<iostream>
#include<queue>
#define garbage -99999

using namespace std;

class Edge
{
    int vertex;
    double weight;
public:
    Edge();
    void Setweight(double w);
    void SetVertex(int v);
    double getweight();
    int getVertex();
};

Edge::Edge()
{
    this->vertex = garbage;
    this->weight = garbage;
}
void Edge::Setweight(double w)
{
    this->weight = w;
}
void Edge::SetVertex(int v)
{
    this->vertex = v;
}
double Edge::getweight()
{
    return weight;
}
int Edge::getVertex()
{
    return vertex;
}

///***Comparator For Min Heap***///

class comparator
{
public:
    int operator()(Edge n1, Edge n2)
    {
        return n1.getweight()>n2.getweight();
    }
};

///***ARRAYLIST***///

class Arraylist
{
    Edge *adjacent;
    int initialsize;
    int maxsize;
    int len;
public:
    Arraylist();
    ~Arraylist();
    void insertItem(int item, double weight);
    int searchItem(int item);
    bool removeItem(int item);
    bool removeItemAt(int position);
    int getItem(int position);
    int getLength();
    bool IsEmpty();
    void printAdjacentVertices();
    void setWeight(int v, double w);
    double Weight(int v);
    Edge getEdgeAt(int position);
};

Arraylist::Arraylist()
{
    initialsize = 2;
    maxsize = initialsize;
    adjacent = new Edge[initialsize];
    len = 0;    ///number of adjacent vertices.
}
void Arraylist::insertItem(int item, double weight)
{
    Edge *temp;
    if(len == maxsize)
    {
        maxsize = 2*maxsize;
        temp = new Edge[maxsize];
        for(int i=0; i<len; i++)
        {
            temp[i].SetVertex(adjacent[i].getVertex());
            temp[i].Setweight(adjacent[i].getweight());
        }
        delete[] adjacent;
        adjacent = temp;
    }
    adjacent[len].SetVertex(item);
    adjacent[len].Setweight(weight);
    len++;
}
int Arraylist::searchItem(int item)
{
    int i=0;
    for(i=0; i<len; i++)
    {
        if(adjacent[i].getVertex() == item)
            return i;
    }
    return garbage;
}
bool Arraylist::removeItemAt(int position)
{
    if(position<0 || position>=len)
        return false;
    if(position == len-1)
    {
        adjacent[position].SetVertex(garbage);
        adjacent[position].Setweight(garbage);
        len--;
        return true;
    }

    adjacent[position].SetVertex(adjacent[len-1].getVertex());
    adjacent[len-1].SetVertex(garbage);
    adjacent[position].Setweight(adjacent[len-1].getweight());
    adjacent[len-1].Setweight(garbage);
    len--;
    return true;
}
bool Arraylist::removeItem(int item)
{
    int x = searchItem(item);
    if(x == garbage)
        return false;
    bool b = removeItemAt(x);
    if(b==true)
        return true;
    else
        return false;
}
int Arraylist::getItem(int position)
{
    if(position<0 || position>=len)
        return garbage;
    return adjacent[position].getVertex();
}
int Arraylist::getLength()
{
    return len;
}
bool Arraylist::IsEmpty()
{
    if(len == 0)
        return true;
    else
        return false;
}
void Arraylist::printAdjacentVertices()
{
    for(int i=0; i<len; i++)
    {
        if(i==len-1)
            cout<<adjacent[i].getVertex()<<"("<<adjacent[i].getweight()<<")";
        else
            cout<<adjacent[i].getVertex()<<"("<<adjacent[i].getweight()<<")-->";
    }
    cout<<endl;
}
double Arraylist::Weight(int v)
{
    int x = searchItem(v);
    if(x == garbage)
        return garbage;
    return adjacent[x].getweight();
}
Edge Arraylist::getEdgeAt(int position)
{
    return adjacent[position];
}
void Arraylist::setWeight(int v, double w)
{
    int x = searchItem(v);
    if(x==garbage)
        return;
    adjacent[x].Setweight(w);
}
Arraylist::~Arraylist()
{
    if(adjacent)
        delete[] adjacent;
    adjacent = 0;
}


///***GRAPH***

class Graph
{
    Arraylist *adjlist;
    Edge e;
    int nVertices;
    int nEdges;
    double **distanceMatrix;
    int **parentMatrix;
public:
    Graph();
    ~Graph();
    void setnVertices(int n);
    bool addEdge(int u, int v, double w);
    void printGraph();
    void removeEdge(int u, int v);
    Edge *searchEdge(int u, int v);
    void reweightEdge(int u, int v, double w);
    bool isEdge(int u, int v);
    double getWeight(int u, int v);

    void floydWarshall(int U, int V);
    bool bellmanford();
    void dijkstra(int n);
    void johnsonsAlgo();
    double getShortestPathWeight(int u, int v);
    void printShortestPath(int u, int v, int U, int V);
    void printDistanceMatrix();
    void printPredecessorMatrix();
    void cleanSPInfo();
};

Graph::Graph()
{
    adjlist = 0;
    nVertices = 0;
    nEdges = 0;
    distanceMatrix=0;
    parentMatrix=0;

}
void Graph::setnVertices(int n)
{
    this->nVertices = n;
    adjlist = new Arraylist[nVertices];

    int i, j;
    distanceMatrix = new double*[nVertices];
    for(i=0; i<nVertices; i++)
    {
        distanceMatrix[i] = new double[nVertices];

        for(j=0; j<nVertices; j++)
            distanceMatrix[i][j] = INT_MAX;
    }

    parentMatrix = new int*[nVertices];
    for(i=0; i<nVertices; i++)
    {
        parentMatrix[i] = new int[nVertices];

        for(j=0; j<nVertices; j++)
            parentMatrix[i][j] = -1;
    }
}

bool Graph::addEdge(int u, int v, double w)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return false;
    int y = adjlist[u].searchItem(v);
    if(y == garbage)
    {
        adjlist[u].insertItem(v, w);
        nEdges++;
        adjlist[v].insertItem(u, w);
        nEdges++;
        return true;
    }

    return false;
}

bool Graph::isEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return  false;

    int y = adjlist[u].searchItem(v);

    if(y==garbage)
        return false;

    return true;
}

void Graph::removeEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;
    bool verdict = isEdge(u, v);
    if(verdict == true)
    {
        adjlist[u].removeItem(v);
        nEdges--;
    }
}

Edge* Graph::searchEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return nullptr;
    int x = adjlist[u].searchItem(v);

    if(x==garbage)
        return nullptr;
    e = adjlist[u].getEdgeAt(x);
    return &e;
}

void Graph::reweightEdge(int u, int v, double w)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;
    adjlist[u].setWeight(v, w);
}

double Graph::getWeight(int u, int v)
{
    return adjlist[u].Weight(v);
}

void Graph::printGraph()
{
    cout<<"Graph:"<<endl;
    for(int i=1; i<nVertices; i++)
    {
        cout<<i<<" : ";
        adjlist[i].printAdjacentVertices();
    }
}

void Graph::dijkstra(int n)
{
    if(n<=0 || n>=nVertices)
        return;
    priority_queue <Edge, vector<Edge>, comparator> Q;

    int i, j;
    double d[nVertices], dis[nVertices];
    for(i=1; i<nVertices; i++)
    {
        d[i] = INT_MAX;
        dis[i] = INT_MAX;
        parentMatrix[n][i] = -1;
    }
    d[n] = 0;
    dis[n] = 0;
    Edge Source;
    Source.SetVertex(n);
    Source.Setweight(0);

    Q.push(Source);

    while(Q.empty()==false)
    {
        Edge u = Q.top();
        Q.pop();
        double du = d[u.getVertex()];
        for(j=0; j<adjlist[u.getVertex()].getLength(); j++)
        {
            Edge v = adjlist[u.getVertex()].getEdgeAt(j);
            double dv = d[v.getVertex()];
            double w = v.getweight();
            if(dv > du + w)
            {
                d[v.getVertex()] = (du + w);                                                                    ///change in the reweighed graph.

                if(dis[u.getVertex()]!=INT_MAX)
                    dis[v.getVertex()] = dis[u.getVertex()] + distanceMatrix[u.getVertex()][v.getVertex()];         ///change in the original graph

                parentMatrix[n][v.getVertex()] = u.getVertex();
                Q.push(v);
            }
        }
    }

    for(i=1; i<nVertices; i++)
        distanceMatrix[n][i] = dis[i];
}

bool Graph::bellmanford()
{
    int i, j, k;
    int newVertex = 0;

    for(i=1; i<nVertices; i++)
        addEdge(newVertex, i, 0);

    for(i=0; i<nVertices; i++)
    {
        distanceMatrix[newVertex][i] = INT_MAX;
    }
    distanceMatrix[newVertex][newVertex] = 0;

    for(i=0; i<nVertices-1; i++)
    {
        for(j=0; j<nVertices; j++)
        {
            for(k=0; k<adjlist[j].getLength(); k++)
            {
                Edge e = adjlist[j].getEdgeAt(k);
                double w = e.getweight();
                int v = e.getVertex();
                if(distanceMatrix[newVertex][j]!=INT_MAX)
                {
                    if(distanceMatrix[newVertex][v] > distanceMatrix[newVertex][j] + w)
                    {
                        distanceMatrix[newVertex][v] = distanceMatrix[newVertex][j]+w;
                    }
                }
            }
        }
    }


    for(i=0; i<nVertices-1; i++)
    {
        for(j=0; j<nVertices; j++)
        {
            for(k=0; k<adjlist[j].getLength(); k++)
            {
                Edge e = adjlist[j].getEdgeAt(k);
                double w = e.getweight();
                int v = e.getVertex();
                if(distanceMatrix[newVertex][j]!=INT_MAX)
                {
                    if(distanceMatrix[newVertex][v] > distanceMatrix[newVertex][j] + w)
                    {
                        cout<<"There is a negative-weight cycle"<<endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void Graph::johnsonsAlgo()
{
    int i, j;

    double wgt[nVertices][nVertices];
    for(i=0; i<nVertices; i++)
    {
        for(j=0; j<nVertices; j++)
        {
            wgt[i][j] = 0;
        }
    }

    for(i=1; i<nVertices; i++)
    {
        for(j=0; j<adjlist[i].getLength(); j++)
        {
            Edge e = adjlist[i].getEdgeAt(j);
            wgt[i][e.getVertex()] = e.getweight();
        }
    }

    bool verdict = bellmanford();
    if(verdict == true)
    {
        for(i=1; i<nVertices; i++)
            removeEdge(0, i);
        return;
    }

    for(i=1; i<nVertices; i++)
    {
        for(j=0; j<adjlist[i].getLength(); j++)
        {
            Edge e = adjlist[i].getEdgeAt(j);
            reweightEdge(i, e.getVertex(), e.getweight()+distanceMatrix[0][i]-distanceMatrix[0][e.getVertex()]);
        }
    }

    for(i=1; i<nVertices; i++)
        removeEdge(0, i);

    for(i=1; i<nVertices; i++)
    {
        for(j=1; j<nVertices; j++)
        {
            distanceMatrix[i][j] = wgt[i][j];
        }
    }

    for(i=1; i<nVertices; i++)
        dijkstra(i);

    for(i=1; i<nVertices; i++)
    {
        for(j=0; j<adjlist[i].getLength(); j++)
        {
            Edge e = adjlist[i].getEdgeAt(j);
            reweightEdge(i, e.getVertex(), wgt[i][e.getVertex()]);
        }
    }

    cout<<"Johnson's algorithm implemented"<<endl;

}

double Graph::getShortestPathWeight(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return garbage;

    return distanceMatrix[u][v];
}

void Graph::printDistanceMatrix()
{
    cout<<"Distance Matrix:"<<endl;
    for(int i=1; i<nVertices; i++)
    {
        for(int j=1; j<nVertices; j++)
        {
            if(distanceMatrix[i][j]==INT_MAX)
                cout<<"INF"<<" ";
            else
                cout<<distanceMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::printPredecessorMatrix()
{
    cout<<"Predecessor Matrix:"<<endl;
    for(int i=1; i<nVertices; i++)
    {
        for(int j=1; j<nVertices; j++)
        {
            if(parentMatrix[i][j]==-1)
                cout<<"NIL"<<" ";
            else
                cout<<parentMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::printShortestPath(int u, int v, int U, int V)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;
    int i=0, j, des=v, path[nVertices], x, y;

    if(distanceMatrix[u][v]==INT_MAX)
    {
        cout << "No path from " << u << " to " << v << " through " << U << " --" << V << endl;
        return;
    }
    while(des!=-1)
    {
        int t = parentMatrix[u][des];
        if(t==-1)
            break;
        path[i] = t;
        des = t;
        i++;
    }

    cout<<"Shortest Path Weight: "<<distanceMatrix[u][v]<<endl;
    for(j=i-1; j>=0; j--)
    {
        if(j==i-1)
        {
            x = path[j];
            cout<<x<<"-->";
        }
        else
        {
            x = path[j];
            y = path[j+1];
            cout<<x<< "(" << adjlist[y].Weight(x) << ")" <<"-->";
        }
    }
    y = path[j+1];
    cout<<v<< "(" << adjlist[y].Weight(v) << ")" <<endl;
}

void Graph::cleanSPInfo()
{
    int i, j;
    for(i=0; i<nVertices; i++)
    {
        for(j=0; j<nVertices; j++)
        {
            distanceMatrix[i][j] = INT_MAX;
            parentMatrix[i][j] = -1;
        }
    }
    //cout<<"APSP matrices cleared"<<endl;
}

void Graph::floydWarshall(int U, int V)
{
    int i, j, k;

    int f=0;

    for(i=1; i<nVertices; i++)
    {
        if(i==U) {
            for(int t=0; t<adjlist[U].getLength(); t++) {
                Edge e = adjlist[U].getEdgeAt(t);
                if(e.getVertex()==V)
                    f=1;
            }
        }
        for(j=0; j<adjlist[i].getLength(); j++)
        {
            Edge v = adjlist[i].getEdgeAt(j);
            distanceMatrix[i][v.getVertex()] = v.getweight();
        }
        distanceMatrix[i][i] = 0;
    }

    if(f==0) {
        cout << "No edge from" << U << " to " << V << endl;
    }

    for(i=0; i<nVertices; i++)
    {
        for(j=0; j<nVertices; j++) {
            if(i!=j && distanceMatrix[i][j]!=INT_MAX)
                parentMatrix[i][j] = i;
            else
                parentMatrix[i][j] = -1;
        }
    }

    for(k=1; k<nVertices; k++)
    {
            if(k!=U && k!=V && distanceMatrix[U][k]!=INT_MAX && distanceMatrix[k][V]!=INT_MAX)
            {
                if(distanceMatrix[U][V] > distanceMatrix[U][k] + distanceMatrix[V][j])
                {
                    distanceMatrix[U][V] = distanceMatrix[U][k] + distanceMatrix[V][j];
                    parentMatrix[U][V] = parentMatrix[k][V];
                }
            }
    }

    for(int k=1; k<nVertices; k++)
    {
        for(i=1; i<nVertices; i++)
        {
            for(j=1; j<nVertices; j++)
            {
                if(i!=j && distanceMatrix[i][U]!=INT_MAX && distanceMatrix[U][V]!=INT_MAX && distanceMatrix[V][j]!=INT_MAX)
                {
                    if(distanceMatrix[i][j] > distanceMatrix[i][U] + distanceMatrix[U][V] + distanceMatrix[V][j]) {
                        distanceMatrix[i][V] = distanceMatrix[i][U] + distanceMatrix[U][V];
                        distanceMatrix[U][j] = distanceMatrix[U][V] + distanceMatrix[V][j];
                        distanceMatrix[i][j] = distanceMatrix[i][U] + distanceMatrix[U][V] + distanceMatrix[V][j];
                        parentMatrix[V][j] = parentMatrix[U][V];
                    }
                }
            }
        }
    }
}


Graph::~Graph()
{
    if(adjlist)
        delete[] adjlist;
    adjlist = 0;
    if(distanceMatrix!=0)
    {
        for(int i=0; i<nVertices; i++)
        {
            delete[] distanceMatrix[i];
        }
        delete[] distanceMatrix;
    }
    distanceMatrix=0;

    if(parentMatrix!=0)
    {
        for(int i=0; i<nVertices; i++)
        {
            delete[] parentMatrix[i];
        }
        delete[] parentMatrix;
    }
    parentMatrix=0;
}

int main()
{
    Graph g;
    int n, m, i, c;
    cout<<"Enter number of vertices & edges: "<<endl;
    cin>>n;
    cin>>m;
    g.setnVertices(n+1);

    cout<<"Add Edges: "<<endl;
    for(i=0; i<m; i++)
    {
        int u, v;
        double w;
        cin>>u;
        cin>>v;
        cin>>w;

        g.addEdge(u, v, w);
    }
    int U, V;
    cin >> U >> V;
    g.cleanSPInfo();
    g.floydWarshall(U, V);
    while(1)
    {
        int x, y;
        cin >> x >> y;
        int w = g.getShortestPathWeight(x, y);
        if(w!=garbage)
            cout << w << endl;
        g.printShortestPath(x, y, U, V);
        //g.printGraph();
    }

    return 0;
}
