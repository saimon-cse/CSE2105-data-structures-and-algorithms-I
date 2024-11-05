#include <iostream>
#include <bits/stdc++.h>
#define garbage -99999
#define WHITE 0
#define GRAY -1
#define BLACK 1
using namespace std;

/// Edge ///

class Edge
{
    int vertex;
    double capacity;
    double flow;
public:
    Edge();
    void Setcapacity(double c);
    void SetVertex(int v);
    void Setflow(double f);
    double getcapacity();
    double getflow();
    int getVertex();
};

Edge::Edge()
{
    this->vertex = garbage;
    this->capacity = garbage;
    this->flow = garbage;
}
void Edge::Setcapacity(double c)
{
    this->capacity = c;
}
void Edge::Setflow(double f)
{
    this->flow = f;
}
void Edge::SetVertex(int v)
{
    this->vertex = v;
}
double Edge::getcapacity()
{
    return capacity;
}
double Edge::getflow()
{
    return flow;
}
int Edge::getVertex()
{
    return vertex;
}


/// Adjacency List ///

class Arraylist
{
    Edge *adjacent;
    int initialsize;
    int maxsize;
    int len;
public:
    Arraylist();
    ~Arraylist();
    void insertItem(int item, double capacity);
    int searchItem(int item);
    bool removeItem(int item);
    bool removeItemAt(int position);
    int getItem(int position);
    int getLength();
    bool IsEmpty();
    void printAdjacentVertices();
    void setCapacity(int v, double c);
    void setFlow(int v, double f);
    void setFlowAt(int i, double f);
    double Capacity(int v);
    double Flow(int v);
    Edge getEdgeAt(int position);
};

Arraylist::Arraylist()
{
    initialsize = 2;
    maxsize = initialsize;
    adjacent = new Edge[initialsize];
    len = 0;    ///number of adjacent vertices.
}
void Arraylist::insertItem(int item, double capacity)
{
    Edge *temp;
    if(len == maxsize)
    {
        maxsize = 2*maxsize;
        temp = new Edge[maxsize];
        for(int i=0; i<len; i++)
        {
            temp[i].SetVertex(adjacent[i].getVertex());
            temp[i].Setcapacity(adjacent[i].getcapacity());
            temp[i].Setflow(adjacent[i].getflow());
        }
        delete[] adjacent;
        adjacent = temp;
    }
    adjacent[len].SetVertex(item);
    adjacent[len].Setcapacity(capacity);
    adjacent[len].Setflow(0);
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
        adjacent[position].Setcapacity(garbage);
        adjacent[position].Setflow(garbage);
        len--;
        return true;
    }

    adjacent[position].SetVertex(adjacent[len-1].getVertex());
    adjacent[len-1].SetVertex(garbage);
    adjacent[position].Setcapacity(adjacent[len-1].getcapacity());
    adjacent[len-1].Setcapacity(garbage);
    adjacent[position].Setflow(adjacent[len-1].getflow());
    adjacent[len-1].Setflow(garbage);
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
            cout<<adjacent[i].getVertex()<<"("<<adjacent[i].getflow()<<"/"<<adjacent[i].getcapacity()<<")";
        else
            cout<<adjacent[i].getVertex()<<"("<<adjacent[i].getflow()<<"/"<<adjacent[i].getcapacity()<<")-->";
    }
    cout<<endl;
}
double Arraylist::Capacity(int v)
{
    int x = searchItem(v);
    if(x == garbage)
        return garbage;
    return adjacent[x].getcapacity();
}
double Arraylist::Flow(int v)
{
    int x = searchItem(v);
    if(x == garbage)
        return garbage;
    return adjacent[x].getflow();
}
Edge Arraylist::getEdgeAt(int position)
{
    return adjacent[position];
}
void Arraylist::setCapacity(int v, double c)
{
    int x = searchItem(v);
    if(x==garbage)
        return;
    adjacent[x].Setcapacity(c);
}
void Arraylist::setFlow(int v, double f)
{
    int x = searchItem(v);
    if(x==garbage)
        return;
    adjacent[x].Setflow(f);
}
void Arraylist::setFlowAt(int i, double f)
{
    if(i>=len || i<0)
        return;
    adjacent[i].Setflow(f);
}
Arraylist::~Arraylist()
{
    if(adjacent)
        delete[] adjacent;
    adjacent = 0;
}


/// **Graph** ///

