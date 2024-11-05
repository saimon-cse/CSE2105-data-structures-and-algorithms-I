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
    int inisize;
    int maxsize;
    int len;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item);
    int dequeue();
    bool empty();
};

Queue::Queue()
{
    inisize = 2 ;
    maxsize = inisize;
    Q = new int[maxsize];
    len = 0;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
    if (len == maxsize)
    {
        int *temp;
        maxsize = 2*maxsize;
        temp = new int[maxsize];
        int i, j;
        j = 0;
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


bool Queue::empty()
{
    if(len == 0)
        return true;
    else
        return false;
}


int Queue::dequeue()
{
    if(len == 0)
        return NULL_VALUE;
    int item = Q[rear] ;
    rear = (rear+1) % maxsize;
    len--;
    return item;
}


Queue::~Queue()
{
    if(Q)
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


class ArrayList
{
    int *list;
    int len;
    int maxSize;
    int iniSize;
public:
    ArrayList();
    ~ArrayList();
    int searchItem(int item);
    void insertItem(int item);
    void removeItem(int item);
    void removeItemAt(int item);
    int getItem(int position);
    int getLength();
    bool empty();
    void printList();
} ;


ArrayList::ArrayList()
{
    iniSize = 2;
    maxSize = iniSize;
    list = new int[maxSize];
    len = 0;
}

int ArrayList::searchItem(int item)
{
    for (int i=0; i<len; i++)
    {
        if( list[i] == item )
            return i;
    }
    return NULL_VALUE;
}

void ArrayList::insertItem(int newitem)
{
    int *tempList, i;
    if (len == maxSize)
    {
        maxSize = 2*maxSize;
        tempList = new int[maxSize];
        for(i=0; i<len ; i++)
        {
            tempList[i] = list[i];
        }
        delete[] list;
        list = tempList;
    };

    list[len] = newitem;
    len++;
}

void ArrayList::removeItem(int item)
{
    int position;
    position = searchItem(item);
    if ( position == NULL_VALUE )
        return;
    removeItemAt(position);
}

void ArrayList::removeItemAt(int position)
{
    if (position < 0 || position >= len)
        return;
    list[position] = list[len-1];
    len--;
}

int ArrayList::getItem(int position)
{
    if(position < 0 || position >= len)
        return NULL_VALUE;
    return list[position];
}

int ArrayList::getLength()
{
    return len;
}

bool ArrayList::empty()
{
    if(len==0)
        return true;
    else
        return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0; i<len; i++)
        cout<<list[i]<<" ";

    cout<<endl;
}

ArrayList::~ArrayList()
{
    if(list)
        delete [] list;
    list = 0;
}


class Graph
{
    ArrayList  *AdjList;
    int nVertices, nEdges;
    bool directed;
    int *col, *p, *dis;

public:
    Graph(bool dir = false);
    ~Graph();
    void setnVertices(int n);
    bool addEdge(int u, int v);
    void printGraph();
    void removeEdge(int u, int v);
    int NumofEdges();
    bool isEdge(int u, int v);
    int getOutDegree(int u);
    int getInDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    void bfs(int source);
    void dfs(int source);
    int getDist(int u, int v);
};


Graph::Graph(bool dir)
{
    nVertices = 0;
    nEdges = 0;
    AdjList = 0;
    directed = dir;
    col = 0;
    p = 0;
    dis = 0;
}

void Graph::setnVertices(int n)
{
    this->nVertices = n;
    if(AdjList!=0)
        delete[] AdjList;
    AdjList = new ArrayList[nVertices];
    col = new int[nVertices];
    p = new int[nVertices];
    dis = new int[nVertices];
    this->nEdges = 0;
}

bool Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return false;

    bool x = isEdge(u, v);

    if(x==true)
        return false;

    this->nEdges++;
    AdjList[u].insertItem(v);

    if(!directed)
        AdjList[v].insertItem(u);
}

void Graph::printGraph()
{
    for(int i=0; i<nVertices; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<AdjList[i].getLength(); j++)
        {
            cout<<AdjList[i].getItem(j)<<" ";
        }
        cout<<endl;
    }
}

