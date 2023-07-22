#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

// Structure to represent a node in the search tree
struct Node {
    int x, y;        // Coordinates of the node
    int g, h, f;     // Cost function values (g: actual cost, h: heuristic cost, f: total cost)
    Node* parent;    // Pointer to the parent node

    Node(int x_, int y_) : x(x_), y(y_), g(0), h(0), f(0), parent(nullptr) {}

    // Calculate the heuristic cost using Manhattan distance
    int heuristic(const Node& goal) const {
        return abs(x - goal.x) + abs(y - goal.y);
    }

    // Calculate the total cost f = g + h
    void calculateCost(const Node& goal) {
        h = heuristic(goal);
        f = g + h;
    }
};

// Custom comparator for the priority queue (min-heap)
struct CompareNodes {
    bool operator()(const Node* a, const Node* b) {
        return a->f > b->f;
    }
};

// A* search algorithm
vector<Node*> aStarSearch(const vector<vector<int>>& grid, const pair<int, int>& start, const pair<int, int>& goal) {
    // Dimensions of the grid
    int rows = grid.size();
    int cols = grid[0].size();

    // Valid moves (up, down, left, right)
    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Priority queue (min-heap) to store the open nodes
    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;

    // Create start and goal nodes
    Node* startNode = new Node(start.first, start.second);
    Node* goalNode = new Node(goal.first, goal.second);

    // Initialize the cost values of the start node
    startNode->g = 0;
    startNode->calculateCost(*goalNode);

    // Add the start node to the open set
    openSet.push(startNode);

    // Map to store the visited nodes
    map<pair<int, int>, Node*> visited;

    // A* search algorithm
    while (!openSet.empty()) {
        // Get the node with the minimum total cost from the open set
        Node* current = openSet.top();
        openSet.pop();

        // Check if the current node is the goal node
        if (current->x == goalNode->x && current->y == goalNode->y) {
            vector<Node*> path;
            Node* node = current;

            // Generate the path by backtracking from the goal node to the start node
            while (node != nullptr) {
                path.push_back(node);
                node = node->parent;
            }
            reverse(path.begin(), path.end());

            // Clean up memory (delete nodes in the open set)
            while (!openSet.empty()) {
                delete openSet.top();
                openSet.pop();
            }

            // Clean up memory (delete nodes in the visited set)
            for (const auto& pair : visited)
                delete pair.second;

            return path;
        }

        // Generate child nodes by exploring the valid moves
        for (const auto& move : moves) {
            int newX = current->x + move.first;
            int newY = current->y + move.second;

            // Check if the new coordinates are within the grid boundaries
            if (newX < 0 || newX >= rows || newY < 0 || newY >= cols)
                continue;

            // Check if the new position is blocked (wall)
            if (grid[newX][newY] == 1)
                continue;

            // Create a new child node
            Node* child = new Node(newX, newY);
            child->parent = current;
            child->g = current->g + 1;
            child->calculateCost(*goalNode);

            // Check if the child node has been visited or has a higher total cost
            if (visited.find(make_pair(newX, newY)) != visited.end() && child->f >= visited[make_pair(newX, newY)]->f) {
                delete child;
                continue;
            }

            // Add the child node to the open set
            openSet.push(child);

            // Add the child node to the visited set
            visited[make_pair(newX, newY)] = child;
        }
    }

    // If the open set becomes empty and the goal node is not reached, there is no path
    // Clean up memory (delete nodes in the open set)
    while (!openSet.empty()) {
        delete openSet.top();
        openSet.pop();
    }

    // Clean up memory (delete nodes in the visited set)
    for (const auto& pair : visited)
        delete pair.second;

    return {};  // Return an empty path
}

// Function to print the path cost and the coordinates of nodes in the path
void printPath(const vector<Node*>& path) {
    cout << "Path: " << path.size() - 1 << endl;
    cout << "[";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << "(" << path[i]->x << ", " << path[i]->y << ")";
        if (i < path.size() - 1)
            cout << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Example grid (0: empty, 1: wall)
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Start and goal positions
    pair<int, int> start = make_pair(1, 1);
    pair<int, int> goal = make_pair(8, 8);

    // Run A* search algorithm
    vector<Node*> path = aStarSearch(grid, start, goal);

    // Print the path cost and the coordinates of nodes in the path
    printPath(path);

    // Clean up memory (delete nodes in the path)
    for (const auto& node : path)
        delete node;

    return 0;
}
