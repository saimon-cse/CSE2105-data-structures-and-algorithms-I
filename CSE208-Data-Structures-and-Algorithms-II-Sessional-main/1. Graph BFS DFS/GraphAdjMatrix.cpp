#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#define NULL_VALUE -999999
#define infinity 999999
#define white 1
#define gray 2
#define black 3

using namespace std;

class Queue
{
    int *Q;
    int inisize, maxsize, front, rear, len;

public:
    Queue();
    void enqueue(int item);
    int dequeue();
    bool empty();
    ~Queue();
};

Queue::Queue()
{
    inisize = 2;
    maxsize = inisize;
    Q = new int[maxsize];
    len = 0;
    front = 0;
    rear = 0;
}

void Queue::enqueue(int item)
{
    if(len == maxsize)
    {
        int *temp, i, j=0;
        maxsize = 2 * maxsize;
        temp = new int[maxsize];

        for(i=rear; i<len; i++)
        {
            temp[j] = Q[i];
            j++;
        }

        for(i=0; i<rear; i++)
        {
            temp[j] = Q[i];
            j++;
        }

        rear = 0;
        front = len;
        delete[] Q;
        Q = temp;
    }

    Q[front] = item;
    front = (front+1) % maxsize;
    len++;
}

int Queue::dequeue()
{
    if(len == 0)
        return NULL_VALUE;
    int x = Q[rear];
    rear = (rear+1) % maxsize;
    len--;
    return x;
}

bool Queue::empty()
{
    if(len == 0)
        return true;
    else
        return false;
}

Queue::~Queue()
{
    delete[] Q;
    Q = 0;
}

class Stack
{
    int *s;
    int len, inisize, maxsize;
public:
    Stack();
    ~Stack();
    void push(int item);
    void pop();
    int top();
    bool empty();
};

Stack::Stack()
{
    len = 0;
    s = 0;
    inisize = 2;
    maxsize = inisize;
    s = new int[maxsize];
}

Stack::~Stack()
{
    if(s!=0)
        delete[] s;
    s = 0;
}

void Stack::push(int item)
{
    if(len == maxsize)
    {
        maxsize = 2*maxsize;
        int *temp = new int[maxsize];

        for(int i=0; i<len; i++)
        {
            temp[i] = s[i];
        }

        delete[] s;
        s = temp;
    }

    s[len] = item;
    len++;
}

void Stack::pop()
{
    s[len-1] = NULL_VALUE;
    len--;
}

int Stack::top()
{
    return s[len-1];
}

bool Stack::empty()
{
    if(len==0)
        return true;
    return false;
}

class Graph
{
    bool directed;
    int **AdjMatrix;
    int nVertices, nEdges, *col, *p, *dis;

public:
    Graph(bool dir);
    ~Graph();
    void setnVertices(int n);
    bool addEdge(int u, int v);
    void printGraph();
    void removeEdge(int u, int v);
    bool isEdge(int u, int v);
    int getOutDegree(int u);
    int getInDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    void bfs(int source);
    void dfs(int source);
    int getDist(int u, int v);
    int NumofEdges();
};

Graph::Graph(bool dir)
{
    directed = dir;
    AdjMatrix = 0;
    nVertices = 0;
    nEdges = 0;
    col = 0;
    p = 0;
    dis = 0;
}

Graph::~Graph()
{
    if(AdjMatrix!=0)
    {
        for(int i = 0; i < nVertices; i++)
        {
            delete[] AdjMatrix[i];
        }
        delete[] AdjMatrix;
    }
    AdjMatrix = 0;
}

int Graph::NumofEdges()
{
    return nEdges;
}

void Graph::setnVertices(int n)
{
    nVertices = n ;
    AdjMatrix = new int*[nVertices];

    for(int i=0; i<nVertices; i++)
    {
        AdjMatrix[i] = new int[nVertices];

        for(int j=0; j<nVertices; j++)
            AdjMatrix[i][j] = 0;
    }
    nEdges = 0;
}

bool Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>= nVertices || v>=nVertices)
        return false;

    bool verdict = isEdge(u, v);

    if(verdict==false)
    {
        AdjMatrix[u][v] = 1;

        if(directed == false)
            AdjMatrix[v][u] = 1;

        nEdges++;
        return true;
    }

    return false;
}

