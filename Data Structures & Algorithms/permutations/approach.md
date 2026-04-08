# Problem : Permutations

## Approach: 
We are required to give permutations of the given input array. So base case is to check the length of current array with input array, if it is same, we push it to ans array.

We also have a seen array which keeps track of elements we have encountered so far. If it a new element, we push it to curr array otherwise we ignore it. Then we explore all possible permutations

## Time Complexity:
O(N*N!) , N = size of nums array

## Space Complexity:
O(N * N!) , N = size of nums array