class Graph
{
    Arraylist *adjlist;
    Edge e;
    int nVertices;
    int nEdges;
    bool directed;
    double **adjmatrix;
public:
    Graph(bool directed=true);
    ~Graph();
    void setnVertices(int n);
    bool addEdge(int u, int v, double c);
    void printGraph();
    void removeEdge(int u, int v);
    Edge *searchEdge(int u, int v);
    bool isEdge(int u, int v);
    double getCapacity(int u, int v);
    double getFlow(int u, int v);
    void updateFlowAt(int u, int i, double f);
    void updateFlow(int u, int v, double f);
    Arraylist *&getAdjacencyList();
    double **getAdjMatrix();
    int getNumVertex();
    int getNumEdge();

    double MaxFlow(int s, int t, bool console, ofstream &filewriter, bool bipartite);
    void Bipartite(int s, int t, bool console, ofstream &filewriter);
};
Graph::Graph(bool directed)
{
    adjlist = 0;
    nVertices = 0;
    nEdges = 0;
    adjmatrix = 0;
    this->directed = directed;
}
Graph::~Graph()
{
    if(adjlist)
        delete[] adjlist;
    adjlist = 0;
}
void Graph::setnVertices(int n)
{
    this->nVertices = n;
    adjlist = new Arraylist[nVertices];

    adjmatrix = new double*[nVertices];
    for(int i=0; i<nVertices; i++)
    {
        adjmatrix[i] = new double[nVertices];

        for(int j=0; j<nVertices; j++)
            adjmatrix[i][j] = garbage;
    }
}
bool Graph::addEdge(int u, int v, double c)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return false;
    int y = adjlist[u].searchItem(v);
    if(y == garbage && directed)
    {
        adjlist[u].insertItem(v, c);
        nEdges++;
        return true;
    }
    int x = adjlist[v].searchItem(u);
    if(x==garbage && y == garbage && directed==false) {
        adjlist[u].insertItem(v, c);
        adjlist[v].insertItem(u, c);
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
double Graph::getCapacity(int u, int v)
{
    return adjlist[u].Capacity(v);
}
double Graph::getFlow(int u, int v)
{
    return adjlist[u].Flow(v);
}
Arraylist*& Graph::getAdjacencyList()
{
    return adjlist;
}
double** Graph::getAdjMatrix()
{
    return adjmatrix;
}
void Graph::updateFlowAt(int u, int i, double f)
{
    if(u<0 || i<0 || u>=nVertices || i>=nVertices)
        return;
    adjlist[u].setFlowAt(i, f);
}
void Graph::updateFlow(int u, int v, double f)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;
    int x = adjlist[u].searchItem(v);
    if(x==garbage)
        return;
    adjlist[u].setFlowAt(x, f);
}
int Graph::getNumVertex()
{
    return nVertices;
}
int Graph::getNumEdge()
{
    return nEdges;
}

void Graph::printGraph()
{
    for(int i=0; i<nVertices; i++)
    {
        cout<<i<<": ";
        adjlist[i].printAdjacentVertices();
    }
}

bool BFS(Graph &Gf, int s, int t, int p[])
{
    int nvertex = Gf.getNumVertex();
    int *visit = new int[nvertex];
    for(int i=0; i<nvertex; i++) {
        visit[i] = WHITE;
        p[i] = -1;
    }
    visit[s] = GRAY;
    queue <int> q;
    q.push(s);
    Arraylist *adjlist = Gf.getAdjacencyList();
    double **Gres = Gf.getAdjMatrix();

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<adjlist[u].getLength(); i++) {
            Edge e = adjlist[u].getEdgeAt(i);
            int v = e.getVertex();
            double f = Gres[u][v];

            if(visit[v]==WHITE && f>0) {
                visit[v] = GRAY;
                p[v] = u;
                q.push(v);
            }
        }
        visit[u] = BLACK;
    }

    if(visit[t]==BLACK)
        return true;
    else
        return false;
}

