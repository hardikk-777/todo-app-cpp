#include <iostream>
#include <vector>
#include <string>
#include <limits> // for numeric_limits

using namespace std;

class Task {
public:
    string description;
    bool isDone;

    Task(string desc) {
        description = desc;
        isDone = false;
    }

    void markDone() {
        isDone = true;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(string desc) {
        tasks.push_back(Task(desc));
        cout << "Task added!\n";
    }

    void showTasks() {
        if (tasks.empty()) {
            cout << "No tasks yet!\n";
            return;
        }
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". [" << (tasks[i].isDone ? "x" : " ") << "] "
                 << tasks[i].description << "\n";
        }
    }

    void markTaskDone(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markDone();
            cout << "Task marked as done!\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task deleted.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
};

int main() {
    TodoList todo;
    int choice;
    string desc;
    int index;

    while (true) {
        cout << "\n=== TODO MENU ===\n";
        cout << "1. Add Task\n2. Show Tasks\n3. Mark as Done\n4. Delete Task\n5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear(); // clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
            cout << "Please enter a valid number.\n";
            continue;
        }

        cin.ignore(); // discard newline after choice input

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, desc);
                todo.addTask(desc);
                break;
            case 2:
                todo.showTasks();
                break;
            case 3:
                cout << "Task number to mark done: ";
                cin >> index;
                todo.markTaskDone(index - 1);
                break;
            case 4:
                cout << "Task number to delete: ";
                cin >> index;
                todo.deleteTask(index - 1);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
}
