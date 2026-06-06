class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*int maxGas = INT_MIN;
        int start = -1;*/

        priority_queue<vector<int>> maxheap;
        int n = gas.size();
        if(n == 1){
            if(gas[0] >= cost[0]){
                return 0;
            }
        }

        for(int i = 0; i < n; i++){
            if(gas[i] - cost[i] > 0){
                maxheap.push({(gas[i]-cost[i]), i});
            }
        }

        while(!maxheap.empty()){
            auto top = maxheap.top();
            maxheap.pop();

            int start = top[1];
            int maxGas = top[0];


            int next = (start+1)%n;
            while(next != start){
                maxGas += gas[next];
                maxGas -= cost[next];
                if(maxGas < 0){
                    break;
                }
                next = (next+1)%n;
            }

            if(next == start){
                return start;
            }
        }

        
        return -1;
    }
};
