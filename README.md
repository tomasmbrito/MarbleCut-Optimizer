# MarbleCut-Optimizer
Dynamic programming solution for maximizing profit from marble slab cuts based on client requests.

# MarbleCut Optimizer 🪨✂️

An algorithmic solution to optimize marble slab cutting and maximize profit based on client demands. Developed in **C++**, this project applies **dynamic programming** to efficiently calculate the highest value obtainable by cutting a marble slab into smaller pieces according to predefined dimensions and prices.

---

## 🧩 Problem Overview

In a marble factory, a rectangular marble slab needs to be cut into smaller pieces requested by clients. Each requested piece has:
- Specific dimensions (`ai × bi`).
- An associated price (`pi`).

The cutting process works as follows:
- The slab can be cut **horizontally** or **vertically** from one side to the other.
- Each resulting sub-slab can either be cut again or counted as a valid piece if it matches any requested dimensions.
- Multiple copies of the same piece are allowed if it increases the profit.

The objective is to calculate the **maximum total profit** from cutting the initial slab.

---

## 🚀 Features

- **Dynamic Programming Optimization**  
  Stores solutions to subproblems to avoid redundant calculations and maximize efficiency.

- **Recursive Cut Handling**  
  Supports all valid horizontal and vertical cuts for every sub-slab.

- **Flexible Input**  
  Accepts any valid rectangular slab and set of requested pieces.

---

## 📥 Input

The program reads from standard input:
1. The dimensions of the marble slab (`X Y`).
2. The number of requested piece types (`n`).
3. `n` lines with the dimensions and price of each piece (`ai bi pi`).

#### Example:
```
3 20
3
2 2 4
1 5 10
3 7 20
```

---

## 📤 Output

A single integer representing the **maximum profit** that can be obtained from the slab. If no valid pieces can be produced, the output is `0`.

#### Example output for the input above:
```
120
```

---

## ⚙️ How to Run

### Compile:
```bash
g++ -std=c++11 -O3 -Wall marblecut.cpp -o marblecut
```

### Execute:
```bash
./marblecut < input.txt
```

---

## 🧰 Technologies
- **Language**: C++
- **Libraries**:
  - `vector` for dynamic matrix representation.
  - Standard input/output for file handling.

---
