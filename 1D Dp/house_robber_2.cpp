//This is a variation of HR 1
/*
The only difference is the houses are now in a circle, so we cant use the first house and 
last together 
so we use house robber 1 ke logic as function and give ranges 
1. from first house to last-1
2. from second house to last house 
Problem essentially divided into two and max out of these chosen
Edge case when len =1 fasega so we harcode it if len 1 return first element no need to calculate
TC O(n) SC O(1)



*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(helperrob(nums,0,nums.size()-1), //0 to n-1
                   helperrob(nums,1,nums.size()));  //1 to n     
    }

private: 
    int helperrob (vector<int>& nums ,int start,int end){
        int prev1 = 0 ; 
        int prev2 = 0 ; 
        for(int i = start ; i<end;i++){
            int temp = prev1 ;
            prev1 = max(prev2 + nums[i], prev1); //since we dont have a variable iterating
            //through nums here we simply use the i variable that is going from start to end
            prev2 = temp;
        }
        return prev1;

    }
};