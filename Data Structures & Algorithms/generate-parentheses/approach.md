# Problem : Generate Parentheses

## Approach: 
The general intuition is that for a string to be accepted, it need to have size 2n and number of open parantheses = number of closed parantheses.

When number of open parantheses is less than n, we can add '(' to the current string. When number of ')' is less than '(', only then can we add ')' to current string.

Keeping these conditions in mind, we can find all valid paranteses.

## Time Complexity:
O(4^N/rootN), unlike subsets, this grows in a different rate

## Space Complexity:
O(N)
