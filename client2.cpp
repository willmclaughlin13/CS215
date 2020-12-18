#include <iostream>
#include "LL.h"
#include "binarytree.h"
using namespace std;

int main() {
    binarytree t;
    for (int i = 0; i < 20; i++) {
        t.insert(rand() % 50);
    }

    cout << "The binary tree: ";
    t.print();
    cout << endl;
    
    LL<int> l;
    l = t.toLL();
    
    cout << "The linked list: ";
    
    for (LL<int>::iterator i = l.begin(); i != l.end(); i++) {    
        cout << *i << " ";
    }
    cout << endl;    
    
	cout << "testing clone: " << endl;
	binarytree w;
	w.clone(t);
}  
