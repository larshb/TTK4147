#!/bin/bash
gcc -o fork fork.c
gcc -pthread -o pthreads pthreads.c
gcc -pthread -o semaphores semaphores.c
gcc -pthread -o mutexes mutexes.c
gcc -pthread -o din_philo din_philo.c
clear
echo "With fork():"
./fork
echo
echo "with vfork():"
./fork -v
echo
echo "with threads:"
./pthreads
echo
echo " * vfork() waits for the child process to eliminate and doesn't share the same memory"
echo " * POSIX threads share global variables, but not local."
echo
read -p "Press ENTER to continue..."
clear
timeout 5 ./semaphores
echo
echo " * If a resource is locked, the caller waits for it to unlock."
echo " * The resources are distributed arbitrarily."
echo
read -p "Press ENTER to continue..."
clear
./mutexes
echo
echo " * Without the mutual exclusions the printing thread might print after var1 is incremented, but before var2 is reassigned."
echo
read -p "Press ENTER to continue..."
clear
timeout 5 ./din_philo
echo
echo " * The deadlock happens when all the philosophers picks up either a fork or a knife."
echo " * I solved it using a semaphore allowing only 4 be picked up."
echo " * Of course I can think of other methods(...)"
echo
read -p "Press ENTER to quit..."
rm fork pthreads semaphores mutexes din_philo
clear
