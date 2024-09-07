/*

convert number to binary and calculate hamming distance/set bits
aka the number of 1s in the binary 

three approaches 
1. Basic convert /store in binary set and traverse through and check if 1(since 32bit int hai 
to TC O(32) SC O(32))
2. Do n = n & n-1 unsetting the set bits (aka 1s in the set) 
, this removes the least significatn bit and ands it with itself TC O(no. of set bits/ no. of 1s) SC O(1)

Intuition: By repeatedly unsetting the rightmost set bit using n = n & (n - 1), we can directly count how many set bits exist.

Approach:

While n is greater than 0:
Unset the rightmost set bit using n = n & (n - 1).
Increment the count.
Return the count.
Complexity:

Time Complexity: O(number of set bits). The loop runs only for the number of set bits.
Space Complexity: O(1).




3. Use inbuilt funciton that counts set bits __builtin_popcount
*/

//1
class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> binary(n);
        int c = 0;
        for(int i = 0 ; i<32;i++){
            if(binary[i]==1)
            c++;
        }       
        return c; 
    }
};

//2
class Solution {
public:
    int hammingWeight(int n) {
              int c = 0 ; 

              while(n)
              {
                n = n & (n-1);
                //this removes the least significant bit aka rightmost 
                c++;
              }     
              return c;   
    }
};
//3
