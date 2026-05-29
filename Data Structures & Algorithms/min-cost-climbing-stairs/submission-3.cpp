class Solution {
public:
    //lets do it using tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int  n = cost.size();
        if(n == 1){
            return cost[0];
        }
        if(n == 2){
            return min(cost[0], cost[1]);
        }
        //edge cases        
        vector<int> dp(n+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-2],dp[n-1]);
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
