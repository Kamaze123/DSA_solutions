class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> memo(len+1, -1);
        return rec(nums, memo, 0, len-1);
    }

    bool rec(vector<int>& nums, vector<int>& memo, int index, int len){
        if(index == len){
            return true;
        }

        if(nums[index] == 0){
            return false;
        }

        if(memo[index] != -1){
            return memo[index];
        }

        int jump =  nums[index];
        for(int i = 1; i <= jump; i++){
            if(rec(nums, memo, index+i, len)){
                return memo[index] = true;
            }
        }

        return memo[index] = false;
    }
};
