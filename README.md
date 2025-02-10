This code implements a queue using two stacks :
enqueue():
a. Adds an element to the queue by pushing it onto stack1 if there's space.
b. Prints a message for overflow if stack1 is full.
dequeue() :  
a. Removes and returns the front element of the queue.
b. Moves elements from stack1 to stack2 and then pops the top of stack2 to simulate removing the front of the queue.
c. Moves elements back to stack1 after the operation.
peek():
a. Displays the front element of the queue without removing it.
b. Temporarily moves elements from stack1 to stack2 and shows the top of stack2 as the front element.
c. Restores elements back to stack1.
is_empty():
a. Checks if stack1 is empty. If it is, the queue is empty.
find_size():
a. Prints the size of the queue, which is the number of elements in stack1.

Time and Space Complexity :
Time Complexity:
a. Enqueue: O(1), since it only involves pushing an element to stack1.
b. Dequeue: O(n) in the worst case, where n is the number of elements in stack1, as it requires moving all elements from stack1 to stack2 and then back again.
c. Peek: O(n) in the worst case, as it also requires moving all elements from stack1 to stack2 to check the front element.
d. Is Empty: O(1), as it checks if stack1 is empty.
e. Find Size: O(1), as it simply checks the top_of_stack1.
Space Complexity:
O(n), as the space used by the two stacks (stack1 and stack2) is proportional to the number of elements in the queue.
