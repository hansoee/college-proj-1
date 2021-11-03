/***GPA CALCULATOR***/
#include <iostream>
using namespace std;

int calculate_gpa (char score[], int sks[], int n){
    int tmp[n]={}, sum=0, sksum=0;
    for(int i=0;i<n;i++){
        switch (score[i])
        {
        case 'A': case 'a':
        score[i]=4;
            break;
        case 'B': case 'b':
        score[i]=3;
            break;
        case 'C': case 'c':
        score[i]=2;
            break;
        case 'D': case 'd':
        score[i]=1;
            break;
        case 'E': case 'e':
        score[i]=0;
            break;    
        default:
        cout<<"wrong input"<<endl;
            break;
        }
    tmp[i]=sks[i]*score[i];
    sum+=tmp[i];
    sksum+=sks[i];
    }
    return sum/sksum;
}

int main(){
    int N;
    cout<<"Jumlah Matkul: "; cin>>N;
    int sks1[N];
    char score1[N];
    
    
    for(int i=0; i<N; i++){
        cout<<"\nNilai Matkul "<<i+1<<endl;
        cin>>score1[i];
        cout<<"\nJumlah SKS"<<endl;
        cin>>sks1[i];
    }
    
    int gpa=calculate_gpa(score1, sks1, N);
    cout<<"\nNilai GPA: "<<gpa<<endl;
}
