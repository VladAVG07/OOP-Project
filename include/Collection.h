//
// Created by vladg on 1/9/2025.
//

#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

template <typename T>
class Collection {
    std::vector<T> items;
public:
    void add(const T& item);
    void removeLast();
    void display() const;
    size_t size() const;
    void sortItems(bool ascending = true);
    bool contains(const T& item) const;
    T& getAt(size_t index);
    void clear();
    void applyToEach(std::function<void(T&)> func);

    typename std::vector<T>::iterator begin() { return items.begin(); }
    typename std::vector<T>::iterator end() { return items.end(); }
    typename std::vector<T>::const_iterator begin() const { return items.begin(); }
    typename std::vector<T>::const_iterator end() const { return items.end(); }
};

#include "../src/Collection.tpp"

#endif //COLLECTION_H
