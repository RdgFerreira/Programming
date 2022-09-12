#include <iostream>

template <class X> X max (X a, X b) { return a > b ? a : b; }
// em sml, forçaria o tipo de X para int (comparação)

class MyInt {
    friend std::ostream& operator<<(std::ostream& os, const MyInt& m) {
        os << m.data;
        return os;
    }
    friend bool operator>(MyInt &mi1, MyInt &mi2) {
        return mi1.data >= mi2.data;
    }
    public:
        MyInt(int i) : data(i) {}
    private:
        const int data;
};

int main() {
    std::cout << max<int>(5,3) << "\n";
    std::cout << max<char>('a','b') << "\n";
    std::cout << max<MyInt>(MyInt(2), MyInt(1)) << "\n"; //Erro: comparação nem print n definida para MyInt
}