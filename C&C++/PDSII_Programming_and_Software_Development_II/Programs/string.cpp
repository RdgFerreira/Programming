#include <iostream>
#include <string>
int main(){
    std::string ola = std::string("Olah\n");
    std::string pds2("Vamos iniciar pds2\n");

    std::cout << ola;
    std::cout << std::endl;
    std::cout << pds2;

    std::string maisuma = "Mais uma!";
    std::cout << maisuma.size();
    std::cout << std::endl;
    maisuma.append("uygkuy");
    std::cout << maisuma.size();
    std::cout << maisuma[1];
    maisuma += pds2;
    std::cout << maisuma;

    std::string str;

    std::cin >> str;
    std::cout << std::endl << str;
    std::cout << str.length() << " " << str.size();

    return 0;
}