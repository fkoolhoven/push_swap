<div align="center">

  <h1>PUSH_SWAP</h1>
  
  <p>
    This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.
  </p>
</div>
  

# About the Project

A project made in accordance with the push_swap project which is part of the Codam Core Curriculum. It is a very simple and a highly straightforward algorithm project: a list of integers must be sorted. You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks. Your goal? Write a program in C called push_swap which calculates and displays
on the standard output the smallest program, made of push_swap language instructions, that sorts the integers received as arguments.

# The Rules

The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
sb (swap b): Swap the first 2 elements at the top of stack b.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
pb (push b): Take the first element at the top of a and put it at the top of b.
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

# Getting Started

Start by cloning the repository:
```c
https://github.com/fkoolhoven/push_swap.git
```

Compile by using make:
```c
make
```

# Usage

```c
./push_swap [list of ints]
```
For example:
```c
./push_swap  2 10 3 6 5 8 -31 0
```

# My Solution

# Important Learnings

# Contact

See my profile page for ways to contact me!
