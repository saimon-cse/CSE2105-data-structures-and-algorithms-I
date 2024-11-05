#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* next;
};
Node* head, *tail;

void inti(){
     head = NULL;
     tail = NULL;
}



void insertFirst(int x){
    Node* temp = new Node;
    temp->key = x;
    temp->next = head;
    head = temp;
    if(!tail) tail = head;
}

void insertLast(int x){
    Node* temp = new Node;
    temp->key = x;
    if(tail!=NULL) tail->next = temp;
    tail = temp;
    tail->next = NULL;
    if(!head) head = tail;
}

bool deleteFirst(){
    if(head==NULL) return false;
    Node* temp = head;
    head = head->next;
    free(temp);
    return true;
}

bool deleteLast(){
    // Node* temp = tail;
    Node* fast = head;
    Node*slow = NULL;
    if(head==NULL) return false;
    while(fast != tail){
        slow = fast;
        fast = fast->next ;
    }
    tail = slow;
    free(fast);
    if(tail==NULL) head = NULL;
    if(tail!=NULL) tail->next = NULL;
    return true;
    
}

void print(){
    Node* temp = head;
    if(temp== NULL) cout << "the list is empty\n";
    while(temp != NULL){
        cout << temp->key << " ";
        temp = temp->next;
    }

    cout << "\n\n";
}

Node* find(int x){
    Node*temp = head;
    while(temp){
        if(temp->key == x) return temp;
        temp = temp->next;
    }
    return temp;
}

int length(){
    Node* temp= head;
    int len = 0;

    while(temp){
        len++;
        temp = temp->next;
    }
    return len;

}

void insetAfterFirstOccur(int x, int nkey){
    Node* loca = find(x);
    if(loca==NULL) return;

    Node*temp = new Node;
    temp->key = nkey;
    temp->next = loca->next;
    loca->next = temp;    

}

Node* findNth(int n){
    Node* temp = head;
    
    while(n--){
        temp = temp->next;
    }
    return temp;
}


int size_n(Node* temp){
    if(temp==NULL) return 0;
    return 1+size_n(temp->next);
}

// void delethNth(int )

int main(){
   inti();

        cout << "1. insert first    2.insert last\n";
        cout << "3. print           4.delete first\n";
        cout << "5. delete last     6.delete any\n\n";
        cout << "7.inset at first occurance\n";
        // cout << 
     while(1){

        int n; cin >> n;

        if(n==1){
            int x ; cin >> x;
            insertFirst(x);
            
            cout << x << " is inserted\n\n";
        }
        else if(n==2){
            int x ; cin >> x;
            insertLast(x);            
            cout << x << " is inserted\n\n";
        }

        else if(n==3){
            cout << "the list is: ";
            print();
        }
        else if(n==4){
            if(deleteFirst()) cout << "first element deleted\n\n";
            else cout << "unsuccessful\n\n";
        }
        else if(n==5){
             if(deleteLast()) cout << "Last element deleted\n\n";
            else cout << "unsuccessful\n\n";
        }
        else if(n==7){
            int x; cin>>x;
             int nV; cin>>nV;
            insetAfterFirstOccur(x, nV);
        }
        
     }
}