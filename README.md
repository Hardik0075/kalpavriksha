This C program implements a stack using a linked list and provides basic stack operations in a menu-driven manner.
push_in_stack() :-
a. Creates a new node using malloc.
b. If memory allocation fails, it prints an error.
c. Inserts the new node at the beginning of the linked list .
d. Increments top to track the stack size.
pop_from_stack() :-
a. Removes the top node from the stack.
b. Checks for stack underflow before popping.
c. If only one node exists, sets head = NULL.
d. Otherwise, moves head to the next node.
e. Decrements top.
peek_of_stack() :-
a. Prints the top element of the stack.
b. If the stack is empty, it prints an appropriate message.
is_stack_empty() :-
a. Checks if top == -1 to determine whether the stack is empty. 5. size_of_stack() :-
a. Prints the size of the stack, which is top + 1.
main():-
a. Initializes head to NULL and top to -1.
b. Uses a menu-driven loop to perform stack operations.

Time and Space Complexity :-

    1. Push :Time Complexity : O(1) and spcae complexity : O(1) .
    2. Pop :Time Complexity : O(1) and spcae complexity : O(1) .
    3. Peek	:Time Complexity : O(1) and spcae complexity : O(1) .
    4. IsEmpty: Time Complexity : O(1) and spcae complexity : O(1) .
    5. Size	: Time Complexity : O(1) and spcae complexity : O(1) .
    6. Main : Time Complexity : O(m) , m is number of operations and spcae complexity : O(n) , n is size of stack .
