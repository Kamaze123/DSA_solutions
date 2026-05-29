class Solution {
public:
    //lets do it using memoization
    int minCostClimbingStairs(vector<int>& cost) {
        int  n = cost.size();
        
        //edge cases 
        vector<int> arr(n+1, -1);       
        int val1 = dp(cost, arr, n-1);
        int val2 = dp(cost, arr , n-2);
        return min(val1, val2);
    }

    int dp(vector<int>& cost, vector<int>& arr, int n){
        //base cases
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        if(arr[n] != -1){return arr[n];}

        int left = dp(cost, arr, n-1);
        int right = dp(cost, arr,  n-2);
        return arr[n]=  cost[n] + min(left, right);
    }

    
};
