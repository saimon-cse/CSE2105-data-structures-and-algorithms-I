#include<bits/stdc++.h>
using namespace std;


int main(){
    int tc; cin >> tc;

    while(tc--){
        double d, x, y;
        cin >> d >> x >> y;

        int cnt = 0;

        int dis=x;
        for(cnt=0; cnt<=50 and x>y; cnt++){
            if(y==0){
                cnt = -1; break;
            }
            y--;
            x -= (dis*d/100);
        }
       if(x>y) cout << -1 << endl;
        else cout << cnt << endl;

       
    }
}

