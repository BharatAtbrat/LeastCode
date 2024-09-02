//Same logic as longest palindromic strings 
/* GOOGLE
Given a string, return # of palindromic substrings in it
    Ex. s = "babad" -> "bab", s = "cbbd" -> "bb"

    2 pointers, middle out, check both odd & even sized strings
    we go outwards and keep checking if string is palindrome 
Here we are simply increment a result whenever a palindrome is found 
we have bonth even and odd palindromes and in order to iterate through even and odd 
both we use i , i for even and i, i+1 for odd 
TC O(n*n) + O(n*n)
 =  O(n^2)
SC = O(1) 
 */

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0 ; 
        //for even palindromes 
        for(int i = 0 ; i < s.size() ;i++){
         int l = i;
         int r = i;
         while(l>=0 && r<= s.size() && s[l]==s[r]){
            result++;
            l--;
            r++;
         }   
        }
        //Now we do it for odd lenght palindromes 
        //we have two middle values i and i+1
        for(int j = 0 ; j < s.size() ;j++){
         int l = j;
         int r = j+1;
         while(l>=0 && r<= s.size() && s[l]==s[r]){
            result++;
            l--;
            r++;
         }   
        }
        return result;
    }
};