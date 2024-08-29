//Medium

//Brute : Use map to store item and its frequency 
//Brute: Use max heap to store elements according to freq and access TC O(n) + O(nlogk) since k hi access karne

//optimal : Bucket sort , create array with the size of nums array and store elements 
// where index where they are stored at is their freq eg, if 3 has freq 5 it is stored at index 5

//Now simply start from the end of array and check if value exists, once k values found return 
//insert into vector like res.insert(res.end(), bucket[i].begin(),bucket[index].end()) this takes
//care of the case when there are multipple entries in the same index since vector array hai 
//to saare values aajate hai 
//TC O(3n) store into map+ store into bucket+ retrieve from it 
//SC O(n+n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            // count freq of each number in nums
        }

        vector<vector<int>> buckets(n + 1);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            buckets[it->second].push_back(it->first);
            // insert nums into the bucket based on freq as their index;
        }

        vector<int> result;
        //isme if you are using bucket.size() do -1 since out of bounds hoga 
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k)
                break;
            if (!buckets[i].empty())
                result.insert(result.end(), buckets[i].begin(),
                              buckets[i].end());
            // the bucket begin and end use kia becuase there can be multiple
            // elements with same freq and we need to print those out together
            // if searching for k most freq
        }
        return result;
    }
};