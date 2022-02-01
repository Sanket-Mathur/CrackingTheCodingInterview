#include <iostream>
#include "HashMap.h"

Node::Node(int key, int value) {
    this->key = key;
    this->value = value;
    next = NULL;
}

int HashMap::calcHash(int key) {
    return key % 20;
}

HashMap::HashMap() {
    table = new Node*[20];
    for (int i = 0; i < 20; i++) {
        table[i] = new Node(-1, -1);
    }
}

void HashMap::insert(int key, int value) {
    if (retrieve(key) != -1) {
        std::cout << "Key already exists" << std::endl;
    }

    int index = calcHash(key);
    Node* map = table[index]->next;

    if (map == NULL) {
        table[index]->next = new Node(key, value);
        return;
    }

    while (map->next != NULL) {
        map = map->next;
    }
    map->next = new Node(key, value);
}
void HashMap::remove(int key) {
    int index = calcHash(key);
    Node* map = table[index]->next;

    if (map == NULL) {
        return;
    } else if (map->next == NULL) {
        if (map->key == key) {
            table[index]->next = NULL;
        }
        return;
    }

    while (map->next != NULL && map->next->key != key) {
        map = map->next;
    }
    if (map->next != NULL) {
        map->next = map->next->next;
    }
}
int HashMap::retrieve(int key) {
    int index = calcHash(key);
    Node* map = table[index]->next;

    while (map != NULL && map->key != key) {
        map = map->next;
    }

    if (map != NULL) {
        return map->value;
    }
    return -1;
}

HashMap::~HashMap() {
    delete[] table;
}