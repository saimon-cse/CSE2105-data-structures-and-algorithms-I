#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* L, *R;
    int v;
};

struct DLL
{   
    Node* head, *tail;

DLL(){
    head = NULL;
    tail = NULL;
}

void insertFirstElement(int x){
    Node* temp = new Node;
    temp->v = x;
    temp->L = NULL;
    temp->R = NULL;
    tail = head;
}

void insertAtFirst(int x){
    if(head==NULL) insertFirstElement(x);

    Node*temp = (Node*) malloc(sizeof(Node));
    temp->v = x;
    temp->R = head;
    head->L = temp;
    temp->L = NULL;
    head = temp;
}

void insertAtLast(int x){
    if(head==NULL) insertFirstElement(x);
    Node* temp = new Node;
    temp->v = x;
    temp->R = NULL;
    temp->L = tail;
    tail->R = temp;
    tail = temp;
}

Node* find(int x){
    Node*temp = head;
    while(temp!=NULL){
        if(temp->v = x) return temp;
        temp = temp->R;
    }
    return temp;

}

void insertAfteFirstOcc(int x){
    Node* ptr = find(x);
    if(ptr==NULL) return;

    Node* temp = new Node;
    temp->v = x;
    // temp->R = NULL;
    if(temp==tail){insertAtLast(x); return;}
    temp->L = ptr;
    temp->R = ptr->R;
    ptr->R->L = temp;
    ptr->R = temp;
}

bool insertAfterLastOccur(int x){
    Node*ptr = tail;
    while(ptr){
        if(ptr->v = x){
            break;
        }
        ptr = ptr->L;
    }
    if(ptr == tail) insertAtLast(x);
    // baki ache

    
}
int len(Node* temp){
    if(temp== NULL) return 0;
    return 1+len(temp->R);
}

Node* middle(){
    Node*first = head;
    Node* last = tail;
    int leng = len(head);
    int mid = leng/2;
    // while(first != last){
        for(int i=0; i<mid; i++){
            first = first->R;
        }
        return first;
    // }
}







};


int main(){
    DLL list;
    while(1){
        int n; cin>>n;
        

        if(n==1){
        int x; cin >> x;
        list.insertAtFirst(x);
        }
        if(n==2){
            cout << list.middle()->v << endl;
        } 
    }
}