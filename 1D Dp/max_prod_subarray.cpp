/*


Brute : 
Simply iterate through and explore all possible products 

TC O(N*N) SC O(1)
But gives tle 

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN ;
        int prod ;
        for(int i = 0 ; i < nums.size() ;i++){
                prod =1;
            for(int j = i ; j< nums.size();j++){
                prod *= nums[j];
                    maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
};

//Brute approach

/*
We need to optimize this recursive solution and DP use karo vai ggwp
Subproblem is to find max prod subarray of two elements 
we know that if the array has all +ve  then the max product subarray = prod of all elements in the array
But for all -ve no.s it is differnet since odd * will give +ve and even * will give -ve values 
eg ; -1, -2, -3 mai -1,-2 ka max prod nikalo that is the base case subproblem

The logic is to maintain two variable maxprodsub, minprodsub (one stores max prod of subarr and the otherstores min)

Why?
Dry run [-1, -2, -3, 4]
we take -1 , -2 -> maxprod = -1*-2 = 2
                   minprod = -2

Now we add -3 into subarr -1,-2,-3
if -ve number
maxprod = minprod * -3 = -2 * -3 = +6
minprod = maxprod * -3 = 2 * -3 = -6

now we add +4
if +ve number 
maxprod = maxprod * 4 = 6 * 4 = +24
minprod = minprod * 4 = -6 * 4 = -24

agar -4 hota to 
maxprod = minprod * -6 = -6 * -4  = +24
minprod = maxprod * -6 = 6 * -4 = -24

so yes we keep doing that and voila we have our answer 
*/
//TC O(n) SC O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = 1;
        int minprod = 1;
        int prod = nums[0];
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxprod, minprod);
            }
            //calc max and min at every elements 
            //and swap if the number is negative 
            maxprod = max(nums[i], maxprod * nums[i]);
            minprod = min(nums[i], minprod * nums[i]);

            prod = max(prod, maxprod);
        }
        return prod;
    }
};

