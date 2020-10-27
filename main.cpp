#include <iostream>
#include "ArrayList.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    ArrayList<int> arr;
    arr = ArrayList<int>();
    for (int i = 0; i < 9; ++i) {
       arr.insert(i,i);
    }


    arr.print_arr();
    cout<<"\n" <<"frontindex is : " << arr.begin();
    cout<<"\n" <<"endindex is : " << arr.end();
    return 0;
}
