/***STRING_FROM_RIGHT***/
#include <iostream>
using namespace std;

string string_from_right(string st, int n){
    string a;
    for(int i=0; i<n; i++){
        a=a+st[i+st.length()-n];
    }
    return a;
}

int main(){
    string st1;
    int n1;
    cout<<"String: ";
    getline(cin,st1);
    cout<<"Jumlah n: "; cin>>n1;
    cout<<string_from_right(st1, n1)<<"\n";
}