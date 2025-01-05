#include <iostream>

class ClassScope {
  public:
    ClassScope () = default;

    static int sharedVar; // definisi, memori dialokasikan
};

int ClassScope::sharedVar = 5; // insialisasi

int main () {
  ClassScope obj1;
  ClassScope obj2;

  std::cout << "Akses langsung nilai variable tanpa perantara object\n";
  std::cout << "\tNilai: " << ClassScope::sharedVar << '\n';
  std::cout << "Akses langsung nilai variable melalui object\n";
  std::cout << "\tNilai: " << obj1.sharedVar << '\n';

  std::cout << "\nObject 1 mengubah nilai variable-nya\n";
  obj1.sharedVar = 10;
  std::cout << "Maka object 2 pun merasakan perubahannya\n";
  std::cout << "\tNilai: " << obj2.sharedVar << '\n';
}
