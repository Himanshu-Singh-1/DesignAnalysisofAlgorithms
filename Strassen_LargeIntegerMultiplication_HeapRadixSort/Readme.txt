-----------------------------------------------------------------------

## PROJECT DESCRIPTION:
Project has implementation of four 4 algorithms: heap sort, radix sort, strassen algorithm for matrix multiplication, large integer multiplication by divide and conquer.
-----------------------------------------------------------------------

## FILES INCLUDED:
1.singh_himanshu_pa2_heap_rdix.c:
	Contains Implementation of following sorting algorithms:
	1. Radix sort 
	2. Heap sort
after running select any of the algorithm and give the input size, i.e the number of numbers to be sorted. Random numbers between 1 to 20 are generated and sorted. Each step of the algorithm is depicted by printing stars which depicts the partially sorted array if the size of array is less than 20.

2. singh_himanshu_pa2_strassen.c
	Contains implementation of Strassen Algorithm for multiplying large matrices. 
	Takes a single input size of matrices to be multiplied. Random numbers are generated and assigned to each field of the matrix. 
	The random arrays generated and the final array after multiplication are printed to console. 

3.  singh_himanshu_pa2_lim.c
	Contains divide and conquer approach to find the product of two large integers. The integers can have any number of digits. The number of digits is entered 
	as an argument to program. The number of digits must be a multiple of 6. The random numbers with specified number of digits and the final product of these random number is printed to the console. 
-----------------------------------------------------------------------

## COMPILING CODE:
1. gcc -g singh_himanshu_pa2_heap_rdix.c -lm -o heap_radix
2. gcc -g singh_himanshu_pa2_strassen.c -lm -o strassen
3. gcc -g singh_himanshu_pa2_lim.c -lm -o lim
-----------------------------------------------------------------------

## RUNNING CODE:
1. fire command ./heap_rdix to launch executable.
2. fire command ./strassen arg1 to launch executable. Arg1: size of the matrices to be multiplied. 
3. fire command ./lim arg1 to launch executable. Arg1: number of digits of the large integers to be multiplied. Have to be a multiple of 6. 
-----------------------------------------------------------------------
