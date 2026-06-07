class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> valid;

        int m = triplets.size();
        int n = target.size();
        for(int i = 0 ;i < m; i++){
            int v = 0;

            for(int j = 0; j < n; j++){
                if(triplets[i][j] > target[j]){
                    v = 1;
                    break;
                }
            }

            if(v == 0){
                valid.push_back(triplets[i]);
            }
        }

        for(int i = 0; i < n; i++){
            int f = 0;
            for(int j = 0; j < valid.size(); j++){
                if(valid[j][i] == target[i]){
                    f = 1;
                    break;
                }
            }

            if(f == 0){return false;}
        }

        return true;
    }
};
