#include "todoapp.h"

// Default constructor
TodoApp::TodoApp() : next_id(1) {}

// Add a new task
void TodoApp::add_task(const std::string& description) {
    tasks.push_back(Task(next_id, description));
    next_id++;
    std::cout << "Task added!" << "\n\n";
}

// View all tasks
void TodoApp::view_task() const {
    if (tasks.empty()) {
        std::cout << "No tasks yet" << "\n\n";
    } else {
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << tasks[i].getId() << ". " << tasks[i].getDescription() << '\n';
        }
    std::cout << "\n\n";
    }
}

// Delete a task by id -
void TodoApp::delete_task(int task_id) {
    // Find the task with matching ID
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&](const Task& task) { return task.getId() == task_id; });

    if (it != tasks.end()) {
        // Erase it
        tasks.erase(it);
        std::cout << "Task deleted!\n\n";
    } else {
        std::cout << "Invalid task id!\n\n";
    }
}

// Toggle task 
void TodoApp::toggle_task(int task_id) {
    if (tasks.empty()) {
        std::cout << "No tasks added!\n\n";
        return;
    }

    // Find the task by ID
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&](const Task& t) { return t.getId() == task_id; });

    if (it == tasks.end()) {
        std::cout << "Invalid task id!\n\n";
        return;
    }

    bool is_completed = it->toggleCompleted();

    if (is_completed) {
        std::cout << "Task marked as completed!\n\n";
    } else {
        std::cout << "Task marked as incomplete!\n\n";
    }
}
