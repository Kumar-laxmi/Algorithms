import java.util.*;

class Node {
    int x, y; // coordinates of the node
    int g; // cost from start node to current node
    int h; // heuristic cost from current node to goal node
    int f; // total cost (g + h)
    Node parent; // parent node

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class AStarsearch {
    private static final int[][] GRID = {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
    };

    private static final int[][] DELTAS = {
            {-1, 0}, // up
            {0, -1}, // left
            {1, 0}, // down
            {0, 1} // right
    };

    private static boolean isValid(int x, int y) {
        int numRows = GRID.length;
        int numCols = GRID[0].length;
        return x >= 0 && x < numRows && y >= 0 && y < numCols && GRID[x][y] == 0;
    }

    private static int heuristic(int x, int y, int goalX, int goalY) {
        return Math.abs(x - goalX) + Math.abs(y - goalY);
    }

    public static List<Node> findPath(Node start, Node goal) {
        PriorityQueue<Node> openSet = new PriorityQueue<>(Comparator.comparingInt(node -> node.f));
        Set<Node> closedSet = new HashSet<>();
        openSet.add(start);

        while (!openSet.isEmpty()) {
            Node current = openSet.poll();
            closedSet.add(current);

            if (current.x == goal.x && current.y == goal.y) {
                // goal node reached, construct and return the path
                List<Node> path = new ArrayList<>();
                while (current != null) {
                    path.add(current);
                    current = current.parent;
                }
                Collections.reverse(path);
                return path;
            }

            for (int[] delta : DELTAS) {
                int newX = current.x + delta[0];
                int newY = current.y + delta[1];

                if (isValid(newX, newY)) {
                    Node neighbor = new Node(newX, newY);
                    neighbor.g = current.g + 1;
                    neighbor.h = heuristic(newX, newY, goal.x, goal.y);
                    neighbor.f = neighbor.g + neighbor.h;
                    neighbor.parent = current;

                    if (closedSet.contains(neighbor)) {
                        continue;
                    }

                    Node existingNode = findNodeInSet(openSet, neighbor);
                    if (existingNode == null) {
                        openSet.add(neighbor);
                    } else if (neighbor.g < existingNode.g) {
                        existingNode.g = neighbor.g;
                        existingNode.f = neighbor.f;
                        existingNode.parent = neighbor.parent;
                    }
                }
            }
        }

        // no path found
        return null;
    }

    private static Node findNodeInSet(PriorityQueue<Node> set, Node target) {
        for (Node node : set) {
            if (node.x == target.x && node.y == target.y) {
                return node;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Node start = new Node(0, 0);
        Node goal = new Node(4, 4);

        List<Node> path = findPath(start, goal);
        if (path != null) {
            System.out.println("Path found:");
            for (Node node : path) {
                System.out.println("(" + node.x + ", " + node.y + ")");
            }
        } else {
            System.out.println("No path found.");
        }
    }
}
