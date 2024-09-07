/*
GOOGLE
each number associated with letters a-z
0 - invalid does not map to anything 
1 - A , 
2-B so on till 26-Z

decode a string given in numeric format with all possible combos 

eg :    12 can be decoded as AB (1 and 2 separate) or L (which corresponds to 12)
        06 is not a valid, leading zeroes is not a a valid string return 0 


Approach, explore and first digits can only be >1 and <=2 since 26 tak hi hote hai 
and 0 is invalid 

for dp soln 
TC O(n) sc O(1)

the subproblem is making the string smaller and usko decode then make is smaller and decode that 
eg ; 1221 then sub 1 : 221 , sub2: 21, sub3: 1 <- base case then we can go back bigger
*/