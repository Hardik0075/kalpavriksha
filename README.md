This code simulates a stack using two queues (queue1 and queue2) for implementing stack operations. push_to_stack:
This function implements the stack push operation. It inserts a value into queue2, then transfers all elements from queue1 to queue2 so that the most recent element inserted is at the front, mimicking stack behavior (last-in-first-out). The elements from queue2 are then copied back to queue1.
pop_from_stack:
This function performs the stack pop operation. It removes the front element from queue1 (which is the most recently added element) and shifts the front pointer to the next element. If the queue becomes empty, it resets the front and rear pointers to -1.
peek_of_stack:
Displays the top element of the stack (i.e., the front element of queue1).
is_stack_empty:
Checks if the stack is empty by verifying if front is -1, meaning there are no elements in queue1.
size_of_stack:
Computes and prints the size of the stack by subtracting the front from the rear pointers, plus one.
Main Function:
The main function provides a user interface to choose between the stack operations. It reads the user's input and calls the appropriate function (push, pop, peek, is empty, size) based on the choice.

Time and Space Complexity :
push_to_stack():
a. Time Complexity: O(n), where n is the number of elements in the stack. This is because all elements from queue1 are transferred to queue2.
b. Space Complexity: O(n), as two queues (queue1 and queue2) are used to store the stack elements. pop_from_stack():
a. Time Complexity: O(1), since the pop_from_stack only involves updating the front pointer.
b. Space Complexity: O(1), as it does not require additional space, aside from the pointers.
peek_of_stack():
a. Time Complexity: O(1), as it only accesses the element at the front of queue1.
b. Space Complexity: O(1), as no extra space is used.
is_stack_empty():
a. Time Complexity: O(1), as it just checks the value of the front pointer.
b. Space Complexity: O(1), as no extra space is required.
size_of_stack():
a. Time Complexity: O(1), as it calculates the size using the difference between the front and rear pointers.
b. Space Complexity: O(1), as no extra space is required.
