/*

VERY GOOD DP PROBLEM 

Given an array of numbers , return the longest inc subsequence, you can remove any number of 
numbres in between to make it increasing and return that 

Brute DFS Basic :
Eg: [ 0 ,1 ,0,3,2,3 ] since at every element we have two choices either to include it in subseq
        or not include it aka 2 choices for n elements 2^n complexity 
        TC O(2^n)
Brute DFS Approach with cache :
     we mek tree because they good for dp and env
                    start 
            0              1       2       3    -> indexes 
            [1]           [2]     [4]     [3]     -> subseq so far 
        1      2     3   
       [1,2] [1,4] [1,3] ->all valid since 1 se > hai 
     2      3
  [1,2,4] [1,2,3]
    3 X      4 X since 4 ka index comes before             
cant form this subsequqnce since index 3 ka val < last element of our sequence aka 4

we remove duplicates or calculations that happend baar baar 
eg for first subtree we alreayd calc at index 3 we cant go any further down since ind 3 is the last 
element 
So from this if we start from the 3rd index as the first element then we dont need to solve any further 
since index[3] pe jo element hai 4 is the biggest out of all of the elements so we just resuse the value

DP Solution
TC O(n^2) SC O(n)

*/