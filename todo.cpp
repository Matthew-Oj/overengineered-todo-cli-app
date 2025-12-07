#include <iostream>
#include <vector>
#include <limits>

struct Task {
    private:
        int id ;
        std::string description;
        bool completed;

    public:
        // Constructor
        Task(int id, std::string description, bool completed = false)
        : id(id), description(description), completed(completed) {}

        // Getters
        int getId() const {
            return id;
        }

        std::string getDescription() const {
            return description;
        }

        bool isComplete() const {
            return completed;
        }
        
        // Setters
        void setDescription(const std::string desc) {
            description = desc;
        }

        void setCompleted(bool value) {
            completed = value;
        }

        // Optional helper
        void toggleCompleted() {
            completed = !completed;
        } 
};

struct TodoApp {
    private:
        std::vector<Task> tasks;
        int next_id = 1; 

    public:
        void add_task(std::string description){
            tasks.push_back(Task(next_id, description));
            next_id++;
            std::cout << "Task added!" << '\n';
        }
        
        void view_task(){
            if (tasks.empty()){
                std::cout << "No tasks yet" << '\n';
            } else {
                for (int i = 0; i < tasks.size(); i++){
                    std::cout << tasks[i].getId() << ". " << tasks[i].getDescription() << '\n';
                }
            }
        }

        void delete_task(int task_id){
            tasks.erase(tasks.begin() + (task_id - 1));
        }
};

int main(){
    TodoApp app;

    while (true){
        std::cout << "--- To-Do App ---" << '\n';
        std::cout << "1. Add Task" << '\n';
        std::cout << "2. View Tasks" << '\n';
        std::cout << "3. Delete Task" << '\n';
        std::cout << "4. Toggle Complete" << '\n';
        std::cout << "5. Quit" << '\n';

        int choice; 
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number.\n";
            continue; 
        }

        if (choice == 1){
            std::string desc;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter a description: ";
            std::getline(std::cin, desc);
            app.add_task(desc);
        } else if (choice == 2){
            app.view_task();

        } else if (choice == 3){
            int task_id;
            std::cout << "Enter task id: ";
            std::cin >> task_id; 
            app.delete_task(task_id);

        } else if (choice == 4){
            // toggle task

        } else if (choice == 5){
            std::cout << "Goodbye!";
            break;
        } else {
            std::cout << "Invalid choice. Try again" << '\n';
            continue;
        }
    };

    return 0;
}