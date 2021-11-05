/**********RECURSIVE BINOMIAL COEFFICIENT**********/
#include <iostream>
using namespace std;

int binomCoef(int n, int k){
    if(k==0||k==n) return 1;                            //C(n,0) dan C(n,n) = 1
    else return binomCoef(n-1, k-1) + binomCoef(n-1, k);     //loop until k=0 or k=n and add up the 1
}

int main(){
    int n, k;
    cout<<"Enter n: "; cin>>n;
    cout<<"Enter k: "; cin>>k;
    if(n<0 || k<0) cout<<"No negative number!\n";
    else if(k>n) cout<<"n should be bigger than k\n";
    else cout<<"C("<<n<<","<<k<<") = "<<binomCoef(n,k)<<"\n";
    return 0;
}