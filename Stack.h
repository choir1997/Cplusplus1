#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
#include "Deque.h"
#include "Car.h"


template <typename T>
class Stack {
private:
    Deque<T> deque_;
public:
    void push(T data) {
        return deque_.push_back(data);
    }
    void pop(void) {
        return deque_.pop_back();
    }
    T& top() {
        return deque_.back();
    }
    size_t size() {
        return deque_.size();
    }
    T& at(size_t index) {
        return deque_.at(index);
    }
    string toStringStack() const {
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


#endif //UNTITLED_STACK_H
