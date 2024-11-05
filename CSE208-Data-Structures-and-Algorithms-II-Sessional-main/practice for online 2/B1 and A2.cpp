#include<iostream>
#include<queue>
#include<fstream>
#include<cstring>
#include<sstream>
#define garbage -99999

using namespace std;

class Vertex
{
public:
    int value;
    string name;
    int wg;
};
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
    this->weight = garbage;
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
    int source, destination, weight;
public:
    Edge();
    void setEdge(int s, int des, int wg);
    int getSource();
    int getDestination();
    int getWG();
};

Edge::Edge()
{
    source = garbage;
    destination = garbage;
    weight = garbage;
}
void Edge::setEdge(int s, int des, int wg)
{
    source = s;
    destination = des;
    weight = wg;
}
int Edge::getSource()
{
    return source;
}
int Edge::getDestination()
{
    return destination;
}
int Edge::getWG()
{
    return weight;
}

///***Comparator For Min Heap***///

class comparator
{
public:
    int operator()(Node n1, Node n2)
    {
        return n1.getweight()>n2.getweight();
    }
};

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
    len = 0;    ///number of adjacent vertices.
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
    cout<<"cool"<<endl;
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
        cout<<"v:"<<adjacent[i].getVertex()<<",w:"<<adjacent[i].getweight()<<"; ";
    cout<<endl;
}
int Arraylist::Weight(int v)
{
    int x = searchItem(v);
    if(x == garbage)
        return garbage;
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
    void SetMaxEdges(int n);
    void addEdge(int u, int v, int w);
    int getIndegree(int u);
    int getOutdegree(int u);
    void printGraph();
    void removeEdge(int u, int v);
    int getWeight(int u, int v);
    void Dijkstra(string source, string destination, ofstream &filewriter, Vertex *V);
    //void BellmanFord(string source, string destination, ofstream &filewriter, Vertex *V);
    int GetEdges();
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
}
void Graph::SetMaxEdges(int n)
{
    this->MaxnEdges = n;
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
int Graph::getOutdegree(int u)
{
    if(u<0 || u>=nVertices)
        return garbage;
    adjlist[u].getLength();
}
int Graph::getIndegree(int u)
{
    if(u<0 || u>nVertices)
        return garbage;
    int deg=0;
    for(int i=0; i<nVertices; i++)
    {
        if(adjlist[i].searchItem(u) != garbage)
            deg++;
    }
    return deg;
}
int Graph::getWeight(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return garbage;
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
    nEdges--;
}
void Graph::Dijkstra(string sou, string des, ofstream &filewriter, Vertex *V)
{
    priority_queue <Node, vector<Node>, comparator> Q;

    int source=garbage, destination=garbage;
    for(int i=0; i<nVertices; i++)
    {
        if(V[i].name==sou)
            source = i;
        if(V[i].name==des)
            destination = i;
    }

    int d[nVertices], p[nVertices];
    int S[nVertices], i, j;
    for(i=0; i<nVertices; i++)
    {
        d[i] = INT_MAX;
        S[i] = 0;
        p[i] = garbage;
    }
    d[source] = 0;
    Node Source;
    Source.SetVertex(source);
    Source.Setweight(V[source].wg);

    Q.push(Source);

    cout<<endl<<endl;
    while(Q.empty()==false)
    {
        Node u = Q.top();
        Q.pop();
        //cout<<V[u.getVertex()].name<<endl;
        int du = d[u.getVertex()];
        for(j=0; j<adjlist[u.getVertex()].getLength(); j++)
        {
            Node v = adjlist[u.getVertex()].getNodeAt(j);
            int dv = d[v.getVertex()];
            int dw = V[v.getVertex()].wg;
            int w = v.getweight();
            if(w < 0)
                w = -1*w;
            w = dw + w;
            if(dv > du + w)
            {
                cout<<"ok"<<endl;
                d[v.getVertex()] = (du + w);
                p[v.getVertex()] = u.getVertex();
                Q.push(v);
            }
        }
    }

    int v = destination, count=0, temp[nVertices];
    while(v!=garbage)
    {
        temp[count] = v;
        v = p[v];
        count++;
    }

    for(i=count-1, j=0; i>=0; i--, j++)
    {
        S[j] = temp[i];
    }

    filewriter<<"Dijkstra Algorithm: "<<endl;
    filewriter<<d[destination]<<endl;
    for(i=0; i<count; i++)
    {
        if(i==count-1)
            filewriter<<V[S[i]].name;
        else
            filewriter<<V[S[i]].name<<" -> ";
    }
}
int Graph::GetEdges()
{
    return nEdges;
}
/*void Graph::BellmanFord(string sou, string des, ofstream &filewriter, Vertex *V)
{


    int d[nVertices], p[nVertices];
    int S[nVertices], i, j;
    for(i=0; i<nVertices; i++)
    {
        d[i] = INT_MAX;
        S[i] = 0;
        p[i] = garbage;
    }
    d[source] = 0;

    for(i=0; i<nVertices-1; i++)
    {
        for(j=0; j<nEdges; j++)
        {
            int u = edges[j].getSource();
            int v = edges[j].getDestination();
            int w = edges[j].getWG();
            if(d[u]!=INT_MAX)
            {
                if(d[v] > d[u] + w)
                {
                    d[v] = d[u]+w;
                    p[v] = u;
                }
            }
        }
    }

    for(i=0; i<nEdges; i++)
    {
        int u = edges[i].getSource();
        int v = edges[i].getDestination();
        int w = edges[i].getWG();
        if(d[u]!=INT_MAX)
        {
            if(d[v] > d[u] + w)
            {
                cout<<"The graph has no solution."<<endl;
                return;
            }
        }
    }

    int v = destination, count=0, temp[nVertices];
    while(v!=garbage)
    {
        temp[count] = v;
        v = p[v];
        count++;
    }

    for(i=count-1, j=0; i>=0; i--, j++)
    {
        S[j] = temp[i];
    }

    filewriter<<"Bellman Ford Algorithm: "<<endl;
    filewriter<<d[destination]<<endl;
    for(i=0; i<count; i++)
    {
        if(i==count-1)
            filewriter<<S[i];
        else
            filewriter<<S[i]<<" -> ";
    }
    filewriter<<endl;
}*/


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
    int i=0, j=0, nvertex=0, nedge=0;
    string line, *token, text;

     Vertex *V;

    ifstream fileReader("Input.txt");
    ofstream filewriter("Output.txt");

    ///setting number of vertices and edges
    getline(fileReader, line);
    stringstream ss(line);
    token = new string[2];
    while(getline(ss, text, ' '))
    {
        token[i] = text;
        i++;
    }

    nvertex = stoi(token[0]);
    nedge = stoi(token[1]);
    g.SetnVertices(nvertex);
    g.SetMaxEdges(nedge);

    ///setting vertices
    token = new string[2];
    V = new Vertex[nvertex];
    i=0;
    while(true)
    {
        if(i==nvertex)
            break;
        getline(fileReader, line);
        stringstream converter(line);
        while(getline(converter, text, ' '))
        {
            token[j] = text;
            j++;
        }

        V[i].name = token[0];
        V[i].value = i;
        V[i].wg = stoi(token[1]);

        j=0;
        i++;
    }

    for(int x=0; x<nvertex; x++)
    {
        cout<<V[x].name<<endl;
    }

    ///Adding edges

    token = new string[3];
    i=0;
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

        string a = token[0];
        string b = token[1];

        int w = stoi(token[2]);
        int u=garbage, v=garbage;

        for(int x=0; x<nvertex; x++)
        {
           if(V[x].name==a)
            u = x;
           if(V[x].name==b)
            v = x;
        }

        j=0;
        i++;
        g.addEdge(u, v, w);
    }

    ///setting source and destination
    i=0;
    token = new string[2];
    getline(fileReader, line);
    stringstream converter(line);
    while(getline(converter, text, ' '))
    {
        token[i] = text;
        i++;
    }

    string u = (token[0]);
    string v = (token[1]);

    //g.BellmanFord(u, v, filewriter, V);
    //filewriter<<endl;
    g.Dijkstra(u, v, filewriter, V);
    fileReader.close();
    filewriter.close();

    return 0;
}

