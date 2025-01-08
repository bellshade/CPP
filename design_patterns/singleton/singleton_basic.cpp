#include <iostream>

class Singleton {
  private:
    Singleton () = default;

  public:
    static Singleton& getInstance () {
      static Singleton instance; // lazy intialize, memory belum dialokasikan sampai fungsi ini dipanggil pertama kali
      return instance;  
    }

    Singleton (const Singleton& obj) = delete;  // mencegah instance assignable

    // definisikan non-static fungsi-fungsi dan variable-variable 
    // lalu akses seperti biasa.
};

// nilai address dari instace Singleton pasti selalu sama,
// yang berarti bahwa object yang dipanggil merupakan object yang sama.
int main () {
  std::cout << "Pemanggilan instance pertama: \n";
  std::cout << "\tInstance address: ";
  std::cout << &Singleton::getInstance() << '\n';

  std::cout << "Pemanggilan instance kedua: \n";
  std::cout << "\tInstance address: ";
  std::cout << &Singleton::getInstance() << '\n';

  std::cout << "Pemanggilan instance ketiga: \n";
  std::cout << "\tInstance address: ";
  std::cout << &Singleton::getInstance() << '\n';
}
