/*
Q100th YAY!
Given a number return true if it is happy 
happy = keep adding the sum of squares of its digits and if at a point the sum is =1 it is happy
not happy = if sum never adds up to 1 and there is an infinite loop

Logic is easy , create a set to store already visited values, while the number is not present
in the set keep calculating the sum , if the sum = 1 return true ow false 

TC O(logn) SC O(logn) 

*/

class Solution {
private: 
    int sumofsq(int n){
        int sum = 0 ;
        while(n>0){
        sum += (n%10)*(n%10) ;
        n = n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> st; //to store already visited nums 

        while(!(st.count(n))){//until value is not in set 
        st.insert(n);
        int temp = n;
        n = sumofsq(n);//returns the n value after calc sum of squares

        if (n==1) return true;

        }
        return false; //false if the sum of sq is not 1 and also the number
        //was already found in the set aka it was visited and the loop
        //is going infinite now 
    }
     

};

//Can also use fast and slow ptrs to detect cycle , if found a cycle then 
//one can never be found also do check if the number is alraedy 1 when entering a cycle ow 
//kabhi nai milega 
