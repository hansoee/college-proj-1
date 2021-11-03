#include <iostream>
using namespace std;

void tukar_data(int &data1, int &data2){
    int temp=data1;
    data1=data2;
    data2=temp;
}

int main(){
    int j, data[]={3,5,8,1,9};
    int n=sizeof(data)/sizeof(int);
    for(int i=1;i<n;i++){
        j=i;
        do{
            tukar_data(data[j], data[j-1]);
            j=j-1;
        }
        while(data[j]>data[j-1] && j>0);        //descending
    }
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}