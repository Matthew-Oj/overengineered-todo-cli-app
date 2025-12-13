#pragma once
#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    // Constructor
    Task(int id, const std::string& description, bool completed = false);

    // Getters
    int getId() const;
    std::string getDescription() const;
    bool isComplete() const;

    // Setters
    void setDescription(const std::string& desc);
    void setCompleted(bool value);

    // Optional helper
    bool toggleCompleted();
};