#include <iostream>
#include <vector>
#include <list>
#include <string>

int main(){
    std::string temp2;

  std::string word;
  while (std::cin >> word) {
    std::cout << word << std::endl;
  }

    std::list<std::string> l;
     while(std::cin>>temp2){
        l.push_back(temp2);
    }
    for(std::list<std::string>::iterator it=l.begin(); it != l.end(); ++it){
        std::cout << *it << " ";
    }
    return 0;
}