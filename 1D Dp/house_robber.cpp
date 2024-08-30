//Google ko pasand hai ye 
//Medium 

// So There can be two approaches to this 
//One is not spaec optimized 

//Space optimized approach Recursion + memoization 
/*
We are given ki adjacent rob nai kar sakta 

Assume we are on i house ,
2 options 
1. Rob this house , then you can only rob i-2th house and the consecutive ones before it (i-3,i-4,i-5..)
2. Dont rob this house, then you can rob i-1th house and the consecutive ones after it (i-2,i-3,i-4...)

Now we just need to find the maximum value out of these robberies. To iterate through the whole array
we simply increemnet prev2 and for prev1 we store the max out of our options in it 

we only use two variables since we only need to take care of the prev max and the prev value 

[... prev2 , prev1  , cur .... ] 

prev2 = 0: Represents the maximum money robbed up to two houses before the current house.
prev1 = 0: Represents the maximum money robbed up to the previous house.

TC O(n) SC O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return nums[0] ; 
        int prev2 = 0;
        int prev1 = 0;

            for(int cur: nums){
                int temp = prev1 ;
                prev1 = max(prev2 + cur, prev1); //choice we have
                prev2 = temp;
                
            }
            return prev1;
            }
};

