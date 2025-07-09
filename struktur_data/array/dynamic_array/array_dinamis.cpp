#include <iostream>
class DynamicArray{
    private:
        int *array;
        int size;
        int capacity;
    public:
        DynamicArray(){
            capacity = 1;
            size = 0;
            array = new int[capacity];
        }
        DynamicArray(int capacity){
            this->capacity = capacity;
            array = new int[capacity];
            size = 0;
        }
        int getsize(){
            return size;   
        }
        int getcapacity(){
            return capacity;
        }
        void push_back(int value){
            if(size == capacity){
                GrowArray();
            }
            //insert element at index size,karena element akan di insert di paling kanan
            array[size] = value;
            //increment size
            size++;

            // return array;
        }
        void pop_back(){
            array[size - 1] = 0;
            
            size--;

            if(size == capacity/2){
                ShrinkArray();
            }
        }
        void InsertAt(int index,int value){
            if(size == capacity){
                GrowArray();
            }
            //geser array kekiri
            for(size_t i = size -1;i >= index;i--){
                array[i + 1] = array[i];
            }
            array[index] = value;
            size++;
        }
        void DeleteAt(int index){
            for(size_t i = index;i < size;i++){
                array[i] = array[i + 1];
            }

            array[size - 1] = 0;
            size--;

            if(size == capacity/2){
                ShrinkArray();
            }
        }
        void resize(int n){
            if(n > size){//ini berarti ukuran array diperbesar
                while(size < capacity){
                    if(size == capacity){ //alokasi memori diperbesar
                        GrowArray(); //metode double capacity
                    }
                }
                array[size] = 0;
                size++;
                //misal size awal 5(index 4),kita ingin resize 3
                //mulai loop n + 1 sampai <= size
                //  
            }else if(n < size){
                for(size_t i = n;i <= size;i++){
                    array[i] = 0;
                }
                size = n; //ukuran array diperkecil hingga n
            }
        }
        //mengalokasi blok memory sebanyak n
        //jika dan hanya jika kita mengetahui max capacity array
        //misal n = 5 capacity 4
            void reserve(int n){
                if(n > capacity){
                    // int* temp = new int[(n - capacity) + capacity];
                    int* temp = new int[n]; //best practices
                    capacity = n;

                    for(int i = 0;i < size;i++){
                        temp[i] = array[i];
                    }

                    delete[] array;//hapus array lama
                    array = temp;
                }
            }
        //digunakan saat ingin menyemapan size = capacity biasanya setelah resize
        void shrink_to_fit(int n){
            if(size == capacity){
                return;
            }else{
                int* temp = new int[n];
    
                for(size_t i = 0;i < size;i++){
                    temp[i] = array[i];
                }
                delete[] array;
                
                array = temp;
                capacity = size;
            }
        }
        int max_size(){
            return capacity;
        }
        int front(){
            return array[0];
        }
        int back(){
            return array[size - 1];
        }
        int accesAtIndex(int index){
            if(index < 1 || index >= size){
                return -1;
            }
            return array[index];
        }
        void clear(){
            for(size_t i = 0;i < size;i++){
                array[i] = 0;
            }
            size = 0;
        }
        /*
        reserve n > capacity
        capacity + x = n
        capacity 

        */
        void GrowArray(){   
            //buat kapasitas array 2 kali lebih besar
            int* temp = new int[capacity * 2];
            capacity = capacity * 2;

            for(int i = 0;i < size;i++){
                temp[i] = array[i];
            }
            //hapus array lama
            delete array;

            array = temp;
        }
        void ShrinkArray(){
            capacity = size;
            int* temp = new int[capacity];
            for(size_t i = 0;i < size;i++){
                temp[i] = array[i];
            }
            delete array;
            array = temp;
        }
        //linear search but std::find using BST(binary search tree)
        int search(int value){
            for(size_t i = 0;i < size;i++){
                if(array[i] == value){
                    return array[i];
                    break;
                }
            }
            return -1;
        }

        void PrintDetail(){
            std::cout << "element array" << std::endl;
            for (size_t i = 0; i < size; i++)
            {
                std::cout << array[i] <<  " ";
            }
            std::cout << std::endl;

            std::cout << "size array: " << size << " " << "capasitas array: " << capacity << std::endl;
        }

        bool IsEmpty(){
            if(size == 0){
                return true;
            }else{
                return false;
            }
        }
};
int main(){
    DynamicArray da;
    //manual insertion
    //std::cout << "Insert Array" << std::endl;
    da.push_back(1);
    da.push_back(2);
    da.push_back(3);
    da.push_back(4);
    da.push_back(5);
    da.max_size();
    std::cout << "tampilkan informasi array" << std::endl;
    int depan = da.front();
    int belakang = da.back();
   int atindex = da.accesAtIndex(2);    
   std::cout << "element pertama: " << depan << std::endl;
   std::cout << "element terakhir: " << belakang << std::endl;
   std::cout << "element pos: " << atindex << std::endl;
    std::cout << "Tampilkan Array" << std::endl;
    da.PrintDetail();
    std::cout << "Hapus Array" << std::endl;
    da.DeleteAt(1);
    std::cout << "Tampilkan Array" << std::endl;
    da.PrintDetail();
    int resize = 2;
    da.resize(resize);
    std::cout << "Tampilkan Array" << std::endl;
    da.PrintDetail();
    da.shrink_to_fit(resize);
    std::cout << "Tampilkan Array" << std::endl;
    da.PrintDetail();
    std::cin.get();
    return 0;

}