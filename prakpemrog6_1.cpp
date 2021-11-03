/***Program Menentukan Zodiak dengan Struct***/
#include <iostream>
using namespace std;

struct data{
    string nama, bln, sign;
    int tgl;
};
int main(){
    data mhs;
    cout<<"Nama: ";
    cin>>mhs.nama; 
    cout<<"Tanggal dan Bulan Lahir: ";
    cin>>mhs.tgl;
    cin>>mhs.bln;
    if(mhs.bln=="Maret" && mhs.tgl>20 && mhs.tgl<32 || mhs.bln=="April" && mhs.tgl>0 && mhs.tgl<20){
        mhs.sign="Aries";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="April" && mhs.tgl>19 && mhs.tgl<31 || mhs.bln=="Mei" && mhs.tgl>0 && mhs.tgl<21){
        mhs.sign="Taurus";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="Mei" && mhs.tgl>20 && mhs.tgl<32 || mhs.bln=="Juni" && mhs.tgl>0 && mhs.tgl<21){
        mhs.sign="Gemini";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="Juni" && mhs.tgl>20 && mhs.tgl<31 || mhs.bln=="Juli" && mhs.tgl>0 && mhs.tgl<23){
        mhs.sign="Cancer";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="Juli" && mhs.tgl>22 && mhs.tgl<32 || mhs.bln=="Agustus" && mhs.tgl>0 && mhs.tgl<23){
        mhs.sign="Leo";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="Agustus" && mhs.tgl>22 && mhs.tgl<32 || mhs.bln=="September" && mhs.tgl>0 && mhs.tgl<23){
        mhs.sign="Virgo";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="September" && mhs.tgl>22 && mhs.tgl<31 || mhs.bln=="Oktober" && mhs.tgl>0 && mhs.tgl<23){
        mhs.sign="Libra";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="Oktober" && mhs.tgl>22 && mhs.tgl<32 || mhs.bln=="November" && mhs.tgl>0 && mhs.tgl<22){
        mhs.sign="Scorpio";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="November" && mhs.tgl>21 && mhs.tgl<31 || mhs.bln=="Desember" && mhs.tgl>0 && mhs.tgl<22){
        mhs.sign="Sagitarius";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else if(mhs.bln=="Desember" && mhs.tgl>21 && mhs.tgl<32 || mhs.bln=="Januari" && mhs.tgl>0 && mhs.tgl<20){
        mhs.sign="Capricorn";
        cout<<"Zodiak Anda: "<<mhs.sign<<endl;
    }
    else{
        cout<<"Format yang Anda masukkan tidak sesuai"<<endl;
    }
    
}