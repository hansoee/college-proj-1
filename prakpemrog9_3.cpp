#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout<<"Masukkan jumlah data: "; cin>>n;
    int arr[n];
    cout<<"Masukkan data: \n";
    srand(time(0));                                 
    for(int i=0; i<n; i++){
        arr[i]=(rand()%10)+1;
    }
    sort(arr, arr+n);
    cout<<"Hasil Sorting: \n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}