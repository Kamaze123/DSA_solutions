class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> cycle;
    vector<bool> seen;
    int cycleStart = -1;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(vector<int> e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        seen.resize(edges.size() + 1, false);

        dfs(1, -1);
        for(int i = edges.size() - 1; i >= 0; i--){
            int e1 = edges[i][0];
            int e2 = edges[i][1];

            if(cycle.count(e1) && cycle.count(e2)){
                return {e1, e2};
            }
        }

        return {};
    }

    bool dfs(int val, int par){
        if(seen[val]){
            cycleStart = val;
            return true;
        }
        seen[val] = true;
        for(int nei : graph[val]){
            if(nei == par){continue;}
            if(dfs(nei, val)){
                if(cycleStart != -1){cycle.insert(val);}
                if(cycleStart == val){cycleStart = -1;}
                return true;
            }
        }

        return false;
    }

};
