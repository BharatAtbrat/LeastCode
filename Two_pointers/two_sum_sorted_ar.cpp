/*
Same as two sum but only difference is the array is sorted
so we can use two pointers to do a binary search and find
the pairs 

TC O(n) SC O(1) it is space optimized 

We iterate through while l<r 
and inc l if sum < target 
ow dec r 
ow we are on the right pairs simply print them out 

ow return empty

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 ; 
        int r = numbers.size()-1;

        while(l<r) {
            int sum = numbers[l] + numbers[r];
            if(sum<target) l++;
            else if(sum>target) r--;
            else return {l+1,r+1};
        }
        return {};
    }
};
