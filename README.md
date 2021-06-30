# push_swap

## Installation
```
git clone --recurse-submodules git@github.com:daisvke/push_swap.git
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
   ◦ a contains a random number of either positive or negative numbers without any duplicates.<br />
   ◦ b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:<br />
  sa: swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.<br />
  sb: swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.<br />
  ss: sa and sb at the same time.<br />
  pa: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.<br />
  pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.<br />
  ra: rotate a - shift up all elements of stack a by 1. The first element becomes the last one.<br />
  rb: rotate b - shift up all elements of stackbby 1. The first element becomes the last one.<br />
  rr: ra and rb at the same time.<br />
  rra: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.<br />
  rrb: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.<br />
  rrr :rra and rrb at the same time.
