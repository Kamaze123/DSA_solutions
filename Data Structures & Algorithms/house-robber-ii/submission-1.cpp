class Solution {
public:
//using memoization
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        //split into two cases
        vector<int> dp(n+1, 0);
        vector<int> dp2(n+1, 0);
        int val1 = rec(nums, n-2, dp);
        nums[0] = 0;
        int val2 = rec(nums, n-1, dp2);
        return  max(val1, val2);
    }

    int rec(vector<int>& nums, int index, vector<int>& dp){
        if(index == 0){
            return nums[index];
        }
        if(index < 0){
            return 0;
        }

        if(dp[index] != 0){
            return dp[index];
        }
        int pick = nums[index] + rec(nums, index-2, dp);
        int notpick = rec(nums, index-1, dp);

        return dp[index] = max(pick, notpick); 
    }
};
