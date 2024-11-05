#include<iostream>
#include<bits/stdc++.h>
#define NIL -999999999
using namespace std;


class BinomialHeap;
class Node
{
    int key, degree;
    Node *parent, *child, *sibling;
    friend class BinomialHeap;
public:
    Node() {
        key = NIL;
        degree = 0;
        parent = NULL;
        child = NULL;
        sibling = NULL;
    }
    Node(int key) {
        this->key = key;
        degree = 0;
        parent = NULL;
        child = NULL;
        sibling = NULL;
    }
    Node(int key, int degree, Node *parent, Node *child, Node *sibling) {
        this->key = key;
        this->degree = degree;
        this->parent = parent;
        this->child = child;
        this->sibling = sibling;
    }
    Node(int key, int degree, Node *parent, Node *child) {
        this->key = key;
        this->degree = degree;
        this->parent = parent;
        this->child = child;
        this->sibling = NULL;
    }
    int getKey() {
        return key;
    }
    int getDegree() {
        return degree;
    }
};

class BinomialHeap
{
    Node *root;
    Node *minimum;
    Node* binomialTreeLink(Node *y, Node *z);
public:
    BinomialHeap();
    BinomialHeap(Node *n);
    ~BinomialHeap();
    Node* findMin();
    Node* extractMin();
    void insertNode(int n);
    void heapUnion(BinomialHeap *h);
    void print(int decider, ofstream &filewriter);
};

BinomialHeap::BinomialHeap()
{
    root = NULL;
    minimum = NULL;
}
BinomialHeap::BinomialHeap(Node *n)
{
    root = n;
    minimum = n;
}
BinomialHeap::~BinomialHeap()
{
    root = NULL;
    minimum = NULL;
    delete root;
    delete minimum;
}

Node* BinomialHeap::binomialTreeLink(Node *y, Node *z)
{
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree += 1;
    return z;
}

Node* BinomialHeap::findMin()
{
    return minimum;
}

void BinomialHeap::insertNode(int n)
{
    Node *node = new Node(n);
    BinomialHeap *bh = new BinomialHeap(node);
    heapUnion(bh);
}

