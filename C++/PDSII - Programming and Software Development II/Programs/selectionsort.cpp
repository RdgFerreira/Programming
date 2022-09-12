#include <iostream>
#include <iomanip>
#include <vector>

std::vector<int> selectionsort(std::vector<int> str){
    if (str.size() == 1){
        return str;
    }
    int min, minindex = 0;
    int aux = 0;
    unsigned int i, j = 0;
    for (i = 0; i < (str.size())-1; ++i){
        min = str[i];
        minindex = i;
        //std::cout << min << " min" << std::endl;
        for (j = i+1; j < str.size(); ++j){
            //std::cout << str[j] <<" str[j]" << std::endl;
            if (str[j] < str[minindex]) {
                //min = str[j];
                minindex = j;
            }
        }
        //std::cout << str[minindex] << " str[minindex]" << std::endl;
        aux = str[i];
        str[i] = str[minindex];
        str[minindex] = aux;
        //std::cout << str[minindex] << " str[minindex]" << std::endl;
    }
    return str;
}

int main(){
    std::vector<int> str = {4, 3, 2, 2, 1};
    for (unsigned int i=0;i<str.size();++i){
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
    std::cout << str.size();
    std::cout << std::endl;
    str = selectionsort(str);
    for (unsigned int i=0;i<str.size();++i){
        std::cout << str[i] << " ";
    }
    return 0;
}
