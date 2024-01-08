#include <iostream>

using namespace std;

const int MAX_TASKS = 100; 

struct Task {
    string description;
};

void display(const Task tasks[], int count) {
    cout << "\n To-Do List \n";
    if (count == 0) {
        cout << "No tasks available.\n";
    } else {
        for (int i = 0; i < count; ++i) {
            cout << i + 1 << ". " << tasks[i].description << endl;
        }
    }
}

void Add(Task tasks[], int& count, const string& description) {
    if (count < MAX_TASKS) {
        Task newTask{description};
        tasks[count++] = newTask;
        cout << "Task added successfully.\n";
    } else {
        cout << "Task list is full. Cannot add more tasks.\n";
    }
}

void Delete(Task tasks[], int& count, int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        count--;
        cout << "Task deleted successfully.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    while (true) {
        cout << "\nOptions:\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Quit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore(); 
                getline(cin, description);
                Add(tasks, taskCount, description);
                break;
            }
            case 2:
                display(tasks, taskCount);
                break;
            case 3: {
                display(tasks, taskCount);
                cout << "Enter task index to delete: ";
                int index;
                cin >> index;
                Delete(tasks, taskCount, index - 1); 
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
