-----------------------------------------------------------------------

## PROJECT DESCRIPTION:
Project has implementation of two  algorithms: Floyd Algorithm, Longest Common Subsequence algorithm
-----------------------------------------------------------------------

## FILES INCLUDED:
1.singh_himanshu_pa3_floyd.c:
Contains Implementation of Floyd algorithm:
It is an algorithm to find the shortest paths in a wieghted graph with no cycles. The graph can have positive or negative wieghts.
An undirected graph with random number of nodes and random wieghts is generated. The algortihm prints out the the sequence of nodes to travel between 
each pair of nodes. This sequence of nodes is the shortest path between the pair and the wieght of edges traversed is printed out as well.

2. singh_himanshu_pa3_lcs.c
Contains Implementation of longest common subsequence. This algorithm takes 2 string as input and returns the longest 
sequence of charcters that are common to both the strings. 
  	

-----------------------------------------------------------------------

## COMPILING CODE:
gcc -g singh_himanshu_pa3_floyd.c -lm -o floyd
gcc -g singh_himanshu_pa3_lcs.c -lm -o floyd
-----------------------------------------------------------------------

## RUNNING CODE:
Execute floyd executable by firing command from bash ./floyd. The graph and the shortest pairs of paths will be printed out for a random graph.

Execute the lcs alogrithm by firing ./lcs arg1 arg2 command with two intput arguments. These 2 arguments can be any sequence of characters. The ouput is the 
longest common subsequence of the two inputs given arguments. 
 
-----------------------------------------------------------------------
