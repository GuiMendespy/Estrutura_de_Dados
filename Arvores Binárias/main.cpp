#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

int main()
{
    double a,b,c;
    string aluno;
    
    cout<<"Nome do auluno: "<<endl;
    cin>>aluno;
    cout<<"Primeira Nota: ";
    cin>>a;
    cout<<"Segunda Nota: ";
    cin>>b;
    cout<<"Terceira Nota: ";
    cin>>c;
    cout<<"Média do "<<aluno<<"foi: "<< (3*a + 4*b + 5*c)/12<<endl;
    return 0;
}