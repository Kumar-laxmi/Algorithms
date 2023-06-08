// Path: C++\Searching\bookAllocation.cpp
// Book Allocation Problem:
    // Time Complexity: O(N log M)
    // Space Complexity: O(1) where N is the number of books and M is the total number of pages in all the books.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if it is possible to allocate books with a maximum of maxPages per student
bool isAllocationPossible(const vector<int>& books, int students, int maxPages) {
    int totalStudents = 1;
    int currentPages = 0;

    for (int i = 0; i < books.size(); i++) {
        if (books[i] > maxPages) {
            return false;  // A book has more pages than the maximum allowed per student
        }

        if (currentPages + books[i] > maxPages) {
            totalStudents++;
            currentPages = books[i];
        } else {
            currentPages += books[i];
        }
    }

    return totalStudents <= students;
}

// Function to find the minimum number of pages to allocate books with the given number of students
int allocateBooks(const vector<int>& books, int students) {
    int totalBooks = books.size();
    int totalPages = 0;

    // Calculate the total number of pages in all the books and find the maximum number of pages in a single book
    for (int i = 0; i < totalBooks; i++) {
        totalPages += books[i];
    }

    int start = 0;
    int end = totalPages;
    int result = -1;

    // Perform binary search on the possible range of maximum pages
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if it is possible to allocate books with the current maximum pages
        if (isAllocationPossible(books, students, mid)) {
            result = mid;
            end = mid - 1;  // Look for a smaller value in the lower half
        } else {
            start = mid + 1;  // Look for a larger value in the upper half
        }
    }

    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int minPages = allocateBooks(books, students);

    cout << "Minimum number of pages to allocate: " << minPages << endl;

    return 0;
}

// Output: Minimum number of pages to allocate: 113


/*
// Algorithm: Certainly! Here's a simple algorithm for the Book Allocation Problem:

1. Start with a lower bound `low` as the minimum number of pages in a book and an upper bound `high` as the sum of all the pages in the books.
2. While `low` is less than or equal to `high`, do the following:
   - Set `mid` as the average of `low` and `high`.
   - Check if it is possible to allocate books with `mid` as the maximum number of pages per student using a linear scan of the books.
   - If allocation is possible, update `high` to `mid - 1` to look for a smaller value.
   - If allocation is not possible, update `low` to `mid + 1` to look for a larger value.
3. Return the value of `low` as the minimum number of pages required to allocate the books among the students.

This simple algorithm uses binary search-like techniques to find the minimum number of pages required for book allocation. It iteratively narrows down the search range by adjusting the `low` and `high` bounds based on whether the allocation is possible or not.

Please note that the detailed implementation may vary based on the specific requirements and constraints of the Book Allocation Problem.
*/