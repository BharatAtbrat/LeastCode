//Amazon 

//Medium , 

//sort strings, use the sorted string as key in key,vector<int> map pairs
//keep comparing each str and add to map then push to result and return 

//O(n * klogk) n = no.of strings , klogk for sorting a string 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            result.push_back(it->second);
            // push the value pair for each key from the map we created and
            // populated
        }
        return result;
    }

private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
            // add to corresp index of letter
        }

        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }
};
