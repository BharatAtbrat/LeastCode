//Medium 
//Calc postfix prod then * with prefix prod 
//TC O(n) 
//SC O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> answer(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix = prefix * nums[i];
        }
        int postfix = 1;
        for (int j = n - 1; j >= 0; j--) {
            answer[j] = answer[j] * postfix;
            postfix = postfix * nums[j];
        }
        return answer;
    }
};