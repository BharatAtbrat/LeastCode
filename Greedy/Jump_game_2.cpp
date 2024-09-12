/* GOOGLE
Iteration to the previous jump game problem altho the logic is a little different

We use greedy for a linear time complexity 


Logic is simple , 
We make sections of the array based on how far we can jump from the current section 
Eg;  2, 3, 1 , 1 ,4 is our question
 we start from 2, that is our section 0 [[2] 3 1 1 4] 
 , the max jump we can make from it 
 is 2 therefore we set the next section as range l,r where l = index of 2+1 and r = maxjump 2 could make aka 2
 second section is [3,1] also jump+1 = 1
 so our arrya looks like 
 [2] [3 1] 1 4
 now we check the max we can jump from section 3->1 max = 3 jumps which add up to index i+nums[i] = 4
 we set our range ka upper limit to max r = 4 ka index aka 4th index and 
 l = prev sec ka last elemtn + 1
jump+1 = 2
 now our array looks like 
 [2] [3 1] [1 4]
 since we could reach the end we also increment the jumps every section 
 we return jumps aka 2

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        //It is always given that we have a way to reach the last index 
        int jumps = 0;
        int left = 0 ; int right = 0 ; 
        while(right < nums.size() -1){
            int furthest = 0 ;
            /*what we are doing is making sections of the array
            using l and r ptrs, we check the longest jump we can make 
            from a section using either l/r ptrs and then set it as the 
            boundary of the next section , the starting boundary would simply 
            be previous section ka last element + 1 aka right+1 */
        for(int i = left ; i<=right;i++){
            furthest = max(furthest, i + nums[i]);
        }
        left = right + 1 ; //setting the starting pt of the next section
        right = furthest;//set the last element of the boundary to the max jump from
                        //the previous section
        jumps+=1;
        }
        return jumps;
        
    }
};