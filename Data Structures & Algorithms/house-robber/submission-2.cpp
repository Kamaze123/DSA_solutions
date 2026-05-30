class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        return rec(nums, dp, n-1);
    }

    int rec(vector<int>& nums, vector<int>& dp, int index){
        if(index == 0){
            return nums[index];
        }
        if(index < 0){
            return 0;
        }

        if(dp[index] != 0){return dp[index];}

        int pick = nums[index] + rec(nums, dp, index-2);
        int notpick = rec(nums, dp, index-1);
        return dp[index] = max(pick, notpick);
    }
};
