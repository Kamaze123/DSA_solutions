class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        queue<int> q;
        unordered_map<int, vector<int>> mp;
        vector<int> in(n, 0);
        vector<int> order;
        int total = 0;
        

        for(int i = 0; i < n; i++){
            mp[i] = {};
        }

        for(auto c : prerequisites){
            mp[c[1]].push_back(c[0]);
            in[c[0]]++;
        }

        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int val = q.front();
            q.pop();
            order.push_back(val);
            total++;
        
            for(int num : mp[val]){
                in[num]--;
                if(in[num] == 0){
                    q.push(num);
                }
            }

        }

        if(total != n){return {};}
        return order;
    }
};
