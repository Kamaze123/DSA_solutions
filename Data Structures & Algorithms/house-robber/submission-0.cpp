class Solution {
public:
//tabulation

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2;i < n; i++){
            if( i == 2){
                dp[i] = nums[i] + nums[i-2];
                continue;
            }
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }

        return  max(dp[n-1], dp[n-2]);
    } 
};
