#pragma once
#include <string>
#include <vector>
#include "task.h"
#include <iostream>

class TodoApp {
private:
    std::vector<Task> tasks;
    int next_id = 1;

public:
    // Constructor
    TodoApp();  // default constructor

    void add_task(const std::string& description);
    void view_task() const;
    void delete_task(int task_id);
};
