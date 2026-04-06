## Problem : Combination target sum

**Approach:** The brute force approach would be to check every element of nums array with itself. This would not be efficient enough. Instead, we use backtracking. We have a local variable, **curr_num**, which keeps tracks of the current state of array.

If curr_num = 0, that means we can push the array to our **ans** 2-D array. If curr_num < 0, the **curr** array is useless, so we can backtrack by one element and add that element back to **curr_num**. We can run a for-loop and iterate throught all possible solutions.

**Why:** Avoids the O(N^N) brute force — reduces to O(N^(T/M)) time.

**Time Complexity:** O(N^(T/M)) where N = size of nums array, T = Target, M = minimum element in nums

**Space Complexity:** O(T/M)
