def todo_manager(todo_list, command, item=None):
    """
    Manages a todo list based on the provided command.

    Args:
        todo_list: A list of to-do items.
        command: The command to execute ('add', 'remove', 'complete').
        item: The item to add, remove, or complete (optional).

    Returns:
        The modified todo list.
        Returns error message when invalid command is given or item is not found in remove or complete.
    """

    if command == 'add':
        if item is not None:
            todo_list.append(item)
        else:
            return "Error: Item must be provided for 'add' command."
    elif command == 'remove':
        if item is not None:
            if item in todo_list:
                todo_list.remove(item)
            else:
                return f"Error: Item '{item}' not found in the todo list."
        else:
            return "Error: Item must be provided for 'remove' command."

    elif command == 'complete':
        if item is not None:
            if item in todo_list:
                todo_list.remove(item)
                todo_list.append(f"[Completed] {item}")
            else:
                return f"Error: Item '{item}' not found in the todo list."
        else:
            return "Error: Item must be provided for 'complete' command."

    else:
        return "Error: Invalid command. Use 'add', 'remove', or 'complete'."

    return todo_list

# Example usage:
my_todo_list = ["Buy groceries", "Pay bills", "Write report"]

print("Initial list:", my_todo_list)

result = todo_manager(my_todo_list, "add", "Call dentist")
print("After adding:", result)

result = todo_manager(my_todo_list, "remove", "Pay bills")
print("After removing:", result)

result = todo_manager(my_todo_list, "complete", "Write report")
print("After completing:", result)

result = todo_manager(my_todo_list, "invalid", "anything")
print("After invalid command:", result)

result = todo_manager(my_todo_list, "remove")
print("after remove without specifying item:", result)

result = todo_manager(my_todo_list, "complete", "nonexistent item")
print("after completing non existent item:", result)