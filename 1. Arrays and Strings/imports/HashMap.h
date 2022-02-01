#ifndef HASHMAP_INCLUDE
#define HASHMAP_INCLUDE

class Node {
public:
    int key, value;
    Node* next;

    Node(int, int);
};

class HashMap {
    Node** table;
    
    int calcHash(int);

public:
    HashMap();

    void insert(int, int);
    void remove(int);
    int retrieve(int);

    ~HashMap();
};

#endif