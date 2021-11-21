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

void editBook(){
    string line;
    int n, m, size = 0;
    cout<<"\n-------------------------------------------------------"<<endl;
    cout << "Pilih nomor buku yang akan diedit!\n"; //buat bedain buku kalo ada buku yg judul/penulis/tahunnya sama
    cout << "No. Buku\t: ";
    cin >> n;
    fstream ebook;
    ebook.open("buku.txt");
    while ((getline(ebook,line))){
        ++size;
    }
    m = size/3;
    buku dataBuku[m];
    ebook.clear();                          //krn eofnya udah keset di akhir setelah line 39 jd setnya dihapus dulu
    ebook.seekg(0);                         //ubah posisi kursor ke awal line lagi

    for(int i = 0; i < m ; i++){
        getline(ebook,dataBuku[i].judul);
        getline(ebook,dataBuku[i].penulis);
        ebook >> dataBuku[i].tahun;
        ebook.ignore();
    }
    ebook.close();

    cin.ignore();
    cout<<"\n--------------------- Edit Book ---------------------"<<endl;
    cout<<"Masukkan Judul Buku \t: "; getline(cin, dataBuku[n-1].judul);
    cout<<"Masukkan Penulis Buku \t: "; getline(cin, dataBuku[n-1].penulis);
    cout<<"Tahun Terbit Buku \t: "; cin>>dataBuku[n-1].tahun;

    ebook.open("buku.txt",ios::trunc|ios::out);
    for(int i = 0; i < m; i++){
        ebook << dataBuku[i].judul << endl;
        ebook << dataBuku[i].penulis << endl;
        ebook << dataBuku[i].tahun << endl;
    }
    ebook.close();
}

void addRack(string title){                  //bikin file txt trs write data book disitu
    bool n=true;
    fstream rack;
    fstream sbook;
    sbook.open("buku.txt");
    rack.open("mybooks.txt", ios::app);
    while(!rack.eof()){
        getline(sbook,bookdata.judul);                
        getline(sbook,bookdata.penulis);
        sbook>>bookdata.tahun;
            if(bookdata.judul==title){
                sbook.ignore();               
                n=0;
                rack<<bookdata.judul<<"\n";             
                rack<<bookdata.penulis<<"\n";
                rack<<bookdata.tahun<<"\n";   
                rack.close(); 
                break;
            }
            else if(sbook.eof() && n) cout<<"unavailable"; 
            sbook.ignore();
    }
    sbook.close();
}

void searchTitle(string title){             //aku bikin 3 fungsi berdasarkan filter soalnya kl pake if atau case error:(
    bool n = true;
    int m = 0;
    searchMenu:
    ifstream sbook;
    sbook.open("buku.txt");
    while(!sbook.eof()){
            getline(sbook,bookdata.judul);       //getline : buat masukin kalimat satu baris di sbook ke bookdata.judul         
            getline(sbook,bookdata.penulis);
            sbook>>bookdata.tahun;
            m++;
            if(bookdata.judul==title){
                sbook.ignore();                 //biar ga error kalo getline nya banyak
                cout<<"\n--------------------- Book Found! ---------------------"<<endl;
                cout<<"Judul    \t: "<<bookdata.judul<<endl;
                cout<<"Penulis  \t: "<<bookdata.penulis<<endl;
                cout<<"Tahun Terbit \t: "<<bookdata.tahun<<endl;
                cout<<"No. Buku \t: " << m << endl; //buat gampangin edit buku hehe
                n = 0;                  //biar nandain kalo programnya udah pernah nemuin judulnya
            }
            else if(sbook.eof() && n) {
                cout<<"Maaf, buku yang anda cari belum tersedia"; //kalo udah sampe akhir baris dan programnya belum nemu judul yg sama
            }
            sbook.ignore();
    }
    sbook.close();
}

void searchAuthor(string author){
    bool n = true;
    int m = 0;
    ifstream sbook;
    sbook.open("buku.txt");
    while(!sbook.eof()){
            getline(sbook,bookdata.judul);
            getline(sbook,bookdata.penulis);
            sbook>>bookdata.tahun;
            m++;
            if(bookdata.penulis==author){
                sbook.ignore();
                cout<<"\n--------------------- Book Found! ---------------------"<<endl;
                cout<<"Judul    \t: "<<bookdata.judul<<endl;
                cout<<"Penulis  \t: "<<bookdata.penulis<<endl;
                cout<<"Tahun Terbit \t: "<<bookdata.tahun<<endl;
                cout<<"No. Buku \t: " << m << endl;
                n = 0;                  //biar nandain kalo programnya udah pernah nemuin judulnya   
            }
            else if(sbook.eof() && n) {
                cout<<"Maaf, buku yang anda cari belum tersedia"; //kalo udah sampe akhir baris dan programnya belum nemu judul yg sama
            }
            sbook.ignore(); 
    }
    sbook.close();
}

