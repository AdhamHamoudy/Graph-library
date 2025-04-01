# Graph_TKNOT_2 - Adham Hamoudy

## 📌 Description
This C++ project implements an **undirected graph using an adjacency list** with basic algorithms like:

- **BFS.**
- **DFS.**
- **Dijkstra's Algorithm**
- **Prim's MST**
- **Kruskal's MST**

The implementation avoids STL containers and uses **basic arrays and pointers only**, as required.

---

## 📂 File Structure
```
Graph_TKNOT_2/
├── Graph.h / Graph.cpp       # Graph class and adjacency list logic
├── Algorithms.h / Algorithms.cpp   # All graph algorithms
├── main.cpp                 # Demo file (creates and runs algorithms)
├── test.cpp                 # Unit tests using doctest
├── doctest.h                # Header-only testing framework
├── Makefile                 # Build, test, valgrind commands
├── README.md                # You're reading this
```

---

## 🧪 How to Build and Run
### 📌 Requirements
- Linux or WSL/Unix-like terminal
- `g++` (C++ compiler)
- `valgrind` (for memory leak checks)

### 🔨 Compile & Run
```bash
make main     
./main
```

### 🧪 Run Unit Tests
```bash
make test
```

### 🧠 Check for Memory Leaks
```bash
make valgrind
```

### 🧹 Clean Build Files
```bash
make clean
```

---

## 📧 Author
**Adham Hamoudy**  
Email: `adhamhamoudy3@gmail.com`

---

## ✅ Notes
- STL is completely avoided — implemented `Queue`, `Union-Find`, and sorting manually
- The project is modular, readable, and commented
- Fully valgrind-safe

> For more info, visit: [GitHub Repository](https://github.com/AdhamHamoudy/Graph_TKNOT_2)

