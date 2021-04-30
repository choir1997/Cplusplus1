#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H
#include "Deque.h"
#include "Car.h"

using namespace std;

template <typename T>
class Vector {
private:
    Deque<T> deque_;
public:
    void push_back(const T& turnTableCar) {
        deque_.push_back(turnTableCar);
    }
    void pop_back() {
        return deque_.pop_back();
    }
    T* back() {
        return deque_.back();
    }
    size_t size() {
        return deque_.size();
    }
    T& at(size_t index) {
        return deque_.at(index);
    }
    string toStringTrain() const{
        return deque_.toString();
    }
    int isFound(const T& carToFind) {
        if (deque_.findCar(carToFind) != -1) {
            return deque_.findCar(carToFind);
        }
        else {
            return -1;
        }
    }
    void clearData() {
        deque_.clear();
    }
};


#endif //UNTITLED_VECTOR_H
