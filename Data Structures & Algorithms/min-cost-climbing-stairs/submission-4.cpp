class Solution {
public:
    //lets do it using tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int  n = cost.size();

        //edge cases        
        int prev1 = cost[0];
        int prev2  = cost[1];
        for(int i = 2; i < n; i++){
            int curr = cost[i] + min(prev1, prev2);

            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1, prev2);
    }

    /*int dp(vector<int>& cost, int total, int n){
        //base cases
        if(n == 0){
            return total + cost[0];
        }
        if(n == 1){
            return total + cost[1];
        }

        int left = dp(cost, total + cost[n], n-1);
        int right = dp(cost, total + cost[n], n-2);
        return min(left, right);
    }*/

    
};
