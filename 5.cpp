#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Show menu
void showMenu() {
    cout << "\n=== TO-DO LIST MENU ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose option: ";
}

// Add a task
void addTask(vector<Task> &tasks) {
    Task t;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, t.description);
    t.completed = false;
    tasks.push_back(t);
    cout << "? Task added!\n";
}

// View tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "\n--- Your Tasks ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "?" : "?") << "] "
             << tasks[i].description << '\n';
    }
}

// Mark task completed
void completeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    int num;
    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "? Invalid task number.\n";
    } else {
        tasks[num - 1].completed = true;
        cout << "?? Task marked as completed!\n";
    }
}

// Remove task
void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    int num;
    viewTasks(tasks);
    cout << "Enter task number to remove: ";
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "? Invalid task number.\n";
    } else {
        cout << "?? Removing: " << tasks[num - 1].description << '\n';
        tasks.erase(tasks.begin() + (num - 1));
    }
}

// Main program
int main() {
    vector<Task> taskList;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(taskList); break;
            case 2: viewTasks(taskList); break;
            case 3: completeTask(taskList); break;
            case 4: removeTask(taskList); break;
            case 5: cout << "Goodbye! ??\n"; break;
            default: cout << "? Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
