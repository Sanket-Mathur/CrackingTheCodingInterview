#ifndef ARRAYLIST_INCLUDE
#define ARRAYLIST_INCLUDE

template <typename T>
class ArrayList {
    T* array;
    int maxsize;

public:
    int size;
    
    ArrayList() {
        maxsize = 10;
        size = 0;
        array = new T[maxsize];
    }
    
    void insert(T item) {
        if (size == maxsize) {
            T* temp = array;
            maxsize *= 2;
            array = new T[maxsize];
            
            for (int i = 0; i < size; ++i) {
                array[i] = temp[i];
            }
            delete[] temp;
        }
        
        array[size++] = item;
    }
    void remove(int ind) {
        for (int i = ind + 1; i < size; ++i) {
            array[i - 1] = array[i];
        }
        --size;
    }
    T at(int ind) {
        return array[ind];
    }
    
    ~ArrayList() {
        delete[] array;
    }
};

#endif