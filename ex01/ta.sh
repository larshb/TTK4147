#!/bin/sh
clear
cat lars.nfo
echo
read -p "Press ENTER to continue..."
cd linked_list
make
clear
echo "Linked list test:"
echo
./exe
echo
read -p "Press ENTER to continue..."
make clean
cd ..
clear
gcc -o allocate allocate.c
#./allocate
echo
echo " * When I tried to write to the variable when not checking the return value from malloc() I risked attempting to write to the NULL pointer."
echo
read -p "Press ENTER to continue..."
rm allocate
clear
cd timing
gcc -o a sleep.c
gcc -o b busy_wait_delay.c
clear
echo "Using sleep:"
time ./a
echo
echo "Using busy-wait:"
time ./b
echo
echo " * Absolute time refers to real-time (actually) elapsed. Execution time is relative to the system clock."
echo " * (...)"
echo
read -p "Press ENTER to quit..."
rm a b
cd ..
clear
