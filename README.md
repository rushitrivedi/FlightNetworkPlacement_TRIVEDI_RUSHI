## Description of  [Stack.cpp](stack.CPP)

STACK HAVE LAST IN FIRST OUT PROPERTY TO SOLVE GIVEN STACK

in this I use an integer array `mstack` to maintain a stack. maximum size of stack is 10.

### For program 1.a

1.static integer, `npush`, that keeps track of the next push expected.For any push out of order, 
  it will not allowed as comparison with "npush" value.
2.Pop is removing and returning the topmost value of the stack.
3.The "show" function lists all content of the stack.

### For 1.b

1. The `validate` method contains the algorithm to check the validness of pattern, which is enterred by user.
2. For illustrative purpose(and also since we're using an array and not a linked list), 
   we've fixed the pattern length to `10`, no more & no less allowed & also,
   we expect each digit to be distinct(i.e `0-9` are all present in the pattern).
3. To validate a given pattern, 
   we take the fact into consideration that by monitoring successive values, 
   the validness can be determined as follows : 
4. To mark popped digits, we use a `status`(integer array of 10), all initially set, and reset on popping(i.e when the digit is encountered in the pattern.).
5. If a digit is more than the following one in the pattern, there is no conflict.
6. If a digit is less than the following one in the pattern, we check the difference; 
   if one, there is no conflict; else we check the `status` of all the digits between the two digits in question. 
   if any digits hasn't been popped yet, the pattern is invalid.
7. when a duplicate digit is found, test terminates announcing an invalid pattern.
8. If all the above tests for invalidness are unsuccessful, 
   test terminates announcing a valid pattern.

The program is interactive, asking the user to select an operation from : 
`1. Push`, `2. Pop`, `3. Show`, `4.Pattern matching`, `5. Exit`.

---

## Approach to Exercise 2:

### What we use:

- We use a Circular Queue `cqueue`, implemented using a linked list.
- `insert` and `delete_data` are functions used to insert and delete
         elements from the circular queue.
- A `head` node keeps track of the current start of the circular queue.
- The `traverse` function shows the current contents of the circular queue.

### Algorithm:

- The function `get_winner` contains the algorithm to find the winner for given `m` & `n`(which are taken as input from the user at the start of the program.). At the start, an `m` element circular queue with data items ranging from `1 - m` (in order) is created and `head` node's link points to the start of this circular queue.(note that data value of node `k is = k (1 <= k <= m))`
- Starting from the first node(pointed to by `head` node's link), round 1 eliminates the nth node. The results are shown which contain details of: remaining members, deleted member, and the number of the node, where the next round starts.
- This continues for (`m-1`) rounds, with one member deleted every round. The data value of the last node that remains is the winner's position no.
