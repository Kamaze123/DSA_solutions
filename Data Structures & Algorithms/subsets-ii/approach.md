# Problem : Subsets II

## Approach: 
Similar to the subsets I questions, apart from the fact that duplicates are allowed in this. To prevent duplicates, we sort the array and pass it to the backtracking function. Now all duplicate elements are adjacent to each other.

Now we can skip through the elements with same value and obtain unique subsets.

## Time Complexity:
O(2^N * N)

## Space Complexity:
O(2^N * N)
