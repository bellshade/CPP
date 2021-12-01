#include <iostream>
class Kecepatan{
    public:
    void setJarak(int j){
        jarak = j;
    }
    void setWaktu(int w){
        waktu = w;
    }
    protected:
    int jarak;
    int waktu;
};

class Kalkulasi: public Kecepatan{
    public:
    int getKecepatan(){
        return (jarak / waktu);
    }
};

int main(void){
    Kalkulasi kalkulasi;
    kalkulasi.setJarak(17);
    kalkulasi.setWaktu(5);

    std::cout<<"total: "<<kalkulasi.getKecepatan()<<std::endl;

    return 0;
}