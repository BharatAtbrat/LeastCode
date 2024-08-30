/*
Classic DP 
You have a string find the largest substring which is also a palindrome 


Now the brute approach for this would be iterating through every letter and checking all the 
substr from the letter to the end of the array 
But that is complexity n * n^2  = n^3 bad 

Interesting way to appraoch 

eg : a c b c a 

we make the current element as the middle and expand on both ends to see the longest substrs

eg index = 0  , letter =a 

.... a since there is nothing on the left of it longest substr =1 

for b             a c <-b-> c a 
                    a and c are equal on both sides making them palindrom and the length of this su
                    substr is 4 +1 = 5 

yehi karna hai 
edge case : Even values , we simply choose i and i+1 index as middle values 
edge case: if len =1 return th whole string 
TC O(n^2) SC O(1)


*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size()-1;
        int maxlen = 0;
        int maxstart = 1;
        if(s.size()==1) return s; //Edge case 
        for (int i = 0; i < s.size()-1; i++) {
            middleware(s, i, i, maxstart, maxlen);
            middleware(s, i, i + 1, maxstart, maxlen);
        }
        return s.substr(maxstart, maxlen);
    };

private:
    void middleware(string s, int i, int j, int& maxstart, int& maxlen) {
        // base case when palindrome substr is valid and accepeted
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--; //go left from mid 
            j++;  //expand to right from mid 
        }
        // choose the max values for start and end
        if (j - i - 1 > maxlen) {
            maxstart = i + 1;
            maxlen = j - i - 1;
        }
    }

};