# Problem : Subsets

## Approach: 
So this is a classic backtracking problem. The constraint given in the question is to not contain any duplicate subsets. 


So we pass a "j" pointer through the backtrack function and we iterate through elements after this "j" pointer to find the subsets, this ensures that there are no duplicates.


We push elements to curr array at every recursive call and push that curr array to the ans array. We add elements then we pop them off, this is the backtracking step.

## Why:
Avoids the O(N^2) brute force — reduces to O(N) time.

## Time Complexity:
O(N) where N = size of nums array

## Space Complexity:
O(N)



