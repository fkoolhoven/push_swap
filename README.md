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
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

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
Given that highest marks were achieved by using the least amount of commands, slower algorithms that read the data more times could be more precise than algortihms optimised for speed. The goal was to minimize the amount of operations.

To solve this "puzzle" I wrote my own algorithm . It is a combination of a form of patience sort and a sort of merging algorithm. First I find the longest list of ascending numbers in stack_a and in the remaining numbers I find the longest list of descending numbers. I seperate these lists in a way so that stack_a is already fully sorted and stack_b will be "somewhat sorted", which will make the merging more efficient. Then to merge the stacks I check which number in stack_b would take the least amount of operations to move to it's correct position in stack_a. I merge the stacks and do a final rotation of stack_a to get the smallest number at the top.

My algorithm was minimized the amount of moves sufficiently to pass this project with 100%.


# Important Learnings

1. I represented the two stacks as two way linked lists (with a previous and next node pointer). I gained hands-on experience with linked lists and list manipulation.
2. I learned about complexity and big-O notation.
3. I learned about various sorting algorithms.

# Contact

See my profile page for ways to contact me!
