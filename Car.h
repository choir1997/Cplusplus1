#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H
#include <string>
#include <sstream>
#include "Car.h"

using namespace std;

struct Car {
    unsigned int id;
    Car() {}
    Car(int carValue) : id(carValue) {}
    ~Car() {}

    //TODO: comparing two cars
    bool operator==(const Car car) { return this->id == car.id; }
    bool operator!=(const Car car) { return this->id != car.id;}

    //Todo: converts car to string
    string toString() const {
        stringstream out;
        out << id;
        return out.str();
    }

    friend ostream& operator<< (ostream& os, const Car& c) {
        os << c.toString();
        return os;
    }

};



#endif //UNTITLED_CAR_H
