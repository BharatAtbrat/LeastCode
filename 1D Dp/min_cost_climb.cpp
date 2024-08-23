class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0;
        int downTwo = 0;
        // cost.push_back(0);
        // add an element at the last index because that is the highest
        // point
        /*for(int i = cost.size()-3; i>=0;i--){
            cost[i] += min(cost[i+1],cost[i+2]);

        }
        return min(cost[0],cost[1]);

        //either you do it reverse order from the end
        //or you could also start from the beginning
*/
        for (int i = 2; i <= cost.size(); i++) {
            int temp = downOne;
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            // cost[i] = min(cost[i]+cost[i-1],cost[i]+cost[i-2]);
            // since cost[i] is being added to both values
            // we can simplify it to something like
            // cost[i] += min(cost[i-1],cost[i-2]);
            // i-1 and i-2 are the jumps that we can make
            downTwo = temp;
        }
        return downOne;
    }
};