void Graph::removeEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return;
    this->nEdges--;
    AdjList[u].removeItem(v);
    if(!directed)
        AdjList[v].removeItem(u);
}

int Graph::NumofEdges()
{
    return nEdges;
}

bool Graph::isEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return  false;
    if(!directed)
    {
        int Echeck1, Echeck2;
        Echeck1 = AdjList[u].searchItem(v);
        Echeck2 = AdjList[v].searchItem(u);
        if(Echeck1 == NULL_VALUE && Echeck2 == NULL_VALUE)
            return false;
        else
            return true;
    }
    else
    {
        int isthere;
        isthere = AdjList[u].searchItem(v);
        if(isthere == NULL_VALUE)
            return false;
        else
            return true;
    }
}

int Graph::getOutDegree(int u)
{
    if(u<0 || u>=nVertices)
        return NULL_VALUE;

    return AdjList[u].getLength();
}

int Graph::getInDegree(int u)
{
    if(u<0 || u>=nVertices)
        return NULL_VALUE;

    int i;
    if(directed)
    {
        int deg=0,i;
        for(i=0; i<nVertices; i++)
        {
            if(AdjList[i].searchItem(u)!=NULL_VALUE)
                deg++;
        }
        return deg;
    }
    else
    {
        AdjList[u].getLength();
    }
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices)
        return false;

    int lenU = AdjList[u].getLength();
    int lenV = AdjList[v].getLength();

    for(int i=0; i<lenU; i++)
    {
        for(int j=0; j<lenV; j++)
        {
            if(AdjList[u].getItem(i) == AdjList[v].getItem(j))
            {
                return true;
            }
        }
    }
    return false;
}

///BFS
void Graph::bfs(int source)
{
    if(source<0 || source >= nVertices)
        return;
    Queue q;

    col = new int[nVertices];
    p = new int[nVertices];
    dis = new int[nVertices];

    int s;
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
    cout<<source<<" ";

    if(!q.empty())
        Queue q;
    q.enqueue(source);

    while(!q.empty())
    {
        s = q.dequeue();
        int len = AdjList[s].getLength();
        int v, i = 0;
        for(i = 0; i < len; i++)
        {
            v = AdjList[s].getItem(i);
            if(col[v] == white)
            {
                col[v] = gray;
                cout<<v<<" ";
                dis[v] = dis[s] + 1;
                p[v] = s;
                q.enqueue(v);
            }
        }
        col[s] = black;
    }
    cout<<endl;
}


///DFS
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

        for(int i=0; i<AdjList[u].getLength(); i++)
        {
            int v = AdjList[u].getItem(i);
            if(col[v]==white)
            {
                p[v] = u;
                cout<<v<<" ";
                col[v] = gray;
                st.push(v);
                flg=1;
                break;
            }
            else
                flg=0;
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
        return infinity;
    this->bfs(u);
    int dis = this->dis[v] - this->dis[u];
    return dis;
}

Graph::~Graph()
{
    if(AdjList)
        delete[] AdjList;
    AdjList = 0;
    if(col)
        delete[] col;
    col = 0;
    if(p)
        delete[] p;
    p = 0;
    if(dis)
        delete[] dis;
    dis = 0;
}


void CreateNvertices(Graph &G, bool dir, int V, int n, int randV)
{
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

            int h = ((vertex[0]*vertex[0] - vertex[0])/8)/vertex[0];
            int uplim = j;

            for(i=0; i<uplim; i++)
            {
                h = ((vertex[0]*vertex[0] - vertex[0])/8)/vertex[0];
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
            /*int x = ((V*V - V)/8)/V;
            for(int i=1; i<x; i=i*2)
                CreateNvertices(G, dir, V, i, 12);*/
            break;
        }

    }

    return 0;
}