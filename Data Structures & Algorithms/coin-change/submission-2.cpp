class Solution {
public:
    unordered_map<int, int> dp;
    int coinChange(vector<int>& coins, int amount) {
        int ans =  rec(coins, amount);
        if(ans == INT_MAX ){
            return -1;
        }

        return ans;
    }

    int rec(vector<int>& coins, int amount){
        if(amount == 0){
            return  0;
        }

        if(dp.contains(amount)){
            return dp[amount];
        }

        int res = INT_MAX;
        for(int coin : coins){
            if(amount - coin >= 0){
                int ans = rec(coins, amount-coin);
                if(ans != INT_MAX){
                    res = min(res, 1 + ans);
                }
            }
        }

        dp[amount] = res;
        return res;
    }
};
