#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define garbage -99999

using namespace std;

class Node
{
    int vertex;
    int weight;
public:
    Node();
    void Setweight(int w);
    void SetVertex(int v);
    int getweight();
    int getVertex();
};

Node::Node()
{
    this->vertex = garbage;
    this->weight = INT_MAX;
}
void Node::Setweight(int w)
{
    this->weight = w;
}
void Node::SetVertex(int v)
{
    this->vertex = v;
}
int Node::getweight()
{
    return weight;
}
int Node::getVertex()
{
    return vertex;
}



class Edge
{
    int vertex1, vertex2, weight;
public:
    Edge();
    void setEdge(int s, int des, int wg);
    int getVertex2();
    int getVertex1();
    int getWG();
};

Edge::Edge()
{
    vertex1 = garbage;
    vertex2 = garbage;
    weight = garbage;
}
void Edge::setEdge(int s, int des, int wg)
{
    vertex1 = s;
    vertex2 = des;
    weight = wg;
}
int Edge::getVertex1()
{
    return vertex1;
}
int Edge::getVertex2()
{
    return vertex2;
}
int Edge::getWG()
{
    return weight;
}

///***Comparator For Min Heap***///
class Heapcomparator
{
public:
    int operator()(Node n1, Node n2)
    {
        return n1.getweight()>n2.getweight();
    }
};


///***Comparator For Sort**///
bool sortComparator(Edge e1, Edge e2)
{
    return (e1.getWG() < e2.getWG());
}



class DisjointSet
{
    int *p;
    int *r;
public:
    DisjointSet(int n);
    void makeSet(int u);
    int findSet(int u);
    void Union(int u, int v);
    int* getParent();
    ~DisjointSet();
};

DisjointSet::DisjointSet(int n)
{
    p = new int[n];
    r = new int[n];
    for(int i=0; i<n; i++)
    {
        p[i] = garbage;
        r[i] = garbage;
    }
}

void DisjointSet::makeSet(int u)
{
    if(u<0) return;
    p[u] = u;
    r[u] = u;
}

int DisjointSet::findSet(int u)
{
    if(p[u]==garbage) return garbage;
    if(u != p[u])
        p[u] = findSet(p[u]);
    return p[u];
}

void DisjointSet::Union(int u, int v)
{
    int x = findSet(u);
    int y = findSet(v);

    if(x==y || x==garbage || y==garbage)
        return;
    if(r[x] > r[y])
        p[y] = x;
    else if(r[x]<r[y])
        p[x] = y;
    else
    {
        p[y] = x;
        r[x] = r[x] + 1;
    }
}

int* DisjointSet::getParent()
{
    return p;
}

DisjointSet::~DisjointSet()
{
    if(p)
        delete[] p;
    if(r)
        delete[] r;
    p = 0;
    r = 0;
}



///***ARRAYLIST***///

class Arraylist
{
    Node *adjacent;
    int initialsize;
    int maxsize;
    int len;
public:
    Arraylist();
    ~Arraylist();
    void insertItem(int item, int weight);
    int searchItem(int item);
    bool removeItem(int item);
    bool removeItemAt(int position);
    int getItem(int position);
    int getLength();
    bool IsEmpty();
    void printAdjacentVertices();
    void setValue(int u);
    void setWeight(int w);
    int Weight(int v);
    Node getNodeAt(int position);
};

Arraylist::Arraylist()
{
    initialsize = 2;
    maxsize = initialsize;
    adjacent = new Node[initialsize];
    len = 0;
}

void Arraylist::insertItem(int item, int weight)
{
    Node *temp;
    if(len == maxsize)
    {
        maxsize = 2*maxsize;
        temp = new Node[maxsize];
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
        cout<<adjacent[i].getVertex()<<"("<<adjacent[i].getweight()<<") ";
    cout<<endl;
}

int Arraylist::Weight(int v)
{
    int x = searchItem(v);
    if(x == garbage)
        return INT_MAX;
    return adjacent[x].getweight();
}

Node Arraylist::getNodeAt(int position)
{
    return adjacent[position];
}

Arraylist::~Arraylist()
{
    if(adjacent)
        delete[] adjacent;
    adjacent = 0;
}



///***GRAPH***////

class Graph
{
    Arraylist *adjlist;
    Edge *edges;
    int nVertices;
    int nEdges;
    int MaxnEdges;
public:
    Graph();
    ~Graph();
    void SetnVertices(int n);
    void addEdge(int u, int v, int w);
    int getDegree(int u);
    void printGraph();
    void removeEdge(int u, int v);
    int getWeight(int u, int v);
    int GetEdges();
    void PrimJernikAlgo(bool C, ofstream &filewriter);
    void KruskalAlgo(bool C, ofstream &filewriter);
};

Graph::Graph()
{
    adjlist = 0;
    nVertices = 0;
    MaxnEdges = 0;
    nEdges = 0;
    edges = 0;
}
void Graph::SetnVertices(int n)
{
    this->nVertices = n;
    adjlist = new Arraylist[nVertices];
    this->MaxnEdges = (n*(n-1))/2;
    edges = new Edge[MaxnEdges];
}

void Graph::addEdge(int u, int v, int w)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices || nEdges==MaxnEdges)
    {
        return;
    }
    adjlist[u].insertItem(v, w);
    adjlist[v].insertItem(u, w);
    edges[nEdges].setEdge(u, v, w);
    nEdges++;
}

