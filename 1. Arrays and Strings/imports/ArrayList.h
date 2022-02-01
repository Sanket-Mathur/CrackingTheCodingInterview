#ifndef ARRAYLIST_INCLUDE
#define ARRAYLIST_INCLUDE

class ArrayList {
    int* array;
    int maxsize;

public:
    int size;
    
    ArrayList();
    
    void insert(int);
    void remove(int);
    int at(int);
    
    ~ArrayList();
};

#endif