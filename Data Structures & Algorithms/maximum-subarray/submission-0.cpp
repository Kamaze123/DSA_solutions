class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        int ans = nums[0];
        int curr = nums[0];
        for(int i = 1; i < n; i++){
            int temp = curr + nums[i];

            if(temp > nums[i]){
                curr = temp;
            }else{
                curr = nums[i];
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};