int Graph::getDegree(int u)
{
    if(u<0 || u>=nVertices)
        return garbage;
    return adjlist[u].getLength();
}

int Graph::getWeight(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return INT_MAX;
    return adjlist[u].Weight(v);
}
void Graph::printGraph()
{
    for(int i=0; i<nVertices; i++)
    {
        cout<<i<<": ";
        adjlist[i].printAdjacentVertices();
    }
}

void Graph::removeEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices || nEdges<=0)
        return;
    adjlist[u].removeItem(v);
    adjlist[v].removeItem(u);
    nEdges--;
}

int Graph::GetEdges()
{
    return nEdges;
}

void Graph::PrimJernikAlgo(bool C, ofstream &filewriter)
{
    priority_queue <Node, vector<Node>, Heapcomparator> q;
    int key[nVertices], p[nVertices];
    bool InQueue[nVertices];
    int sum=0, r;

    for(int i=0; i<nVertices; i++)
    {
        key[i] = INT_MAX;
        p[i] = -1;
        InQueue[i] = false;
    }

    r = rand()%nVertices;
    Node s;
    s.SetVertex(r);
    s.Setweight(0);
    q.push(s);
    key[r] = 0;

    while(!q.empty())
    {
        Node u = q.top();
        q.pop();

        if(InQueue[u.getVertex()]==false) {
            InQueue[u.getVertex()] = true;

            for(int i=0; i<adjlist[u.getVertex()].getLength(); i++)
            {
                Node V = adjlist[u.getVertex()].getNodeAt(i);
                int v = V.getVertex();
                int w = V.getweight();

                if(!InQueue[v] && w<key[v])
                {
                    key[v] = w;
                    Node temp;
                    temp.SetVertex(v);
                    temp.Setweight(w);
                    q.push(temp);
                    p[v] = u.getVertex();
                }
            }
        }
    }

    for(int i=0; i<nVertices; i++)
        if(key[i]!=INT_MAX)
            sum += key[i];

    if(C==true)
    {
        cout<<"Prim's Algorithm:"<<endl;
        cout<<"Root node = "<<r<<endl;
        for(int i=0; i<nVertices; i++)
        {
            if(i!=r && p[i]!=-1)
            {
                cout<<i<<" ";
                cout<<p[i]<<endl;
            }
        }
    }
    else
    {
        filewriter<<"Prim's Algorithm:"<<endl;
        filewriter<<"Root node = "<<r<<endl;
        for(int i=0; i<nVertices; i++)
        {
            if(i!=r && p[i]!=-1)
            {
                filewriter<<i<<" ";
                filewriter<<p[i]<<endl;
            }
        }
    }
}

void Graph::KruskalAlgo(bool C, ofstream &filewriter)
{
    int i, j=0, sum=0;
    Edge e[nVertices-1];
    DisjointSet D(nVertices);

    for(int i=0; i<nVertices; i++)
        D.makeSet(i);

    sort(edges, edges+nEdges, sortComparator);

    for(i=0; i<nEdges; i++)
    {
        int x = D.findSet(edges[i].getVertex1());
        int y = D.findSet(edges[i].getVertex2());
        if(x != y)
        {
            e[j] = edges[i];
            j++;
            D.Union(x, y);
            sum += edges[i].getWG();
        }
    }
    if(C==true)
    {
        cout<<sum<<endl;
        cout<<"Kruskal's algorithm:"<<endl;
        for(i=0; i<j; i++)
        {
            cout<<e[i].getVertex1()<<" ";
            cout<<e[i].getVertex2()<<endl;
        }
    }
    else
    {
        filewriter<<sum<<endl;
        filewriter<<"Kruskal's algorithm:"<<endl;
        for(i=0; i<j; i++)
        {
            filewriter<<e[i].getVertex1()<<" ";
            filewriter<<e[i].getVertex2()<<endl;
        }
    }

}

Graph::~Graph()
{
    if(adjlist)
        delete[] adjlist;
    adjlist = 0;
    if(edges)
        delete[] edges;
    edges = 0;
}


int main()
{
    Graph g;
    int i=0, j=0, nvertex=0, nedge=0, c;
    string line, *token, text;
    srand(time(NULL));

    ifstream fileReader("Input.txt");
    ofstream filewriter("Output.txt");

    getline(fileReader, line);
    stringstream ss(line);
    token = new string[2];
    while(getline(ss, text, ' '))
    {
        token[i] = text;
        i++;
    }

    nvertex = atoi(token[0].c_str());
    nedge = atoi(token[1].c_str());

    g.SetnVertices(nvertex);

    i=0;
    token = new string[3];
    while(true)
    {
        if(i==nedge)
            break;
        getline(fileReader, line);
        stringstream converter(line);
        while(getline(converter, text, ' '))
        {
            token[j] = text;
            j++;
        }

        int u = atoi(token[0].c_str());
        int v = atoi(token[1].c_str());
        int w = atoi(token[2].c_str());

        g.addEdge(u, v, w);
        j=0;
        i++;
    }

    bool YesOrNo;
    cout<<"1.Output on console"<<"\t"<<"2.Output in a File"<<endl;
    while(c!=1 && c!=2)
    {
        cin>>c;
    }
    if(c==1)
        YesOrNo = true;
    else
        YesOrNo = false;

    g.KruskalAlgo(YesOrNo, filewriter);
    g.PrimJernikAlgo(YesOrNo, filewriter);
    fileReader.close();
    filewriter.close();

    return 0;
}

