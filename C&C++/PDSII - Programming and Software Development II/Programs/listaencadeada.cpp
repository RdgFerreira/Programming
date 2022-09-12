#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous; //duplamente encadeada
};

int main() {
    Node a;
    Node b;

    a.data = 99;
    a.next = &b;
    b.data = 123;

    cout << a.data << endl;
    cout << a.next->data << endl;

    return 0;
}
