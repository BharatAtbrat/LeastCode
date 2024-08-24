
// TC O(2^n)
// SC O(n)
// Do combination sum 1 first
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> result ; 

        dfs(candidates, target, 0, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& candidates, int target, int sum , int start ,vector<int>& curr, vector<vector<int>> & result){
        if(sum>target){return;}
        //base case when range exceeded
        if(sum==target){
            result.push_back(curr);
            return;
        }
        //base case when target found at a node

        for(int i = start; i < candidates.size(); i++){
            if(i>start && candidates[i] == candidates[i-1]){
                //checking duplicates
                continue;
            }
            //accepting value and exploring
            curr.push_back(candidates[i]);

            //backtracking 
            dfs(candidates, target, sum + candidates[i], i+1, curr, result);
            //                       updating sum, updating index
            curr.pop_back();
        }
    }
};