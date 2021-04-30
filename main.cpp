#include <iostream>
#include <fstream>
#include <sstream>
#include "Deque.h"
#include "DequeInterface.h"
#include "Station.h"
#include "Car.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    Station<Car> newStation;


    //TODO: Read input files
    for (string line; getline(in, line);) {
        string commandLine1, commandLine2;
        int dataValue = 0;
        if (line.empty()) continue;
        out << endl << line;
        istringstream iss(line);
        getline(iss, commandLine1, ':');

        try {
            if (commandLine1 == "Add") {
                iss >> commandLine2;
                iss >> dataValue;
                Car createCar = Car(dataValue);
                if (commandLine2 == "station") {
                   out << " " << newStation.addCar(createCar);
                } else if (commandLine2 == "queue") {
                    out << " " << newStation.addQueue();
                } else if (commandLine2 == "stack") {
                    out << " " << newStation.addStack();
                }
            }
            else if (commandLine1 == "Remove") {
                iss >> commandLine2;
                if (commandLine2 == "station") {
                    out << " " << newStation.removeCar();
                } else if (commandLine2 == "queue") {
                    out << " " << newStation.removeQueue();
                } else if (commandLine2 == "stack") {
                    out << " " << newStation.removeStack();
                }
            }
            else if (commandLine1 == "Train") {
                iss >> commandLine2;
                out << " " << newStation.toStringTrain();
            }
            else if (commandLine1 == "Size") {
                iss >> commandLine2;
                if (commandLine2 == "queue") {
                    out << " " << newStation.sizeQueue();
                } else if (commandLine2 == "stack") {
                    out << " " << newStation.sizeStack();
                } else if (commandLine2 == "train") {
                    out << " " << newStation.sizeTrain();
                }
            }
            else if (commandLine1 == "Top") {
                iss >> commandLine2;
                if (commandLine2 == "station") {
                    out << " " << newStation.topCar();
                }
                if (commandLine2 == "queue") {
                    out << " " << newStation.topQueue();
                } else if (commandLine2 == "stack") {
                    out << " " << newStation.topStack();
                }
            }
            else if (commandLine1 == "Find") {
                int carToFind;
                iss >> carToFind;
                newStation.find(dataValue);
            }
            else if (commandLine1 == "Stack") {
                cout << "processing...";
                out << " " << newStation.toStringStack();
            }
            else if (commandLine1 == "Queue") {
                out << " " << newStation.toStringQueue();
            }

        }
        catch (string& exceptionString) {
            out << exceptionString;
        }

    }

    return 0;
}
