//Check if array contains duplicate 

//Brute : sort array nlogn + n for checking adjacent elements same hai ki nai 

//Optimal use set to store elements as keep checking as entering if any of them are 
//there in the set O(N) sc O(n)

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>  mp ;
        for(int i = 0 ; i < nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) return true;
            mp.insert(nums[i]);
        }return false;
    }
};