void searchYear(int year){
    bool n = true;
    int m = 0;
    ifstream sbook;
    sbook.open("buku.txt");
    while(!sbook.eof()){
            getline(sbook,bookdata.judul);
            getline(sbook,bookdata.penulis);
            sbook>>bookdata.tahun;
            m++;
            if(bookdata.tahun==year){
                sbook.ignore();
                cout<<"\n--------------------- Book Found! ---------------------"<<endl;
                cout<<"Judul    \t: "<<bookdata.judul<<endl;
                cout<<"Penulis  \t: "<<bookdata.penulis<<endl;
                cout<<"Tahun Terbit \t: "<<bookdata.tahun<<endl;
                cout << "No. Buku \t: " << m << endl;              
                n = 0;                  //biar nandain kalo programnya udah pernah nemuin judulnya 
            }
            else if(sbook.eof() && n) {
                cout<<"Maaf, buku yang anda cari belum tersedia"; //kalo udah sampe akhir baris dan programnya belum nemu judul yg sama
            }
            sbook.ignore(); 
    }
    sbook.close();
}

void searchFilter(){
    string t, a;
    int y;
    cout<<"Cari Buku yang akan dipinjam dengan filter: \n";
        cout<<"1. Judul\n"<<"2. Penulis\n"<<"3. Tahun\n";
        int pil;
        cout<<"Pilihan Anda: "; cin>>pil;
        switch (pil){
        case 1: 
            cin.ignore(); //biar ga error kalo pake getline >1 kali
            cout<<"\nJudul buku yang dicari: ";
            getline(cin,t);
            searchTitle(t);
            break;
        case 2:
            cin.ignore();
            cout<<"\nNama penulis buku yang dicari: ";
            getline(cin,a);
            searchAuthor(a);
            break;
        case 3:
            cout<<"\nTahun Terbit buku yang dicari: ";
            cin>>y;
            searchYear(y);
            break;
        default:
        cout<<"wrong input\n";
            break;
        } 
}

