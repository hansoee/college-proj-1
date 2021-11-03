#include <iostream>
using namespace std;

int fib(int x){
    int arr[x];
    arr[0]={1}; arr[1]={1};
    for(int i=2;i<=x;i++){
        arr[i]=arr[i-2]+arr[i-1];
    }
    return arr[x];
}
int main(){
    int n;
    cout<<"masukkan n "; cin>>n;
    cout<<"\n"<<fib(n)<<endl;
}