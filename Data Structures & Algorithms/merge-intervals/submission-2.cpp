class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if( n == 1 || n == 0){return intervals;}

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            vector<int> back = ans.back();

            if(intervals[i][0] >= back[0] && intervals[i][0] <= back[1]){
                ans.pop_back();
                ans.push_back({back[0], max(back[1], intervals[i][1])});
            }else{
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};
