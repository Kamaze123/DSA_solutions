class Solution {
public:
//greddy solution
    bool canJump(vector<int>& nums) {
        int size = nums.size() -1;

        int goal = size;
        for(int i = size-1; i >= 0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }

        return goal == 0;
    }
};
