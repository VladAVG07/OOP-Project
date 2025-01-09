#ifndef COLLECTION_TPP
#define COLLECTION_TPP

#include <stdexcept>

template <typename T>
void Collection<T>::add(const T& item) {
    items.push_back(item);
}

template <typename T>
void Collection<T>::removeLast() {
    if (!items.empty()) {
        items.pop_back();
    }
}

template <typename T>
void Collection<T>::display() const {
    for (const auto& item : items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <typename T>
size_t Collection<T>::size() const {
    return items.size();
}

template <typename T>
void Collection<T>::sortItems(bool ascending) {
    std::sort(items.begin(), items.end(), [ascending](const T& a, const T& b) {
        return ascending ? (a < b) : (a > b);
    });
}

template <typename T>
bool Collection<T>::contains(const T& item) const {
    return std::find(items.begin(), items.end(), item) != items.end();
}

template <typename T>
T& Collection<T>::getAt(size_t index) {
    if (index >= items.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return items[index];
}

template <typename T>
void Collection<T>::clear() {
    items.clear();
}

template <typename T>
void Collection<T>::applyToEach(std::function<void(T&)> func) {
    for (auto& item : items) {
        func(item);
    }
}

#endif
