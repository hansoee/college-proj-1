#include <iostream>
using namespace std;

void tukar(int &data1, int &data2){
    int temp=data1;
    data1=data2;
    data2=temp;
}

void desc_inSort(int data[], int n){          //descending
    int j;
    cout<<"\nDescending Insertion Sort:\n";
    for(int i=1;i<n;i++){
        j=i;
        while(data[j]>data[j-1] && j>0){
            tukar(data[j], data[j-1]);
            j=j-1;
        };        
    }
}

void asc_inSort(int data[], int n){          //ascending
    int j;
    cout<<"\nAscending Insertion Sort:\n";
    for(int i=1;i<n;i++){
        j=i;
        while(data[j]<data[j-1] && j>0){
            tukar(data[j], data[j-1]);
            j=j-1;
        };        
    }
}

void display(int data[], int n){
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int N;
    cout<<"Masukkan jumlah data: "; cin>>N;
    int arr[N];
    cout<<"Masukkan data yang mau diurutkan: ";
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cout<<"\nData awal:\n"; display(arr,N);
    asc_inSort(arr, N);
    display(arr,N);
    desc_inSort(arr, N);
    display(arr,N);
    
    return 0;
}