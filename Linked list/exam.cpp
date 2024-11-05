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


void revPrint(Node* temp){
    if(temp == NULL) return;
    // temp = ;
    revPrint(temp->next);
    cout << temp->key << " ";
}



int size( Node* temp){
    if(temp == NULL) return 0;
    return 1+size(temp->next);
}



bool delethNth(int x, int n){
    if(!find(x)) return false;
    
    Node* slow= NULL;
    Node* fast = head;
    Node* temp = head;
    bool status = false;


int count =0;
    while(fast != NULL){

        if(fast->key == x){
            slow = fast;
            // cout << "4\n";
            fast = fast->next;
            // cout << "5\n";
            count++;
            // cout << "6\n";
        }

        if(fast->key == x and count == n){
            slow->next = fast->next;
            // cout << "1\n";
            free(fast);
            // cout << "2\n";
            fast = slow->next;
            // cout << "2\n";
            status = true;
            // cout << "3\n";
        }
        
        if(fast->key != x){
            slow = fast;
            // cout << "7\n";
            fast = fast->next;
            // cout << "8\n";
        }
        // cout << "9\n";
    }
    return status;
}




int main(){
    init();
    cout<<"1. Insert First           2. Insert last             3. Find\n";
    cout<<"4. Delete First           5. Delete last             6. Delete Any\n";
    cout<<"7. Print                  8. Size                    9. Print Reverse\n";
    cout<<"10. Delete Nth Occurence\n\n";          

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
            cout << "The size of the list is: ";
            cout << size(head) << endl<<endl;
        }

        else if(choice==9){
              cout << "The list is: ";
            revPrint(head);
            cout << "\n\n";
        }

        else if(choice==10){
            int x,n;
            cout << "Enter value: ";
            cin >> x ;
            
            cout << "Enter position: ";
            cin >>n;

            if(delethNth(x,n-1)) cout << "Successful\n\n";
            else cout << "Failed!\n\n";
        }     

        else {
            cout<<"Invalid choice"<<endl<<endl;
        }


    }
}
