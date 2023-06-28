#include<iostream>
#include<vector>
#include<cmath>
#include <exception>
#include <numeric>

template <typename T> std::vector<float> persamaan_garis(const std::vector<T>&x,const std::vector<T>&y){
    if (x.size()!=y.size()){
        throw std::invalid_argument("Ukurannya tidak pas");
    }
    int n=x.size();
    std::vector<float>result;
    std::vector<T>x_2;
    std::vector<T>y_2;
    std::vector<T>xy;
    // pangkat x
    for(int i=0;i<x.size();i++){
        float pangkat=pow(x[i],2);
        x_2.push_back(pangkat);
    }
    // pangkat yang y
    for(int i=0;i<y.size();i++){
        float pangkat=pow(y[i],2);
        y_2.push_back(pangkat);
    }
    for(int i=0;i<x.size();i++){
        float kali=x[i]*y[i];
        xy.push_back(kali);
    }
    float b0 = (std::accumulate(y.begin(), y.end(), 0.0) * std::accumulate(x_2.begin(), x_2.end(), 0.0))
               / ((n * std::accumulate(x_2.begin(), x_2.end(), 0.0)) - std::pow(std::accumulate(x.begin(), x.end(), 0.0), 2));
    
    float b1 = ((n * std::accumulate(xy.begin(), xy.end(), 0.0)) - (std::accumulate(x.begin(), x.end(), 0.0) * std::accumulate(y.begin(), y.end(), 0.0)))
               / ((n * std::accumulate(x_2.begin(), x_2.end(), 0.0)) - std::pow(std::accumulate(x.begin(), x.end(), 0.0), 2));
    result.push_back(b0);
    result.push_back(b1);
    return result;
}


int main(){
    std::vector<int>x={1,3,4,5,8};
    std::vector<int>y={4,2,1,0,0};
    std::vector<float>persamaan=persamaan_garis(x,y);
    std::cout<<"vector values:";
    for(const auto& value:persamaan){
        std::cout<<value<<" ";
    }
    std::cout << std::endl;
    // bagaimana kalau panjang data nggak ada;
    try
    {
        /* code */
        x={1,3,4,5,8};
        y={4,2,1};
        std::vector<float>persamaan2=persamaan_garis(x,y);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}