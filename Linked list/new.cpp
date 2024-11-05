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
    Node* temp = new Node;
    temp->key = x;
    temp->next = head;
    head = temp;

    if(!tail) tail = head;
}

void insertLast(int x){
    Node* temp = new Node;
    temp->key = x;
    if(tail) temp->next = tail;
    tail = temp;
    tail->next = NULL;
    if(!head) head = tail;
}

Node* find(int x){
    Node* temp = head;
    while(temp){
        if(temp->key == x) return temp;
        temp=temp->next;
    }
    return temp;
}

bool deleteFirst(){
    if(!head) return false;
    Node* temp = head;
    head = head->next;
    delete(temp);
    if(!head) head = tail;
    return true;
}

bool deleteLast(){
    if(!tail) return false;
    Node *slow = NULL;
    Node *fast = head;

    while (fast != tail)
    {
        slow = fast;
        fast = fast->next;
    }
    tail = slow;
    free(fast);
    if(tail)    tail->next = NULL;
    if(!tail)   head = NULL; 
    return true;
}

bool deleteAny(int x){
    if(!find(x)) return false;
    if(x==head->key) return deleteFirst();
    if(x==tail->key) return deleteLast();

    Node* slow = NULL;
    Node* fast = head;
    // Node* temp ;

    while (fast->key != x)
    {
        // if(fast->key == x) 
        slow = fast;
        fast = fast->next;
    }
    slow->next = fast->next;
    free(fast);
    return true;

}

void print( ){
    Node* temp = head;
    while (temp)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    
}

int len(){
    Node* temp = head;
    int leng=0;
    while(temp != NULL){
        temp=temp->next;
        leng++;   
    }
    return leng;
}

void sortLL(){
    if(head==NULL) return;
    Node* slow = head;
    Node* fast = head->next;
    for(int j=0; j<len()-1; j++){
        for(int i=0; i<len()-j-1; i++){
            if(slow->key > fast->key){
                int temp = slow->key;
                slow->key = fast->key;
                fast->key = temp;
            }
            slow = fast;
            fast = fast->next;
        }   
        slow = head;
        fast = head->next; 
    }
}

void revPrint(Node* temp){
    if(temp == NULL) return;
    // temp = ;
    revPrint(temp->next);
    cout << temp->key << " ";
}

bool removeDuplicates() {
    if (head == NULL)
        return false; 

    bool status = false;
    Node* temp = head;

    while (temp != NULL) {
        Node* slow = temp;
        Node* fast = temp->next;

        while (fast != NULL) {
            if (temp->key == fast->key) {
                slow->next = fast->next;
                free(fast);
                fast = slow->next; 
                status = true;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }
        temp = temp->next;
    }

    return status;
}


bool removedup(){
    if(head == NULL) return false;

    Node* temp = head;
    bool status = false;

    while(temp != NULL){
        Node * slow = temp;
        Node* fast = temp->next;
        while(fast!=NULL){
            if(temp->key == fast->key){
                slow->next = fast->next;
                free(fast);
                fast = slow->next;
                status = true;
            }
            else{
                slow = fast;
                fast = fast->next;
            }
        }
        temp = temp->next;
    }
    return status;
}


int main(){
    init();
    cout<<"1. Insert First           2. Insert last             3. Find\n";
    cout<<"4. Delete First           5. Delete last             6. Delete Any\n";
    cout<<"7. Print                  8. Sort                    9. length\n";
    cout<<"10. Reverse Print         11. Remove Duplicates      12. To be implemented\n";

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
            sortLL();
            cout << "The list is Sorted\n\n";
        }

        else if(choice==9){
            cout << "The size of the list is: ";
            cout << len() << endl<<endl;
        }

        else if(choice==10){
            cout << "The list is: ";
            revPrint(head);
            cout << "\n\n";
        }

        else if(choice==11){
            if(removedup()) cout << "Removed Duplicants\n\n";
            else cout << "No Duplicat found!\n\n";
        }

        else if(choice==12){

        }
        else if(choice == 13){
            cout << "Head:" << head->key<< endl;;
            cout << "Tail: " << tail->key << endl;
        }

        else {
            cout<<"Invalid choice"<<endl<<endl;
        }


    }
}
