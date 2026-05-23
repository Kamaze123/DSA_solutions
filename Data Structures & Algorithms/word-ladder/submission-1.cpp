class Solution {
public:
    unordered_set<string> hashset;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string s : wordList){
            hashset.insert(s);
        }

        queue<pair<string, int>> q;
        int found = 0;
        int ans;
        q.push({beginWord, 1});

        while(!q.empty()){
            string s = q.front().first;
            int step = q.front().second;

            q.pop();
            if(s == endWord){
                found = 1;
                ans = step;
                break;
            }

            for(int i = 0; i < s.size();i++){
                char temp = s[i];
                for(int j = 0; j < 26; j++){
                    char c = 'a' + j;
                    if(c == temp){continue;}
                    s[i] = c;
                    if(hashset.count(s)){
                        q.push({s, step+1});
                        hashset.erase(s);
                    }
                }
                s[i] = temp;
            }
            
        }

        if(found == 0){
            return 0;
        }

        return ans;
    }

  
};
