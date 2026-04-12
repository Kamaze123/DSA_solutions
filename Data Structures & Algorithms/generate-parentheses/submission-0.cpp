class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(curr, 0, 0, n);
        return ans;
    } 
    
    void backtrack(string& curr, int open, int close, int n){
        if(open == close && close == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            backtrack(curr, open+1, close, n);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            backtrack(curr, open, close+1, n);
            curr.pop_back();
        }
    }

};
