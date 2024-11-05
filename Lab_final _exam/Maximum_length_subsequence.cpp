
/*

You are given an array A consisting of N integers. A subsequence of the array is called good if every pair of elements in the subsequence have an absolute difference of at most 10.

Example:

Assumptions
N = 8
A = [1, 9, 14, 2, 17, 14, 5, 18]
Approach

Subsequence: [9,14,17,14,18] is good which is the maximum length subsequence.
Hence the output is 5.

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    sort(a, a+n);
    
    int len =0;

    int j=0;
    for(int i =0; i<n; i++){
        while(a[i]-a[j] > 10){
            j++;
        }

        len = max(len, i-j+1);
    }

    cout << len << endl;
}

/*

10
2 4 5 10 14 101 118  129 130 131 

8
1 9 14 2 17 14 5 18

*/