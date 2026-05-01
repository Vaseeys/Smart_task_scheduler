# Smart Task Scheduling System 🚀

An academic project developed for the **Data Structures** course, implementing an efficient task manager using a **Binary Max-Heap** priority queue.

## 📌 Overview
This system simulates a real-time task scheduler where tasks are executed based on their priority rather than their arrival time. This is a fundamental concept used in Operating Systems and Cloud Task Management.

## ✨ Features
- **Priority-Based Execution:** Uses a Max-Heap to ensure $O(\log n)$ insertion and $O(\log n)$ extraction of the highest priority task.
- **Persistent Storage:** Integrated file handling (`task_data.txt`) to save and reload tasks automatically.
- **Scalable Design:** Built using C++ vectors to handle dynamic memory allocation.
- **Robust Interface:** Clean, menu-driven console UI with formatted tabular output.

## 🛠️ Data Structures Used
- **Binary Max-Heap:** The core engine for priority management.
- **Array-based Mapping:** Vector implementation for efficient element access.
- **Structure (Struct):** Custom `Task` object to store Metadata (ID, Name, Priority).

## 🚀 How to Run
1. Ensure you have a C++ compiler installed (GCC/Clang/MSVC).
2. Clone this repository:
   ```bash
   git clone [https://github.com/Vaseeys/smart-task-scheduler.git](https://github.com/Vaseeys/smart-task-scheduler.git)
   
