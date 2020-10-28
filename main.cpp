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

    for(typename ArrayList<T>::Iterator iter = L.begin(); !(iter.operator==(L.end())); iter.operator++()) {
        cout << iter.operator*() << " ";
    }
    cout << endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    ArrayList<int> arr;
    arr = ArrayList<int>();



    for (int i = 0; i < 9; ++i) {
       arr.insertBack(1);
    }
    ArrayList<int>::Iterator itr = arr.begin();
    ArrayList<int>::Iterator itr2 = arr.end();
    cout << "itr val: " << itr.operator*()<<"\n";
    cout << "itr val2: " << itr2.operator*()<<"\n";

    if(itr2.operator==(arr.end())){
        cout << " iterator operator == is working"<< "\n";
    }else{
        cout << "nope";
    }


   arr.print_arr(); // working printr
   printArr(arr); // iterator printer
    cout <<"\n";
    //cout<< "printing arr[itr]: " << itr.operator*()<< "\n";
    testArrayListUnderflow();

    return 0;
}



