class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr = {};
        int len = nums.size();
        backtrack(nums, curr, target, len, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, int curr_num, int len, int j){
        if(curr_num == 0){
            ans.push_back(curr);
            return;
        }
        if(curr_num < 0){
            return;
        }
        

        for(int i = j; i < len; i++){
            curr.push_back(nums[i]);
            curr_num -= nums[i];
            backtrack(nums, curr, curr_num, len, i);
            curr.pop_back();
            curr_num += nums[i];
        }
    }
};
