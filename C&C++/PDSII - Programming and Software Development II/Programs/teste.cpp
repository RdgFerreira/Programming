#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){
    cout << "Hello, World" << endl;
    cout << 1 << 2 << 3 << "Numbers" << endl;
    cout << M_PI << endl;
    string name = "RodrigoFerreira";
    cout << name << endl;
    int *valores = new int;
    valores[0] = 1;
    valores[1] = 2;
    cout << valores[0] << " " << valores[1] << endl;
    vector<int> v = {4, 5, 6};
    v.insert(v.begin(),{1, 2, 3});
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    v.insert(v.begin(),{-2, -1, 0});
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    int i = 3;
    v.erase(v.begin() + i);
    for (int vit : v){
        cout << vit << " ";
    }
    return 0;
}