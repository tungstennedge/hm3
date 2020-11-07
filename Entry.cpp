//
// Created by Wayne Li on 2020-11-06.
//

#include "Entry.h"
#include <cstdlib>

Entry::Entry() {
    key = 0;
    data = to_string(rand()%100);
}
Entry::~Entry() {

}
void Entry::random() {
    data = to_string(rand()%100);
    key = rand()%100;
}

string Entry::getData() {
    return data;
}
int Entry::getKey() {
    return key;
}

