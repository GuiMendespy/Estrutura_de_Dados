#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl,std::vector;

vector<int> suap(int& a, int& b){
    
    std::vector<int> lista;
    int c{0};
    c = a;
    a = b;
    b = c;
    lista.push_back(a);
    lista.push_back(b);
    return lista;
    
}

int main()
{
    int a{8},b{9},i{0};
    vector<int> lista = suap(a,b);
    for(i=0;i<lista.size();i++){
        cout<<lista[i]<< " ";
    }

    return 0;
}