#include <iostream>
using namespace std;

void Imprime(int *v, int n) {
    cout << endl << "[";
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            cout << v[i];
        }
        else {
            cout << v[i] << ", ";
        }
    }
    cout << "]" << endl;
}

void merge(int v[], int const nleft, int const mid, int const nright) {
    auto const l_size = mid - nleft + 1;
	auto const r_size = nright - mid;

	auto *vleft = new int[l_size];
    auto *vright = new int[r_size];

	for (auto i1 = 0; i1 < l_size; i1++) {
		vleft[i1] = v[nleft + i1];
    }
	for (auto j1 = 0; j1 < r_size; j1++) {
		vright[j1] = v[mid + 1 + j1];
    }

    auto i = 0;
    auto j = 0;
    int k = nleft;

    while (i < l_size && j < r_size) {
        if (vleft[i] <= vright[j]) {
            v[k] = vleft[i];
            i++;
        } else {
            v[k] = vright[j];
            j++;
        }
        k++;
    }

    while (i < l_size) {
		v[k] = vleft[i];
		i++;
		k++;
	}
	while (j < r_size) {
		v[k] = vright[j];
		j++;
		k++;
	}
}

void Mergesort(int v[], int const left, int const right) {
    if(left < right) {
        auto mid = left + (right - left)/2;

        if (left != mid) Mergesort(v, left, mid);
        if (mid+1 != right) Mergesort(v, mid+1, right);
        merge(v, left, mid, right);
        Imprime(v, 8);
    }
}


int main() {
    int v[] = { 72, 63, 18, 9, 36, 45, 54, 27 };
	auto size = sizeof(v) / sizeof(v[0]);
    
    cout << endl << "Vetor original: =================";
    Imprime(v, size);
    Mergesort(v, 0, size - 1);
    cout << endl << "Vetor ordenado: =================";
    Imprime(v, size);






    return 0;
}