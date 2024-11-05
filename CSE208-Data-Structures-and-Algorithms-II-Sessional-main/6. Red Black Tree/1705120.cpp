#include <iostream>
#include <bits/stdc++.h>
#define NIL -99999999
#define RED 1
#define BLACK 0
using namespace std;

class RBT;
class Node
{
    int key;
    int color;
    Node *L;
    Node *R;
    Node *P;
    friend class RBT;
public:
    Node(){
        key = NIL;
        L = NULL;
        R = NULL;
        P = NULL;
        color = NIL;
    }
    Node(int x, int c=RED) {
        key = x;
        L = NULL;
        R = NULL;
        P = NULL;
        color = c;
    }
};


class RBT
{
    Node *root;
    void printRBT(Node *node, string &s);
    bool Find(int num, Node *node);
public:
    RBT() {
        root = NULL;
    }
    void Insert(int num);
    void InsertFixup(Node *z);
    void leftRotate(Node *x);
    void rightRotate(Node *y);
    void Delete(int num);
    void DeleteFixup(Node *x);
    Node* inorderSuccessor(Node *node);
    void Find(int num) {
        if(Find(num, root) == true)   cout << "True";
        else    cout << "False";
    }
    void printRBT() {
        string s="";
        printRBT(root, s);
        cout << s;
    }
};

void RBT::printRBT(Node *node, string &s)
{
    if (node == NULL)
        return;
    string t = to_string(node->key);
    s += t;
    s.push_back(':');
    if(node->color==BLACK)
        s.push_back('b');
    else if(node->color==RED)
        s.push_back('r');

    if (node->L==NULL && node->R==NULL)
        return;

    s.push_back('(');
    printRBT(node->L, s);
    s.push_back(')');

    s.push_back('(');
    printRBT(node->R, s);
    s.push_back(')');
}

bool RBT::Find(int num, Node* node)
{
    if(node == NULL)    return false;
    else if(node->key == num)   return true;
    else if(node->key > num)    return Find(num, node->L);
    else    return Find(num, node->R);
}

void RBT::leftRotate(Node *x)
{
    auto y = x->R;
    x->R = y->L;
    if(y->L != NULL)
        y->L->P = x;

    y->P = x->P;

    if(x->P == NULL) {
        y->P = NULL;
        root = y;
    }
    else if(x == x->P->L) {
        x->P->L = y;
    }
    else {
        x->P->R = y;
    }
    y->L = x;
    x->P = y;
}

void RBT::rightRotate(Node *y)
{
    auto x = y->L;
    y->L = x->R;
    if(x->R != NULL)
        x->R->P = y;
    x->P = y->P;

    if(y->P == NULL) {
        x->P = NULL;
        root = x;
    }
    else if(y == y->P->L)
        y->P->L = x;
    else
        y->P->R = x;

    x->R = y;
    y->P = x;
}

void RBT::InsertFixup(Node *z)
{
    Node *y = NULL;
    while(z->P!=NULL && z->P->color == RED)
    {
        if(z->P == z->P->P->L) {

            y = z->P->P->R;             //uncle

            if(y != NULL && y->color == RED) {
                z->P->color = BLACK;
                y->color = BLACK;
                z->P->P->color = RED;
                z = z->P->P;
            }
            else if(y == NULL || y->color==BLACK){
                if(z == z->P->R) {
                    z = z->P;
                    leftRotate(z);
                }
                z->P->color = BLACK;
                z->P->P->color = RED;
                rightRotate(z->P->P);
            }
        }
        else {
            y = z->P->P->L;             //uncle

            if(y != NULL && y->color == RED) {
                z->P->color = BLACK;
                y->color = BLACK;
                z->P->P->color = RED;
                z = z->P->P;
            }
            else if(y == NULL || y->color==BLACK){
                if(z == z->P->L) {
                    z = z->P;
                    rightRotate(z);
                }
                z->P->color = BLACK;
                z->P->P->color = RED;
                leftRotate(z->P->P);
            }
        }
    }
    root->color = BLACK;
}

void RBT::Insert(int num)
{
    Node *y = NULL;
    Node *node = new Node();
    Node *x = root;
    while(x != NULL) {
        y = x;
        if(num < x->key)
            x = x->L;
        else
            x = x->R;
    }
    node->P = y;
    if(y == NULL) {
        root = node;
    }
    else if(num < y->key)
        y->L = node;
    else
        y->R = node;
    node->key = num;
    node->R = NULL;
    node->L = NULL;
    node->color = RED;

    if(node->P != NULL) {
        if(node->P->color == RED && node->P->P != NULL)
            InsertFixup(node);
        else
            node->P->color = BLACK;
    }
    else
        node->color = BLACK;
}

