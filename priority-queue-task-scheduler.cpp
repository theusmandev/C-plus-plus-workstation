#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Define a Task structure
struct Task {
    string name;
    int priority;

    // Custom comparator for priority_queue
    bool operator<(const Task& t) const {
        // Higher priority number comes first
        return priority < t.priority;
    }
};

int main() {
    priority_queue<Task> taskQueue;
    int choice;

    do {
        cout << "\n--- Task Scheduler ---\n";
        cout << "1. Add Task\n2. Execute Task\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume newline

        if (choice == 1) {
            Task t;
            cout << "Enter task name: ";
            getline(cin, t.name);
            cout << "Enter priority (higher number = higher priority): ";
            cin >> t.priority;
            cin.ignore();
            taskQueue.push(t);
            cout << "Task added successfully.\n";
        } 
        else if (choice == 2) {
            if (!taskQueue.empty()) {
                Task t = taskQueue.top();
                taskQueue.pop();
                cout << "Executing task: " << t.name 
                     << " (Priority: " << t.priority << ")\n";
            } else {
                cout << "No tasks to execute.\n";
            }
        } 
        else if (choice != 3) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    cout << "Exiting Task Scheduler. Goodbye!\n";
    return 0;
}

