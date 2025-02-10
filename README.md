Student Records Management Using Insertion Sort:

Design a program that helps manage student records in a school or university. Each record contains the following details:

Student ID (integer, unique for each student) Name (string, up to 50 characters) Marks (integer, out of 100) Age (integer) Your program should:

Accept multiple student records from the user. Sort the student records using the insertion sort algorithm, based on the following criteria: Primary: Marks in descending order (higher marks first). Secondary: Age in ascending order (younger students first) for students with the same marks. Provide options to: Display the sorted list of students. Add a new student record and maintain the sorted order dynamically. Ensure the program handles edge cases, such as: Duplicate marks or ages. Input validation (e.g., marks should be between 0 and 100, age should be positive, and IDs should be unique). Example: Input:

Number of students: 4 Records: ID: 101, Name: Alice, Marks: 85, Age: 20 ID: 102, Name: Bob, Marks: 90, Age: 21 ID: 103, Name: Charlie, Marks: 85, Age: 19 ID: 104, Name: Diana, Marks: 95, Age: 22 Output (Sorted):

ID: 104, Name: Diana, Marks: 95, Age: 22 ID: 102, Name: Bob, Marks: 90, Age: 21 ID: 103, Name: Charlie, Marks: 85, Age: 19 ID: 101, Name: Alice, Marks: 85, Age: 20

Time complexity :

copy_string () : O(n) , where n is length of string
string_length() : O(n) , where n is length of string
create_student() : O(n) , where n is the length of the name being copied using copy_string .
free_student_list() : O(n) , free_student_list:O(m), where m is the number of nodes in the linked list.
insert_student_sorted() : O(n+m) , where m is number of student in list and n is the length of string for copy_string
display_student() : O(m), where m is number of student in list
Overall Complexity: O(k \* (m+n)) , where k is number of inputs , m is number of nodes , n is length of string.
Space Complexity :

Student nodes : each uses O(1) and there are m nodes , so O(m).
Overall complexity : O(m+n), where n is average length of name variable and m is number of nodes
