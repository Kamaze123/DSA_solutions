class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return rec(0, s, dp);
        
    }

    int rec(int i, string& s, vector<int>& dp){
        if(i == s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int way = rec(i+1, s, dp);

        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))){
            way += rec(i+2, s, dp);
        }

        return dp[i] = way;
    }
};
