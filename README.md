Two Pointer Search for Secret Weapon Pairs in a Treasure Hunt:

In a game where players are treasure hunters, they are tasked with collecting pairs of weapons from a chest filled with various items. The players need to find two distinct weapons from the chest such that their total power is equal to a specified target power.

The treasure chest contains a sorted array of weapon power values. The goal is to find two distinct weapons whose combined power equals the target. The search must be efficient to handle large chests of weapons, so players are instructed to use a two-pointer technique.

Game Context:
In this game, the players enter the power values of different weapons stored in a sorted array. The array represents the power of each weapon, and the objective is to find two weapons that, when combined, will give a power equal to the target power.

Tasks:
Input:

The game prompts the user to enter the number of weapons in the chest.
The user then inputs a sorted array of weapon power values.
Lastly, the player is given a target power to search for within the chest.
Output:

If two weapons are found whose combined power equals the target, return the value of the two weapons.
If no such pair exists, return "No valid weapon pair found."
Two Pointer Search:
The two-pointer approach is used for efficient searching. Initialize two pointers:
One pointer at the beginning of the array (left).
One pointer at the end of the array (right).
Add the values at the left and right pointers.
If their sum equals the target power, return their 1-based indices.
If the sum is less than the target, move the left pointer to the right (increase it).
If the sum is greater than the target, move the right pointer to the left (decrease it).
Repeat this process until either a valid pair is found or the pointers cross each other.

Example:

Input:
Enter the number of weapons: 7
Enter the sorted weapon powers: 1 3 4 5 7 9 10
Enter the target power: 12
Output:
Weapon pair found! 5 and 7
Explanation: The power values 5 and 7 sum up to 12.

Input :
Enter the number of weapons: 7
Enter the sorted weapon powers: 1 3 4 5 7 9 10
Enter the target power: 20
Output:
No valid weapon pair found.

Requirements:
The array of weapon powers is sorted in ascending order.
Use the two-pointer technique to solve the problem with O(n) time complexity.

Handle cases such as:
There are fewer than two weapons.
The target power cannot be achieved.
The array contains duplicate weapon powers.

Constraints:
Array length: The number of weapons in the chest will be between 2 and 10^6.
Target power: The target power will be a valid integer.

Time Complexity: 1. O(n) , for list creation of size n. 2. O(n) , for first case to move right to last node .
Overall : O(n^2), as we will traverse from left to right and also move right node to second last right node.

Space Complexity : 1. Linked List Storage: O(n) , where n is number of node. 2. auxiliary space : O(1) 3. Overall : O(n).
