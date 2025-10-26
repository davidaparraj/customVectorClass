#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP


template <typename T>
class MyVector {
public:
    MyVector(int capacity=1);
    ~MyVector();
    MyVector(const MyVector<T>& other);
    T getCapacity() const { return capacity;}
    void push_back(const T& value); // Adds element to the last position
    T pop_back(void); // Removes last element
    void print() const; // Prints vector
    T& at(int index); // Modify it to add negative index behavior (i.e -1 = last element, like python)

    // New methods
    int getSize() const {return size;} // Returns size of vector
    void clear(); // Clears all the vector
    void push_front(const T& value); // Insert value at the beginning of the vector (index 0)
    void insert(int pos, const T& value); // Insert value at specified position
    void erase(int index); // Clears the entire vector
    void remove_dups(); // Remove duplicates

private:
    void allocate_memory(int memory_size);

    T *elements;
    int size;
    int capacity;
};

#endif
