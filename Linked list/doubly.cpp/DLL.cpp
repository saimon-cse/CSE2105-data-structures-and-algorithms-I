#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *L, *R;
};

struct DLL{
    Node *head, *tail;

    DLL(){
        head = NULL;
        tail = NULL;
    }

    void createFirstElement(int x){
        head = new Node;
        //head = (Node*) malloc(sizeof(Node))
        head->v = x;
        head->L = NULL;
        head->R = NULL;
        tail = head;

    }

    void insertFirst(int x){
        if(head==NULL){createFirstElement(x); return;}
        Node* temp = new Node;
        temp->v = x;
        head->L = temp;
        temp->R = head;
        head = temp;
        head->L = NULL;
    }

    bool insertAfter(int x, int nV){
    if(findFirstOccurrence(x) == NULL) return false;
    if(findFirstOccurrence(x) == tail) {
    //return insertLast(nV);
    insertLast(nV);
    return true;

    }

        Node* ptr = findFirstOccurrence(x);
        Node* temp = new Node;
        temp->v = nV;
        temp->L = ptr;
        temp->R = ptr->R;
        ptr->R->L = temp;
        ptr->R = temp; 
        
        return true;       
    }


    bool insertLast(int x){
        if(head==NULL) createFirstElement(x);
        Node* temp = new Node;
        // if(temp==)
        temp->v = x;
        temp->L = tail;
        temp->R = NULL;
        tail->R = temp;
        tail = temp;
    }

    Node* findFirstOccurrence(int x){
        Node* temp= head;
        while(temp != NULL){
            if(temp->v == x) return temp;
            temp= temp->R;
        }
        return temp;
    }

    bool deleteFromFirst(){

    }

    bool deleteFromLast(){

    }

    bool deleteFirstOccurrence(int x){
        
    }

    void print( ){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->v << " ";
            temp = temp->R;
        }
        cout << endl << endl;
    }

    int length(){

    }
};



int main(){
    DLL list;
    cout<<"1. Insert First           2. Insert last             3. Find\n";
    cout<<"4. Delete First           5. Delete last             6. Delete Any\n";
    cout<<"7. Print                  8. Insert after x          9. To be implemented\n";
    cout<<"10. To be implemented     11. To be implemented      12. To be implemented\n";

    while(1){

        int choice;   cin>>choice;

        if(choice==1){
            cout<<"Enter value: ";
            int x;   cin>>x;   list.insertFirst(x);
            cout<<x<<" has been inserted at first"<<endl<<endl;
        }

        else if(choice==2){
            cout<<"Enter value: ";
            int x;   cin>>x;   list.insertLast(x);
            cout<<x<<" has been inserted at last"<<endl<<endl;
        }

        else if(choice==3){
            cout<<"Enter value: ";
            int x;   cin>>x;   Node *temp = list.findFirstOccurrence(x);
            if(temp == NULL) cout<<x<<" has not been found"<<endl<<endl;
            else cout<<x<<" has been found"<<endl<<endl;
        }

        else if(choice==4){
            bool status = list.deleteFromFirst();
            if(status == false) cout<<"No element in the list"<<endl<<endl;
            else cout<<"First element has been deleted successfully"<<endl<<endl;
        }

        else if(choice==5){
            bool status = list.deleteFromLast();
            if(status == false) cout<<"No element in the list"<<endl<<endl;
            else cout<<"Last element has been deleted successfully"<<endl<<endl;
        }

        else if(choice==6){
            cout<<"Enter value: ";
            int x;   cin>>x;   bool status = list.deleteFirstOccurrence(x);
            if(status == false) cout<<x<<" could not be deleted"<<endl<<endl;
            else cout<<x<<" has been deleted successfully"<<endl<<endl;
        }

        else if(choice==7){
            cout<<"The list is: ";    list.print();   cout<<endl<<endl;
        }

        else if(choice==8){
            int x, nV;
            cout<<"Enter x:";           cin>>x;
            cout<<"Enter new value: ";  cin>>nV;
            bool status = list.insertAfter(x, nV);
            if(status == false) cout<<x<<" is not present in the list "<<endl<<endl;
            else cout<<x<<" has been successfully inserted after "<<nV<<endl<<endl;
        }

        else if(choice==9){
            cout<<"The size of the list is: "<<list.length()<<endl<<endl;
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

