# Karger's Algorithm (Minimum Cut)

This repository contains an implementation of Karger's algorithm in Python. Karger's algorithm is a randomized algorithm used to find the minimum cut in an undirected, unweighted, and connected graph.

## Algorithm Overview

Karger's algorithm is a Monte Carlo randomized algorithm that works by iteratively contracting random edges of the graph until only two vertices (or subsets) remain. The algorithm then counts the number of remaining edges between the two subsets, which represents the minimum cut of the original graph.

The algorithm follows these steps:

1. Create subsets for each vertex.
2. Keep contracting random edges until only two subsets remain.
3. Count the number of remaining edges between the two subsets.
4. Return the minimum cut found.

## Implementation Details

The implementation is done in Python and consists of the following components:

- `Edge` class: Represents an unweighted edge in the graph.
- `Graph` class: Represents a connected, undirected, and unweighted graph as a collection of edges.
- `Subset` class: Represents a subset for the Union-Find algorithm used in Karger's algorithm.
- `find` function: Finds the subset to which a particular vertex belongs (uses path compression technique).
- `union` function: Performs the union of two subsets (uses union by rank).
- `karger_min_cut` function: Implements Karger's algorithm to find the minimum cut in the graph.
- `main` function: Driver program to test the algorithm.

## Usage

To use the Karger's algorithm implementation, follow these steps:

1. Ensure that Python 3.x is installed on your system.
2. Clone the repository or download the source code.
3. Open a terminal or command prompt and navigate to the directory containing the source code.
4. Run the command `python karger.py` to execute the program.
5. The program will output the minimum cut found in the graph.

## Example

```python
# Create a graph with 4 vertices and 5 edges
V = 4
E = 5
graph = Graph(V, [Edge(0, 1), Edge(0, 2), Edge(0, 3), Edge(1, 2), Edge(2, 3)])

# Run Karger's algorithm to find the minimum cut
min_cut = karger_min_cut(graph)
print("Minimum cut found by Karger's algorithm:", min_cut)
