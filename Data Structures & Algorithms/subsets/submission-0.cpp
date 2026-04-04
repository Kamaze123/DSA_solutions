class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr = {};
        backtrack(nums, 0, curr, nums.size());
        return ans;
    }

    void backtrack(vector<int>& nums, int j,  vector<int>& curr, int len){
        if(len == curr.size()){
            ans.push_back(curr);
            return;
        }

        ans.push_back(curr);
        for(int i = j; i < len; i++){
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr, len);
            curr.pop_back();
        }
    }
};
