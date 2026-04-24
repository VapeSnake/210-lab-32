// COMSC-210 | Lab 32 | Noel Mier-Luna
#include <iostream>
#include "Car.H"
#include <deque>

using namespace std;

const int START_CARS = 2; // Number of cars to start with in the deque

int main() {
    srand(time(0)); // Seed the random number generator. Now Car objects are randomly generated.
    deque<Car> Cars; // Create a deque that holds Car objects.
    // Add some cars to the deque
    for (int i = 0; i < START_CARS; i++) {
        Cars.push_back(Car());
    }

    // Print the cars in the deque
    cout << "Initial cars in the deque:\n";
    for (int i = 0; i < Cars.size(); i++) {
        Cars[i].print(); // Printed using operator[] to access each Car object in the deque and call its print() method.
    }
    cout << endl;
    cout << "Demonstrating deque operations:\n";
    // Add a new car to the front of the deque
    Car newCar;
    Cars.push_front(newCar);
    cout << "After adding a new car to the front:\n";
    for (int i = 0; i < Cars.size(); i++) {
        Cars[i].print();
    }
    cout << endl;
    // Remove a car from the back of the deque  
    Cars.pop_back();
    cout << "After removing a car from the back:\n";
    for (int i = 0; i < Cars.size(); i++) {
        Cars[i].print();
    }
    // Peek at front and back cars
    cout << "\nPeeking at the front car:\n";
    Cars.front().print(); // Using front() to access the first car in the deque and print it.
    cout << "\nPeeking at the back car:\n";
    Cars.back().print(); // Using back() to access the last car in the deque and print it.
    



}
