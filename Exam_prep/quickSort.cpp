#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int p, int q){
    int i = p;

    for(int j=p; j<q; j++){
        if(a[j] < a[q]) swap(a[i++], a[j]);
    }
    swap(a[q], a[i]);

    return i;
}
void quickSort(int a[], int p, int q){
    if(p>=q) return;

    int i = partition(a, p, q);
    quickSort(a, p, i-1);
    quickSort(a, i+1, q);
}



int main(){
    int n; cin >> n; 
    int a[n]; 
    for(int i=0; i<n; i++) cin >> a[i];

    quickSort(a, 0, n-1);

    for(auto i:a) cout << i << " ";
}