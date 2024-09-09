/*
HARNESS 

Good questions 


Calculate the length of the longest substring with non repeating char

Brute: Find All substrings O(n^2) and choose the longest one 
Optimal : 
We use two ptrs, major logic is the keep increasing the windows isze until 
a repeating character is found. If found(chcked using set) we start 
removing duplicates from the start until no duplicates, aka window ka size
kam 

ow we simply increase the window size and add the element to the set too
TC O(n) SC O(n)
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> checker; 
        int left = 0;
        int right = 0 ; 
         int longets = 0 ;

         while(right<s.size()){
                if(checker.find(s[right])==checker.end()){
                    checker.insert(s[right]); //add to set if not present 
                    //check longest
                    longets = max(longets, right-left+1); 
                    right++;
                }
                else {
//ow duplicate found, remove from  start of our window and also our set until true 
                checker.erase(s[left]);
                left++;

                }
         }
         return longets;
    }
};