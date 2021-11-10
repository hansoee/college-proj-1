#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct buku{            //perlu pake id?
    string judul;
    string penulis;
    int tahun;
} bookdata;

void addBook(){                  //create a txt file and write book data in it
    fstream abook;
    abook.open("buku.txt", ios::app);
    abook<<bookdata.judul<<"\n";             // '<<' masukkan data buku ke txt
    abook<<bookdata.penulis<<"\n";
    abook<<bookdata.tahun<<"\n";
    abook.close();
}

void deleteBook();
void editBook();

void searchBook(){            //ONE STRING INPUT
    string st1;
    cout<<"\nJudul buku yang dicari: ";
    cin>>st1;
    string line;
    int temp=0;
    ifstream sbook;
    sbook.open("buku.txt");
    while(!sbook.eof()){
            sbook>>bookdata.judul;                  //inisiasi data buku dari txt
            sbook>>bookdata.penulis;
            sbook>>bookdata.tahun;
    }       
            if(bookdata.judul==st1){
                cout<<"\n--------------------- Book Found! ---------------------"<<endl;
                cout<<"Judul    \t: "<<bookdata.judul<<endl;
                cout<<"Penulis  \t: "<<bookdata.penulis<<endl;
                cout<<"Tahun Terbit \t: "<<bookdata.tahun<<endl;
                sbook>>bookdata.judul;                  //inisiasi data buku dari txt
                sbook>>bookdata.penulis;
                sbook>>bookdata.tahun;
                
            }
            else cout<<"no"; 
        
    
}

void borrowBook();
void returnBook();

void addRack(){                  //bikin file txt trs write data book disitu
    fstream rack;
    
    rack.open("mybooks.txt", ios::app);        //buku di rak user (yg dipinjem)
    rack<<bookdata.judul<<"\n";             // '<<' masukkan data buku ke txt
    rack<<bookdata.penulis<<"\n";
    rack<<bookdata.tahun<<"\n";
    rack.close();

    rack.seekp(0, ios::end);
    int spot = rack.tellg();
        if( spot == 0){
            cout << "Empty file\n";
        }
}

void displayRack(){                 
    ifstream dRack;
    dRack.open("mybooks.txt");
    dRack>>bookdata.judul;                  //inisiasi data buku dari txt
    dRack>>bookdata.penulis;
    dRack>>bookdata.tahun;

    while(!dRack.eof()){                //eof(endoffile)=looping data sampe akhir file
        cout<<"Judul Buku: "<<bookdata.judul<<"\n";
        cout<<"Penulis: "<<bookdata.penulis<<"\n";
        cout<<"Tahun Terbit: "<<bookdata.tahun<<"\n";
        cout<<"------------------------------------"<<"\n";
        
        dRack>>bookdata.judul;                  //cek eof agar perulangan berhenti https://www.youtube.com/watch?v=f_CBXDVI9kk 28:20
        dRack>>bookdata.penulis;
        dRack>>bookdata.tahun;
    }
    dRack.close();
}

//TAMPILKAN SELURUH BUKU DI DATABASE
void displayBook(){                 
    ifstream dbook;
    dbook.open("buku.txt");

    dbook>>bookdata.judul;                  //inisiasi data buku dari txt
    dbook>>bookdata.penulis;
    dbook>>bookdata.tahun;

    while(!dbook.eof()){                //eof(endoffile)=looping data sampe akhir file
        cout<<"Judul Buku: "<<bookdata.judul<<"\n";
        cout<<"Penulis: "<<bookdata.penulis<<"\n";
        cout<<"Tahun Terbit: "<<bookdata.tahun<<"\n";
        cout<<"------------------------------------"<<"\n";
        
        dbook>>bookdata.judul;                  //cek eof agar perulangan berhenti https://www.youtube.com/watch?v=f_CBXDVI9kk 28:20
        dbook>>bookdata.penulis;
        dbook>>bookdata.tahun;
    }
    dbook.close();
}

int main(){
    int choice;
    firstmenu:
    cout<<"----------- Selamat Datang di Perpustakaan Online! -----------\n";
    cout<<"Siapa Anda?\n"<<"1.Pengunjung\n"<<"2.Pustakawan\n";
    cout<<"--------------------------------------------------------------\n";
    cout<<"Pilih 1 atau 2: "; cin>>choice;
    
    //MENU PENGUNJUNG
    if(choice==1){
        system("cls");
        user:
        int userchoice;
        cout<<"----------- Selamat Datang di Perpustakaan Online! -----------\n";
        cout<<"1. Cari Buku\n"<<"2. Pinjam Buku\n"<<"3. Kembalikan Buku\n"<<"4. Lihat Semua Buku\n"<<"5. Lihat Buku Saya\n"<<"6. Ganti Peran\n"<<"7. Keluar\n";
        cout<<"--------------------------------------------------------------\n";
        cout<<"Pilihan Anda: "; cin>>userchoice;
        switch (userchoice)
        {
        case 1:
            //searchBook();
            break;
        case 2:
            //borrowBook();
            break;
        case 3:
            //returnBook();
            break;
        case 4:
            cout<<"\n";
            displayBook();
            break;
        case 5:{
            cout<<"Cari Buku yang akan dipinjam dengan filter: \n";
            cout<<"1. Judul\n"<<"2. Penulis\n"<<"3. Tahun\n";
            int pil;
            cout<<"Pilihan Anda: "; cin>>pil;
            switch (pil){
            case 1:
                searchBook();
                break;
            case 2:

                break;
            case 3:

                break;
            default:
                break;
            }
            //searchBook();
            addRack();
            break;
        }
        case 6:
            goto firstmenu;
            break;
        case 7:
            exit(0);
        default:
            goto user;
            break;
        }

    }

    //MENU PUSTAKAWAN   
    else if(choice==2){
        system("cls");
        librarian:
        int libchoice;
        cout<<"\n----------- Selamat Datang di Perpustakaan Online! -----------\n";
        cout<<"1. Cari Buku\n"<<"2. Lihat Semua Buku"<<"3. Tambah Buku\n"<<"4. Hapus Buku\n"<<"5. Edit Buku\n"<<"6. Ganti Peran\n"<<"7. Keluar\n";
        cout<<"--------------------------------------------------------------\n";
        cout<<"Pilihan Anda: "; cin>>libchoice;
        switch (libchoice)
        {
        case 1:
            //searchBook();
            break;
        case 2:
            cout<<"\n";
            displayBook();
            break;
        case 3: {
            int inp=1;
            while(inp!=0){
            cout<<"\nMasukkan Judul Buku \t: "; cin>>bookdata.judul;                      //MASI GABISA PAKE GETLINE
            cout<<"Masukkan Penulis Buku \t: "; cin>>bookdata.penulis;
            cout<<"Tahun Terbit Buku \t: "; cin>>bookdata.tahun;               //infinite loop ketika input selain int
            addBook();
            cout<<"\nApakah Anda ingin input data buku lagi? [1(ya)/0(tidak)] "; cin>>inp;
            }
            system("cls");
            goto librarian;
            break;
            }
        case 4:
            //deleteBook();
            break;
        case 5:
            //editBook();
            break;
        case 6:
            goto firstmenu;
            break;
        case 7:
            exit(0);
        default:
            goto librarian;
            break;
        }        
    }
    else{
        system("cls");        //works on windows only, linux&mac use 'clear'
        cout<<"Masukkan angka 1 atau 2\n";
        goto firstmenu;
    }
}
