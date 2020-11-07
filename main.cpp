#include <iostream>
#include "Entry.h"
#include "Heap.h"
using namespace std;
void printEntires(Entry* arr, int n){
    cout <<"Printing Entries, (key, string) "<< "\n\n";
    for (int i = 0; i < n; ++i) {
        cout << "(" << arr[i].getKey();
        cout << ", " << arr[i].getData() << ")"<< "\n";
    }
}
void printEntries(Entry e){
    cout << "(" << e.getKey();
    cout << ", " << e.getData() << ")"<< "\n";
}
void heapsort2(Heap h, int n, Entry* entries){
    for (int i = 0; i < n; ++i) {
        cout << "removeing entry: ";
        entries[i] = h.removeMax();
    }
}
void populateEntries(int n, Entry* entries){
    for (int i = 0; i < n; ++i) {
        Entry e;
        e.random();
        entries[i] = e;
    }
}
int main() {
    int n = 2;
    std::cout << "Hello, World!" << std::endl;

    Entry* entries = new Entry[n];
    populateEntries(n,entries);
    printEntires(entries,n);

    Heap h = Heap();
    h.make(entries,n);
    Entry e = h.removeMax();
    printEntries(e);
    Entry d = h.removeMax();
    printEntries(d);
    return 0;
}
