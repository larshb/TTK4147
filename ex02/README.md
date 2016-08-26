# Exercise 2: Concurrency

## Notes

#### Assignment A:

With `vfork()` the program crashes because memory is not shared.

#### Assignment B:

The thread(s) shares the memory of the global variable but not the local one.

#### Assignment D:

The variables do not always have the same value because the print thread might print their values before the other one is reassigned.

#### Assignment E:

The problem was solved by using semaphores. (See the `//`-marks in [the code](din_philo.c).)
