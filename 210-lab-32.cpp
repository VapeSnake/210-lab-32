// COMSC-210 | Lab 33 Branch | Noel Mier-Luna
#include <iostream>
#include "Car.H"
#include <deque>
#include <array>

using namespace std;

const int START_CARS = 2;   // Number of cars to start with in the deque
const int MAX_PERIODS = 20; // Max number of time periods for program.
const int MAX_LANES = 4;    // Max number of lanes at the toll booth.

int main() {
    srand(time(0)); // Seed the random number generator. Now Car objects are randomly generated.
    // Create an array to hold deques of car objects to simulate 4 lanes.
    array < deque < Car > , MAX_LANES > Lanes;
    cout << "Initial queue:\n"; // Print the initial state of the toll booth before any cars are added.
    for (int i = 0; i < MAX_LANES; i++) { // Outer loop iterates through each lane.
        for (int j = 0; j < START_CARS; j++) { // Inner loop adds START_CARS number of cars to each lane at the start of the program.
            Lanes[i].push_back(Car()); // Add START_CARS number of cars to each lane at the start of the program.
        }
        cout << "Lane " << i + 1 << ":\n"; // Print the initial state of each lane after adding cars.
        for (auto & car: Lanes[i]) {
            car.print(); // Print each car in the lane.
        }
    }
    int time = 1; // Time counter to compare to MAX_PERIODS.
    while (time <= MAX_PERIODS) { // Loop repeats 20 times.
        cout << "\nTime: " << time << "\n"; // Print the current time period at the start of each loop iteration.
        // First For loop will handle 50/50 chance car leaves. Second For loop will display queues of each lane.
        for (int i = 0; i < MAX_LANES; i++) {
            int randomNum = rand() % 100; // Generate a random number between 0 and 99 to determine if a car joins, leaves, or switches lanes.
            if (randomNum < 46) // 46% chance car joins.
            {
                Lanes[i].push_back(Car()); // Adds new car to back of lane.
                cout << "Lane " << i + 1 << " Joined: "; // Print which lane a car joined.
                cout << "   ";
                Lanes[i].back().print(); // Print the car that just joined the lane.
            } else if ((randomNum < 85) && !Lanes[i].empty()) // 39% chance car leaves if lane has cars.
            {
                cout << "Lane " << i + 1 << " Paid: "; // Print which lane a car paid and left.
                cout << "   ";
                Lanes[i].front().print(); // Print the car that is about to leave the lane.
                Lanes[i].pop_front(); // Remove the first car from the lane as it has been processed.
            } else // 15% chance rear car switches to a different lane.
            {
                int switchLane = rand() % MAX_LANES; // Randomly select a lane from 1 to 4 for the car to switch to.
                if (!Lanes[i].empty()) // Bug fix: Checks first if current lane is empty before trying to switch. Skips if there are no cars to switch.
                { // This loop ensures that car doesn't switch to same lane and checks if current lane has cars to be able to switch lanes.
                    while (switchLane == i) {
                        switchLane = rand() % MAX_LANES; // Changes switchLane to new random lane until a switch is available.
                    } //
                    Lanes[switchLane].push_back(Lanes[i].back()); // Add the car that is switching to the back of the new lane.
                    Lanes[i].pop_back(); // Remove the car from the original lane as it has switched to a new lane.
                    cout << "Lane " << i + 1 << " Switched to Lane " << switchLane + 1 << ": "; // Print which lane a car switched from.
                    cout << "   ";
                    Lanes[switchLane].back().print(); // Print the car that just switched lanes.
                } else {
                    cout << "Lane " << i + 1 << " Empty\n"; // Print message if lane is empty and cannot switch lanes.
                }
            }
        }
        for (int i = 0; i < MAX_LANES; i++) { // Display the current state of each lane after processing joins/leaves.
            cout << "Lane " << i + 1 << " Queue:"; // Print the lane number before listing cars in that lane.
            if (Lanes[i].empty()) { // If lane is empty, print that it is empty and skip to next lane.
                cout << " empty.\n";
            } else { // If lane is not empty, print each car in the lane.
                cout << "\n"; // New line for better readability before listing cars in the lane.
                for (auto & car: Lanes[i]) {
                    cout << "   "; // Indent car details for better readability.
                    car.print(); // Print each car currently in the lane.
                }
            }
        }
        time++; // Increment time counter at the end of each loop iteration.
    }
}
