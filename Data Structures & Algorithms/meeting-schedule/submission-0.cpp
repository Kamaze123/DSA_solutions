/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1){return true;}
        vector<vector<int>> temp;

        for(auto i : intervals){
            temp.push_back({i.start, i.end});
        }

        sort(temp.begin(), temp.end());

        for(int i =  1; i < temp.size(); i++){
            auto l = temp[i-1];
            int last = l[1];
            auto curr = temp[i];
            int r = curr[0];
            if(r < last){return false;}
        }
        return true;
    }
};
