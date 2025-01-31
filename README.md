Here , we are implementing queue using one stack:
enqueue:
Adds a value to the stack if there's space. If the stack is full, a "Queue overflow" message is printed. dequeue:
Removes the front element of the queue. If the stack is empty, a "Queue underflow" message is printed. The function works recursively to simulate queue behavior using a stack by first removing elements until the front element is found and then re-enqueuing the other elements back into the stack.
peek_of_queue:
Displays the front element of the queue. It works similarly to dequeue but only checks the element without removing it permanently.
is_queue_empty:
Checks whether the stack (used as the queue) is empty.
find_size_of_queue:
Computes the size of the queue by checking the top_of_stack index. If the stack is empty, it prints "Queue is empty".

Time and Space Complexity :
enqueue():
a. Time Complexity: O(1), since it simply pushes an element onto the stack.
b. Space Complexity: O(1), as the space used is only for the element being inserted into the stack.
dequeue():
a. Time Complexity: O(n), because the recursive calls need to pop all elements from the stack until the front element is reached, and then push elements back.
b. Space Complexity: O(n), due to the recursive call stack.
peek_of_queue():
a. Time Complexity: O(n), since it recursively calls itself to find the front element.
b. Space Complexity: O(n), due to the recursion stack.
is_queue_empty():
a. Time Complexity: O(1), as it checks if the stack is empty.
b. Space Complexity: O(1), as it uses no additional space.
find_size_of_queue():
a. Time Complexity: O(1), as it checks the size by looking at the top_of_stack index.
b. Space Complexity: O(1), as it does not use any extra space.
Overall : Time Complexity : O(n) and space Complexity : O(n).
