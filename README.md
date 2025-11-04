Elementary Cellular Automaton

This project implements an elementary cellular automaton simulator in C, which evolves a one-dimensional grid of binary cells (alive = "*", dead = " ") over multiple generations according to a Wolfram rule number between 0 and 255. 

Developed as part of coursework in Computer Science at the University of Nottingham, this program demonstrates structured procedural programming, algorithmic modelling of discrete systems, and dynamic memory management using malloc and calloc in C.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Features

The program accepts user input for the grid size, number of generations, and rule number. It dynamically allocates memory for arrays representing the current and next generations, evolves each generation based on the chosen Wolfram rule, and applies wrap-around boundaries so the leftmost and rightmost cells are neighbours. Each generation is printed to the terminal, using * for live cells and spaces for dead cells, while all allocated memory is correctly freed at the end of execution to prevent leaks, as verified by Valgrind.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example

When compiled with a C compiler such as GCC, the program can be run using the command ./elementary_cellular_automaton <cells> <generations> <rule>. For example, ./elementary_cellular_automaton 30 20 110 produces a 30-cell grid evolving for 20 generations under Rule 110, a well-known automaton that exhibits complex emergent behaviour. The rule number is converted into binary, and each bit represents the outcome for one of the eight possible neighbourhood patterns (000–111). For every cell, the program computes its neighbourhood pattern index k = 4L + 2C + R, then applies the formula S' = floor(W / 2^k) mod 2 to determine whether the cell will be alive ("*") or dead (" ")in the next generation.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Compilation

Ensure a C compiler such as GCC is installed. To compile, run
gcc -Wall -ansi -pedantic -o elementary_cellular_automaton elementary_cellular_automaton.c
Then execute using
./elementary_cellular_automaton <cells> <generations> <rule>

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Usage Notes

The program expects exactly three integer arguments in the order: number of cells (positive integer), number of generations (positive integer), and the Wolfram rule number (integer between 0 and 255). Input validation ensures that all arguments are within range. Invalid or non-integer inputs cause the program to print an error message and exit with a non-zero status code. The automaton output is printed line by line, with each line representing one generation.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Technical Overview

Each cell’s next-generation state is determined by its own value and those of its immediate left and right neighbours. The neighbourhood is converted into a decimal pattern value using the equation
k = 4L + 2C + R,
where L, C, and R represent the left, current, and right cell states respectively. The rule number is then used to determine the new state of the cell using the formula
S' = floor(W / 2^k) mod 2,
where W is the Wolfram rule number. This formula shifts the binary representation of the rule number by k positions and extracts the least significant bit to decide whether the cell will be alive (1) or dead (0) in the next generation.

The program uses integer arithmetic only, without bitwise operators or external libraries. It employs pointer swapping between the current and next generation arrays for efficient memory handling and ensures that all dynamically allocated memory is freed at the end of execution.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Memory Check

To verify memory safety, you can use Valgrind:
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./elementary_cellular_automaton 30 20 110
The final summary should read
ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0).
