/*AMAZON
3 approaches, 
Brute O(n^n)
Better DP O(n^2)
Optimal using greedy O(n)

The logic is simple ek example se dekho 

3 2 1 0 4 , 
we start from last index and set 4 as goal
now we check if 0 can reach goal/4, no it cant 
we check if 1 can reach goal nope
we check 2 can reach goal , nope 
we check 3 can reach the goal(4), nope 
so in end goal isnt the first index there fore we cant aka return false

2 3 1 1 4
we start from last , set 4 as goal 
check if 1 can reach 4 , yes, set goal to 1(index 3) now 
check if 1 can reach goal(1) , yes , set goal to 1(index 2)
check if 3 can reach goal(1 index 2), yes , set goal to 3 (index 1)
check if 2 can reach goal(3 aka index 1), yes, set goal to 2 (index 0)
since we have successfully reached first index we can return true
sice we dont have to calculate the shortest path we just need 
to chcek if we can reach the end index we dont check if 3 se direct ja skte ki nai
nah dont read that its bs 

TC O(n) SC O(n)

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
            int goalpost  = nums.size()-1;
            //we start from the end element and keep shifting 
            //our goal post depending on if the previous element can 
            //visit the current element 
            for(int i  = goalpost; i>=0;i--){
                if(i + nums[i] >= goalpost)
                //if cur index + jumplength can reach the current goal
                //aka the last element for the first iteration we simply shift 
                //the goal to that element 
                goalpost = i;

            }
            return (goalpost==0)?true:false;
            //if our goal reaches the first index that means we have succesffully
            //kept shifting it the the previous elmnt that can reach it 
            //and hence return true 
    }
};
