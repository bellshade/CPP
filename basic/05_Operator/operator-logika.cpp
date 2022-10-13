#include <iostream>

// Fungsi cek operator
void func(std::string pesan, int x, int y, bool parameter){
    std::cout << "Nilai " << x << pesan << y << " " ;
    if(parameter == true){
        std::cout << ": True/Benar" << std::endl;
    }else{
        std::cout << ": False/Salah" << std::endl;
    }
}

int main(){

	int a = 6;
	int b = 4;
	int hasil;

	// A. Operator dasar Numerik 
    std::cout << "\nA. Operator numerik\n\n";
    /*
        Terdapat 5 operator numerik, yaitu:
        1. Addition / Penjumlahan (+)
        2. Subtraction / Pengurangan (-)
        3. Multiplication / Perkalian (*)
        4. Division / Pembagian (/)
        5. Modulus / Modulo (%)
    */

	// penjumlahan
	hasil = a + b;
	std::cout << a << " + " << b << " = " << hasil << std::endl;

	// pengurangan
	hasil = a - b;
	std::cout << a << " - " << b << " = " << hasil << std::endl;

	// perkalian
	hasil = a * b;
	std::cout << a << " x " << b << " = " << hasil << std::endl;

	// pembagian
	hasil = a / b;
	std::cout << a << " / " << b << " = " << hasil << std::endl;

	// modulus
	hasil = a % b;
	std::cout << a << " % " << b << " = " << hasil << std::endl;

	// urutan eksekusi;
	hasil = a + b * a;
	std::cout << "Hasil = " << hasil << std::endl; 



    // B. Operator lanjutan Relasional
    std::cout << "\nB. Operator Relasional\n";
    /*
        kita akan mencoba cek nilai ini dengan operator-operator yang ada
        seperti: 
        1. > (Lebih dari)
        2. < (Kurang dari)
        3. == (sama dengan), 
        4. != (Tidak sama dengan)
        5. >= (Lebih dari sama dengan)
        6. <= (Kurang dari sama dengan)
    */

    int x, y;
    bool output;

    // 1. Lebih dari
    std::cout << "\n1. Lebih dari (>)\n";
    x = 1;
    y = 2;
    output = x > y;
    func(" Lebih dari ", x, y, output);

    // 2. Kurang dari
    std::cout << "\n2. Kurang dari (<)\n";
    x = 1;
    y = 2;
    output = x < y;
    func(" Kurang dari ", x, y, output);

    // 3. Sama dengan
    std::cout << "\n3. Sama dengan (==)\n";
    x = 1;
    y = 2;
    output = x == y;
    func(" Sama dengan ", x, y, output);

    x = 2;
    y = 2;
    output = x == y;
    func(" Sama dengan ", x, y, output);

    // 4. Tidak sama dengan
    std::cout << "\n4. Tidak sama dengan (!=)\n";
    x = 1;
    y = 2;
    output = x != y;
    func(" Tidak sama dengan ", x, y, output);

    x = 2;
    y = 2;
    output = x != y;
    func(" Tidak sama dengan ", x, y, output);

    // 5. Lebih dari sama dengan
    std::cout << "\n5. Lebih dari sama dengan (>=)\n";
    x = 1;
    y = 2;
    output = x >= y;
    func(" Lebih dari sama dengan ", x, y, output);

    x = 2;
    y = 1;
    output = x >= y;
    func(" Lebih dari sama dengan ", x, y, output);

    x = 1;
    y = 1;
    output = x >= y;
    func(" Lebih dari sama dengan ", x, y, output);

    x = 2;
    y = 2;
    output = x >= y;
    func(" Lebih dari sama dengan ", x, y, output);

    // 6. Kurang dari sama dengan
    std::cout << "\n6. Tidak sama dengan (<=)\n";
    x = 1;
    y = 2;
    output = x <= y;
    func(" Kurang dari sama dengan ", x, y, output);

    x = 2;
    y = 1;
    output = x <= y;
    func(" Kurang dari sama dengan ", x, y, output);

    x = 1;
    y = 1;
    output = x <= y;
    func(" Kurang dari sama dengan ", x, y, output);

    x = 2;
    y = 2;
    output = x <= y;
    func(" Kurang dari sama dengan ", x, y, output);

    

    // C. Operator Logika
    std::cout << "\nC. Operator logika\n\n";
    /*
        Terdapat 3 operator logika yaitu: 
        1. And (&&)
        2. Not (!)
        3. Or (||)
    */

    a = 3;
	b = 2;

	// 1. not
    std::cout << "untuk not (!)\n";
	output = !(a == 3);
    std::cout << output << std::endl;

	// 2. and : kedua nilai benar untuk menghasilkan true
	std::cout << "untuk and (&&)\n";
	output = (a == 3) and (b == 2); // true and true
	std::cout << output << std::endl;
	output = (a == 4) and (b == 2); // false and true
	std::cout << output << std::endl;
	output = (a == 3) && (b == 3); // true and false
	std::cout << output << std::endl;
	output = (a == 4) && (b == 3); // false and false
	std::cout << output << std::endl;

	// 3. or : salah satu nilai true maka hasil true
	std::cout << "untuk or (||)\n";
	output = (a == 3) or (b == 2); // true and true
	std::cout << output << std::endl;
	output = (a == 4) or (b == 2); // false and true
	std::cout << output << std::endl;
	output = (a == 3) || (b == 3); // true and false
	std::cout << output << std::endl;
	output = (a == 4) || (b == 3); // false and false
	std::cout << output << std::endl;


	return 0;
}