#include <iostream>
using namespace std;

int faktorial(int a){
    int i=1,temp=1;
    while(i<=a){            //looping i (1-a)
        temp*=i;        //dikali sm 1 simpan di temp
        i++; 
    }
    return temp;
}

int main(){
    int N;
    cin>>N;
    cout<<faktorial(N)<<endl;
}
