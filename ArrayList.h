//
// Created by Wayne Li on 2020-10-27.
//
#include <iterator>
#ifndef UNTITLED5_ARRAYLIST_H
#define UNTITLED5_ARRAYLIST_H
template<typename T>
class ArrayList{
public:
    class Iterator{
    public:
        Iterator(int i, ArrayList<T> arr){
            array_ = arr;
            index = i;
        }
        T operator*();
        Iterator operator++();
        Iterator operator--();
        bool operator==(Iterator i);


        ArrayList<T> array_;
        int index;

    };
public:
ArrayList();
ArrayList(int c);
void copy(T*, int capacity, int length, int front_index);
bool resize(int n);
void insertBack(T e);
void insertFront(T e);
void insert(Iterator i, T e );
void shiftIndecies(int start, int finish);
void removeFront();
void removeBack();
void remove(Iterator i);
void print_arr();
T getVal(int i);
int size();
bool empty();
Iterator end();
Iterator begin();
T getAt();



private:
    T* array_;
    int length_;
    int front_index;
    int capacity_;

};

#include "ArrayList.cpp"
#endif //UNTITLED5_ARRAYLIST_H
