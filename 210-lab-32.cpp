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
    cout << "Initial queue:\n"; // Print the initial state of the toll booth before any cars are added.
    for (int i = 0; i < MAX_LANES; i++) { // Outer loop iterates through each lane.
        for (int j = 0; j < START_CARS; j++) {
            Lanes[i].push_back(Car()); // Add START_CARS number of cars to each lane at the start of the program.
        }
        cout << "Lane " << i + 1 << ":\n"; // Print the initial state of each lane after adding cars.
        for (auto & car: Lanes[i]) {
            car.print(); // Print each car in the lane.
        }
    }
    // Milestone 4: Only coding 50/50 probability of car joining/leaving for all lanes.
    int time = 1; // Time counter to compare to MAX_PERIODS.
    while (time <= MAX_PERIODS) { // Loop repeats 20 times.
        cout << "\nTime: " << time << "\n"; // Print the current time period at the start of each loop iteration.
        for (int i = 0; i < MAX_LANES; i++) { // Outer loop iterates through each lane.
            if (rand() % 2 == 0) { // 50% chance to test if car joins lane.
                Lanes[i].push_back(Car()); // Add a new car to the back of the current lane.
                cout << "Lane " << i + 1 << ": " << " Joined: ";
                Lanes[i].back().print(); // Peek at the last car added to the lane.
                cout << "Lane " << i + 1 << " Queue:\n"; // Print the current state of the lane after a new car joins.
                for (auto & car: Lanes[i]) {
                    cout << "  ";
                    car.print(); // Print each car in the lane.
                }
            } else if (!Lanes[i].empty()) { // 50% chance car pays and leaves the lane.
                cout << "Lane " << i + 1 << ": " << " Paid: ";
                Lanes[i].front().print(); // Peek at the first car in line that is about to leave.
                Lanes[i].pop_front(); // Remove the first car from the lane as it has been processed.
                cout << "Lane " << i + 1 << " Queue:\n"; // Print the current state of the lane after a car leaves.
                    for (auto & car: Lanes[i]) {
                        cout << "  ";
                        car.print(); // Print each car in the lane.
                    }
                } else {
                    cout << "Lane " << i + 1 << " Queue: empty\n"; // If lane is empty, print message indicating no cars to process.
                }
            }
        time++; // Increment time after processing all lanes to simulate the passage of time at the toll booth.
        }
    }

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