/**********ACKERMAN RECURSIVE FUNCTION**********/
#include <iostream>
using namespace std;

int ackerman(int m, int n){
    if(m==0) return n+1;
    else {
        if(n==0) return ackerman(m-1, 1);
        else return ackerman(m-1, ackerman(m, n-1));
    }
}

int main(){
    int x, y;
    cout<<"Enter the first number: "; cin>>x; 
    cout<<"Enter the second number: "; cin>>y;
    if(x<0 || y<0) cout<<"Negative number is not defined!\n";
    else cout<<"a("<<x<<","<<y<<")"<<" = "<<ackerman(x,y)<<"\n";        //why does it give no return when the x>y?
    return 0;
}