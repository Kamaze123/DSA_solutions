class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int num = 0;
        for(int i = 0; i <= size;i++){
            num = num ^ i;
        }

        for(int x : nums){
            num = x ^ num;
        }

        return num;
    }
};
