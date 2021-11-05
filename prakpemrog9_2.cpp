#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int &data1, int &data2){
    int temp=data1;
    data1=data2;
    data2=temp;
}

void desc_inSort(int data[], int n){          //descending insertion sort
    int j;
    cout<<"\nDescending Insertion Sort:\n";
    for(int i=1;i<n;i++){
        j=i;
        while(data[j]>data[j-1] && j>0){
            swap(data[j], data[j-1]);
            j=j-1;
        };        
    }
}

void asc_inSort(int data[], int n){          //ascending insertion sort
    int j;
    cout<<"\nAscending Insertion Sort:\n";
    for(int i=1;i<n;i++){
        j=i;
        while(data[j]<data[j-1] && j>0){
            swap(data[j], data[j-1]);
            j=j-1;
        };        
    }
}

void asc_selSort(int data[], int c1, int numb){         //ascending selection sort
    int position, d;
    for(c1=0; c1<(numb-1); c1++){
        position=c1;
        for(d=c1+1; d<numb;d++){
            if(data[position]>data[d]) position = d;
        }
        swap(data[c1], data[position]);
    }
}

void desc_selSort(int data[], int c1, int numb){         //ascending selection sort
    int position, d;
    for(c1=0; c1<(numb-1); c1++){
        position=c1;
        for(d=c1+1; d<numb;d++){
            if(data[position]>data[d]) position = d;
        }
        swap(data[c1], data[position]);
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
    int arr[N], opt;
    cout<<"\nData awal:\n"; 
    srand(time(0));                                 //print random number
    for(int i=0; i<N; i++){
        arr[i]=(rand()%10)+1;
    }
    display(arr, N);
    cout<<"\n";
    cout<<"1. Ascending Insertion Sort\n";
    cout<<"2. Descending Insertion Sort\n";
    cout<<"3. Ascending Selection Sort\n";
    cout<<"4. Descending Selection Sort\n";
    cout<<"\nPilih jenis sorting: "; cin>>opt;
    switch(opt){
        case 1:
            asc_inSort(arr, N);
            display(arr,N);
            break;
        case 2:
            desc_inSort(arr, N);
            display(arr,N);
            break;
        case 3:
            asc_selSort(arr, 0, N);
            display(arr,N);
            break;
        case 4:
            desc_selSort(arr, 0, N);
            display(arr,N);
            break;
        default: cout<<"option number is undefined";
    return 0;
    }
}