class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans =  rec(coins,dp, amount);
        if(ans == INT_MAX ){
            return -1;
        }

        return ans;
    }

    int rec(vector<int>& coins, vector<int>& dp, int amount){
        if(amount == 0){
            return  0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int res = INT_MAX;
        for(int coin : coins){
            if(amount - coin >= 0){
                int ans = rec(coins, dp, amount-coin);
                if(ans != INT_MAX){
                    res = min(res, 1 + ans);
                }
            }
        }

        dp[amount] = res;
        return res;
    }
};
