class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        vector<int> curr = {};
        sort(nums.begin(),nums.end());

        backtrack(nums, curr, len,0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, int len, int j){
        if(curr.size() == len){
            ans.push_back(curr);
            return;
        }

        ans.push_back(curr);
        for(int i =  j; i < len; i++){
            if(i  > j && nums[i] == nums[i-1]){continue;}
            curr.push_back(nums[i]);
            backtrack(nums, curr,  len, i+1);
            curr.pop_back();
        }
    } 
};
