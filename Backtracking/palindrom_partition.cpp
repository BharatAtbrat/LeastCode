
//Explore similarly and keep checking if palindrom, if not dont explore that branch further 
// return into result 
//TC O(n*2^n)
//SC O(n)
//Medium ,backtracking, google 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        vector<vector<string>> result ;
        dfs(s, 0, curr, result);
        return result;
    }
private:
    void dfs(string s, int start ,vector<string>& curr, vector<vector<string>>& result){
        if (start == s.size()){
            result.push_back(curr);
            return;
            //base case as always 
            //leaf node pe start = s.size()
        }
        for(int i = start ; i < s.size() ; i ++)
        {
            if(ispalindrome(s, start, i)) {
                string str = s.substr(start, i - start + 1);
                //exploring with an element
                curr.push_back(str);
                //calling backtracking
                dfs(s, i+1, curr, result);
                //remove once explored to explore w/o this 
                curr.pop_back();
            }
        }
    }
    //start is 0 and ith index currently is the end since start -> i hi apna substr hai
    bool ispalindrome (string s , int start ,int end ){
        //two ptr approach
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }return true;
    }
};