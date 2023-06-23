#include <iostream>
#include <vector>

void display(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void beadSort(std::vector<int>& arr) {
    int len = arr.size();
    int i, j, max, sum;
    std::vector<std::vector<unsigned char>> beads(len, std::vector<unsigned char>());

    for (i = 1, max = arr[0]; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (i = 0; i < len; i++) {
        beads[i].resize(max);
        for (j = 0; j < arr[i]; j++) {
            beads[i][j] = 1;
        }
    }

    for (j = 0; j < max; j++) {
        for (sum = i = 0; i < len; i++) {
            sum += beads[i][j];
            beads[i][j] = 0;
        }
        for (i = len - sum; i < len; i++) {
            beads[i][j] = 1;
        }
    }

    for (i = 0; i < len; i++) {
        for (j = 0; j < max && beads[i][j]; j++) {
        }
        arr[i] = j;
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    display(arr);

    beadSort(arr);

    std::cout << "Sorted array: ";
    display(arr);

    return 0;
}