double Graph::MaxFlow(int s, int t, bool console, ofstream &filewriter, bool bipartite)
{
    double maxflow=0;
    int *p = new int[nVertices];
    Graph Gf;
    Gf.setnVertices(nVertices);

    double **Gres = Gf.getAdjMatrix();

    for(int u=0; u<nVertices; u++) {
        for(int v=0; v<nVertices; v++) {
            Gres[u][v] = 0;
        }
    }

    for(int u=0; u<nVertices; u++)
    {
        for(int j=0; j<adjlist[u].getLength(); j++) {
            Edge e = adjlist[u].getEdgeAt(j);
            int v = e.getVertex();
            double c = e.getcapacity();
            double f = e.getflow();

            Gf.addEdge(u, v, c);
            Gf.updateFlowAt(u, j, (c-f));

            Gres[u][v] = (c-f);
            adjmatrix[u][v] = f;

            if(f!=0) {
                Gf.addEdge(v, u, c);
                int len = adjlist[v].getLength();
                Gf.updateFlowAt(v, len-1, f);

                Gres[v][u] = f;
            }
        }
    }

    Arraylist *adjlistGf = Gf.getAdjacencyList();
    while(BFS(Gf, s, t, p))
    {
        double res_capacity = INT_MAX;
        int i = t;
        while(i!=s) {
            int u = p[i];
            double r = Gres[u][i];
            res_capacity = min(res_capacity, r);
            i = u;
        }

        i = t;
        while(i!=s) {
            int u = p[i];
            double r = Gres[u][i];
            r -= res_capacity;
            Gres[u][i] = r;

            if(Gres[i][u]==0) {
                double c = Gf.getCapacity(u, i);
                Gf.addEdge(i, u, c);
            }
            r = Gres[i][u];
            r += res_capacity;
            Gres[i][u] = r;

            r = adjmatrix[u][i];
            if(r!=garbage) {
                r += res_capacity;
                adjmatrix[u][i] = r;
            }
            r = adjmatrix[i][u];
            if(r!=garbage) {
                r -= res_capacity;
                if(r>=0)
                    adjmatrix[i][u] = r;
                else
                    adjmatrix[i][u] = 0;
            }
            i = u;
        }

        maxflow += res_capacity;
    }

    ///Updating flow to the adjacency list///
    for(int u=0; u<nVertices; u++)
    {
        for(int i=0; i<adjlist[u].getLength(); i++) {
            Edge e = adjlist[u].getEdgeAt(i);
            int v = e.getVertex();
            double f = adjmatrix[u][v];
            updateFlowAt(u, i, f);
        }
    }


    if(console && !bipartite)
    {
        cout << maxflow << endl;
        for(int i=0; i<nVertices; i++)
        {
            int len = adjlist[i].getLength();
            for(int j=0; j<len; j++) {
                Edge e = adjlist[i].getEdgeAt(j);
                int v = e.getVertex();
                int f = e.getflow();
                int c = e.getcapacity();
                cout << i << " " << v << " " << f << "/" << c << endl;
            }
        }
    }
    else if(!bipartite)
    {
        filewriter << maxflow << endl;
        for(int i=0; i<nVertices; i++)
        {
            int len = adjlist[i].getLength();
            for(int j=0; j<len; j++) {
                Edge e = adjlist[i].getEdgeAt(j);
                int v = e.getVertex();
                int f = e.getflow();
                int c = e.getcapacity();
                filewriter << i << " " << v << " " << f << "/" << c << endl;
            }
        }
        cout << "The answer is printed on outputmaxflow.txt file" << endl;
    }

    return maxflow;
}
bool BipartiteCheck(Graph &G)
{
    int n = G.getNumVertex();
    Arraylist *adjlist = G.getAdjacencyList();
    int *col = new int[n];
    for(int i=0; i<n; i++) {
        col[i] = GRAY;
    }

    int s = 0;
    col[s] = BLACK;
    queue <int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        bool loop = G.isEdge(u, u);
        if(loop)    return false;

        for(int i=0; i<adjlist[u].getLength(); i++) {
            Edge e = adjlist[u].getEdgeAt(i);
            int v = e.getVertex();

            if(col[v]==GRAY) {
                if(col[u]==BLACK)   col[v] = WHITE;
                else if(col[u]==WHITE)  col[v] = BLACK;
                q.push(v);
            }
            else if(col[v]==col[u])
                return false;
        }
    }
    return true;
}
void Graph::Bipartite(int s, int t, bool console, ofstream &filewriter)
{
    double maxbipartite = MaxFlow(s, t, console, filewriter, true);

    if(console) {
        cout << maxbipartite << endl;
        for(int i=0; i<nVertices-2; i++)
        {
            int len = adjlist[i].getLength();
            for(int j=0; j<len; j++) {
                Edge e = adjlist[i].getEdgeAt(j);
                int v = e.getVertex();
                int f = e.getflow();
                int c = e.getcapacity();
                if(f==c && v!=nVertices-1)
                    cout << i << " " << v << endl;
            }
        }
    }
    else {
        filewriter << maxbipartite << endl;
        for(int i=0; i<nVertices-2; i++)
        {
            int len = adjlist[i].getLength();
            for(int j=0; j<len; j++) {
                Edge e = adjlist[i].getEdgeAt(j);
                int v = e.getVertex();
                int f = e.getflow();
                int c = e.getcapacity();
                if(f==c && v!=nVertices-1)
                    filewriter << i << " " << v << endl;
            }
        }
        cout << "The answer is printed on outputbipartite.txt file" << endl;
    }
}

