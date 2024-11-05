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

}

void insertLast(int x){

}

Node* find(int x){

}

bool deleteFirst(){

}

bool deleteLast(){

}

bool deleteAny(int x){

}

void print( ){

}

int main(){
    init();
    cout<<"1. Insert First           2. Insert last             3. Find\n";
    cout<<"4. Delete First           5. Delete last             6. Delete Any\n";
    cout<<"7. Print                  8. To be implemented       9. To be implemented\n";
    cout<<"10. To be implemented     11. To be implemented      12. To be implemented\n";

    while(1){

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