void BinomialHeap::heapUnion(BinomialHeap *h)
{
    Node *r1 = new Node();
    r1 = root;
    Node *r2 = h->root;
    Node *carry = NULL;
    Node *newRoot = new Node();
    Node *temp = newRoot;

    while(r1!=NULL || r2!=NULL || carry!=NULL)
    {
        if((r1!=NULL && r2!=NULL) && r1->degree==r2->degree) {
            if(carry==NULL) {
                Node *node1 = new Node(r1->key, r1->degree, r1->parent, r1->child);
                Node *node2 = new Node(r2->key, r2->degree, r2->parent, r2->child);

                ///Node *node1 = r1;
                ///Node *node2 = r2;
                if(r1->key < r2->key)
                    carry = binomialTreeLink(node2, node1);
                else
                    carry = binomialTreeLink(node1, node2);
                r1 = r1->sibling;
                r2 = r2->sibling;
                //cout << endl << endl << "HERE I AM" << endl << endl;
            }
            else {
                if(carry->degree == r1->degree) {
                    temp->sibling = r2;
                    Node *c = new Node(carry->key, carry->degree, carry->parent, carry->child);
                    Node *node = new Node(r1->key, r1->degree, r1->parent, r1->child);
                    ///Node *c = carry;
                    ///Node *node = r1;
                    if(r1->key > carry->key)
                        carry = binomialTreeLink(node, c);
                    else
                        carry = binomialTreeLink(c, node);
                    r1 = r1->sibling;
                    r2 = r2->sibling;
                    temp = temp->sibling;
                    //cout << endl << endl << "HERE I AM - 1" << endl << endl;
                }
                else {
                    ///carry->sibling = NULL;
                    temp->sibling = carry;
                    carry = NULL;
                    temp = temp->sibling;
                    //cout << endl << endl << "HERE I AM - 2" << endl << endl;
                }
            }
        }
        else if((r1!=NULL && r2!=NULL) && r1->degree!=r2->degree) {
            if(carry==NULL) {
                if(r1->degree > r2->degree) {
                    temp->sibling = r2;
                    r2 = r2->sibling;
                    temp = temp->sibling;
                    //cout << endl << endl << "HERE I AM - 3" << endl << endl;
                }
                else {
                    temp->sibling = r1;
                    r1 = r1->sibling;
                    temp = temp->sibling;
                    //cout << endl << endl << "HERE I AM - 4" << endl << endl;
                }
            }
            else {
                if(r1->degree > r2->degree) {
                    if(carry->degree == r2->degree) {
                        Node *c = new Node(carry->key, carry->degree, carry->parent, carry->child);
                        Node *r = new Node(r2->key, r2->degree, r2->parent, r2->child);
                        ///Node *c = carry;
                        ///Node *r = r2;
                        if(carry->key < r2->key)
                            carry = binomialTreeLink(r, c);
                        else
                            carry = binomialTreeLink(c, r);
                        r2 = r2->sibling;
                        //cout<< "HERE I AM - 5" << endl;
                    }
                    else if(carry->degree < r2->degree) {
                        ///carry->sibling = NULL;
                        temp->sibling = carry;
                        temp = temp->sibling;
                        carry = NULL;
                        //cout << "HERE I AM - 6" << endl;
                    }
                }
                else {
                    if(carry->degree == r1->degree) {
                        Node *c = new Node(carry->key, carry->degree, carry->parent, carry->child);
                        Node *r = new Node(r1->key, r1->degree, r1->parent, r1->child);
                        ///Node *c = carry;
                        ///Node *r = r1;
                        if(carry->key < r1->key)
                            carry = binomialTreeLink(r, c);
                        else
                            carry = binomialTreeLink(c, r);
                        r1 = r1->sibling;
                        //cout << "HERE I AM - 7" << endl;
                    }
                    else if(carry->degree < r1->degree) {
                        ///carry->sibling = NULL;
                        temp->sibling = carry;
                        temp = temp->sibling;
                        carry = NULL;
                        //cout << "HERE I AM - 8" << endl;
                    }
                }
            }
        }
        else if(r2==NULL && r1!=NULL) {
            if(carry==NULL) {
                temp->sibling = r1;
                temp = temp->sibling;
                r1 = r1->sibling;
                //cout << "HERE I AM - 9" << endl;
            }
            else {
                if(carry->degree == r1->degree) {
                    Node *c = new Node(carry->key, carry->degree, carry->parent, carry->child);
                    Node *r = new Node(r1->key, r1->degree, r1->parent, r1->child);

                    ///Node *c = carry;
                    ///Node *r = r1;
                    if(carry->key < r1->key)
                        carry = binomialTreeLink(r, c);
                    else
                        carry = binomialTreeLink(c, r);

                    r1 = r1->sibling;

                    //cout << "HERE I AM - 10" << endl;
                }
                else {
                    ///carry->sibling = NULL;
                    temp->sibling = carry;
                    carry = NULL;
                    temp = temp->sibling;
                    //cout << "HERE I AM - 11" << endl;
                }
            }
        }
        else if(r1==NULL && r2!=NULL) {
            if(carry==NULL) {
                temp->sibling = r2;
                temp = temp->sibling;
                r2=r2->sibling;
                //cout << "HERE I AM - 12" << endl;
            }
            else {
                if(carry->degree == r2->degree) {
                    Node *c = new Node(carry->key, carry->degree, carry->parent, carry->child);;
                    Node *r = new Node(r2->key, r2->degree, r2->parent, r2->child);
                    ///Node *c = carry;
                    ///Node *r = r2;
                    if(carry->key < r2->key)
                        carry = binomialTreeLink(r, c);
                    else
                        carry = binomialTreeLink(c, r);
                    r2 = r2->sibling;
                    //cout << "HERE I AM - 13" << endl;
                }
                else {
                    ///carry->sibling = NULL;
                    temp->sibling = carry;
                    carry = NULL;
                    temp = temp->sibling;
                    //cout << "HERE I AM - 14" << endl;
                }
            }
        }
        else {
            if(carry!=NULL) {
                ///carry->sibling = NULL;
                temp->sibling = carry;
                temp = temp->sibling;
                carry = NULL;
                //cout<< "HERE I AM - 15"<< endl;
            }
        }
    }
    root = newRoot->sibling;
    minimum = root;
    Node *n = root;
    while(n != NULL)
    {
        if (n->key < minimum->key) minimum = n;
        n = n->sibling;
    }
}
Node* BinomialHeap::extractMin()
{
    Node *minNode = findMin();
    if(minNode==NULL)
        return NULL;
    Node *prevx = NULL;
    Node *x = root;
    while(x != minNode) {
        prevx = x;
        x = x->sibling;
    }
    if(prevx == NULL)                   //root was the minimum
        root = x->sibling;
    else
        prevx->sibling = x->sibling;

    Node *current = minNode->child;
    Node *revchild = NULL;

    while(current != NULL) {
        Node *next = current->sibling;
        current->sibling = revchild;
        revchild = current;
        current = next;
    }
    BinomialHeap *h = new BinomialHeap();
    h->root = revchild;
    heapUnion(h);
    return minNode;
}

