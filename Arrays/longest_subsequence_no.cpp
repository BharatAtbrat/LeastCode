//Medium IMP GOOGLE BUT A LOT OF OTHER COMPANIES LOVE THIS ONE 

//Brute : sort array , now check if adjacent are in sequence if yes, add to cur len
//compare to maxlen and store max, at the end also check max bw them once again 
//consider edge cases like empty nums array , or duplicates (duplicates must be included but skipped)
//TC O(nlogn + n)
//SC O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute nlogn approach 
    if(nums.empty()) return 0;
        sort(nums.begin(),nums.end()) ; 
        int cur = 1; 
        int maxlen  = 1; 
        for(int i = 1 ; i < nums.size();i++){
                if(nums[i-1]==nums[i]) continue ;
                //duplicates 

                else if(nums[i]==nums[i-1]+1) cur++;
                else {
                    maxlen = max(maxlen, cur);
                    cur =1 ;
                }
        }
   return max(maxlen, cur);
   //this is important because if the longest subsequenece
   //is at the last then it keeps adding curr and when the time comes

   //else stment is never called so the maxlen is never set to the cur
   //hence we need to check at the end if the cur > maxlen
    }


};


//Optimal 

//Interseting approach using set, store all elements of nums into a set
//Logic:
/*
Iterate through the set, keep checking if the prev neighbor of the current element is present 
if its not present that means that a sequence has started 

eg 100 1 3 2 4 
100 ke prev is not presetn so a seq starts, now check if 101 present in set, its not so exits and check 
cur lenght with lognest 
now move to 1 prev neighbor 0 not present soa new seq 
check 2 : present , len = 2,
check 3: present, len++
check 4: present , len = 4
check 5: not preseent so exit and compare with longest and chose max aka 4 return 4
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0 ;
        //a seq starts if prev element is not present
        for(auto i: s){
            //rememebr i is storign values of the nums array
            
            int length = 1 ; 
            if(!s.count(i-1)){
                //while prev negbor not present
                //seq starts 
                while(s.count(i+length)) 
                //check if next element is present
                length++; //if yes keep inc len
            }
            longest = max(longest, length);
            }
            return longest;
        }
    
};


//TC O(n) SC O(n)