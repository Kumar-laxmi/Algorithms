#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct {
    double x;
    double y;
} Point;

double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void kmeans(int k, Point *data, int data_size, int *assignments, Point *centroids) {
    for (int i = 0; i < k; i++) {
        centroids[i] = data[i];
    }

    int changed;
    do {
        changed = 0;
        for (int i = 0; i < data_size; i++) {
            int closest_centroid = -1;
            double closest_distance = DBL_MAX;

            for (int j = 0; j < k; j++) {
                double distance = euclidean_distance(data[i], centroids[j]);
                if (distance < closest_distance) {
                    closest_distance = distance;
                    closest_centroid = j;
                }
            }

            if (assignments[i] != closest_centroid) {
                assignments[i] = closest_centroid;
                changed = 1;
            }
        }

        for (int i = 0; i < k; i++) {
            int count = 0;
            Point sum = {0, 0};

            for (int j = 0; j < data_size; j++) {
                if (assignments[j] == i) {
                    count++;
                    sum.x += data[j].x;
                    sum.y += data[j].y;
                }
            }

            if (count > 0) {
                centroids[i].x = sum.x / count;
                centroids[i].y = sum.y / count;
            }
        }
    } while (changed);
}

int main() {
    int k = 3;
    Point data[] = {
        {1, 1},
        {1, 2},
        {2, 1},
        {2, 2},
        {8, 8},
        {8, 9},
        {9, 8},
        {9, 9},
    };
    int data_size = sizeof(data) / sizeof(data[0]);
    int assignments[data_size];
    Point centroids[k];

    kmeans(k, data, data_size, assignments, centroids);

    for (int i = 0; i < data_size; i++) {
        printf("Point (%f, %f) belongs to cluster %d\n", data[i].x, data[i].y, assignments[i]);
    }

    for (int i = 0; i < k; i++) {
        printf("Centroid %d: (%f, %f)\n", i, centroids[i].x, centroids[i].y);
    }

    return 0;
}
