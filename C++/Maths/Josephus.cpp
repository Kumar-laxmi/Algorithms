#include <iostream>
#include <list>
using namespace std;

// Josephus Problem Algorithm:
// 1. Create a circular list to represent the circle of people.
// 2. Initialize the list with people numbered from 1 to n.
// 3. Start with an iterator pointing to the first person.
// 4. Repeat the elimination process until only one person remains:
//     a. Move the iterator k-1 steps in a circular manner.
//     b. Erase the person at the current position.
//     c. Update the iterator to the next position after the elimination, wrapping around if necessary.
// 5. Return the position of the last remaining person.

int josephus(int n, int k) {
    list<int> circle;
    for (int i = 1; i <= n; ++i) {
        circle.push_back(i);  // Initialize the circle with people numbered from 1 to n
    }

    auto it = circle.begin();  // Iterator pointing to the current person
    while (circle.size() > 1) {  // Continue until only one person remains
        for (int count = 1; count < k; ++count) {
            ++it;  // Move the iterator k-1 steps in a circular manner
            if (it == circle.end()) {
                it = circle.begin();  // Wrap around to the beginning if the end is reached
            }
        }

        it = circle.erase(it);  // Eliminate the person at the current position
        if (it == circle.end()) {
            it = circle.begin();  // Wrap around to the beginning if the end is reached after elimination
        }
    }

    return circle.front();  // Return the position of the last remaining person
}

int main() {
    int n;  // Number of people in the circle
    int k;   // Elimination step size
    cout<<"Enter n and k "<<endl;
    cin>>n>>k;
    int last_person = josephus(n, k);  // Solve the Josephus Problem
    cout << "The last remaining person is at position: " << last_person <<endl;

    return 0;
}
