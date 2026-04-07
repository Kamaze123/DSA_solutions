# Problem : Combination target sum II

## Brute force approach:
The brute force approach would be to find all the possible solutions which add up to the target sum, which includes the duplicates. Then we sort each array individually, then we sort the entire 2-D array.

By doing so, we get the duplicate array adjacent to each other. Then we can remove the duplicate and push the original arrays to the ans array. This is not efficient.


## Approach: 
The main problem is the duplicate arrays. This can be avoided if we sort the array and then we run the backtracking algo on it. 
## Why:
By doing so, we get the duplicate values adjacent to each other. Now we have a chose to either take them all together or to ignore the duplicates and just one value.

## Time Complexity:
O(2^N)

## Space Complexity:
O(N)
