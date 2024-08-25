//Amazon 
//Medium ,  backtracking , mostly ,
//redo
//TC O(n*4^n)
//SC O(n)


//Hardcode nums and values in map 
//use those to access strings and create combinations 
//bruh didnt get it much do it again 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string curr = "";
        vector<string> result;
        // we have to return all strings

        dfs(digits, 0, mp, curr, result);
        return result;
    }

private:
    void dfs(string digits, int start, unordered_map<char, string>& mp,
             string& curr, vector<string>& result) {
        if (start == digits.size()) {
            result.push_back(curr);
            return;
        }
        string str = mp[digits[start]];
        // we get corresp string of the digit
        for (int i = 0; i < str.size(); i++) {
            curr.push_back(str[i]);
            // go to the next digit and then backtrack
            // do dry run
            dfs(digits, start + 1, mp, curr, result);
            curr.pop_back();
        }
    }
};