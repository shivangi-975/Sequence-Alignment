# Sequence-Alignment
In this assignment, we will look at an application of Dynamic Programming to align DNA sequences. In the global DNA sequence alignment problem, you are given as input two DNA sequences S1, S2, which are strings using the four characters A, C, T, G. The strings are of lengths m, n, where possibly m 6= n. Given two DNA sequences, the goal is to compute the best possible (minimum) alignment cost between them. 

Alignment and scoring:
Consider the target and query sequences (our first sequence will always be called the
target and second the query): AGGGCCT, TGGCA respectively. Note that these are of different
lengths, so one natural way to pair them would be:

A G G G C C T
T G G _ C _ T
Here, is called a gap, that can be inserted anywhere in either string, to make the rest
of sequences align better. There is a penalty s(x, y) for matching character x to character y.
Consider the following scoring function:

s(x, y) =

0, if x = y
2, if x nequal y
1, if x = __ or y=__