void Graph::printGraph()
{
    for(int i=0; i<nVertices; i++)
    {
        cout<<i<<": ";

        for(int j=0; j<nVertices; j++)
        {
            if(AdjMatrix[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
}

void Graph::removeEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;

    int verdict = isEdge(u, v);

    if(verdict==false)
    {
        AdjMatrix[u][v] = 0;

        if(directed==false)
            AdjMatrix[v][u] = 0;
    }
}

bool Graph::isEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return  false;

    if(AdjMatrix[u][v]==1)
        return true;

    return false;
}

int Graph::getOutDegree(int u)
{
    if(u<0 || u >= nVertices)
        return NULL_VALUE;

    int edges = 0;
    for(int i=0; i<nVertices; i++)
    {
        if(AdjMatrix[u][i]==1)
            edges++;
    }

    return edges;
}

int Graph::getInDegree(int u)
{
    if(u<0 || u >= nVertices)
        return NULL_VALUE;

    if(directed==false)
    {
        int edges = 0;
        for(int i=0; i<nVertices; i++)
        {
            if(AdjMatrix[u][i]==1)
                edges++;
        }

        return edges;
    }

    int deg = 0;
    for(int i=0; i<nVertices; i++)
    {
        if(AdjMatrix[i][u]==1)
            deg++;
    }

    return deg;
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return false;

    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            if(AdjMatrix[u][i] == AdjMatrix[v][j])
            {
                return true;
            }
        }
    }
}

void Graph::bfs(int source)
{
    if(source<0 || source >= nVertices)
        return;

    Queue q;
    col = new int[nVertices];
    p = new int[nVertices];
    dis = new int[nVertices];

    for(int i=0; i<nVertices; i++)
    {
        if(i != source)
        {
            col[i] = white;
            p[i] = NULL_VALUE;
            dis[i] = infinity;
        }
    }

    col[source] = gray;
    p[source] = NULL_VALUE;
    dis[source] = 0;

    q.enqueue(source);
    cout<<source<<" ";

    while(!q.empty())
    {
        int s = q.dequeue();
        for(int i=0; i<nVertices; i++)
        {
            if(AdjMatrix[s][i]==1);
            {
                if(col[i] == white)
                {
                    cout<<i<<" ";
                    col[i] = gray;
                    p[i] = s;
                    dis[i] = dis[s]+1;
                    q.enqueue(i);
                }
            }
        }

        col[s] = black;
    }
    cout<<endl;
}

void Graph::dfs(int source)
{
    if(source<0 || source >= nVertices)
        return;

    col = new int[nVertices];
    p = new int[nVertices];
    dis = new int[nVertices];

    for(int i=0; i<nVertices; i++)
    {
        col[i] = white;
        p[i] = NULL_VALUE;
    }

    int flg=0;
    Stack st;

    col[source] = gray;
    st.push(source);
    cout<<source<<" ";

    while(!st.empty())
    {
        int u = st.top();

        for(int i=0; i<nVertices; i++)
        {
            if(AdjMatrix[u][i]==1)
            {

                if(col[i]==white)
                {
                    cout<<i<<" ";
                    p[i] = u;
                    col[i] = gray;
                    st.push(i);
                    flg=1;
                    break;
                }
                else
                    flg=0;
            }
        }

        if(flg==0)
        {
            col[u] = black;
            st.pop();
            flg=1;
        }
    }
    cout<<endl;
}

int Graph::getDist(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return NULL_VALUE;
    bfs(u);
    int dis = this->dis[v] - this->dis[u];
    return dis;
}

void CreateNvertices(Graph &G, bool dir, int V, int n, int randV)
{
    int lim = randV + n;
    int i, j, x;
    for(i=randV; i<V; i++)
    {
        x = G.NumofEdges();
        if(x == n*V)
            break;
        for(j=0; j<V; j++)
        {
            x = G.NumofEdges();
            if(x == n*V)
                break;
            G.addEdge(i, j);
        }
    }

    ///cout<<"randv: "<<randV<<" Edges: "<<G.NumofEdges()<<endl;
}

void CreateFractionalEdges(Graph &G, bool dir, int V, double n, int randV)
{
    double u = V;
    int i, j, x;
    for(i=randV; i<V; i++)
    {
        x = G.NumofEdges();
        if(x == u*n)
            break;
        for(j=0; j<V; j++)
        {
            x = G.NumofEdges();
            if(x == u*n)
                break;
            G.addEdge(i, j);
        }
    }

    ///cout<<"randv: "<<randV<<" Edges: "<<G.NumofEdges()<<endl;
}

