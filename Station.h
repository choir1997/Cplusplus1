#ifndef UNTITLED_STATION_H
#define UNTITLED_STATION_H
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"
#include "Deque.h"
#include "Car.h"

template <typename T>
class Station {
private:
    Vector<T> train;
    Stack<T> stack;
    Queue<T> queue;
    T turnTableCar;
    bool empty;

public:
    Station() { this->empty = true; }
    ~Station() {}

    string addCar(const T& newCar) {
        if (!empty) {
            throw string("Turntable occupied!");
        }
        else {
            turnTableCar = newCar;
            empty = false;
            return "OK";
        }
    }
    string removeCar() {
        if (!empty) {
            train.push_back(turnTableCar);
            empty = true;
        }
        else {
            throw string("Turntable empty!");
        }
        return "OK";
    }
    string topCar() {
        if (empty) {
            throw string("Turntable empty!");
        }
        else {
            return "OK";
        }
    }
    string addStack() {
        if (empty) {
            throw string("Turntable empty!");
        }
        else {
            stack.push(turnTableCar);
            empty = true;
            return "OK";
        }
    }
    string removeStack() {
        if (!empty) {
            throw string("Turntable occupied!");
        }
        if (stack.size() == 0) {
            throw string("Stack empty!");
        }
        else {
            turnTableCar = stack.top();
            stack.pop();
            empty = false;
            return "OK";
        }
    }
    T& topStack() {
        if (stack.size() == 0) {
            throw string("Stack empty!");
        }
        return stack.top();
    }
    size_t sizeStack() {
        return stack.size();
    }
    string addQueue() {
        if (empty) {
            throw string("Turntable empty!");
        }
        else {
            queue.push(turnTableCar);
            empty = true;
            return "OK";
        }
    }
    string removeQueue() {
        if (!empty) {
            throw string("Turntable occupied!");
        }
        if (queue.size() == 0) {
            throw string("Queue empty!");
        }
        else {
            turnTableCar = queue.top();
            queue.pop();
            empty = false;
            return "OK";
        }
    }
    T& topQueue() {
        if (queue.size() == 0) {
            throw string("Queue empty!");
        }
        return queue.top();
    }
    size_t sizeQueue() {
        return queue.size();
    }
    size_t sizeTrain() {
        return train.size();
    }
    void find(T carToFind) {
        if (!empty && turnTableCar == carToFind) {
            cout << "Turntable" << endl;
        }
        else {
            if (stack.isFound(carToFind) != -1) {
                cout << "Stack[" << stack.isFound(carToFind) << "]" << endl;
            }
            else if (train.isFound(carToFind) != -1) {
                cout << "Train[" << train.isFound(carToFind) << "]" << endl;
            }
            else if (queue.isFound(carToFind) != -1) {
                cout << "Queue[" << queue.isFound(carToFind) << "]" << endl;
            }
        }
    }
    //TODO: display contents of vector
    string toStringTrain() const {
        return train.toStringTrain();
    }
    string toStringStack() const {
        return stack.toStringStack();
    }
    string toStringQueue() const {
        return queue.toStringQueue();
    }
};


#endif //UNTITLED_STATION_H
