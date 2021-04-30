#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H
#include "Deque.h"
#include "Car.h"

using namespace std;

template <typename T>
class Queue {
private:
    Deque<T> deque_;
public:
    void push(T car) {
        return deque_.push_back(car);
    }
    void pop(void) {
        return deque_.pop_front();
    }
    T& top() {
        return deque_.front();
    }
    size_t size() {
        return deque_.size();
    }
    string toStringQueue() const {
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


#endif //UNTITLED_QUEUE_H
