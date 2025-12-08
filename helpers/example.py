# Simple To-Do App in Python using Classes

class Task:
    def __init__(self, id, description, is_completed=False):
        self.id = id
        self.description = description
        self.is_completed = is_completed

    def __str__(self):
        status = "✔" if self.is_completed else "✘"
        return f"[{self.id}] {self.description} - {status}"

class ToDoApp:
    def __init__(self):
        self.tasks = []
        self.next_id = 1

    def add_task(self, description):
        self.tasks.append(Task(self.next_id, description))
        self.next_id += 1
        print("Task added!")

    def view_tasks(self):
        if not self.tasks:
            print("No tasks yet.")
        else:
            for task in self.tasks:
                print(task)

    def delete_task(self, task_id):
        for task in self.tasks:
            if task.id == task_id:
                self.tasks.remove(task)
                print("Task deleted!")
                return
        print("Task not found.")

    def toggle_task(self, task_id):
        for task in self.tasks:
            if task.id == task_id:
                task.is_completed = not task.is_completed
                print("Task status updated!")
                return
        print("Task not found.")

app = ToDoApp()

while True:
    print("--- To-Do App ---")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Delete Task")
    print("4. Toggle Complete")
    print("5. Quit")

    choice = input("Choose an option: ")

    if choice == "1":
        desc = input("Enter a description: ")
        app.add_task(desc)

    elif choice == "2":
        app.view_tasks()

    elif choice == "3":
        try:
            task_id = int(input("Enter task id: "))
            app.delete_task(task_id)
        except ValueError:
            print("Invalid id.")

    elif choice == "4":
        try:
            task_id = int(input("Enter task id: "))
            app.toggle_task(task_id)
        except ValueError:
            print("Invalid id.")

    elif choice == "5":
        print("Goodbye!")
        break

    else:
        print("Invalid choice. Try again.")