void hapus(string path, string eraseTitle) {
    string line;
    ifstream bin;
    bin.open(path); //isi dr path dicopy ke temp yg nnti direname balik
    ofstream temp;
    temp.open("temp.txt");
    
    while (!bin.eof()) {
        if (iswspace(bin.peek())) bin.ignore();
        getline(bin,bookdata.judul);
        getline(bin,bookdata.penulis);
        bin>>bookdata.tahun;
        //write semua baris kecuali baris yg mau dihapus ke file temp.txt
        if (bookdata.judul != eraseTitle /*&& bookdata.penulis != eraseAuthor && bookdata.tahun != eraseYear*/){
            
            temp << bookdata.judul << endl;
            temp << bookdata.penulis << endl;
            temp << bookdata.tahun << endl;
        }
           
    }
    temp.close();
    bin.close();
    
    // copas buku.txt ke temp, buku.txt dihapus, ganti nama temp jd path = buku.txt
    const char * p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

void deleteBook(){
    string titleDelete, authorDelete; //sori gais msi nyari cara :pray_hands:
    int choice, yearDelete;
    deleteMenu:
    ifstream dbook;
    ofstream bin;              //buat tempat buang data
    int del;
    cout<<"Cari buku untuk dihapus berdasarkan filter\n";
    cout<<"1: Judul, 2: Penulis, 3: Tahun terbit, 4: Kembali, 5: Keluar\n";
    cin>>choice;
    switch(choice){
        case 1:
        cin.ignore();
        cout<<"Judul buku: ";
        getline(cin,titleDelete);
        searchTitle(titleDelete);
        cout<<"Hapus buku ini? [1 (ya) / 0 (tidak)]"; cin>>del;
        if(del==1){
            hapus("buku.txt", titleDelete);
        }
        break;
        case 2:
        cin>>authorDelete;
        searchAuthor(authorDelete);

        break;
        case 3:
        cin>>yearDelete;
        searchYear(yearDelete);

        break;
        case 4:
        //goto librarian;
        break;
        case 5:
        exit(0);
        default:
        goto deleteMenu;
        break;
    } 
}

void editFilter(){
    editMenu:
    cout<<"\nCari Buku yang akan diedit dengan filter: \n";
    cout<<"1. Judul\n"<<"2. Penulis\n"<<"3. Tahun\n"<<"4. Keluar\n";
    
    int pil;
    string titleEdit;
    string authorEdit;
    int yearEdit;

    cout<<"Pilihan Anda: "; cin>>pil;
    switch (pil){
        case 1:{
            cin.ignore();
            cout<<"\nJudul buku yang dicari: ";
            getline(cin,titleEdit);
            searchTitle(titleEdit);
            editBook();
        }
            break;
        case 2:{
            cin.ignore();
            cout<<"\nNama Penulis yang dicari: ";
            getline(cin,authorEdit);
            searchAuthor(authorEdit);
            editBook();
        }
            break;
        case 3:{
            cout<<"\nTahun Terbit dari buku yang dicari: ";
            cin>>yearEdit;
            searchYear(yearEdit);
            editBook();
        }
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"Input pilihan tidak sesuai\n";
            goto editMenu;
            break;
        }
    }

void borrowBook()
    {
    string t, a;
    int y;
    cout << "Cari Buku yang akan dipinjam dengan filter: \n";
    cout << "1. Judul\n" << "2. Penulis\n" << "3. Tahun\n";
    int pil;
    cout << "Pilihan Anda: "; cin >> pil;
    switch (pil) {
    case 1:
        cin.ignore(); //biar ga error kalo pake getline >1 kali
        cout << "\nJudul buku yang dicari: ";
        getline(cin, t);
        searchTitle(t);
        addRack(t);
        hapus("buku.txt", t);
        break;
    case 2:
        cin.ignore();
        cout << "\nNama penulis buku yang dicari: ";
        getline(cin, a);
        searchAuthor(a);
        //addRack();                                        //blm bikin yg pinjam pake author
        break;
    case 3:
        cout << "\nTahun Terbit buku yang dicari: ";
        cin >> y;
        searchYear(y);
        //addRack();                                        //blm bikin yg pinjam pake year
        break;
    default:
        cout << "wrong input\n";
        break;
    }
}

void returnBook()                 //Belum jadi ges
{
    string titleDelete, authorDelete; //sori gais msi nyari cara :pray_hands:
    int choice, yearDelete;
deleteMenu:
    ifstream mybooks;
    ofstream bin;              //buat tempat buang data
    int del;
    cout << "Cari buku untuk dihapus berdasarkan filter\n";
    cout << "1: Judul, 2: Penulis, 3: Tahun terbit, 4: Kembali, 5: Keluar\n";
    cin >> choice;
    switch (choice) {
    case 1:
        cin.ignore();
        cout << "Judul buku: ";
        getline(cin, titleDelete);
        searchTitle(titleDelete);
        cout << "Hapus buku ini? [1 (ya) / 0 (tidak)]: "; cin >> del;
        if (del == 1) {
            hapus("mybooks.txt", titleDelete);
        }
        break;
    case 2:
        cin.ignore();
        cout << "Nama penulis: ";
        getline(cin, authorDelete);
        searchAuthor(authorDelete);
        cout << "Hapus buku ini? [1 (ya) / 0 (tidak)]: "; cin >> del;
        if (del == 1) {
            hapus("mybooks.txt", authorDelete);
        }
        break;
    case 3:
        cout << "Tahun terbit: ";
        cin >> yearDelete;
        searchYear(yearDelete);
        cout << "Hapus buku ini? [1 (ya) / 0 (tidak)]: "; cin >> del;
        if (del == 1) {
            hapus("mybooks.txt", authorDelete);
        }
       
        break;
    case 4:
        //goto librarian;
        break;
    case 5:
        exit(0);
    default:
        goto deleteMenu;
        break;
    }
}

void sortAlp(struct buku dataBuku[80], int n){          //bubble sort struct diurutkan dari string judul
    struct buku temp;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<(n-i-1); j++){
            if(dataBuku[j].judul>dataBuku[j+1].judul){
                temp=dataBuku[j];
                dataBuku[j]=dataBuku[j+1];
                dataBuku[j+1]=temp;
            }
        }
    }
}

void displayRack(){                 
    int size=0;
    string line;
    ifstream dbook;
    dbook.open("mybooks.txt");
    while ((getline(dbook,line))){
        ++size;
    }
    int n=size/3;                               
    buku dataBuku[n];
    dbook.clear();                          
    dbook.seekg(0);                         
    for(int i=0; i<n; i++){                
        getline(dbook, dataBuku[i].judul);
        getline(dbook, dataBuku[i].penulis);
        dbook>>dataBuku[i].tahun;
        dbook.ignore();
    }
    sortAlp(dataBuku, n);
    for(int i=0; i<n; i++){                
        cout<<"Judul Buku: "<<dataBuku[i].judul<<"\n";
        cout<<"Penulis: "<<dataBuku[i].penulis<<"\n";
        cout<<"Tahun Terbit: "<<dataBuku[i].tahun<<"\n";
        cout<<"------------------------------------"<<"\n";
    }
    dbook.close();
}

