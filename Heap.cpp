//
// Created by Wayne Li on 2020-11-06.
//
#include <iostream>
#include "Heap.h"
using namespace std;
Heap::Heap() {
    arr = new Entry[5];
    size = 5;
    stored = 0;
}
Heap::~Heap(){

}
bool Heap::isEmpty() {
    if(stored == 0) return true;
}

int Heap::getSize() {
    return size;
}
int Heap::getParentIndex(int i) {
    return (i-2)/2;
}
int Heap::getLeftIndex(int i) {
    return i*2+1;
}
int Heap::getRightIndex(int i) {
    return i*2+2;
}
bool Heap::hasParent(int i){
    return (getParentIndex(i)<size);
}
bool Heap::hasLeft(int i){
    return (getLeftIndex(i)<size);
}
bool Heap::hasRight(int i){
    return (getRightIndex(i)<size);
}
Entry Heap::parent(int i){
    return arr[getParentIndex(i)];
}
Entry Heap::left(int i){
    return arr[getLeftIndex(i)];
}
Entry Heap::right(int i){
    return arr[getRightIndex(i)];
}
void Heap::swap(int index1, int index2) {
    Entry tempval = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tempval;
}
void Heap::expandCapacity() {
    if(stored == size){
        Entry* newArr = new Entry[size*2];
        for (int i = 0; i < stored; ++i) {
            newArr[i] = arr[i];
        }

        arr = newArr;
        size*=2;
    }
}
Entry Heap::removeMax() {
    if(stored == 0){
        cout << "empty heap error. ";
        throw;
    }
    Entry val = arr[stored-1];
    arr[0] = arr[stored-1];
    stored--;
    heapifyDown();
    return val;
}
void Heap::heapifyDown(){
    int index = 0;
    while(hasLeft(index)){
        int smaller = getLeftIndex(index);
        if(hasRight(index) && right(index).getKey()<left(index).getKey()){
            smaller = getRightIndex(index);
        }
        if(arr[index].getKey() < arr[smaller].getKey()){
            break;
        }else{
            swap(index, smaller);
            index = smaller;
        }
    }


}
void Heap::insert(Entry e){
    expandCapacity();
    arr[stored] = e;
    stored++;
    heapifyUp();
}

void Heap::heapifyUp(){
    int index = stored -1;
while(hasParent(index)&& parent(index).getKey()>arr[index].getKey()){
    swap(getParentIndex(index),index);
    index = getParentIndex(index);
}
}
void Heap::make(Entry* data, int n){
    for (int i = 0; i < n ; ++i) {
        insert(data[i]);
    }
}
Entry* Heap::getUnderlyingArray() {
    return arr;
}