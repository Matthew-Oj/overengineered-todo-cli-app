#include "todoapp.h"

// Default constructor
TodoApp::TodoApp() : next_id(1) {}

// Add a new task
void TodoApp::add_task(const std::string& description) {
    tasks.push_back(Task(next_id, description));
    next_id++;
    std::cout << "Task added!" << '\n';
}

// View all tasks
void TodoApp::view_task() const {
    if (tasks.empty()) {
        std::cout << "No tasks yet" << '\n';
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            std::cout << tasks[i].getId() << ". " << tasks[i].getDescription() << '\n';
        }
    }
}

// Delete a task by id
void TodoApp::delete_task(int task_id) {
    if (task_id > 0 && task_id <= tasks.size()) {
        tasks.erase(tasks.begin() + (task_id - 1));
        std::cout << "Task deleted!" << '\n';
    } else {
        std::cout << "Invalid task id!" << '\n';
    }
}
