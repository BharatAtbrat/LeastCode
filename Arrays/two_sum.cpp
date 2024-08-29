//Easy 

//Brute: only works if the array is sorted 
//ow index match nai hoga , two ptrs start and end pe , iterate through and keep adding until 
//target  matches ow false 

//optimal : use maps nicely O(n) O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // val : index

        for (int i = 0; i < n; i++) {
            int second_num = target - nums[i];
            // find the second no. aka compliment
            // search for it in the map
            if (mp.find(second_num) != mp.end())
                // if found return the value and its index from
                // the map
                return {mp[second_num], i};

            // ow inesrt the value in the map
            mp.insert({nums[i], i});
        }
        return {};
    }
};