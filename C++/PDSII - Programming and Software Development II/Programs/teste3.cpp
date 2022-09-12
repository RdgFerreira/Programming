#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {3,2,4,6,5,1};
    vector<int> vsorted;
    int min = 100;
    int jmin = 0;
    int size = v.size();

    for (int i=0; i<size; i++) {
        min = 100;
        for (int j=0; j<v.size(); j++) {
            if (min > v[j]) {
                min = v[j];
                jmin = j;
                //cout << j << " " << min << " " << jmin << endl;
            }
        }
        vsorted.push_back(min);
        v.erase(v.begin() + jmin);
    }

    for (int vit : vsorted) {
        cout << vit << " ";
    }


    return 0;
}