//TAMPILKAN SELURUH BUKU DI DATABASE
void displayBook(){                 
    int size=0;
    string line;
    ifstream dbook;
    dbook.open("buku.txt");
    while ((getline(dbook,line))){
        ++size;
    }
    int n=size/3;                               //jumlah baris dibagi 3 (data struct->judul, penulis, tahun)
    buku dataBuku[n];
    dbook.clear();                          //krn eofnya udah keset di akhir setelah line 39 jd setnya dihapus dulu
    dbook.seekg(0);                         //ubah posisi kursor ke awal line lagi
    for(int i=0; i<n; i++){                //input data dari txt ke array
        getline(dbook, dataBuku[i].judul);
        getline(dbook, dataBuku[i].penulis);
        dbook>>dataBuku[i].tahun;
        dbook.ignore();
    }
    sortAlp(dataBuku, n);
    for(int i=0; i<n; i++){                //input data dari txt ke array
        cout<<"Judul Buku: "<<dataBuku[i].judul<<"\n";
        cout<<"Penulis: "<<dataBuku[i].penulis<<"\n";
        cout<<"Tahun Terbit: "<<dataBuku[i].tahun<<"\n";
        cout<<"------------------------------------"<<"\n";
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
        bool inp;
        cout<<"--------------------------------------------------------------\n";
        cout<<"            Selamat Datang, Pengunjung Perpustakaan!          \n";
        cout<<"--------------------------------------------------------------\n";
        cout<<"1. Cari Buku\n"<<"2. Pinjam Buku\n"<<"3. Kembalikan Buku\n"<<"4. Lihat Semua Buku\n"<<"5. Lihat Buku Saya\n"<<"6. Ganti Peran\n"<<"7. Keluar\n";
        cout<<"--------------------------------------------------------------\n";
        cout<<"Pilihan Anda: "; cin>>userchoice;
        switch (userchoice)
        {
        case 1:
            search:
            system("cls");
            searchFilter();
            cout<<"Apakah Anda ingin mencari buku lagi? [1 (ya) / 0 (tidak)] "; cin>>inp;
            if (inp) goto search;
            else {
                system("cls");
                goto user;
            }
            break;
        case 2:
            borrowBook();
            break;
        case 3:
            returnBook();
            break;
        case 4:
            system("cls");
            displayBook();
            cout<<"[1 (Kembali) / 0 (Keluar)] "; cin>>inp;
            if (inp) goto user;
            else exit(0);
            break;
        case 5:{
            system("cls");
            displayRack();
            cout<<"[1 (Kembali) / 0 (Keluar)] "; cin>>inp;
            if (inp) goto user;
            else exit(0);
            break;
        }
        case 6:
            system("cls");
            goto firstmenu;
            break;
        case 7:
            exit(0);
        default:
            system("cls");
            cout<<"Input salah!\n";
            goto user;
            break;
        }

    }

    //MENU PUSTAKAWAN   
    else if(choice==2){
        system("cls");
        librarian:
        int libchoice;
        cout<<"--------------------------------------------------------------\n";
        cout<<"                  Selamat Datang, Pustakawan!                 \n";
        cout<<"--------------------------------------------------------------\n";
        cout<<"1. Cari Buku\n"<<"2. Lihat Semua Buku\n"<<"3. Tambah Buku\n"<<"4. Hapus Buku\n"<<"5. Edit Buku\n"<<"6. Ganti Peran\n"<<"7. Keluar\n";
        cout<<"--------------------------------------------------------------\n";
        cout<<"Pilihan Anda: "; cin>>libchoice;
        switch (libchoice)
        {
        case 1:
            searchFilter();
            break;
        case 2:
            cout<<"\n";
            displayBook();
            break;
        case 3: {
            int inp=1;
            while(inp!=0){
            cin.ignore();
            cout<<"\nMasukkan Judul Buku \t: "; getline(cin, bookdata.judul);
            cout<<"Masukkan Penulis Buku \t: "; getline(cin,bookdata.penulis);
            cout<<"Tahun Terbit Buku \t: "; cin>>bookdata.tahun;               //infinite loop ketika input selain int
            addBook();
            cout<<"\nApakah Anda ingin input data buku lagi? [1 (ya) / 0 (tidak)] "; cin>>inp;
            }
            system("cls");
            goto librarian;
            break;
            }
        case 4:
            deleteBook();
            break;
        case 5:
            editFilter();
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
