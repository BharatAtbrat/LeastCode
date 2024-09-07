/*


TC O(n) SC O(1)

XOR between two same numbers returns a 0
so all the duplicates in the array will xor to 0 and the remaining one will
have somethig other than zero usko print karwa do bas 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0 ; 
         for(auto i:nums)
         {
	     res^=i;
         }
         return res;
    }
};