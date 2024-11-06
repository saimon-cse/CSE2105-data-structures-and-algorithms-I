#include<bits/stdc++.h>
using namespace std;

bool checkBalance(string s){
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            st.push(s[i]);
        
        else if(s[i]==')' or s[i]=='}' or s[i]==']'){
            if(st.empty()) return false;
            
            char top = st.top();
            st.pop();

            if((top !='(' and s[i]==')')   or (s[i]=='}' and top !='{') or (s[i]==']' and top !='[')){
               return false;
            }
        }
    }

    return st.empty();
}

int main(){
  
    string s;
    cin >> s;


    if(checkBalance(s)) cout << "Valid\n";
    else cout << "invalid\n";
}

/*

Example Inputs:
[23+3+(234+44)]

{(2+3)*[5-(6/2)]}

23+3+(234+44))

(){{{[}]}}


Input: (23+3+({[234+44]}))
Output: Invalid

Input: ((((
Output: Invalid

*/