/**
 * Project: Smart Task Scheduling System
 * Author: Vaseekaran A (711525BEV057)
 * Department: EE – VLSI Design & Technology
 * Course: Data Structures
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to define a Task
struct Task {
    int id;
    string name;
    int priority; // Higher value = Higher priority

    // Display task details in a formatted row
    void display() const {
        cout << "| " << setw(5) << id << " | " 
             << setw(20) << name << " | " 
             << setw(10) << priority << " |" << endl;
    }
};

class SmartScheduler {
private:
    vector<Task> heap;
    const string storageFile = "task_data.txt";

    // Maintain Max-Heap property after insertion
    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2].priority < heap[index].priority) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Maintain Max-Heap property after extraction
    void heapifyDown(int index) {
        int maxIdx = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left].priority > heap[maxIdx].priority)
            maxIdx = left;
        if (right < heap.size() && heap[right].priority > heap[maxIdx].priority)
            maxIdx = right;

        if (index != maxIdx) {
            swap(heap[index], heap[maxIdx]);
            heapifyDown(maxIdx);
        }
    }

public:
    SmartScheduler() {
        loadFromFile();
    }

    void addTask(int id, string name, int priority) {
        Task newTask = {id, name, priority};
        heap.push_back(newTask);
        heapifyUp(heap.size() - 1);
        saveToFile();
        cout << "\n[Success] Task added and synchronized with storage.\n";
    }

    void executeHighestPriority() {
        if (heap.empty()) {
            cout << "\n[Error] No tasks in the queue.\n";
            return;
        }

        cout << "\n[Executing] Task: " << heap[0].name << " (ID: " << heap[0].id << ")\n";
        
        // Move last element to root and heapify down
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        
        saveToFile();
    }

    void displayAllTasks() {
        if (heap.empty()) {
            cout << "\nQueue is currently empty.\n";
            return;
        }

        cout << "\n" << string(45, '-') << "\n";
        cout << "| " << setw(5) << "ID" << " | " << setw(20) << "Task Name" << " | " << setw(10) << "Priority" << " |\n";
        cout << string(45, '-') << "\n";
        for (const auto& t : heap) {
            t.display();
        }
        cout << string(45, '-') << "\n";
    }

    void saveToFile() {
        ofstream outFile(storageFile);
        for (const auto& t : heap) {
            outFile << t.id << " " << t.priority << " " << t.name << "\n";
        }
        outFile.close();
    }

    void loadFromFile() {
        ifstream inFile(storageFile);
        if (!inFile) return;

        Task t;
        while (inFile >> t.id >> t.priority) {
            getline(inFile >> ws, t.name);
            heap.push_back(t);
        }
        inFile.close();
        // Rebuild heap to ensure integrity
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }
};

int main() {
    SmartScheduler scheduler;
    int choice;

    while (true) {
        cout << "\n======================================";
        cout << "\n SMART TASK SCHEDULING SYSTEM (C++)";
        cout << "\n======================================";
        cout << "\n1. Add New Task";
        cout << "\n2. Execute Next (Highest Priority)";
        cout << "\n3. View All Pending Tasks";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1: {
                int id, prio;
                string name;
                cout << "Enter Task ID: "; cin >> id;
                cout << "Enter Task Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Priority (1-100): "; cin >> prio;
                scheduler.addTask(id, name, prio);
                break;
            }
            case 2:
                scheduler.executeHighestPriority();
                break;
            case 3:
                scheduler.displayAllTasks();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

