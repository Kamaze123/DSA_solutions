class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> seen;
    bool validTree(int n, vector<vector<int>>& edges) {


        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        
        if(!dfs(0,-1)){
            return false;
        }

        return seen.size() == n;
    }

    bool dfs(int val,int parent){
        if(seen.count(val)){
            return false;
        }

        seen.insert(val);
        for(int nei : mp[val]){
            if(nei == parent){
                continue;
            }
            if(!dfs(nei, val)){
                return false;
            }
        }
        return true;
    }
};
