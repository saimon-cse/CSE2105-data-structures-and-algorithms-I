#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin>>n;

        int a = n;
        int flag=0;
        while(a){
            if(a%10 > 1){ flag =1;
            break;
            }

            a=a/10;
        }
        if(flag == 1){
            cout << "NO\n";
            // return 0; 
            continue;
        }

        string s;
        while(n){
            
        }

    }
}