import heapq

class Node:
    def __init__(self, state, parent=None, action=None, cost=0, heuristic=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.cost = cost
        self.heuristic = heuristic
        self.priority = cost + heuristic

    def __lt__(self, other):
        return self.priority < other.priority

def astar_search(start_state, goal_state, actions_fn, cost_fn, heuristic_fn):
    open_list = []
    closed_set = set()

    start_node = Node(start_state)
    heapq.heappush(open_list, start_node)

    while open_list:
        current_node = heapq.heappop(open_list)

        if current_node.state == goal_state:
            path = []
            while current_node.parent:
                path.append(current_node.action)
                current_node = current_node.parent
            return list(reversed(path))

        closed_set.add(current_node.state)

        for action in actions_fn(current_node.state):
            new_state = action.execute(current_node.state)
            if new_state in closed_set:
                continue

            new_cost = current_node.cost + cost_fn(action)
            new_heuristic = heuristic_fn(new_state, goal_state)
            new_node = Node(new_state, current_node, action, new_cost, new_heuristic)

            # Check if there is a cheaper path to the same state in the open list
            existing_nodes = [node for node in open_list if node.state == new_state]
            if existing_nodes:
                existing_node = existing_nodes[0]
                if existing_node.cost <= new_cost:
                    continue
                open_list.remove(existing_node)

            heapq.heappush(open_list, new_node)

    return None  # No path found

# Example usage:

# Define your actions, cost function, and heuristic function

class Action:
    def __init__(self, name):
        self.name = name

    def execute(self, state):
        # Implement your action logic here
        pass

def actions_fn(state):
    # Return a list of valid actions for the given state
    pass

def cost_fn(action):
    # Return the cost of performing the given action
    pass

def heuristic_fn(state, goal_state):
    # Return the heuristic estimate from the given state to the goal state
    pass

# Define your start state and goal state
start_state = ...
goal_state = ...

# Call the A* search function
path = astar_search(start_state, goal_state, actions_fn, cost_fn, heuristic_fn)

if path:
    print("Path found:", path)
else:
    print("No path found.")
