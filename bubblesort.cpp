/*bandingkan dua data bersebelahan,
tukar dua data, cek sampai n-1,
iterasi sampai tidak ada data yang ditukar*/
#include <iostream>
using namespace std;

void tukar_data(int &data1, int &data2){
    int temp=data1;
    data1=data2;
    data2=temp;
}

void sort(int arr[], int n){
    for(int i=0; i<n-1; i++){              //pake do while, kl pake for harus di break
        for(int j=0; j<n-1; j++){
            if(arr[j]<arr[j+1]){
                tukar_data(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[]={2,3,7,6,8,9,5};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}