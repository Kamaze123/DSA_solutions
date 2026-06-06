class Solution {
public:
    unordered_map<int, bool> memo;
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        return rec(nums, 0, len-1);
    }

    bool rec(vector<int>& nums, int index, int len){
        if(index == len){
            return true;
        }

        if(nums[index] == 0){
            return false;
        }

        if(memo.count(index)){
            return memo[index];
        }

        int jump =  nums[index];
        for(int i = 1; i <= jump; i++){
            if(rec(nums, index+i, len)){
                memo[index] = true;
                return true;
            }
        }

        memo[index] = false;
        return false;
    }
};
