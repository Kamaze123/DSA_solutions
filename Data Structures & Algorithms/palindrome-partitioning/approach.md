# Problem : 131)Palindrome Partitioning

## Approach: 
We use backtracking in this. We use a local array to keep track of all the current palindromes we have. Then we iterate through the given string. If a particular substring is a palindrome, we push into the local array and restart checking for palindrome from the necxt index.
Else, we increase the size of substring and continue checking for palindrome. 
## Time Complexity:
At every index, we have two choices, either push substring to array or increase susbstring size. So time complexity is O(2^n * n)
## Space Complexity:
O(2^n * n)
