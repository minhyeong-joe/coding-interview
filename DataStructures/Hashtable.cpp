#include "Hashtable.hpp"
#include <iostream>
#include <stdexcept>

template<class K, class V>
HashTable<K,V>::HashTable() {
    _capacity = DEFAULT_CAPACITY;
    _size = 0;
}

template<class K, class V>
HashTable<K,V>::~HashTable() {
}

template<class K, class V>
int HashTable<K,V>::hash(const K& key) const {
    return (int)key % _capacity;
}

template<class K, class V>
void HashTable<K,V>::expandTable() {
    // TO DO
}

template<class K, class V>
void HashTable<K,V>::shrinkTable() {
    // TO DO
}

template<class K, class V>
void HashTable<K,V>::insert(const K& key, const V& value) {
    if (contains(key)) {
        throw std::invalid_argument("Duplicate Key Exception");
    }
    int index = hash(key);
    Data newData{key, value};
    table[index].push_back(newData);
    _size += 1;
    if (((double)_size/(double)_capacity) > 0.5) {
        expandTable();
    }
}

template<class K, class V>
void HashTable<K,V>::remove(const K& key) {
    int index = hash(key);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i]._key == key) {
            table[index].erase(table[index].begin() + i);
            _size -= 1;
            if (((double)_size/(double)_capacity) < 0.5) {
                shrinkTable();
            }
            return;
        }
    }
    throw std::invalid_argument("Key does not exist");
}

template<class K, class V>
bool HashTable<K,V>::contains(const K& key) const {
    int index = hash(key);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i]._key == key) {
            return true;
        }
    }
    return false;
}

template<class K, class V>
V HashTable<K,V>::get(const K& key) const {
    int index = hash(key);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i]._key == key) {
            return table[index][i]._value;
        }
    }
    throw std::invalid_argument("Key does not exist");
}

template<class K, class V>
void HashTable<K,V>::print() const {
    for (int i = 0; i < _capacity; i++) {
        std::cout << "Index # " << i << ": ";
        for (int j = 0; j < table[i].size(); j++) {
            std::cout << "{" << table[i][j]._key << ":" << table[i][j]._value << "}";
            if (j < table[i].size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }
}