//
// Created by Wayne Li on 2020-10-27.
//

#include "ArrayList.h"
#include "iostream"
using namespace std;
template<typename T>
ArrayList<T>::ArrayList(){
    array_ = new T[4];
    capacity_ = 4;
    length_ = 0;
}

template<typename T>
ArrayList<T>::ArrayList(int c){
    array_ = new T[c];
    capacity_ = c;
    length_ = 0;
}
template <typename T>
bool ArrayList<T>::resize(const int new_capacity)
{
    auto* temp = new T[new_capacity];
    //copy array to new array with new capacity
    for (auto i{ 0 }; i < length_; ++i)
    {
        //transfer ownership of every element
        temp[i] = array_[(front_index + i) % capacity_];
    }
    //free old array
    delete[] array_;
    //point to *temp
    capacity_ = new_capacity;
    //reset front index to 0
    front_index = 0;
    array_ = temp;
    temp = nullptr;		//pointer dangling
    //return statement
    return true;
}
template <typename T>
 void ArrayList<T>::copy(T* copy, int capacity_, int length_, int front_index)
{
    //create new array in the heap
    array_ = new T[capacity_];
    //traverse copy array and copy data organizing array
    for (auto i{ 0 }; i < length_; ++i)
    {
        array_[i] = copy->array_[(copy->front_index + i) % copy->capacity_];
    }
}
template <typename T>
void ArrayList<T>::insertBack(T e) {

    if (length_ >= capacity_) resize(static_cast<int>(capacity_ * 2));
    //add end index length
    array_[(front_index + length_) % capacity_] = std::move(e);
    //increase length
    ++length_;

}
template<typename T>

void ArrayList<T>::print_arr() {
    for (int i = 0; i < capacity_; ++i) {
        cout<< array_[i];
    }
}

template<typename T>
void ArrayList<T>::insertFront(T e) {
    if (length_ >= capacity_) resize(static_cast<int>(capacity_ * 2));
    //decrement front_index
    if (front_index == 0) front_index = capacity_ - 1;
        //decrement front index
    else --front_index;
    //increment length
    ++length_;
    //insert new front value
    array_[front_index] = e;
}
template<typename T>
void ArrayList<T>::insert(Iterator it, T e) {

    if (length_ >= capacity_) resize(static_cast<int>(capacity_ * 2));
    length_++;
    ArrayList<T> temp;
    temp = ArrayList<T>(capacity_);
    for (int j = 0; j < capacity_; ++j) {
        if(j == it.getI()){
            temp.insertBack(e);
        }
        temp.insertBack(array_[j]);
    }
    delete array_;
    array_ = temp.array_;


}
template<typename T>
void ArrayList<T>::removeFront() {
    if (length_ == 0) throw std::range_error("Array length_ is 0");
    front_index = ++front_index % capacity_;
    //decrease length
    --length_;
}
template<typename T>
void ArrayList<T>::removeBack() {
    if (length_ == 0) throw std::range_error("Array length_ is 0");
    --length_;
}

template<typename T>
void ArrayList<T>::remove(Iterator i) {
    ArrayList<T> temp;
    temp = ArrayList<T>(capacity_);
    for (int j = 0; j < capacity_; ++j) {
        if(j == i.getI()){
            j++;
        }
        temp.insertBack(array_[j]);
    }
    delete array_;
    array_ = temp.array_;
    length_--;
}
template<typename T>
int ArrayList<T>::size() {
    return length_;
}
template<typename T>
bool ArrayList<T>::empty() {
if(length_ == 0){
    return true;
}
return false;
}
template<typename T>
Iterator ArrayList<T>::begin() {
    return Iterator(front_index);
}
template<typename T>
Iterator ArrayList<T>::end() {
    return Iterator(length_);
}
template<typename T>
T Iterator::operator*<T>() {

}