Item Search in a Store Inventory (Linear Search)
You are tasked with implementing a search function for finding an item in a store’s inventory using the Linear Search algorithm. The inventory is represented as a list of items where each item has a unique ID and a name.
Your program will take a target item name and search for it in the inventory list. If the item exists, return the item’s ID; otherwise, return a message indicating that the item is not found.

Tasks:
Data Structure: Represent the store inventory as an array or list of items, where each item contains:
Item ID (integer): A unique identifier for each item.
Item Name (string): The name of the item.
Linear Search: Implement the Linear Search algorithm to:
Search for an item by its name in the inventory list.
Return the Item ID if the item is found.
Return a message like "Item not found" if the item is not in the inventory.

Input:
The program should first prompt the user to input the number of items in the store inventory.
Then, for each item, the user will enter the Item ID and Item Name.
Finally, the program will prompt the user to input the target item name they want to search for.

Output:
If the item is found, display: Item found! Item ID: <ID>.
If the item is not found, display: Item not found.

Example:
Input:
Enter the number of items in the inventory: 3

Enter Item deatials: 1,Laptop
Enter Item deatials: 2,Mouse
Enter Item deatials: 3,Keyboard

Enter the target item name: Phone
Output:
Item not found

Time Complexity : 1. linear_search(): O(n) , where n is number of nodes. 2. add_to_list(): O(n) , as we have to traverse whole list to add new node. 3. copy_string(): O(m), where m is the length of the item name. 4. compare_string() : O(m), where m is length of the small item name. 5. Overall : O(n^2) , to add n nodes to our list we need to traverse our list n times.

Space Complexity : 1. O(n * m) , where n is the number of items and m is the average length of the item names. 2. O(1) , for other temporary variables. 3. Overall : O(n*m).
