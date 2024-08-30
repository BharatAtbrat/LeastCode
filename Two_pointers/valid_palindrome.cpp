/*

SPOTIFY
Easy question 
Check if the given string in a valid palindrome
Brute approach
Create a new string and only insert non empty letters
reverse it and check with original TC O(2n) SC O(n) can eb sc optimized 

Optimal
Two pointers, keep checking if equal and update values 

Also check cases when alphanumneric values present, we ignore those 
TC O(n) SC O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        
        while(l<r) {
            while(!isalnum(s[l]) && l<r) l++;
            while(!isalnum(s[r]) && l<r) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
