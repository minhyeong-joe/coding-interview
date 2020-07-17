#ifndef _HASH_TABLE_HPP
#define _HASH_TABLE_HPP

// vector as a linked list mimic
#include <vector>

const int DEFAULT_CAPACITY = 10;

template<class K, class V>
class HashTable {
private:
    struct Data {
        K _key;
        V _value;
    };
    std::vector<Data> table[DEFAULT_CAPACITY];
    int _capacity;
    int _size;
    
    // helper methods
    int hash(const K& key) const;
    void expandTable();
    void shrinkTable();
public:
    HashTable();
    ~HashTable();
    void insert(const K& key, const V& value);
    void remove(const K& key);
    bool contains(const K& key) const;
    V get(const K& key) const;
    void print() const;
};

#include "Hashtable.cpp"

#endif