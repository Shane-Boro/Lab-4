# Lab-4

# Option A: Compile and assemble both files directly with GCC
gcc main.c sum_array.s -o lab4

# Option B: Assemble with 'as' and link with GCC
as sum_array.s -o sum_array.o
gcc -c main.c -o main.o
gcc main.o sum_array.o -o lab4

# Run with test data file
./lab4 data.txt