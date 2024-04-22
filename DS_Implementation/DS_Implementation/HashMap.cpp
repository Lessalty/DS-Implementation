
//A hash map or hash table is a data structure that offers an efficient way to store and manage data using a key - value pair system.It allows 
// for fast retrieval, insertion, and deletion operations, commonly performing these operations in average - case constant time,𝑂(1)
//
//
//    
//
//
//
//In C++, hash maps are commonly implemented using an array of linked lists(or even more complex structures like balanced binary search trees) to manage collisions.Collisions occur when multiple keys hash to the same index.


#include <iostream>
#include <list>
#include <vector>

template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    HashNode* next;

    HashNode(K key, V value) : key(key), value(value), next(nullptr) {}
};

template <typename K, typename V>
class HashMap {
private:
    std::vector<HashNode<K, V>*> table;
    int capacity;
    int size;

    int hashFunction(K key) {
        return key % capacity;
    }

public:
    HashMap(int cap = 101) : capacity(cap), size(0) {
        table.resize(capacity, nullptr);
    }

    ~HashMap() {
        for (int i = 0; i < capacity; ++i) {
            HashNode<K, V>* entry = table[i];
            while (entry != nullptr) {
                HashNode<K, V>* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        table.clear();
    }

    void insert(K key, V value) {
        int bucketIndex = hashFunction(key);
        HashNode<K, V>* entry = table[bucketIndex];
        HashNode<K, V>* prev = nullptr;

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new HashNode<K, V>(key, value);
            if (prev == nullptr) {
                table[bucketIndex] = entry;
            }
            else {
                prev->next = entry;
            }
            size++;
        }
        else {
            entry->value = value;
        }
    }

    V get(K key) {
        int bucketIndex = hashFunction(key);
        HashNode<K, V>* entry = table[bucketIndex];

        while (entry != nullptr) {
            if (entry->key == key) {
                return entry->value;
            }
            entry = entry->next;
        }

        throw std::out_of_range("Key not found");
    }

    void remove(K key) {
        int bucketIndex = hashFunction(key);
        HashNode<K, V>* entry = table[bucketIndex];
        HashNode<K, V>* prev = nullptr;

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            throw std::out_of_range("Key not found to remove");
        }
        else {
            if (prev == nullptr) {
                table[bucketIndex] = entry->next;
            }
            else {
                prev->next = entry->next;
            }
            delete entry;
            size--;
        }
    }

    int getSize() {
        return size;
    }
};

int main() {
    HashMap<int, std::string> map(7); // Create a hash map with an initial capacity
    map.insert(1, "Value One");
    map.insert(2, "Value Two");
    map.insert(3, "Value Three");

    std::cout << "Value for key 2: " << map.get(2) << std::endl;

    map.remove(2);

    try {
        std::cout << "Value for key 2: " << map.get(2) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
