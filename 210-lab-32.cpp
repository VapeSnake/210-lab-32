// COMSC-210 | Lab 32 | Noel Mier-Luna
#include <iostream>
#include "Car.H"
#include <deque>

using namespace std;

const int START_CARS = 2; // Number of cars to start with in the deque

int main()
{
    srand(time(0));  // Seed the random number generator. Now Car objects are randomly generated.
    deque<Car> Cars; // Create a deque that holds Car objects.
    // Add some cars to the deque
    cout << "Initial queue of cars at toll booth:\n";
    for (int i = 0; i < START_CARS; i++)
    {
        Cars.push_back(Car());
    }
    // Print the cars in the deque
    for (int i = 0; i < Cars.size(); i++)
    {
        Cars[i].print(); // Printed using operator[] to access each Car object in the deque and call its print() method.
    }
    cout << endl;
    int time = 1; // Time counter to simulate time periods at toll booth.
    while (!Cars.empty())
    { // Loop continues until the toll has no cars left in line using .empty() method.
        if (100 * rand() % 100 < 55)
        { // 55% chance new car arrives at toll booth A.K.A push_back() new car object.
            Cars.push_back(Car());
            cout << "Time " << time << "Operation: Car joined lane: ";
            Cars.back().print(); // Peek at last car added.
            for (int i = 0; i < Cars.size(); i++)
            {
                Cars[i].print(); // Print the current state of the queue after a new car joins.
            }
        }
        else
        { // 45% chance a car is processed and leaves the toll booth A.K.A pop_front() first car in line.
            cout << "Time " << time << "Operation: Car paid: ";
            Cars.front().print();     // Peek at first car in line that is about to leave.
            Cars.pop_front().print(); // Remove the first car from the deque as it has been processed.
            for (int i = 0; i < Cars.size(); i++)
            {
                Cars[i].print(); // Print the current state of the queue after a car leaves.
            }
        }
    }
}
