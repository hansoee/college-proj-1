#include <iostream>
#include <cstring>
using namespace std;

bool check(string s, int i){
    int len=s.length()-1;
    if(s[i]==s[len-i]){            
        if(i==len/2) return 1;
        else return check(s, i+1);
    }
    else return 0;
}

int main(){
    string st;
    cout<<"Masukkan kalimat: "; getline(cin,st);
    if(check(st,0)){
        cout<<"palindrom\n";
    }
    else cout<<"bukan palindrom\n";
    return 0;
}