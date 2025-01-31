Here we are implementing queue using array .
Enqueue():
a. If the queue is full (rear == size_of_queue - 1), we print Queue Overflow.
b. If inserting the first element, front is set to 0 .
c. The new element is inserted at rear + 1, and rear is incremented.
Dequeue():
a. If front > rear, the queue is empty (Underflow).
b. The front element is printed and removed by incrementing front.
c. If the last element is dequeued, both front and rear are reset to -1.
Peek_of_queue() :
a. If the queue is empty, print a message.
b. Otherwise, print the element at front (the first element in the queue).
is_queue_empty():
a. If front > rear, the queue is empty.
b. Otherwise, the queue is not empty.
size_of_queue():
a. The queue size is rear - front + 1.
b. If the queue is empty, print a message.
main():
a. The user enters the queue size.
b. A loop runs until the user selects Exit (6).
c. The user chooses an operation (1 to 6), and the respective function is called.

Time and Space Complexity :
Time Complexity of all the function is O(1) and whole code O(m) , m is number of operation.
Space complexity of function is O(1) and whole code is O(n), where n is size of queue.
