class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr = {};
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, curr, 0, len);

       
        return ans;
    }

    void backtrack(vector<int>& nums, int curr_num, vector<int>& curr, int j, int len){
        if(curr_num == 0){
            ans.push_back(curr);
            return;
        }

        if(curr_num < 0){
            return;
        }

        for(int i = j; i < len; i++){
        
            if(i > j && nums[i] == nums[i-1]){continue;}
            if(curr_num < nums[i]){break;}
            curr.push_back(nums[i]);
            backtrack(nums, curr_num - nums[i],  curr, i+1, len);
            curr.pop_back();
        }
    }
};
