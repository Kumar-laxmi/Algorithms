#include <iostream>
#include <vector>
#include <algorithm>

void pigeonholeSort(std::vector<int>& arr) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max - min + 1;
    std::vector<int> pigeonholes(range, 0);

    for (int i = 0; i < arr.size(); i++) {
        pigeonholes[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (pigeonholes[i] > 0) {
            arr[index++] = i + min;
            pigeonholes[i]--;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    pigeonholeSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
