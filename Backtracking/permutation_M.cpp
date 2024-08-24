/*
Given array nums of distinct integers return all possible permutations
Eg: nums = 1, 2, 3
O/P = [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]

make this into small subproblems 

| 1,2,3 -> make permutations of this 
| 2,3 -> mae permutations of these now
| 3 -> make permtn of this (it will only be 3 )
| [] -> make permutations from this  
  then we return to parent

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }

private:
    void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        // Recursive case: Swap each element starting from  'start' with every
        // other element.
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            // eg 2,3 hai to 2,3 is one perm
            // Recursively call dfs to generate permutations with the next
            // element fixed.
            dfs(nums, start + 1, result);
            // Swap the elements back to restore the original configuration
            swap(nums[i], nums[start]);
        }
    }
};