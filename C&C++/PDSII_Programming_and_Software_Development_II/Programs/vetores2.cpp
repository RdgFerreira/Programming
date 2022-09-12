#include <iostream>

using namespace std;

int main() {
	
	int stackMatrixB[3][4] = { //Stack
	 {0, 1, 2, 3},
	 {4, 5, 6, 7},
	 {8, 9, 10, 11}
	};
	
	int rows = 3;
	int cols = 4;
    int** heapMatrix = new int*[rows]; //Heap (vetor de vetores alocado dinamicamente)
	for (int i=0; i < rows; i++)
	    heapMatrix[i] = new int[cols];
	
	for (int i=0; i < rows; i++){
        cout << endl;
	    for (int j=0; j < cols; j++){
            heapMatrix[i][j] = (rows*i + i) + j;
            cout << heapMatrix[i][j] << " "; 
        }
    }

	for (int i=0; i < rows; i++)
	    delete[] heapMatrix[i];
	delete[] heapMatrix;
	
	return 0;
}

