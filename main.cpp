#include <iostream>
#include "ArrayList.h"
#include <iterator>
static void testArrayListUnderflow()
{
    try{
        ArrayList<int> arr;
        arr = ArrayList<int>();
        arr.insertBack(1);
        arr.removeFront();
        arr.removeFront();

        cout <<"did not catch exception"<< "\n";
    }catch(EmptyListException){
        cout << "caught Empty Stack Excpetion" << "\n";
    }
    try{
        ArrayList<int> arr;
        arr = ArrayList<int>();
        arr.insertBack(1);
        arr.removeBack();
        arr.removeBack();

        cout <<"did not catch exception"<< "\n";
    }catch(EmptyListException){
        cout << "caught Empty Stack Excpetion" << "\n";
    }
    try{
        ArrayList<int> arr;
        arr = ArrayList<int>();
        arr.insertBack(1);
        ArrayList<int>::Iterator itr(0,arr);
        itr = arr.begin();
        arr.remove(itr);
        arr.remove(itr);

        cout <<"did not catch exception"<< "\n";
    }catch(EmptyListException){
        cout << "caught Empty Stack Excpetion" << "\n";
    }



}
void testIntegerIterator(){
    ArrayList<int> arr;
    arr = ArrayList<int>();

}

void testStringIterator(){

}
template<typename T>
void printArr(ArrayList<T> L){
    for(typename ArrayList<T>::Iterator iter = L.begin(); !iter.operator==(L.end()); iter.operator++()) {
        cout << *iter << " ";
    }
    cout << endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    ArrayList<int> arr;
    arr = ArrayList<int>();
    ArrayList<int>::Iterator itr(0,arr);

    for (int i = 0; i < 9; ++i) {
       arr.insert(itr,i);
    }


    printArr(arr);
    cout <<"\n";
    cout<< "printing arr[itr]: " << itr.operator*()<< "\n";
    testArrayListUnderflow();

    return 0;
}



