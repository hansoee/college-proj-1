/***Data Mahasiswa dengan Array dan Struct***/
#include <iostream>
using namespace std;

struct data{
    int student_id, midterm_score, finalexam_score;
} mhs[50];
int main(){
    int N;
    cout<<"Masukkan jumlah mahasiswa: ";
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>mhs[i].student_id;
    }
}