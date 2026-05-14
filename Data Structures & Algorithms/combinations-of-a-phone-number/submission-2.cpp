class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        vector<string> combinations = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr = "";
        backtrack(digits, combinations, curr, 0);
        return ans;
    }

    void backtrack(string digits, vector<string> combinations, string& curr, int  i){
        if(digits.length() == curr.length()){
            if(curr != ""){
                ans.push_back(curr);
            }
            return;
        }
       
        int index = digits[i] - '0';
        string chars = combinations[index-2];
        for(int j = 0; j < chars.size(); j++){
            curr.push_back(chars[j]);
            backtrack(digits, combinations, curr, i+1);
            curr.pop_back();
        }
    }
};
