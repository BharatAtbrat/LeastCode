class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //sort the array so dups will be right next to each 
        //other 
        vector<int> curr;
        vector<vector<int>> result;

        dfs(nums, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& curr,vector<vector<int>>& result){
                    result.push_back(curr);
                    for(int i = start ; i < nums.size(); i++){
                        if(i>start && nums[i]==nums[i-1]){
                            //condn to check duplicates and skip 
                            //over when found 
                            continue;
                        }
                        //case when we are including the value
                        curr.push_back(nums[i]);
                        //call backtracking again to explore
                        //all cases when the value is being included
                        //aka left branch of tree
                        dfs(nums, i+1, curr, result);
                        //Note: we increment the index here to explore

                        //case when we are not including the value
                        curr.pop_back();

                    }
                }
};