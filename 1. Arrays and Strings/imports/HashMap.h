#include <iostream>
#include <functional>

#ifndef HASHMAP_INCLUDE
#define HASHMAP_INCLUDE

template <typename K, typename V>
class Node {
public:
    K key;
    V value;
    Node* next;

    Node(K key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

template <typename K, typename V>
class HashMap {
    Node<K, V>** table;
    
    int calcHash(K key) {
        return std::hash<K>()(key) % 20;
    }

public:
    HashMap() {
        table = new Node<K, V>*[20];
        for (int i = 0; i < 20; i++) {
            table[i] = new Node<K, V>(K(), V());
        }
    }

    void insert(K key, V value) {
        if (retrieve(key) != -1) {
            std::cout << "Key already exists" << std::endl;
        }

        int index = calcHash(key);
        Node<K, V>* map = table[index]->next;

        if (map == NULL) {
            table[index]->next = new Node<K, V>(key, value);
            return;
        }

        while (map->next != NULL) {
            map = map->next;
        }
        map->next = new Node<K, V>(key, value);
    }
    void remove(K key) {
        int index = calcHash(key);
        Node<K, V>* map = table[index]->next;

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
    int retrieve(K key) {
        int index = calcHash(key);
        Node<K, V>* map = table[index]->next;

        while (map != NULL && map->key != key) {
            map = map->next;
        }

        if (map != NULL) {
            return map->value;
        }
        return -1;
    }

    ~HashMap() {
        for (int i = 0; i < 20; i++) {
            Node<K, V>* map = table[i]->next;
            while (map != NULL) {
                Node<K, V>* temp = map;
                map = map->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

#endif