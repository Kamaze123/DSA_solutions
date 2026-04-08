class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr = {};
        int len = nums.size();
        vector<int> seen(len,0);
        
    
        backtrack(nums, curr, seen, len);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, vector<int>& seen, int len){
        if(curr.size() == len){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < len; i++){
            if(seen[i] == 1){
                continue;
            }
            curr.push_back(nums[i]);
            seen[i] = 1;
            backtrack(nums, curr, seen, len);
            seen[i] = 0;
            curr.pop_back();
        }
    }
};
