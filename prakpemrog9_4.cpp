#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n, w[1000], c[1000], x;
    double h[1000], harga=0;
    cin>>n>>x;
    for(int i=0; i<n; i++) cin>>w[i];
    for(int i=0; i<n; i++){
        cin>>c[i];
        h[i]=c[i]*1.0/w[i];
    }
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1; j++){
            if (h[j]<h[j+1]){
                swap(h[j], h[j+1]);
                swap(c[j], c[j+1]);
                swap(w[j], w[j+1]);
            }
        }
    int i=0;
    while (x>0 && i<n){
        if(x-w[i]<0){
            harga+=c[i]*x*1.0/w[i];
            x=0;
        }
        else{
            x-=w[i];
            harga+=c[i];
        }
        i++;
    }
    cout<<fixed<<setprecision(5)<<harga<<endl;
}