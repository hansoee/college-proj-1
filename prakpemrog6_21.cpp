/***Data Mahasiswa dengan Array dan Struct***/
#include <iostream>
using namespace std;

struct data{
    int student_id;
    float midterm_score, finalexam_score, av;
} mhs[50];
int main(){
    int N;//, a;
    cout<<"Masukkan jumlah mahasiswa: ";
    cin>>N;
    cout<<endl;
    while(N>0){ //inputnya decrement 
        //a=N-1;
        //cout<<"Mahasiswa "<<a+1<<endl;
        cout<<"Masukkan ID Mahasiswa: ";
        cin>>mhs[N-1].student_id;
        
        cout<<"Masukkan Nilai Ujian Tengah Semester: ";
        cin>>mhs[N-1].midterm_score;
               
        cout<<"Masukkan Nilai Ujian Akhir: ";
        cin>>mhs[N-1].finalexam_score;
        mhs[N-1].av=(mhs[N-1].midterm_score+mhs[N-1].finalexam_score)*0.5;

        cout<<endl<<"Hasil"<<endl;
    
        cout<<"ID Mahasiswa: "<<mhs[N-1].student_id<<endl;
        cout<<"Rata-rata: "<<mhs[N-1].av<<endl;
        N--;
        cout<<endl; 

    }
    
    return 0;
}