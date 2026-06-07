class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        map<int,int> mp;

        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }


        while(!mp.empty()){
            int minKey = mp.begin()->first;

            for(int i = 0; i < groupSize; i++){
                if(!mp.contains(minKey)){return false;}
                mp[minKey]--;
                if(mp[minKey] == 0){
                    mp.erase(minKey);
                }
                minKey++;
            }
        }

        return true;
    }
};