Node* RBT::inorderSuccessor(Node *node)
{
    node = node->R;
    while(node != NULL)
    {
        if(node->L == NULL)
            break;
        else
            node = node->L;
    }
    return node;
}

void RBT::DeleteFixup(Node *x)
{
    Node *w = NULL;
    while(x!=NULL && x!= root && x->color==BLACK)
    {
        if(x == x->P->L)
        {
            w = x->P->R;
            if(w->color == RED) {                                               //case 1
                w->color = BLACK;
                x->P->color = RED;
                leftRotate(x->P);
                w = x->P->R;
            }
            if(((w->L!=NULL && w->R!=NULL) && w->L->color==BLACK && w->R->color==BLACK) || (w->L==NULL && w->R==NULL))
            {
                w->color = RED;                         //case 2
                x = x->P;
            }
            else {
                if((w->R!=NULL && w->R->color==BLACK) || (w->R==NULL && w->L!=NULL && w->L->color==RED))
                {
                    w->L->color = BLACK;                //case 3
                    w->color = RED;
                    rightRotate(w);
                    w = x->P->R;
                }
                w->color = x->P->color;                     //case 4
                x->P->color = BLACK;

                if(w->R != NULL)
                    w->R->color = BLACK;

                leftRotate(x->P);
                x = root;
            }
        }
        else if(x == x->P->R)
        {
            w = x->P->L;
            if(w->color == RED) {                       //case 1
                w->color = BLACK;
                x->P->color = RED;
                rightRotate(x->P);
                w = x->P->L;
            }
            if(((w->R!=NULL && w->L!=NULL) && w->R->color==BLACK && w->L->color==BLACK) || (w->R==NULL && w->L==NULL))
            {
                w->color = RED;                                             //case 2
                x = x->P;
            }
            else {
                if(((w->L!=NULL) && w->L->color==BLACK) || (w->L==NULL && w->R!=NULL && w->R->color==RED))
                {
                    w->R->color = BLACK;                                   //case 3
                    w->color = RED;
                    leftRotate(w);
                    w = x->P->L;
                }
                w->color = x->P->color;                     //case 4
                x->P->color = BLACK;

                if(w->L != NULL)
                    w->L->color = BLACK;

                rightRotate(x->P);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RBT::Delete(int num)
{
    Node *z = NULL;
    Node *x = NULL, *y = NULL;
    Node *temp = root;
    while(temp != NULL)
    {
        if(num < temp->key)
            temp = temp->L;
        else if(num > temp->key)
            temp = temp->R;
        else {
            z = temp;
            break;
        }
    }

    if(z == NULL)   return;

    if(z->L == NULL || z->R == NULL)
        y = z;
    else
        y = inorderSuccessor(z);

    // y cannot be null
    if(y->L != NULL)
        x = y->L;
    else if(y->R != NULL)
        x = y->R;
    else
        x = new Node(NIL, BLACK);

    //x cannot be null;
    //if(x != NULL)
    x->P = y->P;

    if(y->P == NULL)
        root = x;
    else if(y == y->P->L)
        y->P->L = x;
    else
        y->P->R = x;

    if(y != z) {
        z->key = y->key;
    }

    if(root->key == NIL)
        root = NULL;
    else if(x != NULL && y->color == BLACK)
        DeleteFixup(x);

    if(x->key == NIL) {
        if(y->P != NULL && x == y->P->L)
            y->P->L = NULL;
        else if(y->P != NULL && x == y->P->R)
            y->P->R = NULL;
        x = NULL;
        delete x;
    }
    y = NULL;
    delete y;
}



int main()
{
    RBT rb;
    ifstream file("input.txt");
    string line, text;
    while(getline(file, line))
    {
        int i=0;
        stringstream ss(line);
        string *token = new string[2];
        while(getline(ss, text, ' ')) {
            token[i] = text;
            i++;
        }
        string x = token[0];
        int t = stoi(token[1]);
        if(x=="I") {
            rb.Insert(t);
            rb.printRBT();
            cout << endl;
        }
        else if(x=="F") {
            rb.Find(t);
            cout << endl;
        }
        else {
            rb.Delete(t);
            rb.printRBT();
            cout << endl;
        }
    }
    return 0;
}
