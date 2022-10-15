#include <iostream>
#include <vector>

void loop(std::vector <std::string> para){
    std::cout << "Berikut berisikan data yang berupa: " << std::endl;
    for(int i = 0; i < para.size(); i++){
        if(i < 9){
            std::cout << "0";
        }
        std::cout << i+1 << ". " << para[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    /*
        Untuk mempermudah penjelasaan, 
        kita akan ambil contoh kasus Mahasiswa
    */
    std::vector <std::string> nama 
    {
        "Aldi","Andre","Chairul","Danda","Rifki","Rojak","Muctar","Mustofa","Rendi"
    };

    // Saat ini nilai default vector berisikan 9 orang
    loop(nama);

    /*
        (?) Apakah nilai default vector yang sudah kita atur sedemikian rupa bisa kitak otak-atik?
            Ya, bisa
        (?) Bagaimana caranya?
            cara mudahnya hanya dengan memanggil nama vectornya lalu akses member fungsinya
            seperti:
            (vectorName).(member function)
    */

    /*
        1. Tambah data
            Ada beberapa cara untuk menambahkan data pada vector.
            
            - push_back (adds an element to the end)
              seperti namanya, push_back berfungsi menambahkan data pada pada index vector terakhir
              dengan rumus: vectorName.push_back(nilai)
              seperti contohnya dibawah ini, saya akan menambahakan data baru pada index akhir dari vector
            
            - insert (inserts elements)
              kita dapat manambahkan data pada posisi yang kita inginkan 
              dengan rumus: vectorName.insert (vectorName.begin() + posisi, nilai)

            - emplace (constructs element in-place)
              kita juga dapat menambahkan data menggunakan emplace, emplace yang berarti menempatkan 
              dengan rumus: vectorName.emplace(const_iterator position, element)
              emplace ini juga terbagi menjadi beberapa bagian yaitu: 
                - emplace_front()
                - emplace_back()
            
            Sisanya kalian bisa cek yang ada pada FYI/Reference
    */
    nama.push_back("Rizki"); // maka nama Rizki ada pada urutan ke-10
    loop(nama);



    nama.insert(nama.begin() + 1, "Saipul"); // Nilai saat ini menjadi 11
    /*
        nama.begin() berfungsi untuk mengatur nilainya akan di mulai dari depan
        nama.begin() + 1 mengartikan kita akan mengambil posisi index ke-1
        index ke-0 = Aldi
        index ke-1 = Andre
        index ke-2 = Chairul
        Saat ini saya telah memasukan nilai baru bernama "Saipul" untuk index ke-1
        yang dapat di artikan bahwa "Saipul" akan diletakan pada index ke-1 alias setelah index ke-0
        (?) lalu bagaimana dengan index ke-1 yang berisikan nilai bernama "Andre"?
            Nilai tersebut akan maju menggantikan yang baru saja di tambahkan
        (?) Apakah bisa menambahkan data dari belakang? 
            Ya pakai push_back ~_~
    */
    loop(nama);



    nama.emplace(nama.begin(), "Luhut"); // Nilai saat ini menjadi 12
    /*
        Nah kalau ini beda sih, lain lagi ini hehehe.
        Sudah jelas kan kalau saya menempatkan nama "Luhut" pada awal (begin) index vector
        tidak ada yang perlu dibahas lagi, hanya itu saja.
    */
    loop(nama);





    /*
        2. Hapus data
            Ada beberapa cara untuk menghapus data pada vector.
            
            - pop_back (removes the last element)
              pop_back berfungsi menghapus data pada pada index vector terakhir
            
            - erase (erases elements)
              Dengan rumus: vectorName.erase(nilai.begin()+posisi, nilai.begin()+posisi_baru)

            - clear (clears the contents)
              
            
            Sisanya kalian bisa cek yang ada pada FYI/Reference
    */

    nama.pop_back(); // Nilai saat ini menjadi 11
    /*
        Tidak perlu menggunakan parameter, cukup member function saja
        Nilai yang akan terhapus adalah nama "Rizki"
    */
    loop(nama);



    nama.erase(nama.begin() + 1, nama.begin() + 2); // Nilai saat ini menjadi 10
    /*
        nama.begin() berfungsi untuk mengatur nilainya akan di mulai dari depan
        nama.begin() + 1 mengartikan kita akan mengambil posisi index ke-1
        index ke-0 = Luhut
        index ke-1 = Aldi
        index ke-2 = Saipul
        Dapat di artikan: ambil nilai index ke-1 lalu hapus dan di gantikan dengan index ke-2
        
        Kalian bebas untuk menghapus nilanya, 
        pastikan nilai yang dipilih yang akan di hapus lalu di gantikan nilai setelahnya
        (?) Bagaimana contoh-contohnya?
            - (nama.begin() + 1, nama.begin() + 2)
            - (nama.begin() + 5, nama.begin() + 6)
            - (nama.begin() + 8, nama.begin() + 9)
        kira-kira seperti ini jabarannya: (nilai yang terpilih, nilai yang akan menggantikan posisi yang terpilih)
    */
    loop(nama);


    
    nama.clear(); // Semua data yang ada pada vector telah dihapuskan
    loop(nama);





    // 3. Swap (swaps the contents) / Menukar data antar vector

    std::vector <std::string> nama1 {"Aldi","Andre","Chairul"};
    std::vector <std::string> nama2 {"Danda","Rifki","Rojak"};

    std::cout << "[!] Sebelum datanya di tukar: " << std::endl;

    std::cout << "Data yang ada pada nama1: " << std::endl;
    loop(nama1);

    std::cout << "Data yang ada pada nama2: " << std::endl;
    loop(nama2);

    nama1.swap(nama2); // Menukar data

    std::cout << "[!] Setelah datanya di tukar: " << std::endl;

    std::cout << "Data yang ada pada nama1: " << std::endl;
    loop(nama1);

    std::cout << "Data yang ada pada nama2: " << std::endl;
    loop(nama2);





    // 4. Resize (changes the number of elements stored) / Mengatur ulang nilai index

    std::vector <std::string> buffer {"a","b","c","d","e"};
    /*
        Saat ini vector buffer berisikan 5 data
        saya akan coba mengatur nilai indexnya
    */
    std::cout << "[!] Sebelum dirubah: " << std::endl;
    loop(buffer);

    // Dari 5 menjadi 7
    std::cout << "[!] Setelah nilai indexnya dibesarkan: " << std::endl;
    buffer.resize(7); // Nilai index awal tidak berubah, dan memunculkan 2 slot index baru yang masih kosong
    loop(buffer);

    // Dari 5 menjadi 3
    std::cout << "[!] Setelah nilai indexnya dikecilkan: " << std::endl;
    buffer.resize(3); // Hanya akan memunculkan 3 data, sisanya akan di pangkas tapi tidak terhapus
    loop(buffer);
    
    return 0;
}
