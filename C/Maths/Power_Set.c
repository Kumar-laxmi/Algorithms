#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generatePowerSet(int originalSet[], int numElements) {
    int numSubsets = pow(2, numElements);

    for (int i = 0; i < numSubsets; i++) {
        printf("{ ");
        for (int j = 0; j < numElements; j++) {
            if ((i & (1 << j)) != 0) {
                printf("%d ", originalSet[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    int numElements;
    printf("Enter the number of elements in the original set: ");
    scanf("%d", &numElements);

    int originalSet[numElements];
    printf("Enter the elements of the original set: ");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &originalSet[i]);
    }

    printf("Power Set:\n");
    generatePowerSet(originalSet, numElements);

    return 0;
}