class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> seen;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n  = numCourses;
        for(int i = 0; i < n; i++){
            mp[i] = {};
        }

        for(auto c : prerequisites){
            mp[c[0]].push_back(c[1]);
        }

        for(int i  = 0; i < n; i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int val){
        if(seen.count(val)){
            return false;
        }

        if(mp[val].empty()){
            return true;
        }

        seen.insert(val);
        for(int num : mp[val]){
            if(!dfs(num)){
                return false;
            }
        }

        seen.erase(val);
        mp[val].clear();
        return true;
    }
};
