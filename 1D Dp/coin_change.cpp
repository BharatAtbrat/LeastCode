/*

You are given an integer array coins representing coins of different denominations and
 an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount.
 If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Eg; inp coins 1,2,5 amt = 11 output  = 3 coins needed at minimum aka 5+5+1


We can approach it with a greedy approach , take the biggest values and start adding them
eg 1,3,4,5 amt = 7 

greedy 5+4 != 7
        5+3 != 7
        5+1+1 == 7 ie ans = 3 but wrong answer is 4+3 aka 2 coins min 

        cant use greedy

Brute force dfs soln 
create a tree with options that we can take
each node stores the amount remaining after our previoous choice 

create a tree that explores every value and every node contains the amount remaining 
we see a lot of nodes that are being repeated 
we can optimize this recursive soln using dp 
and storing the copied values 
we know it takes one step to  go from amt 1 to amt 0 
aka we onmly need 1  coin of denomination 1 to get to base casea of 0

DP Bottom up approach from 7 to 0
TC O(amount * length)
SC O(amount) since we have a dp array that stores all the amounts 
So we have two array dp[0] = 0;
                     dp[1] = 1; //we know ki ek hi coin chahiye to solve is from 1  
                     dp[2] = 1 + dp[1]; = 2 ; ie 2 coins
                    dp[3] = 1; since 3 is already there 
                        dp[4] = 1
                        dp[5] = 1
                        dp[6] = dp[3]+dp[3] =  1+1 = 2;          
                        dp[7] = 1 + dp[6]; = 3 ; //one possible solution but min?
                        dp[7] = dp[3] + dp[4]; 1+1 = 2;
                        dp[7] = dp[4] + dp[3] = 1+1; or 1 + dp[7-4] = 2 // another soln 
                        dp[7] = dp[5] + dp[2]; 1+2 = 3;
                        
                        solns min =  2 coins either 4+3 ,3+4  
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // base case hai
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) // aka valid since amnt is still
                                       // remaining
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                // this is essentially doing dp[x] = 1 + dp[x-curcoinval]
                // eg d[7] = 1 + dp[7-3]; if curr coin is 3 (arr = 1,3,4,5)
            }
        }
        // we have set the dp initial values to max
        // or not possible values since max amt is amount
        // so if the dp[amount] has amoutn+1 that means
        // we havent found a solution
        return (dp[amount] != amount + 1) ? dp[amount] : -1;
    }
};