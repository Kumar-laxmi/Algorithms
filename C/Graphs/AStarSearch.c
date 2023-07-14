#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point parent;
    double f;
    double g;
    double h;
} Cell;

typedef struct {
    Point point[MAX_SIZE];
    int length;
} Path;

typedef struct {
    Point start;
    Point goal;
    bool isObstacle[ROWS][COLS];
} Map;

void initializeMap(Map* map) {
    // Set all cells as non-obstacle by default
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map->isObstacle[i][j] = false;
        }
    }
    
    // Set obstacles
    map->isObstacle[1][1] = true;
    map->isObstacle[2][2] = true;
    map->isObstacle[3][3] = true;
    
    // Set start and goal points
    map->start.row = 0;
    map->start.col = 0;
    map->goal.row = 4;
    map->goal.col = 4;
}

double calculateHeuristic(Point current, Point goal) {
    // Manhattan distance heuristic
    return abs(current.row - goal.row) + abs(current.col - goal.col);
}

bool isValidPoint(Point point) {
    return (point.row >= 0 && point.row < ROWS && point.col >= 0 && point.col < COLS);
}

bool isObstacle(Map* map, Point point) {
    return map->isObstacle[point.row][point.col];
}

bool isGoal(Point current, Point goal) {
    return (current.row == goal.row && current.col == goal.col);
}

Path findPath(Map* map) {
    int dRow[] = {-1, 1, 0, 0};  // Up, Down, Left, Right
    int dCol[] = {0, 0, -1, 1};  // Up, Down, Left, Right
    
    Cell cells[ROWS][COLS];
    bool isVisited[ROWS][COLS];
    
    // Initialize cells and visited array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j].parent.row = -1;
            cells[i][j].parent.col = -1;
            cells[i][j].f = cells[i][j].g = cells[i][j].h = 0;
            isVisited[i][j] = false;
        }
    }
    
    // Create a priority queue to store cells to be visited
    Point queue[MAX_SIZE];
    int front = 0;
    int rear = 0;
    
    // Enqueue start point
    queue[rear++] = map->start;
    isVisited[map->start.row][map->start.col] = true;
    
    while (front != rear) {
        // Dequeue the front point from the queue
        Point current = queue[front++];
        
        // Check if the current point is the goal
        if (isGoal(current, map->goal)) {
            // Reconstruct the path
            Path path;
            path.length = 0;
            
            while (current.row != -1 && current.col != -1) {
                path.point[path.length++] = current;
                current = cells[current.row][current.col].parent;
            }
            
            return path;
        }
        
        // Generate neighboring points
        for (int i = 0; i < 4; i++) {
            Point neighbor;
            neighbor.row = current.row + dRow[i];
            neighbor.col = current.col + dCol[i];
            
            // Skip if the neighbor is not a valid point or an obstacle
            if (!isValidPoint(neighbor) || isObstacle(map, neighbor))
                continue;
            
            // Calculate tentative g score
            double gScore = cells[current.row][current.col].g + 1;
            
            // Check if the neighbor has not been visited or the new path to it is better
            if (!isVisited[neighbor.row][neighbor.col] || gScore < cells[neighbor.row][neighbor.col].g) {
                // Update cell information
                cells[neighbor.row][neighbor.col].parent = current;
                cells[neighbor.row][neighbor.col].g = gScore;
                cells[neighbor.row][neighbor.col].h = calculateHeuristic(neighbor, map->goal);
                cells[neighbor.row][neighbor.col].f = gScore + cells[neighbor.row][neighbor.col].h;
                
                if (!isVisited[neighbor.row][neighbor.col]) {
                    // Enqueue the neighbor if it has not been visited
                    queue[rear++] = neighbor;
                    isVisited[neighbor.row][neighbor.col] = true;
                }
            }
        }
    }
    
    // No path found
    Path emptyPath;
    emptyPath.length = 0;
    return emptyPath;
}

void printPath(Path path) {
    for (int i = path.length - 1; i >= 0; i--) {
        printf("(%d, %d) ", path.point[i].row, path.point[i].col);
    }
    printf("\n");
}

int main() {
    Map map;
    initializeMap(&map);
    
    Path path = findPath(&map);
    
    if (path.length > 0) {
        printf("Path found: ");
        printPath(path);
    } else {
        printf("No path found.\n");
    }
    
    return 0;
}
