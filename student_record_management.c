#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int student_id;
    char name[50];
    int marks;
    int age;
    struct student *next;
} student;

void copy_string(char destination[], char source[])
{
    int index = 0;
    while (source[index] != '\0')
    {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
}

int string_length(char string[])
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

student *create_student(int student_id, char *name, int marks, int age)
{
    student *new_student = (student *)malloc(sizeof(student));
    if (new_student == NULL)
    {
        return NULL;
    }
    new_student->student_id = student_id;
    copy_string(new_student->name, name);
    new_student->marks = marks;
    new_student->age = age;
    new_student->next = NULL;
    return new_student;
}

void free_student_list(student **head)
{
    student *current = *head;
    while (current != NULL)
    {
        student *temporary_node = current;
        current = current->next;
        free(temporary_node);
    }
    *head = NULL;
}

void insert_student_sorted(student **head, int student_id, char *name, int marks, int age)
{
    student *new_student = create_student(student_id, name, marks, age);
    if (new_student == NULL)
    {
        printf("Memory Allocation Failed");
        free_student_list(head);
        return;
    }
    if (*head == NULL || ((*head)->marks < marks) ||
        ((*head)->marks == marks && (*head)->age > age))
    {
        new_student->next = *head;
        *head = new_student;
        return;
    }

    student *current = *head;
    while (current->next != NULL && (current->next->marks > marks || (current->next->marks == marks && current->next->age <= age)))
    {
        current = current->next;
    }

    new_student->next = current->next;
    current->next = new_student;
}

void display_students(student *head)
{
    printf("\nStudent Records:\n");
    while (head != NULL)
    {
        printf("ID: %d, Name: %s, Marks: %d, Age: %d\n", head->student_id, head->name, head->marks, head->age);
        head = head->next;
    }
}

int main()
{
    int number_of_students;
    printf("Enter the number of students: ");
    scanf("%d", &number_of_students);

    while (number_of_students <= 0)
    {
        printf("Invalid input!\nPlease enter a positive number of students: ");
        scanf("%d", &number_of_students);
    }

    student *head = NULL;

    for (int iterator = 0; iterator < number_of_students; iterator++)
    {
        int student_id, marks, age;
        char name[50];

        printf("\nEnter details for student %d:\n", iterator + 1);

        printf("Student ID: ");
        scanf("%d", &student_id);

        printf("Name: ");
        scanf(" %[^\n]", name);

        printf("Marks (0-100): ");
        scanf("%d", &marks);
        while (marks < 0 || marks > 100)
        {
            printf("Invalid marks!\nEnter marks between 0 and 100: ");
            scanf("%d", &marks);
        }

        printf("Age: ");
        scanf("%d", &age);
        while (age <= 0)
        {
            printf("Invalid age!\nEnter a positive age: ");
            scanf("%d", &age);
        }
        insert_student_sorted(&head, student_id, name, marks, age);
    }

    printf("\nSorted Student Records:\n");
    display_students(head);

    free_student_list(&head);
    return 0;
}