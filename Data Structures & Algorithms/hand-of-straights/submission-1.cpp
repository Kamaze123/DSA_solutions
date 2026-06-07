class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());

        int n = hand.size();
        unordered_map<int,int> mp;
 
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(!mp.contains(hand[i])){
                continue;
            }
            int num  = hand[i];

            for(int j = num; j < num + groupSize; j++){
                if(!mp.contains(j)){return false;}
                mp[j]--;
                if(mp[j] == 0){
                    mp.erase(j);
                }
            }

        }

        return true;
    }
};
