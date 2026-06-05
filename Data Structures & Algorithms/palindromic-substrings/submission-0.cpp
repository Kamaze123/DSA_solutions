class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        int ans = 0;

        for(int i = 0; i < size; i++){
            //odd substring
            int l = i;
            int r = i;

            while(l >= 0 && r < size && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }

            //even substring
            l = i;
            r = i+1;
            while(l >= 0 && r < size && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};
