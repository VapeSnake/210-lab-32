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
    cout << "Initial queue of cars at toll booth:\n";
    for (int i = 0; i < START_CARS; i++) {
        Cars.push_back(Car());
    }
    // Print the cars in the deque
    for (int i = 0; i < Cars.size(); i++) {
        Cars[i].print(); // Printed using operator[] to access each Car object in the deque and call its print() method.
    }
    cout << endl;
   
    
    

}
