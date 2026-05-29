class Solution {
public:
    int climbStairs(int n) {
        vector<int> seen(n+1, -1);
        return dp(n, seen);
    }

   int dp(int n, vector<int>& seen){
        if(n == 0){
            return 1;
        }

        if(n == 1){
            return 1;
        }

        if(seen[n] != -1){return seen[n];}
        int left = dp(n-1, seen);
        int right = dp(n-2, seen);
        return seen[n] = left + right;
    }
};
