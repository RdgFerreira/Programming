#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {7, 5, 16, 8};
    std::vector<int> w;
    std::cout << w.size() <<std::endl;
    v.push_back(25);  //coloca elementos ao final da sequencia
    v.push_back(13);
    for(int n : v) {  //for(int i = 0; i < v.size(); i++){int n = v[i]}
        std::cout << n << std::endl;
    }
    std::cout << v.size();
    std::cout << " " << v[1];
    std::vector<int>::iterator it;
    it = v.begin();
    v.erase(it);
    std::cout << " " << v.size();


    return 0;
}