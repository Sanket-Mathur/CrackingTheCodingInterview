#include <iostream>
#include "ArrayList.h"

ArrayList::ArrayList() {
    maxsize = 10;
    size = 0;
    array = new int[maxsize];
}

void ArrayList::insert(int item) {
    if (size == maxsize) {
        int* temp = array;
        maxsize *= 2;
        array = new int[maxsize];
        
        for (int i = 0; i < size; ++i) {
            array[i] = temp[i];
        }
        delete[] temp;
    }
    
    array[size++] = item;
}
void ArrayList::remove(int ind) {
    for (int i = ind + 1; i < size; ++i) {
        array[i - 1] = array[i];
    }
    --size;
}
int ArrayList::at(int ind) {
    return array[ind];
}

ArrayList::~ArrayList() {
    delete[] array;
}