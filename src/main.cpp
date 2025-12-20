#include <iostream>
#include <limits>
#include "../include/todoapp.h"

int main(){
    TodoApp app;

    while (true){
        std::cout << "--- To-Do App ---" << '\n';
        std::cout << "1. Add Task" << '\n';
        std::cout << "2. View Tasks" << '\n';
        std::cout << "3. Delete Task" << '\n';
        std::cout << "4. Toggle Complete" << '\n';
        std::cout << "5. File (Save/Load)" << '\n';
        std::cout << "6. Quit" << '\n';

        int choice; 
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number." << "\n\n";
            continue; 
        }

        if (choice == 1){
            // Add Task 
            std::string desc;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter a description: ";
            std::getline(std::cin, desc);
            app.add_task(desc);
        } else if (choice == 2){
            // View Tasks 
            app.view_task();

        } else if (choice == 3){
            // Delete Task
            int task_id;
            std::cout << "Enter task id: ";
            std::cin >> task_id; 
            app.delete_task(task_id);

        } else if (choice == 4){
            // Toggle task
            int task_id;
            std::cout << "Enter task id: ";
            std::cin >> task_id;
            app.toggle_task(task_id); 

        } else if (choice == 5){

        
        } else if (choice == 6){
            // Quit App
            std::cout << "Goodbye!";
            break;
        } else {
            std::cout << "Invalid choice. Try again" << '\n';
            continue;
        }
    };

    return 0;
}