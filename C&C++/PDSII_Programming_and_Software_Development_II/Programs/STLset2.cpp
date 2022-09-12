#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 3, 5, 7, 9};

    if(s.find(6) != s.end()) {
        // Element in set
    } else {
        // Element not presents in set
        s.insert(6);
    }

    if(s.insert(6).second) {
        // Element INSERTED in set
    } else {
        // Element NOT INSERTED in set
    }

    for (int e : s) {
        std::cout << e << std::endl;
    }
    return 0;
}