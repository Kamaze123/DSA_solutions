class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size()-1;
        vector<int> seen(size+1, 0);
        queue<vector<int>> q;
        int ans = -1;
        q.push({0, 0});
        seen[0] = 1;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int num = top[0];
            int step = top[1];

            if(num >= size){
                ans = step;
                break;
            }

            for(int i = 1; i <= nums[num]; i++){
                if(num + i <= size && seen[num+i] == 0){
                    q.push({num+i, step + 1});
                    seen[num+i] = 1;
                }
            }
        }

        return ans;
    }
};
