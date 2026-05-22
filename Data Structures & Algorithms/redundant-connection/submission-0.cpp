class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> seen;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if(edges.size() == 0){
            return {};
        }

        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        int j = 0;

        for(int i = edges.size() - 1; i >= 0; i--){
            int e1 =  edges[i][0];
            int e2 = edges[i][1];
            seen = {};
            dfs(1, e1, e2);
            if(seen.size() == edges.size()){
                j = i;
                break;
            }
        }

        return edges[j];
    }

    void dfs(int val, int x, int y){
        seen.insert(val);

        for(int nei : mp[val]){
            if((nei == x && val == y) || (nei == y && val == x)){
                continue;
            }
            if(!seen.count(nei)){
                dfs(nei, x, y);
            }
        }
    }
};
