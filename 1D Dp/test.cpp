#include <bits/stdc++.h>

int equalizeArray(int n , int arr[]){
    int min = 0 ;
    unordered_map<int,int> freq;

    for(int i = 0 ; i < n ; i++){
        freq[arr[i]]++;
    }

    int max = 0 ;
    int remove = 0;

    for(const &auto check: freq){
        int curitem = check.first;
        int curfreq = check.second;

        if(curfreq>max || (curfreq == max && curitem>remove)){
            max =curfreq;
            remove = curitem;
        }
    }
    min  = n - max;
    return min;
}    


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum  = 0 ; 
        for(int i = 0 ; i < nums.size();i++){
        sum+=nums[i];
        }

        sum = sum/2; //this is our target since all the elemnts sum up
        //to a value eg 1 5 11 5 sum upto 22 , then we half it = 11 then if 
        //we find a set of digits that sum up to 11 then we are sure ki baak
        //bache hue elemnts will surely add up to 11 
  
        }
    }
};