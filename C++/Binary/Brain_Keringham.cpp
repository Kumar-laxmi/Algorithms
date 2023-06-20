#include <iostream>

//Brian Kerningham's Algorithm in CPP
int setBits(int n)
{
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    std::cout << setBits(15);
    return 0;   
}