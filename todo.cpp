#include <iostream>

// design
// id : {description: 1, completed: 1 }

class Todo {
    public:
        int id;
        std::string description;
        bool completed; 
};

int main(){
    
    // init 
    Todo todoObj1;
    todoObj1.id = 1;
    todoObj1.description = "Go to the shops";
    todoObj1.completed = false;

    std::cout << todoObj1.description;

    return 0;
}