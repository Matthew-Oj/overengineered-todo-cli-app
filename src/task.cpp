#include "task.h"
#include <string> 

// Constructor
Task::Task(int id, const std::string& description, bool completed)
    : id(id), description(description), completed(completed) {}

// Getters
int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
bool Task::isComplete() const { return completed; }

// Setters
void Task::setDescription(const std::string& desc) { description = desc; }
void Task::setCompleted(bool value) { completed = value; }

// Helper
void Task::toggleCompleted() { completed = !completed; }