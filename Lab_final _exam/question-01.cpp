#include<bits/stdc++.h>
using namespace std;


void printst(stack<char> &st){
    if(st.empty()) return;

    char top = st.top();
    st.pop();
    printst(st);
    cout << top; 

}


int main(){
    
    string s;
    cin >> s;

    stack<char> st;
    st.push(s[0]);
    for(int i=1; i<s.size(); i++){
        if(s[i] != st.top())
            st.push(s[i]);
    }

    printst(st);



}


/*

aabbaccaaaddc

*/