#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *next;
};

Node *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}

void insertFirst(int x){
    Node *temp = new Node;
    temp->key = x ;
    temp->next = head;
    head = temp;
    if(tail==NULL) tail = head;
    
}

void insertLast(int x){
    Node* temp = new Node;
    // Node* temp = (Node*) mallloc(sizeof(Node));
    temp->key = x;
    if(tail != NULL)  tail->next = temp; // if there the tail in NULL then it will ocur a Runtime error
    tail = temp;
    tail->next = NULL;

    if(head == NULL) head = tail;

}

Node* find(int x){
    Node* temp = head;
    while(temp != NULL){
        if(temp->key == x) return temp;
        temp = temp->next;
    }
    return temp;
}

bool deleteFirst(){
    if(head==NULL) return false;
    Node *temp = head;
    head = head->next;
    // delete(temp);
    free(temp);
    if(head == NULL) tail = NULL;
    return true;
}

bool deleteLast(){
    Node *slow = NULL;
    Node* fast = head;

    while(fast!=tail){
        slow = fast;
        fast = fast->next;
    }
    tail = slow;
    tail->next = NULL;
    free(fast);

}

bool deleteAny(int x){
    Node* temp = NULL ;
    
}

void print( ){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->key << " ";
        temp = temp->next;
    }
}

int main(){
    init();
    cout<<"1. Insert First           2. Insert last             3. Find\n";
    cout<<"4. Delete First           5. Delete last             6. Delete Any\n";
    cout<<"7. Print                  8. To be implemented       9. To be implemented\n";
    cout<<"10. To be implemented     11. To be implemented      12. To be implemented\n";

    while(1){
        cout << "Choice: ";

        int choice;   cin>>choice;
        
        if(choice==1){
            cout<<"Enter value: ";
            int x;   cin>>x;   insertFirst(x);
            cout<<x<<" has been inserted at first"<<endl<<endl;
        }

        else if(choice==2){
            cout<<"Enter value: ";
            int x;   cin>>x;   insertLast(x);
            cout<<x<<" has been inserted at last"<<endl<<endl;
        }

        else if(choice==3){
            cout<<"Enter value: ";
            int x;   cin>>x;   Node *temp = find(x);
            if(temp == NULL) cout<<x<<" has not been found"<<endl<<endl;
            else cout<<x<<" has been found"<<endl<<endl;
        }

        else if(choice==4){
            bool status = deleteFirst();
            if(status == false) cout<<"No element in the list"<<endl<<endl;
            else cout<<"First element has been deleted successfully"<<endl<<endl;
        }

        else if(choice==5){
            bool status = deleteLast();
            if(status == false) cout<<"No element in the list"<<endl<<endl;
            else cout<<"Last element has been deleted successfully"<<endl<<endl;
        }

        else if(choice==6){
            cout<<"Enter value: ";
            int x;   cin>>x;   bool status = deleteAny(x);
            if(status == false) cout<<x<<" could not be deleted"<<endl<<endl;
            else cout<<x<<" has been deleted successfully"<<endl<<endl;
        }

        else if(choice==7){
            cout<<"The list is: ";    print();   cout<<endl<<endl;
        }

        else if(choice==8){

        }

        else if(choice==9){

        }

        else if(choice==10){

        }

        else if(choice==11){

        }

        else if(choice==12){

        }

        else {
            cout<<"Invalid choice"<<endl<<endl;
        }
    }
}
