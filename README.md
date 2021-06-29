# push_swap

## Performance

* 3 elements<br />
   average  : 1 move<br />
   max      : 2 moves
* 5 elements<br />
   average  : 7 moves<br />
   max      : 10 moves
* 100 elements<br />
   average  : 1081 moves<br />
   max      : 1081 moves
* 500 elements <br />
   average  : 6778 moves<br />
   max      : 6778 moves

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
