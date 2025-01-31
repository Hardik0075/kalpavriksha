Here we are implementing using queue using linked list .
Enqueue() :-
a. A new node is dynamically allocated (malloc).
b. If memory allocation fails, it prints an error message.
c. If the queue is empty (rear_pointer == NULL), both front and rear point to the new node.
d. Otherwise, the new node is linked at the end, and rear_pointer is updated.
i. Time Complexity: O(1)
ii. Space Complexity: O(1)
Dequeue() :-
a. If front_pointer == NULL, print queue underflow.
b. Store the front node's data in dequeued_value.
c. Move front_pointer to the next node.
d. If the queue becomes empty, set rear_pointer = NULL.
e. Free the removed node (free(temporary_node)).
i. Time Complexity: O(1)
ii. Space Complexity: O(1)
Peek_of_queue() :-
a. If the queue is empty, print an error.
b. Otherwise, print the front element.
i. Time Complexity: O(1)
ii. Space Complexity: O(1)
is_queue_empty() :-
a. If front_pointer == NULL, print "Queue is empty".
b. Otherwise, print "Queue is not empty".
i. Time Complexity: O(1)
ii. Space Complexity: O(1)
Size_of_queue():
a. If the queue is empty, print 0.
b. Otherwise, traverse the list and count nodes.
i. Time Complexity: O(n) (since we traverse the entire queue)
ii. Space Complexity: O(1)
Free_queue() :-
a. Function to free the allocated memeory to queue.
i. Time Complexity: O(n)
ii. Space Complexity: O(1)
Overall :
a. Time Complexity : O(n),where n is size of queue;
b. Space Complexity : O(n), where n is size of queue.
