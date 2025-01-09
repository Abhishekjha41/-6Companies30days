Brackets in Matrix Chain Multiplication :

Given an array arr[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is arr[i] * arr[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also, please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "true" for the correct string and "false" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.


Examples:

Input: arr[] = [40, 20, 30, 10, 30]
Output: true
Explanation: Let's divide this into matrix(only 4 are possible) [ [40, 20] -> A, [20, 30] -> B, [30, 10] ->C, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC), then we multiply A to (BC) -> (A(BC)), then we multiply D to (A(BC)) -> ((A(BC))D)
so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.