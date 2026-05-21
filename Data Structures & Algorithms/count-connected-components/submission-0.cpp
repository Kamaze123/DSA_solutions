class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visit;
    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int count = 0;

        for(int i =  0; i < n; i++){
            if(!visit.count(i)){
                count++;
                dfs(i);
            }
        }

        return count;
    }

    void dfs(int val){
        visit.insert(val);

        for(int nei : graph[val]){
            if(!visit.count(nei)){
                dfs(nei);
            }
        }
    }
};
