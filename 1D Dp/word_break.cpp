/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


Brute approach : Try every posible letter in the given string and check if a word 
exists in our dictionary TC O(n * n)

Brute aproach 2 : Check if the word in our dictionary matches the string 
substr(start index, lenghth of substr); for CPP
eg : leetcode is our string and the words in the dict are {leet, code}
1 - check if leet  matches the first 4 letters in our string (it does)
2- check if leet matches the next 4 chars in our string (nope) , then check if code matches the 
   4 letters or not (it does)
   TC O(n*m) then matching also takes O(n) so O(n*m*n)
We try and partition only at the point where our string matches a word in our dict 
and then do the same for the next upcoming word 
The paritition becomes our subproblems 
TC O(2^n)
eg : abcd is string and dict is a,b,c,ab,bc,cd

      wwe start at a -> present in the dict do we parition a | bcd
      now we have a subproblem bcd that we iterat 
      b - present b|cd
      wordbreak(cd)
      c - present c|d
      d - not present 
      null - base case go back false 

      another subtree (abhi wo dekhte jo true aara hai aka solving the question)

      ab -> dict has ab aka parition now ab | cd 
      wordbreak(cd) repeating subproblme from previous iteration 
      cd - present in dict 
      cd | null
      null -> base case since all true up until now we return true  
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        // set all values into a set
        return wb(st, s);
    }

private:
    bool wb(unordered_set<string>& st, string s) {
        int n = s.size();
        if (n == 0)
            return true;
        for (int i = 1; i <=n; i++) {
            if (st.count(s.substr(0, i)) && wb(st, s.substr(i)))
                return true;
        }

        return false;
    }
};

/*
if we brute force this 
dry run for string = leetcode and dict = {leet, code}

i =1 
substr (l) not true doesnt go in loop
substr (le) false
      (lee) false
substr (leet) true && wb(st, s.substr(4) = code since subs from startin index 4)

recursive call 
i=1 se start once again
subs(c) false
subs(co) false
subs(cod) false
subs(code) true && wb(st, s.substr(8) = "") aka this recurisve call will return true since s.size ==0
ie if is exectuted and true returned
nice but TC (2^n) bad bad TC we use DP to optimize this recursive approach 

*/


/*


*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        // set all values into a set
        int n = s.size();
        vector<int> dp(n + 1, -1);
        // we create dp arr to store precalc values
        // SOI FUCKING UNDERSTOOD
        // THIS IS EASY
        return wb(st, s, 0, dp);
    }

private:
    bool wb(unordered_set<string>& st, string s, int index, vector<int>& dp) {
        int n = s.size();
        if (index == 0)
            return true;
        if (dp[index] != -1) {
            return dp[index];
            // SO , we initialize with -1 meaning jidhar bhi -1 waha koi calc
            // nai hua ab tak BUT! if its not -1 that means we have previosuly
            // got that index and uska solution hamne already store kia dp array
            // mai so we just return that index from dp array instead of
            // recalculating!! EZ
        }
        for (int i = index + 1; i <= n; i++) {
            if (st.count(s.substr(0, i)) && wb(st, s.substr(i), i, dp))
                return dp[index] = true;
        }

        return dp[index] = false;
    }
};

/*TC O(n^2) SC O(n) we use memoization to store whether the previous substring 
waas already checked for bein allowed segmenetation */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false); // this stores wehter the current subst
        // can be broken further [0...index-1] is the substring
        dp[0] = true; // base case since a single letter string can always be
                      // segmented

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i;
                 j++) { // this makes substrings from [o to i-1]
                // now we check if the substring can be segmented
                // sine every index of dp[] stores if substr from 0 to curindex
                // can be segmented And we also check if the string is in our
                // dictionary set if yes store true in the position of dp
                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true; //we start i from 1 since 0 index already true hai
                    break;
                }
                /*Check if dp[j] is true (meaning s[0...j-1] can be segmented)
                 * and if the substring s[j...i-1] exists in the set st.*/
            }
        }
        return dp[n]; // the last index of dp stores whether the whole
                      // string can be segmented
                      // if yes then we can make the string from our dictionary
    }
};