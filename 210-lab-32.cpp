// COMSC-210 | Lab 32 | Noel Mier-Luna
#include <iostream>
#include "Car.H"
#include <deque>
#include <array>

using namespace std;

const int START_CARS = 2; // Number of cars to start with in the deque
const int MAX_PERIODS = 20; // Max number of time periods for program.
const int MAX_LANES = 4; // Max number of lanes at the toll booth.

int main() {
    srand(time(0)); // Seed the random number generator. Now Car objects are randomly generated.
    // Create an array to hold deques of car objects to simulate 4 lanes.
    array <deque<Car>, MAX_LANES> Lanes;
    for (int i = 0; i < MAX_LANES; i++) { // Outer loop iterates through each lane.
        for (int j = 0; j < START_CARS; j++) {
            Lanes[i].push_back(Car()); // Add START_CARS number of cars to each lane at the start of the program.
        }
        cout << "Initial state of lane " << i + 1 << ":\n"; // Print the initial state of each lane after adding cars.
        for (auto & car: Lanes[i]) {
            car.print(); // Print each car in the lane.
        }
    }
    cout << endl;
    cout << "--- TESTING DEQUE OPERATIONS ---\n";
    cout << ""

    /*
    int time = 1; // Time counter to simulate time periods at toll booth.
    while (!Cars.empty()) { // Loop continues until the toll has no cars left in line using .empty() method.
        if (rand() % 100 < 55) { // 55% chance new car arrives at toll booth A.K.A push_back() new car object.
            Cars.push_back(Car());
            cout << "Time: " << time << " Operation: Car joined lane: ";
            Cars.back().print(); // Peek at last car added.
            for (auto & car: Cars) {
                car.print(); // Print the current state of the queue after a new car joins.
            }
            time++;
        } else { // 45% chance a car is processed and leaves the toll booth A.K.A pop_front() first car in line.
            cout << "Time: " << time << " Operation: Car paid: ";
            Cars.front().print(); // Peek at first car in line that is about to leave.
            Cars.pop_front(); // Remove the first car from the deque as it has been processed.
            for (auto & car: Cars) {
                car.print(); // Print the current state of the queue after a car leaves.
            }
            time++; // Increment time after each operation to simulate the passage of time at the toll booth.
        }
    }
        */
}