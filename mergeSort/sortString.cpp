#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

    int maxV = INT_MIN;
    int minV = INT_MAX;

void merge(string &a, int p, int q){
    int mid = (p + q) >> 1;
    int L = mid - p + 1;
    int R = q - mid;
    int left[L+1];
    int right[R+1];

    for(int i=0; i<L; i++) left[i] = a[p+i];
    for(int i=0; i<R; i++) right[i] = a[mid+i+1];

    left[L] = INF;
    right[R] = INF;

    
    

    for(int i=0, j=0, k=p; k<=q; k++){
        if(left[i] <= right[j]) a[k] = left[i++];
        else a[k] = right[j++];

    }


}


void mergeSort(string &a, int p, int q){
    if(p>=q) return; 
    int mid  = (p + q) / 2;
    mergeSort(a, p, mid);
    mergeSort(a, mid+1, q);
    merge(a, p, q);
}

int main(){
    // int a[]{1, 4, 5 , 2, 3};

    string a = "saimon";
    mergeSort(a, 0, 4);

    for(auto i:a) cout << i ;
    cout << endl;

}