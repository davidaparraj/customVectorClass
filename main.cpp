/*#include "MyVector.hpp"
#include "MyVector.cpp"

int main(void) {
    MyVector<char> *pVec = new MyVector<char>();
    char nums[] = {81, 117, 105, 122, 45, 52, 32, 87, 101, 100, 110, 101, 115, 100, 97, 121, 32, 49, 48, 50, 50, 47, 50, 47, 50, 48, 50, 53};

    for(int i = 0; i < 28; i++){
        pVec->push_back(nums[i]);
    }

    pVec->print();

    delete pVec;
    return 0;
}*/

#include "MyVector.hpp"
#include "MyVector.cpp"
#include <iostream>
#include <random>

int main(void) {
    std::mt19937 eng(1);
    std::uniform_int_distribution<int> dist(0, 20);
    
    MyVector<int> *p = new MyVector<int>(100);
    for (int i = 0; i < 20; i++) {
        p->push_front(dist(eng));
    }
    
    // Test erase
    while (p->getSize() > 5) {
        std::uniform_int_distribution<int> dist2(p->getSize() * -1, p->getSize() - 1);
        int index = dist2(eng);
        std::cout << index << std::endl;
        p->erase(index);
        p->print();
    }

     std::cout << "Capacity: " << p->getCapacity() << std::endl;
    
    // Test remove_dups
    for (int i = 0; i < 20; i++) {
        p->push_front(dist(eng));
    }

    std::cout << "Before remove_dups()\n";
    p->print();
    p->remove_dups();
    std::cout << "After remove_dups()\n";
    p->print();

    delete p;
  
    return 0;
}