class Solution {
public:
//reverse then transpose
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        int  k = 0;
        for(int i = 0; i < n; i++){
            for(int j  = i+1; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            k++;
        }
    }
};