/*
FACEBOOK

Interesting problem 
so we are given two arrays cost and gas 
essentially 1 gas = 1 cost 

so both arrays are similar in dimension 

cost = 
gas =  1 2 3 4 5
cost = 3 4 5 1 2

we need to check if starting from any position we are able to reach a full 
circle without running out of gas
so we find the different array first 

dif [i] = gas[i] - cost[i]
dif = -2 -2 -2 3 3 
and now we start iterating our difference array 
we cant add -ve to our total whenever -ve found set total to 0 aka reset
and move the starting index to the next value and do it again

TC O(N) SC O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0))
            return -1;
        int total = 0 ; 
        int start = 0;
        for(int i = 0 ; i < gas.size();i++){
            total += gas[i] - cost[i];
            if(total<0){ total = 0;
                        start = i+1;//move to next item agar total -ve hora hai to
                    //we try some other gas station
                        }
        }
        return start;
    }
};