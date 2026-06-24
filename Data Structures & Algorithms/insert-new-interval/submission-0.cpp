class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;
        int size = intervals.size();
        if(size == 0){
            ans.push_back(newInterval);
            return ans;
        }

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);
        for(int i = 1; i < size+1; i++){
            vector<int> last = ans.back();

            if(intervals[i][0] >= last[0] && intervals[i][0] <= last[1]){
                ans.pop_back();
                ans.push_back({last[0], max(last[1], intervals[i][1])});
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;

        
    }
};
