//
// Created by Wayne Li on 2020-11-06.
//

#ifndef UNTITLED6_ENTRY_H
#define UNTITLED6_ENTRY_H
#include <string>
using namespace std;


class Entry {
private:
    int key;
    string data;
public:
    Entry();
    ~Entry();
   void random();
   int getKey();
   string getData();

};

#include "Entry.cpp"
#endif //UNTITLED6_ENTRY_H