void BinomialHeap::print(int decider, ofstream &filewriter)
{
    Node *x = new Node();
    x = root;
    if(root==NULL) {
        cout << "The heap is empty" << endl;
        return;
    }

    if(decider==1)
    {
        cout << "Printing Binomial Heap..." << endl;
        while(x!=NULL)
        {
            cout << "Binomial Tree, B" << x->degree << endl;
            int i=0;
            Node *t = new Node();
            t = x;
            vector <Node*> level;
            vector <Node*> children;
            while(i<=x->degree) {
                cout << "Level " << i << " : ";
                if(i==0) {
                    cout << x->key << endl;
                    i++;
                    continue;
                }
                else if(i==1) {
                    t = t->child;
                    Node *n = new Node(t->key, t->degree, t->parent, t->child, t->sibling);
                    while(n!=NULL) {
                        level.push_back(n);
                        cout << n->key << " ";
                        if(n->child!=NULL)  children.push_back(n->child);
                        n = n->sibling;
                    }
                    cout << endl;
                    level.clear();
                    level = children;
                    children.clear();
                    i++;
                    continue;
                }
                for(auto y: level) {
                    Node *n = new Node(y->key, y->degree, y->parent, y->child, y->sibling);
                    while(n!=NULL) {
                        cout << n->key << " ";
                        if(n->child!=NULL)  children.push_back(n->child);
                        n = n->sibling;
                    }
                }
                i++;
                level.clear();
                level = children;
                children.clear();
                cout << endl;
            }
            x = x->sibling;
        }
    }
    else if(decider==2)
    {
        filewriter << "Printing Binomial Heap..." << endl;
        while(x!=NULL)
        {
            filewriter << "Binomial Tree, B" << x->degree << endl;
            int i=0;
            Node *t = new Node();
            t = x;
            vector <Node*> level;
            vector <Node*> children;
            while(i<=x->degree) {
                filewriter << "Level " << i << " : ";
                if(i==0) {
                    filewriter << x->key << endl;
                    i++;
                    continue;
                }
                else if(i==1) {
                    t = t->child;
                    Node *n = new Node(t->key, t->degree, t->parent, t->child, t->sibling);
                    while(n!=NULL) {
                        level.push_back(n);
                        filewriter << n->key << " ";
                        if(n->child!=NULL)  children.push_back(n->child);
                        n = n->sibling;
                    }
                    filewriter << endl;
                    level.clear();
                    level = children;
                    children.clear();
                    i++;
                    continue;
                }
                for(auto y: level) {
                    Node *n = new Node(y->key, y->degree, y->parent, y->child, y->sibling);
                    while(n!=NULL) {
                        filewriter << n->key << " ";
                        if(n->child!=NULL)  children.push_back(n->child);
                        n = n->sibling;
                    }
                }
                i++;
                level.clear();
                level = children;
                children.clear();
                filewriter << endl;
            }
            x = x->sibling;
        }
    }
}


int main()
{
    BinomialHeap H;
    ifstream fileReader("input.txt");
    ofstream fileWriter("output.txt");
    string line, text;
    cout << "1.Output on console" << "\t" << "2.Output in a File" << endl;
    int decide;
    cin >> decide;
    if(decide!=1 && decide!=2)
        return 0;
    while(getline(fileReader, line))
    {
        int i=0;
        stringstream ss(line);
        vector <string> v;
        while(getline(ss, text, ' ')) {
            v.push_back(text);
        }
        string *str = new string[v.size()];
        for(auto element : v) {
            str[i] = element;
            i++;
        }
        if(str[0]=="I") {
            int num = stoi(str[1]);
            H.insertNode(num);
        }
        else if(str[0]=="F") {
            Node *n = new Node();
            n = H.findMin();
            if(decide==1) {
                cout << "Find-Min returned " << n->getKey() << endl;
            }
            else if(decide==2) {
                fileWriter << "Find-Min returned " << n->getKey() << endl;
            }
        }
        else if(str[0]=="E") {
            Node *n = new Node();
            n = H.extractMin();
            if(decide==1) {
                cout << "Extract-Min returned " << n->getKey() << endl;
            }
            else if(decide==2) {
                fileWriter << "Extract-Min returned " << n->getKey() << endl;
            }
        }
        else if(str[0]=="P") {
            H.print(decide, fileWriter);
        }
        else if(str[0]=="U") {
            BinomialHeap H1;
            for(int i=1; i<v.size(); i++) {
                int num = stoi(str[i]);
                H1.insertNode(num);
            }
            BinomialHeap *H2 = &H1;
            H.heapUnion(H2);
        }
    }
    return 0;
}
