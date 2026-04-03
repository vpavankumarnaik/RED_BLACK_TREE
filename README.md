# RED_BLACK_TREE

## Overview
This project implements a **Red-Black Tree (RBT)** in C.  
A Red-Black Tree is a **self-balancing binary search tree** that maintains balanced height using specific rules and properties. This ensures efficient operations such as insertion, deletion, and searching with **O(log n)** time complexity.

This project was developed as part of my learning program at **Emertxe** to gain practical experience with advanced data structures.

## Features
The program is menu-driven and supports the following operations:

1. Insert a node into the tree
2. Display the Red-Black Tree
3. Search for a node
4. Find the minimum element
5. Find the maximum element
6. Delete a node
7. Delete the minimum node
8. Delete the maximum node
9. Exit the program

## Red-Black Tree Properties
The implementation maintains the following Red-Black Tree rules:

- Every node is either **Red** or **Black**
- The **root node is always Black**
- Red nodes cannot have red children
- Every path from root to leaf has the same number of black nodes
- New nodes are inserted as **Red**

To maintain these properties, the program performs:
- **Left rotations**
- **Right rotations**
- **Recoloring of nodes**

## Concepts Used
- Binary Search Trees
- Self-balancing trees
- Tree rotations
- Dynamic memory allocation
- Pointers and structures in C

## Technologies Used
- Programming Language: **C**
- Platform: **Linux / GCC Compiler**


## Learning Outcome
Through this project, I gained a deeper understanding of:
- Advanced data structures
- Efficient tree balancing techniques
- Implementation of complex algorithms in C

## How to Run
gcc *.c
./a.out
