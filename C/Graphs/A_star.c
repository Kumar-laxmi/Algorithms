#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point parent;
    int f;
    int g;
    int h;
} Node;

Node grid[ROWS][COLS];
bool closedList[ROWS][COLS];
Point start, end;

void init()
{
    // Initialize grid with default values
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j].f = 0;
            grid[i][j].g = 0;
            grid[i][j].h = 0;
            grid[i][j].parent.x = -1;
            grid[i][j].parent.y = -1;
        }
    }

    // Set start and end points
    start.x = 0;
    start.y = 0;
    end.x = ROWS - 1;
    end.y = COLS - 1;

    // Set obstacles
    grid[2][2].f = -1;
    grid[2][3].f = -1;
    grid[2][4].f = -1;
    grid[3][4].f = -1;
    grid[4][4].f = -1;
    grid[5][4].f = -1;
    grid[6][4].f = -1;
    grid[7][4].f = -1;
}

bool isValid(Point p)
{
    // Check if point is within the grid
    if (p.x < 0 || p.x >= ROWS || p.y < 0 || p.y >= COLS)
        return false;

    // Check if point is not an obstacle
    if (grid[p.x][p.y].f == -1)
        return false;

    return true;
}

bool isDestination(Point p)
{
    // Check if point is the destination
    if (p.x == end.x && p.y == end.y)
        return true;

    return false;
}

int calculateHValue(Point p)
{
    // Calculate Manhattan distance between current point and end point
    int h = abs(p.x - end.x) + abs(p.y - end.y);
    return h;
}

void aStar()
{
    // Initialize openList with start point
    Point current = start;
    grid[current.x][current.y].h = calculateHValue(current);
    grid[current.x][current.y].f = grid[current.x][current.y].g + grid[current.x][current.y].h;
    grid[current.x][current.y].parent.x = current.x;
    grid[current.x][current.y].parent.y = current.y;
    Node openList[ROWS * COLS];
    int openListCount = 1;
    openList[0] = grid[current.x][current.y];

    while (openListCount > 0)
    {
        // Find node with lowest f value in openList
        int lowestIndex = 0;
        for (int i = 0; i < openListCount; i++)
        {
            if (openList[i].f < openList[lowestIndex].f)
                lowestIndex = i;
        }

        // Remove current node from openList and add it to closedList
        Node current = openList[lowestIndex];
        openList[lowestIndex] = openList[openListCount - 1];
        openListCount--;
        closedList[current.parent.x][current.parent.y] = true;

        // Generate successors of current node
        Point successors[4] = {{current.parent.x - 1, current.parent.y}, {current.parent.x + 1, current.parent.y}, {current.parent.x, current.parent.y - 1}, {current.parent.x, current.parent.y + 1}};

        for (int i = 0; i < 4; i++)
        {
            Point successor = successors[i];
            if (isValid(successor) && !closedList[successor.x][successor.y])
            {
                int g = current.g + 1;
                int h = calculateHValue(successor);
                int f = g + h;
                Node child = grid[successor.x][successor.y];

                // Add child to openList if it is not already there
                bool inOpenList = false;
                for (int j = 0; j < openListCount; j++)
                {
                    if (openList[j].parent.x == successor.x && openList[j].parent.y == successor.y)
                    {
                        inOpenList = true;
                        break;
                    }
                }

                if (!inOpenList || f < child.f)
                {
                    child.f = f;
                    child.g = g;
                    child.h = h;
                    child.parent.x = current.parent.x;
                    child.parent.y = current.parent.y;

                    if (!inOpenList)
                    {
                        openList[openListCount] = child;
                        openListCount++;
                    }
                    else
                    {
                        for (int j = 0; j < openListCount; j++)
                        {
                            if (openList[j].parent.x == successor.x && openList[j].parent.y == successor.y)
                            {
                                openList[j] = child;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void printPath()
{
    // Traverse parent nodes from end to start and print the path
    Point current = end;
    while (!(current.x == start.x && current.y == start.y))
    {
        printf("(%d,%d) ", current.x, current.y);
        current = grid[current.x][current.y].parent;
    }
    printf("(%d,%d)\n", start.x, start.y);
}

int main()
{
    init();
    aStar();
    printPath();
    return 0;
}
