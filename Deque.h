#ifndef UNTITLED_DEQUE_H
#define UNTITLED_DEQUE_H
#include <string>
#include <sstream>
#include <iostream>
#include "Car.h"
#include "DequeInterface.h"

using namespace std;

template<typename T>
class Deque : public DequeInterface<T> {
private:
    unsigned int capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    T* the_data;
public:
    Deque(void) : capacity(DEFAULT_CAPACITY), num_items(0), front_index(-1), rear_index(-1), the_data(new T[DEFAULT_CAPACITY]) {}
    ~Deque() { clear(); }

    void push_front(const T& dataValue) {
        if (num_items == capacity) {
            reallocate();
        }
        if ((front_index == 0 && rear_index == capacity - 1) || front_index == rear_index + 1) {
            return;
        }
        else if ((front_index == -1 && rear_index == -1)) {
            front_index = 0;
            rear_index = 0;
            the_data[front_index] = dataValue;
        }
        else if (front_index == 0) {
            front_index = capacity - 1;
            the_data[front_index] = dataValue;
        }
        else {
            front_index--;
            the_data[front_index] = dataValue;
        }
        num_items++;
    }
    void push_back(const T& carValue) {
        if (num_items == capacity) {
            reallocate();
        }
        if ((front_index == 0 && rear_index == capacity - 1) || front_index == rear_index + 1) {
            return;
        }
        else if ((front_index == -1 && rear_index == -1)) {
            front_index = 0;
            rear_index = 0;
            the_data[rear_index] = carValue;
        }
        else if (rear_index == capacity - 1) {
            rear_index = 0;
            the_data[rear_index] = carValue;
        }
        else {
            rear_index++;
            the_data[rear_index] = carValue;
        }
        num_items++;
    }
    void pop_front() {
        if (front_index == -1 && rear_index == -1) {
            return;
        }
       else if (front_index == rear_index) {
           front_index = rear_index = - 1;
       }
       else if (front_index == capacity - 1) {
           front_index = 0;
       }
       else {
           front_index++;
       }
       num_items--;
    }
    void pop_back() {
        if (empty()) {
            return;
        }
        else if (front_index == rear_index) {
            front_index = rear_index = -1;
        }
        else if (rear_index == 0) {
            rear_index = capacity - 1;
        }
        else {
            rear_index--;
        }
        num_items--;

    }
    T& front(void) {
        return the_data[front_index];
    }
    T& back(void) {
        return the_data[rear_index];
    }
    size_t size() const {
        return num_items;
    }
    bool empty() const {
        return num_items == 0;
    }
    T& at(size_t index) {
        return the_data[(front_index + index) % capacity];
    }

    string toString() const {
        int i = front_index;
        ostringstream printString;
        if (empty()) {
            return printString.str();
        }
        while (i != rear_index) {
            printString << the_data[i] << " ";
            i = (i + 1) % capacity;
        }
        printString << the_data[rear_index];

        return printString.str();
    }
    int findCar(const T& carToFind) {
        int i = front_index;
        int j = rear_index;

        for (int i = front_index; i < num_items; i++) {
            if (the_data[i] == carToFind) {
                cout << "FOUND";
                return i;
            }
            i = (i + 1) % capacity;
        }

        return -1;
    }
    void reallocate() {
        size_t new_capacity = 2 * capacity;
        T* new_data = new T[new_capacity];
        size_t j = front_index;
        for (size_t i = 0; i < num_items; i++) {
            new_data[i] = the_data[j];
            j = (j + 1) % capacity;
        }
        front_index = 0;
        rear_index = num_items - 1;
        capacity = new_capacity;
        std::swap(the_data, new_data);

        delete[] new_data;
    }
    void clear() {
        delete[] the_data;
    }
};

#endif //UNTITLED_DEQUE_H
