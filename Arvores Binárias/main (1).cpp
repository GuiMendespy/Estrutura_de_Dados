#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

int main()
{
    int l,km;
    cout<<"Quantidade abastecida para tanque cheio (l): ";
    cin>>l;
    cout<<"Quantidade de Km percorrida (km): ";
    cin>>km;
    cout<<"Seun possante tem razão de: "<<km/l<< " quilômetros/litro";
    
    return 0;
}