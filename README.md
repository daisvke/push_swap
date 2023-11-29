# push_swap

## Description

* This program sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.<br />
It uses various types of algorithms such as the radix sort.
* It uses the following algorithms:<br />
   - for < 80 elements to sort: **insertion sort**
   - for >= 80 elements : **radix sort**<br />
   which corresponds to the grades below:
      - 4/5 pts for 100 elements to sort
      - 3/5 pts for 500 elements

## Installation

```
git clone --recurse-submodules https://github.com/daisvke/push_swap.git
cd push_swap
make
```

## Performance

| Elements | Average | Max |
|------|------|------|
| 3 | 1 | 2 |
| 5 | 7 | 10 |
| 100 | 1081 | 1081 |
| 500 | 6778 | 6778 |

## Game rules

* The game is composed of 2 stacks named a and b.
* To start with:<br />
   - a contains a random number of either positive or negative numbers without any duplicates.<br />
   - b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:<br />
  **sa: swap a** - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.<br />
  **sb: swap b** - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.<br />
  **ss:** sa and sb at the same time.<br />
  **pa: push a** - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.<br />
  **pb: push b** - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.<br />
  **ra: rotate a** - shift up all elements of stack a by 1. The first element becomes the last one.<br />
  **rb: rotate b** - shift up all elements of stackbby 1. The first element becomes the last one.<br />
  **rr:** ra and rb at the same time.<br />
  **rra: reverse rotate a** - shift down all elements of stack a by 1. The last element becomes the first one.<br />
  **rrb: reverse rotate b** - shift down all elements of stack b by 1. The last element becomes the first one.<br />
  **rrr:** rra and rrb at the same time.

## ft_printnode

The ft_printnode function allows to check the state of the stacks at any moment.
<p align=center>
   <img src="/screenshots/push-swap-output.png" width="40%" />
</p>

## Checker
* checker will get as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack. If no argument is given checker stops and displays nothing.
* checker will then wait and read instructions on the standard input, each instruction will be followed by '\n'. Once all the instructions have been read, checker will execute them on the stack received as an argument.
* If after executing those instructions, stack a is actually sorted and bis empty, then checker displays "OK" followed by a '\n' on the standard output. In every other case, checker displays "KO" followed by a '\n' on the standard output.
* In case of error, checker displays "Error" followed by a '\n' on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn't exist and/or is incorrectly formatted.

<p align=center>
   <img src="/screenshots/push-swap-and-checker-output.png" width="40%" />
</p>
