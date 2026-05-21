class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> seen;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }

        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        dfs(0);
        return seen.size() == n;
    }

    void dfs(int val){
        seen.insert(val);

        for(int nei : mp[val]){
            if(!seen.count(nei)){
                dfs(nei);
            }
        }
    }
};
