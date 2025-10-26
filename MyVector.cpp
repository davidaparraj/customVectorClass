#include "MyVector.hpp"
#include <iostream>

// Constructor
template<typename T>
MyVector<T>::MyVector(int capacity) : size(0) {
    this->capacity = capacity;
    elements = new T[capacity];
}

// Destructor
template<typename T>
MyVector<T>::~MyVector() {
    delete [] elements;
}

// Copy constructor
template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    elements = new T[capacity];

    //copy elements
    for(int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

// Adds element to last position
template<typename T>
void MyVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        allocate_memory(capacity * 2); // doubles capacity when size is equal or bigger
    }
    elements[size] = value;
    size++;
}

// Removes last element
template<typename T>
T MyVector<T>::pop_back(void) {
    if (size > 0) {
        if (size - 1 < capacity / 2) {
            allocate_memory(capacity / 2);
        }
        return elements[--size]; // Pre-decrements the value of size
    }
    else {
        // Throw an exception
        throw "The vector is empty!";
    }
}

// Prints Vector
template<typename T>
void MyVector<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << ' ';
    }
    std::cout << "]\n"; 
}

// Allocates new memory when capacity is low
template<typename T>
void MyVector<T>::allocate_memory(int memory_size) {
    capacity = memory_size;
    T *old = elements;
    // Allocate a new memory (bigger or smaller)
    elements = new T[memory_size];
    for (int i = 0; i < size; i++) {
        elements[i] = old[i];
    }
    // Deallocate the old memory
    delete [] old;
}

// Points at current element
template<typename T>
T& MyVector<T>::at(int index) {
    // Check if index is positive or negative
    if (index < 0){ // Negative
        return elements[index + size];
    }
    else{ // Positive
        return elements[index];
    }
}

// Clears all elements
template<typename T>
void MyVector<T>::clear() {
    // Remove all elements
    delete[] elements;
    size = 0;
    capacity = 1;
    elements = new T[capacity];
}

// Inserts new element to the first position
template<typename T>
void MyVector<T>::push_front(const T& value) {
    // Resize if capacity is exceeded
    if (size >= capacity){
        allocate_memory(capacity * 2);
    }
    // Move all values one to the right
    for (int i = size; i > 0; i--){
        elements[i] = elements[i-1];
    }
    // Change new size
    size++;
    // Add new value at index 0
    elements[0] = value;
}

// Adds element at a certain index
template<typename T>
void MyVector<T>::insert(int pos, const T& value) {
    // Resize if capacity is exceeded
    if (size >= capacity){
        allocate_memory(capacity * 2);
    }

    // Check if pos is positive or negative
    if (pos < 0){ // Update negative index (starting from left)
        pos = (size + pos) + 1;
    }

    // Move values to the right starting from pos
    for (int i = size; i >= pos; i--){
        elements[i] = elements[i-1];
    }
    // Update size
    size++;
    // Insert value at pos
    elements[pos] = value;
}

// Erases element at a certain index
template<typename T>
void MyVector<T>::erase(int index){
    // Support for negative index
    if(index < 0) {index = size + index;}

    // Index is out of range
    if(index < 0 || index >= capacity){
        throw "Index is out of range!";
    }

    // Shift elements left
    for(int i = index; i < size - 1; i++){
        elements[i] = elements[i + 1];
    }
    --size;

    // Memory management
    if(size <= capacity / 2){
        allocate_memory(capacity / 2);
    }
}

// Removes duplicates
template<typename T>
void MyVector<T>::remove_dups(){
    // Remove duplicate elements
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; ){
            if(elements[i] == elements[j]){
                erase(j);
            }
            else{
                j++;
            }
        }
    }
}
