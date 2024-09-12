/*
given a number as array [1, 2, 3] add 1 to number it and return array 
look at edge cases when digit =9 , or number 999
TC O(n) SC O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =0;
        for(int i = digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0; //case when digit > 9 aka add karne ke baad 10
            //so 1 carry 
            //essentially wo digit ko 0 kardia now
            //our code goes to next iteration and goes to 
            /*
            1 2 9 -> 9 ki jaga 0 , now next ieration we have 2, 2<9 so we 2++
            ==3 and return digits 
            1 3 0


            */
        }
        digits[0] = 1; //This is the case when 999 is there thats all
        digits.push_back(0);
        return digits;
    }
};