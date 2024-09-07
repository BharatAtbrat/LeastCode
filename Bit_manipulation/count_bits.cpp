/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
*/
//Basic O(n) solution ,storing all values in vector array then counting set bits in each 

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        vector<int> res;
        while (n >= 0) {
            arr.push_back(n);
            n--;
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            res.push_back(__builtin_popcount(arr[i]));
        }
        return res;
    }
};
//why converty each to binary then store when you can simply use them directly 

class Solution {
public:
    vector<int> countBits(int n) {
 
        vector<int> res;
   
        for (int i = 0 ; i <=n;i++) {
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};

//Can also use dp to solve it since a lot of bits and their calcs are being repeated 
//well do that later 
//Can be optimized  to O (logn)?