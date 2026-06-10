class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int num = size;
        for(int i = 0; i < size;i++){
            num = num ^ i ^ nums[i];
        }
        
        return num;
    }
};