int main()
{
    int s, t, nV=0, nE=0;
    string line, *token, text;

    cout << "Select Any of the two options" << endl;
    cout << "1. Max flow" << endl;
    cout << "2. Bipartite Matching" << endl;

    int choice;
    cin >> choice;
    if(choice==1)
    {
        Graph g;
        int i=0, j=0;
        ifstream fileReader("inputmaxflow.txt");
        ofstream filewriter("outputmaxflow.txt");

        //Setting number of vertexes and edges.///
        getline(fileReader, line);
        stringstream ss(line);
        token = new string[2];
        while(getline(ss, text, ' ')) {
            token[i] = text;
            i++;
        }
        nV = stoi(token[0]);
        nE = stoi(token[1]);
        g.setnVertices(nV);

        // Adding edges ///
        token = new string[3];
        i=0;
        while(true)
        {
            if(i==nE)
                break;
            getline(fileReader, line);
            stringstream converter(line);
            while(getline(converter, text, ' '))
            {
                token[j] = text;
                j++;
            }

            int u = stoi(token[0]);
            int v = stoi(token[1]);
            double capacity  = stoi(token[2]);

            g.addEdge(u, v, capacity);
            j=0;
            i++;
        }
        // Setting source and sink ///
        i=0;
        getline(fileReader, line);
        stringstream last(line);
        token = new string[2];
        while(getline(last, text, ' ')) {
            token[i] = text;
            i++;
        }
        s = stoi(token[0]);
        t = stoi(token[1]);

        cout << "Graph created" << endl;
        cout << "choose between 2 options" << endl;
        cout << "1. print on console" << endl;
        cout << "2. write on a file" << endl;
        cout << "default is on file" << endl;
        int x;
        cin >> x;
        bool console=false;
        if(x==1)    console = true;

        double maxflow = g.MaxFlow(s, t, console, filewriter, false);
    }
    else if(choice==2)
    {
        Graph g, G(false);
        int i=0, j=0;
        ifstream fileReader("inputbipartite.txt");
        ofstream filewriter("outputbipartite.txt");

        //Setting number of vertexes and edges.///
        getline(fileReader, line);
        stringstream ss(line);
        token = new string[2];
        while(getline(ss, text, ' ')) {
            token[i] = text;
            i++;
        }
        nV = stoi(token[0]);
        nE = stoi(token[1]);
        g.setnVertices(nV+2);
        G.setnVertices(nV);
        s = nV;
        t = nV+1;

        token = new string[2];
        i=0;
        while(true)
        {
            if(i==nE)
                break;
            getline(fileReader, line);
            stringstream converter(line);
            while(getline(converter, text, ' '))
            {
                token[j] = text;
                j++;
            }

            int u = stoi(token[0]);
            int v = stoi(token[1]);
            double capacity  = 1;

            g.addEdge(u, v, capacity);
            g.addEdge(s, u, 1);
            g.addEdge(v, t, 1);
            G.addEdge(u, v, capacity);
            j=0;
            i++;
        }

        cout << "Graph Created" << endl;
        cout << "choose between 2 options" << endl;
        cout << "1. print on console" << endl;
        cout << "2. write on a file" << endl;
        cout << "default is on file" << endl;
        int x;
        cin >> x;
        bool console=false;
        if(x==1)    console = true;


        bool isbipartite = BipartiteCheck(G);

        if(!isbipartite)
        {
            if(console) {
                cout << "The graph is not bipartite" << endl;
            }
            else {
                filewriter << "The graph is not bipartite" << endl;
                cout << "The answer is printed on outputbipartite.txt file" << endl;
            }
            return 0;
        }
        g.Bipartite(s, t, console, filewriter);
    }
    return 0;
}
