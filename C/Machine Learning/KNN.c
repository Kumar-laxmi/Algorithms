/* K-nearest algorithm is an example of supervised learning algorithm . It assumes that the similarity between
the new instance and the data point puts the new instance to the category it is most suitable
I have considered Iris dataset features Sepal Length , Sepal Width with 3 classes mainly 
Setosa (1) , Virginica(2) and Versicolor(3)
https://www.youtube.com/watch?v=Vk9lGGODaJA  -->You can refer that example here */

#include <stdio.h>
#include <math.h>
#define MAX_DATA_COUNT 100

// Euclidean Distance is used to calculate distance between new instance and data point 
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int data_count, i, j, K;
    double data[MAX_DATA_COUNT][3]; // x, y, and label
    double distances[MAX_DATA_COUNT];
    int nearest_neighbors[MAX_DATA_COUNT] = {0};
    double x, y;
    int label_counts[20] = {0};


    // To get the information about number of data points , store them in 2d array. 
    printf("Enter the number of data points: ");
    scanf("%d", &data_count);
    printf("Enter the data points (x, y, and label):\n");
    for (i = 0; i < data_count; i++) {
        scanf("%lf%lf%lf", &data[i][0], &data[i][1], &data[i][2]);
    }

    printf("Enter the point for which KNN needs to be performed: ");
    scanf("%lf%lf", &x, &y);
    printf("Enter the value of K: ");
    scanf("%d", &K);

    // Calculate the distances
    for (i = 0; i < data_count; i++) {
        distances[i] = euclidean_distance(x, y, data[i][0], data[i][1]);
         printf("\nDistance between (%.2lf , %.2lf) and  (%.2lf  %.2lf) is %.2lf\n" , x , y ,data[i][0], data[i][1] ,  distances[i]);
    }

    // Find the K nearest neighbors
    for (i = 0; i < K; i++) {
        int min_index = -1;
        double min_distance = -1.0;
        for (j = 0; j < data_count; j++) {
            if (nearest_neighbors[j] == 0) {
                if (min_index == -1 || distances[j] < min_distance) {
                    min_index = j;
                    min_distance = distances[j];
                }
            }
        }
        nearest_neighbors[min_index] = 1;
    }

    // Print the K nearest neighbors
    printf("The %d nearest neighbors are:\n", K);
    for (i = 0; i < data_count; i++) {
        if (nearest_neighbors[i] == 1) {
            printf("(%.2lf, %.2lf) with label %.2lf\n", data[i][0], data[i][1], data[i][2]);
            label_counts[(int) data[i][2]]++;
        }
    }

    // To determine the label of the new instance
    int  count ;
    int label = -1;
    for (i = 0; i < 20; i++) {
            if(label_counts[i] > count )
             count = label_counts[i];
             label = i+1;
            printf("\nThe new instance  belongs to the class%d",label);
            return 0;
        }

}
