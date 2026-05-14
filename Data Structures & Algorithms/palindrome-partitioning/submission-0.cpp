class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(s, 0, curr);
        return ans;
    }

    void backtrack(string s, int j, vector<string>& curr){
        if(s.length() == j){
            ans.push_back(curr);
        }

        for(int i = j; j < s.length(); j++){
            if(checkPalindrome(s, i, j)){
                curr.push_back(s.substr(i, j-i+1));
                backtrack(s, j+1, curr);
                curr.pop_back();
            }
        }
    }

    bool checkPalindrome(string s, int i, int j){
        int l = i;
        int r = j;

        while(l < r){
            if(s[l] != s[r]){return false;}
            l++;
            r--;
        }
        return true;
    }

    
};
