Problem Statement
You are given two singly unsorted linked lists, L1 and L2, each containing integer values. Your task is to merge the two lists into a single sorted linked list and find the median of the merged list. The merged list must be sorted in ascending order.

Requirements:
Merge the Lists: Merge the two given unsoted linked lists into one sorted linked list. The linked lists L1 and L2 may not be sorted initially, but after merging, the final list must be in ascending order.
Find the Median: Return the median of the merged linked list.
If the merged list has an odd number of elements, the median is the middle element.
If the merged list has an even number of elements, the median is the average of the two middle elements.

Constraints:
Each list may contain up to 10^6nodes.
The linked list elements are integers, and they may be positive or negative.
The lists L1 and L2 may be of different lengths.
Input Format:
The first input is an integer n1, denoting the number of nodes in the first linked list L1.
The second input is a sequence of n1 integers, each representing the value of a node in the linked list L1.
The third input is an integer n2, denoting the number of nodes in the second linked list L2.
The fourth input is a sequence of n2 integers, each representing the value of a node in the linked list L2.
Output Format:
The output should first display the merged linked list in ascending order.
The output should then display the median of the merged list.
Example:
Input:
Enter the number of elements in L1: 3
Enter the elements of L1: 1 4 7
Enter the number of elements in L2: 4
Enter the elements of L2: 2 3 6 8
Output:
Merged List: 1 → 2 → 3 → 4 → 6 → 7 → 8
Median: 4
Explanation:
The merged list from L1 and L2 is: 1 → 2 → 3 → 4 → 6 → 7 → 8, which is already sorted.
The number of elements in the merged list is 7 (odd), so the median is the middle element, which is 4.

Time Complexity :
1.Insertion in list : O(n1^2+n2^2) , where n1 and n2 are size of list1 and list2.
1.sorting and merging : O(n1logn1 + n2logn2 ) , where n1 and n2 are the lengths of the two linked lists.
2.Finding Median: O(n1+n2), as it iterates through the entire merged list.
3.Printing List: O(n1+n2), as it traverses the merged list.
Overall Time Complexity: O(n1^2+n2^2 + n1logn1 + n2logn2 + (n1+n2))
Space Complexity : O(n1+n2), for the merged linked list.
