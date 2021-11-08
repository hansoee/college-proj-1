#include <iostream>
using namespace std;

void tukar(int &data1, int &data2){
    int temp=data1;
    data1=data2;
    data2=temp;
}

void desc_inSort(int data[], int n){          
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

void asc_inSort(int data[], int n){          
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

void desc_selSort(int data[], int pod, int lim){         
    cout<<"\nDescending Selection Sort:\n";
    for(int i=pod; i<lim; i++){
        int token=i; 
        for(int j=i+1; j<lim; j++){
            if(data[i]<data[j]){
                token=j;
                tukar(data[i], data[j]);
            }
        }   
    }
}

void asc_selSort(int data[], int pod, int lim){         
    cout<<"\nAscending Selection Sort:\n";
    for(int i=pod; i<lim; i++){
        int token=i; 
        for(int j=i+1; j<lim; j++){
            if(data[i]>data[j]){
                token=j;
                tukar(data[i], data[j]);
            }
        }   
    }
}

void desc_bubSort(int arr[], int n){
    cout<<"\nDescending Bubble Sort:\n";
    for(int i=0; i<n-1; i++){              
        for(int j=0; j<n-1; j++){
            if(arr[j]<arr[j+1]){
                tukar(arr[j],arr[j+1]);
            }
        }
    }
}

void asc_bubSort(int arr[], int n){
    cout<<"\nAscending Bubble Sort:\n";
    for(int i=0; i<n-1; i++){              
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                tukar(arr[j],arr[j+1]);
            }
        }
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
    cout<<"Masukkan data yang akan diurutkan: ";
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cout<<"\nData awal:\n"; display(arr,N);
    asc_inSort(arr, N);
    display(arr,N);
    desc_inSort(arr, N);
    display(arr,N);
    asc_selSort(arr, 0, N);
    display(arr,N);
    desc_selSort(arr, 0, N);
    display(arr,N);
    asc_bubSort(arr, N);
    display(arr,N);
    desc_bubSort(arr, N);
    display(arr,N);
    return 0;
}
