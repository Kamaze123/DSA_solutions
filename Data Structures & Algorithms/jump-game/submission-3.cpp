class Solution {
public:
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

        int jump =  nums[index];
        for(int i = 1; i <= jump; i++){
            if(rec(nums, index+i, len)){
                return true;
            }
        }

        return false;
    }
};
