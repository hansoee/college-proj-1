#include <iostream>
using namespace std;

int faktorial(int x){
    if(x>=1) return (x*faktorial(x-1)); 
    else if(x=0) return 1;              //0!=1
    else return 0;                      //negative number don't have factorial
}
int main(){
    int a;
    cin>>a;
    cout<<faktorial(a);
}