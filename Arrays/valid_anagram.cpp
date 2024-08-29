//Easy 
//check if two words are valid anagrams abc , bac aka same no. of letters 
//brute : sort both string and compare TC O(n) sc O(1)

//Optimal : two way , 2 arrays 26len , increment every index while iterating arr[st[i]-'a']
//decrement when checking other string, TC O(n) SC O(26)
//similar for maps TC O(n) SC O(n) but since n = 26 O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
     /*   vector<int> ar1(26,0) ; 
        vector<int> ar2(26,0) ;
        if (s.size() != t.size()) return false;
        for(int i =  0 ; i < s.size();i++){
            ar1[s[i]-'a']++;
        } 
        for(int i = 0 ; i < t.size();i++){
            ar2[t[i]-'a']++;
        }
        //or your could just do ar1[t[i]-'a']--; and use a single array
        return (ar1==ar2)?true:false;*/
 
        unordered_map<char, int> mp ;

        for(char c : s ){
            mp[c]++;
        }
        //now decrement
        for(char z : t){
            mp[z]--;
        }

        //now check if any pair not zero

        for(auto i : mp){
            if(i.second != 0) return false;

        }
        return true;
    }
};
