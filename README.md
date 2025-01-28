Game Leaderboard Sorting

You are tasked with implementing a sorting function to rank players on a game leaderboard using the Quick Sort algorithm. Each player has the following attributes:
Player ID (integer): A unique identifier for each player.
Player Name (string): The player's username or nickname.
Score (integer): The player's total score in the game.
The leaderboard is currently unordered, and you need to sort it in descending order of score. In the event of a tie (when two or more players have the same score), the players should be sorted in alphabetical order of their names in ascending order.

Tasks:
Implement sorting to the leaderboard based on:
Primary criterion: Score in descending order.
Secondary criterion: If two players have the same score, sort by Name in ascending order.

Input:
The program should first prompt the user to input the number of players.
Then, for each player, the program should ask for their Player ID, Player Name, and Score.
Output:
After sorting, display the leaderboard with the players' details in the sorted order.
Example:
Input:

Enter number of players: 5

Player ID: 1
Name: Jack
Score: 1500

Player ID: 2
Name: Anna
Score: 1800

Player ID: 3
Name: Mike
Score: 1500

Player ID: 4
Name: Zoe
Score: 2000

Player ID: 5
Name: Ben
Score: 1800
Output:

Sorted Leaderboard:
Player ID: 4, Name: Zoe, Score: 2000
Player ID: 2, Name: Anna, Score: 1800
Player ID: 5, Name: Ben, Score: 1800
Player ID: 1, Name: Jack, Score: 1500
Player ID: 3, Name: Mike, Score: 1500

Time Complexity : 1. append_player() : O(n^2) , for n nodes and each time n traversal to append it. 2. quick_sort() = O(nlogn) -> average case and O(n^2) ->worst case 3. partition : O(n\*l) , where n is number of players and l is average length of sting 4. copy_String and compare_String : O(m) , where m size of string . 5. free_list(), O(n), where n is nuner of players. 6. Overall = O(n^2)

Space Complexity : 1. player_list() : O(n), n is number of nodes. 2. quick sort partioning : O(logn) ->average case and O(n) ->worst case 3. Auxiliary Space : O(1) 4. Overall : O(n)
