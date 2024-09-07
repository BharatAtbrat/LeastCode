/*
Theres three approaches 
both are techincally brute 
but varying tc and sc 


Raw Brute: use 3 loops and search the array to find the pairs that add up to 0
TC O(n^3) SC O(1)

Brute 2: Run a loop, fix i , then another loop from i+1 to n-1 . Now we know the remaining sum
            sum - ar[i], we try and find numbers that add up to this sum 
            we use the two sum approach using map for this 
            we keep adding the number and its index to the map, and every iteration keep checking
            if sum-arr[i] is present in the map , if it is then the pair is returned  
          TC O(nlogn + n*n) SC O(n)
          we can improve on the space complexity of this one 
Best brute 3: We use two pointers, but before that we fix an i value and iterate it throug 
the array until n-2 indexes, 
in each iteration we check for underflows , and then use two sum conecpt using two ptrs 
start = i+1 and end = n-1 to find if sum = i  + start + end wale elements add up to zero

Note: also make sure duplicate values are handled , if the correct start and end are found chec
if the next values match tthem and keep iterating check the code 

*/
//BRUTE 3 : Best soln imo
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n  = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < n-2;i++){
            if(nums[0]>0) break; //since we have a sorted arr, if first element
            //is +ve then kabhi bhi 0 nahi aa sakta we need -ve values and +ve or 0
            //underflow
            if(i>0 && nums[i] == nums[i-1]) continue;
            //avoid duplicates and go to the last duplicate if exists
            //now we simply do two sum for the remaining j , k 
            int start = i+1;
            int end = n-1;

            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum>0) end--;
                else if(sum<0) start++;
                else {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    //this is the case when sum = 0 but we also need to check duplicates

                    while(start<end && nums[start] == nums[start+1]) start++;
                    //dont forget to increment start 
                    start++;
                    while(start<end && nums[end] == nums[end-1])end--;
                    end--;
                
                }
                
                }

        }
        return ans;
    }
};
