#include <iostream>
using namespace std;

void swap(int &data1, int &data2){
    int temp=data1;
    data1=data2;
    data2=temp;
}

void sort(int data[], int n){          
    int j;
    for(int i=1;i<n;i++){
        j=i;
        while(data[j]<data[j-1] && j>0){
            swap(data[j], data[j-1]);
            j=j-1;
        };        
    }
}

float median(int data[], int n){
    if (n%2!=0){
        return data[n/2];
    }
    else {
        float result = 0.5*(data[(n-1)/2] + data[(n+1)/2]);
        return result;
    }
}

int main(){
    int N;
    cout<<"Jumlah data: "; cin>>N;
    int arr[N];
    cout<<"Masukkan data: ";
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr,N);
    cout<<"Median: "<<median(arr, N)<<"\n";
}