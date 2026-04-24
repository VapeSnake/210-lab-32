#include <iostream>
#include "Car.H"
#include <deque>

using namespace std;

const int START_CARS = 2; // Number of cars to start with in the deque

int main() {

    deque<Car> Cars; // Create a deque that holds Car objects.
    // Add some cars to the deque
    for (int i = 0; i < START_CARS; i++) {
        Cars.push_back(Car());
    }

    // Print the cars in the deque
    cout << "Initial cars in the deque:\n";
    for (int i = 0; i < Cars.size(); i++) {
        Cars[i].print(); // Print each car's details using operator[] to access the car in the deque
    }




}
