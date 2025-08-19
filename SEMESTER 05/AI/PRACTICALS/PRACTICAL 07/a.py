# Practical 07: Water Jug Problem
# Using Breadth-First Search (BFS) to find the solution

from collections import deque

def water_jug_solution():
    """
    Solves the Water Jug Problem for a 4-litre and 3-litre jug,
    aiming for 2 litres in the 4-litre jug.
    """
    jug1_capacity = 4
    jug2_capacity = 3
    target = 2

    # A queue to store states to visit (jug1, jug2, path)
    queue = deque([((0, 0), [])])
    
    # A set to keep track of visited states to avoid cycles
    visited = set([(0, 0)])

    print("--- Water Jug Problem Solver ---")
    print(f"Capacity: Jug1={jug1_capacity}L, Jug2={jug2_capacity}L")
    print(f"Target: {target}L in Jug1\n")

    while queue:
        (current_state, path) = queue.popleft()
        jug1, jug2 = current_state
        
        # Add the current state to the path for tracking
        current_path = path + [(jug1, jug2)]

        # Check if the target is reached
        if jug1 == target:
            print("Solution Found!")
            for i, state in enumerate(current_path):
                print(f"Step {i}: Jug1={state[0]}L, Jug2={state[1]}L")
            return

        # --- Generate all possible next states ---

        # 1. Fill Jug1
        next_state = (jug1_capacity, jug2)
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, current_path))

        # 2. Fill Jug2
        next_state = (jug1, jug2_capacity)
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, current_path))

        # 3. Empty Jug1
        next_state = (0, jug2)
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, current_path))

        # 4. Empty Jug2
        next_state = (jug1, 0)
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, current_path))

        # 5. Pour from Jug1 to Jug2
        pour_amount = min(jug1, jug2_capacity - jug2)
        next_state = (jug1 - pour_amount, jug2 + pour_amount)
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, current_path))

        # 6. Pour from Jug2 to Jug1
        pour_amount = min(jug2, jug1_capacity - jug1)
        next_state = (jug1 + pour_amount, jug2 - pour_amount)
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, current_path))

    print("No solution found.")

# Run the solver
if __name__ == "__main__":
    water_jug_solution()