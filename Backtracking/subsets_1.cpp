//Medium hai vai
//FB
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        dfs(nums, 0, curr, result);
        return result;
    }

private:
    void dfs(vector<int>& nums, int start, vector<int>& curr,
             vector<vector<int>>& result) {
        //add cur array to result
        result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
           //explore via adding value to the tree
            curr.push_back(nums[i]);
            //call backtracking to explore with the added value 
            dfs(nums, i + 1, curr, result);
            //we explore by adding elements into curr 
            //once done with that call dfs returns and 
            //now the last element is popped so we can 
            //explore without that element
            //lookat tree
            //condn for removing that element and not exploring 
            curr.pop_back();
        }
    }
};
//ps for anyone else reading this code please ignore my comments