int main()
{
    int selector, V=1000, sources[10];
    srand(time(NULL));

    cout<<"1.Directed"<<"\t"<<"2.Undirected"<<endl;
    cin>>selector;

    bool dir = false;

    if(selector==1)
        dir = true;
    else if(selector==2)
        dir = false;

    Graph G(dir);

    sources[0] = rand()%100;
    for(int i=1; i<10; i++)
    {
        sources[i] = sources[i-1] + 50 + rand()%50;
    }

    while(1)
    {
        cout<<"1. Set number of vertices"<<endl;
        cout<<"2. Add edge.\n3. Print Graph.\n4. Remove Edge"<<endl;
        cout<<"5. Is edge."<<endl;
        cout<<"6. Get out degree.\n7. Get in degree."<<endl;
        cout<<"8. Has common adjacent\n9. BFS.\n10. DFS"<<endl;
        cout<<"11. Get Distance\n12. Runtime Analysis."<<endl;
        cout<<"13. Create n*|V| number of Edges."<<endl;
        cout<<"14. time takes to run BFS"<<endl;
        cout<<"15. Exit."<<endl;


        int choice;
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Enter number of vertices: ";
            cin>>V;
            G.setnVertices(V);
            cout<<endl;
        }
        else if(choice == 2)
        {
            int u, v;
            cout<<"Enter the value of two vertices: ";
            cin>>u;
            cin>>v;
            G.addEdge(u, v);
            cout<<endl;
        }
        else if(choice == 3)
        {
            G.printGraph();
            cout<<endl;
        }
        else if(choice == 4)
        {
            int u, v;
            cout<<"Enter the value of two vertices: ";
            cin>>u;
            cin>>v;
            G.removeEdge(u, v);
            cout<<endl;
        }
        else if(choice == 5)
        {
            int u, v;
            cout<<"Enter the value of two vertices: ";
            cin>>u;
            cin>>v;
            bool res = G.isEdge(u, v);
            if(res == true)
            {
                cout<<"true"<<endl;
            }
            else
                cout<<"false"<<endl;
        }
        else if(choice == 6)
        {
            int u;
            cout<<"Enter a vertex: ";
            cin>>u;
            cout<<G.getOutDegree(u)<<endl;
        }
        else if(choice == 7)
        {
            int u;
            cout<<"Enter a vertex: ";
            cin>>u;
            cout<<G.getInDegree(u)<<endl;
            break;
        }
        else if(choice == 8)
        {
            int u, v;
            printf("Enter the value of two vertices: \n");
            cin>>u;
            cin>>v;
            bool res = G.hasCommonAdjacent(u, v);
            if(res)
                cout<<"true"<<endl;
            else
                cout<<"flase"<<endl;
        }
        else if(choice == 9)
        {
            int u;
            cout<<"Enter the source vertex: ";
            cin>>u;
            G.bfs(u);
        }
        else if(choice == 10)
        {
            int u;
            cout<<"Enter the source vertex: ";
            cin>>u;
            G.dfs(u);
        }
        else if(choice == 11)
        {
            int u, v;
            cout<<"Enter the value of two vertices: ";
            cin>>u;
            cin>>v;
            int d = G.getDist(u, v);
            cout<<"distance: "<<d<<endl;
        }
        else if(choice == 12)
        {
            int i, j=0, k=0;
            double sum = 0;
            int randV = rand()%100;
            int vertex[5];

            for(i=1000; i<17000; i=i*2)
            {
                vertex[j] = i;
                j++;
            }

            int uplim = j;
            int h = ((vertex[0]*vertex[0] - vertex[0])/8)/vertex[0];

            for(i=0; i<uplim; i++)
            {
                h = ((vertex[i]*vertex[i] - vertex[i])/8)/vertex[i];
                G.setnVertices(vertex[i]);
                for(j=1; j<h; j=j*2)
                {
                    CreateNvertices(G, dir, vertex[i], j, randV);
                    for(k=0; k<10; k++)
                    {
                        auto t1 = chrono::high_resolution_clock::now();
                        G.bfs(sources[k]);
                        auto t2 = chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
                        sum += duration;
                    }
                    sum = sum/10;
                    cout<<"The average time taken for "<<vertex[i]<<" vertices & "<<j*vertex[i]<<" edges: "<<sum<<" microseconds"<<endl;
                    sum = 0;
                }
                cout<<endl<<endl;
                sum = 0;
            }
        }
        else if(choice == 13)
        {
            double n;
            cout<<"To create n*|V| edges\nEnter the value of n: ";
            cin>>n;
            CreateFractionalEdges(G, dir, V, n, 0);
        }
        else if(choice == 14)
        {
            int s;
            cout<<"enter source: "<<endl;
            cin>>s;
            auto t1 = chrono::high_resolution_clock::now();
            G.bfs(s);
            auto t2 = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            cout<<"BFS running time: "<<duration<<" microseconds"<<endl;
        }
        else if(choice == 15)
        {
            int x = ((V*V - V)/8)/V;
            for(int i=1; i<x; i=i*2)
                CreateNvertices(G, dir, V, i, 12);
            //break;
        }

    }

    return 0;
}
