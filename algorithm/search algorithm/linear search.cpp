#include <iostream>
#include <vector>
#include <algorithm>
#include<array>
#include <stdlib.h>
using namespace std;
/*sumber crud
https://gist.github.com/nihitx/1f56c129b35c992d35ba9c11647d2721
karena program ini fokus ke implementasi linear search bukan membuat crud
*/
bool SearchName(vector<string>& nama, string &DataNama){
    cout << "Masukkan nama penulis yang anda ingin cari ";
    getline(cin,DataNama);
    for(int i = 0; i < nama.size(); i++){
        if(DataNama == nama[i]){
            return true;
        }
    }
    return false;
}

bool SearchBook(vector<string>& buku, string &DataBuku){
    cout << "Masukkan nama buku yang anda ingin cari ";
    for(int i = 0; i < buku.size(); i++){
        if(DataBuku == buku[i]){
            return true;
        }
    }
    return false;
}

bool LinearSearch(vector<string>& bookarray, string &data){
    cout << "Masukkan buku yang anda ingin cari ";
    getline(cin,data);
    for(int i = 0; i < bookarray.size(); i++){
        if(data == bookarray[i]){
            return true;
        }
    }  
    return false;
}
int main(){
    cout << "**  welcome to the database **" << endl;
    char choice;
    int pilihan;
    string data;
    string DataNama;
    string DataBuku;
    string bookname;
    string removebook;
    int countnum;
    string authorname;
    string fullbook;
    vector<string> bookarray;
    vector<string> nama;
    vector<string> buku;
    do{
        system("clear");
        cout << " a. Tambah buku" << endl;
        cout << " b. Hapus buku" << endl;
        cout << " c. Kosongkan database" << endl;
        cout << " d. Tampilkan jumlah buku" << endl;
        cout << " e. Tampilkan semua buku" << endl;
        cout << " f. cari buku " << endl;
        cout << " g. keluar" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> choice;
        if(choice == 'g' ) {
            printf("Mengakhiri program...");
        }
        else{
            if(choice == 'a'){
                cout << "Masukkan judul buku: " ;
                cin >> bookname;
                buku.push_back(bookname);
                cout << "Masukkan nama penulis :";
                cin >> authorname;
                nama.push_back(authorname);
                fullbook = bookname + " " + authorname;
                bookarray.push_back(fullbook);
                cout << "Buku berhasil di tambahkan" << endl;
            }else if(choice =='b'){
                cout << "Masukkan judul buku yang ingin dihapus: " ;
                cin >> removebook;
                for(int i = 0; i < bookarray.size() ; i++){
                    if (bookarray[i].find(removebook) != std::string::npos) {
                        bookarray.erase (bookarray.begin()+i);
                        break;
                    }
                }
                cout << " " << endl;
                cout << "Buku berhasil di hapus" << endl;
                cout << " " << endl;
            }else if(choice == 'c'){
                bookarray.clear();
                cout << "Database telah dikosongkan"  << endl;
                cout << " " << endl;
            }else if(choice == 'd'){
                countnum = bookarray.size();
                cout << "Jumlah buku dalam database:" << countnum << endl;
            }else if(choice == 'e'){
                cout << "Daftar buku dalam database " << endl;
                for(int i = 0; i < bookarray.size() ; i++){
                    cout << i + 1 << " " << bookarray[i] <<  " " << endl; ;

                }
                cout << " " << endl;
            }else if(choice == 'f'){
                cout << "1.cari buku berdasarkan nama penulis \n";
                cout << "2.cari buku berdasarkan nama buku \n";
                cout << "3.cari buku berdasarkan \n";
                cout << "Masukkan pilihan anda: ";
                cin >> pilihan;
                cin.ignore();
                switch(pilihan){
                    case 1:
                        if(SearchName(nama,DataNama)){
                            cout << "data penulis ditemukan! " << endl;
                            break;
                        }else{
                            cout << "Data penulis tidak di temukan " << endl;
                            break;
                        }
                    case 2:
                        if(SearchBook(buku,DataBuku)){
                            cout << "Data Buku ditemukan! " << endl;
                            break;
                        }else{
                            cout << "Data buku tidak ditemukan " << endl;
                            break;
                        }
                    case 3:
                        if(LinearSearch(bookarray,data)){
                            cout << "Data Buku ditemukan! " << endl;
                            break;
                        }else{
                            cout << "Data buku tidak ditemukan! " << endl;
                            break;
                        }
                    default:
                        cout << "Invalid input " << endl;         
                        break;   
                }
             }
        }
    }while(choice != 'g');

    return 0;
}