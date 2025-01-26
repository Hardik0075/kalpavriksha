#include <stdio.h>
#include <stdlib.h>

typedef struct task
{
    int task_id;
    int deadline;
    int priority;
    int duration;
    struct task *next;
} task;

task *create_task(int task_id, int deadline, int priority, int duration)
{
    task *new_task = (task *)malloc(sizeof(task));
    if (new_task == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_task->task_id = task_id;
    new_task->deadline = deadline;
    new_task->priority = priority;
    new_task->duration = duration;
    new_task->next = NULL;
    return new_task;
}

void free_task_list(task **head)
{
    task *temporary_node = *head;
    task *next_task;

    while (temporary_node != NULL)
    {
        next_task = temporary_node->next;
        free(temporary_node);
        temporary_node = next_task;
    }

    *head = NULL;
}

void swap_tasks(task *task_first, task *task_second)
{
    int temporary_node_id = task_first->task_id;
    int temporary_node_deadline = task_first->deadline;
    int temporary_node_priority = task_first->priority;
    int temporary_node_duration = task_first->duration;

    task_first->task_id = task_second->task_id;
    task_first->deadline = task_second->deadline;
    task_first->priority = task_second->priority;
    task_first->duration = task_second->duration;

    task_second->task_id = temporary_node_id;
    task_second->deadline = temporary_node_deadline;
    task_second->priority = temporary_node_priority;
    task_second->duration = temporary_node_duration;
}

int compare_tasks(task *task_first, task *task_second)
{
    if (task_first->deadline < task_second->deadline)
        return 1;
    if (task_first->deadline > task_second->deadline)
        return 0;
    if (task_first->priority > task_second->priority)
        return 1;
    if (task_first->priority < task_second->priority)
        return 0;
    return task_first->duration < task_second->duration;
}

void selection_sort_tasks(task *head)
{
    task *current = head;
    task *minimum_task;
    task *iterator_node;

    while (current != NULL)
    {
        minimum_task = current;
        iterator_node = current->next;

        while (iterator_node != NULL)
        {
            if (compare_tasks(iterator_node, minimum_task))
            {
                minimum_task = iterator_node;
            }
            iterator_node = iterator_node->next;
        }

        if (minimum_task != current)
        {
            swap_tasks(current, minimum_task);
        }
        current = current->next;
    }
}

void add_task_to_list(task **head, int task_id, int deadline, int priority, int duration)
{
    task *new_task = create_task(task_id, deadline, priority, duration);
    if (new_task == NULL)
    {
        free_task_list(head);
        return;
    }
    if (*head == NULL)
    {
        *head = new_task;
    }
    else
    {
        task *temporary_node = *head;
        while (temporary_node->next != NULL)
        {
            temporary_node = temporary_node->next;
        }
        temporary_node->next = new_task;
    }
}

void print_task_list(task *head)
{
    task *temporary_node = head;
    while (temporary_node != NULL)
    {
        printf("taskID: %d, Deadline: %d, Priority: %d, Duration: %d\n", temporary_node->task_id, temporary_node->deadline, temporary_node->priority, temporary_node->duration);
        temporary_node = temporary_node->next;
    }
}

int main()
{
    int number_of_tasks;

    printf("Enter the number of tasks: ");
    scanf("%d", &number_of_tasks);
    while (number_of_tasks <= 0)
    {
        printf("Invalid input! Please enter a positive integer for the number of tasks.\n");
        printf("Enter the number of tasks: ");
        scanf("%d", &number_of_tasks);
    }

    task *head = NULL;

    for (int iterator = 0; iterator < number_of_tasks; iterator++)
    {
        int task_id, deadline, priority, duration;

        printf("\nEnter details for task %d:\n", iterator + 1);

        printf("task ID: ");
        scanf("%d", &task_id);
        while (task_id < 0)
        {
            printf("Invalid input! task ID cannot be less than 0. Please enter again.\n");
            printf("task ID: ");
            scanf("%d", &task_id);
        }

        printf("Deadline: ");
        scanf("%d", &deadline);
        while (deadline < 0)
        {
            printf("Invalid input! Deadline cannot be less than 0. Please enter again.\n");
            printf("Deadline: ");
            scanf("%d", &deadline);
        }

        printf("Priority: ");
        scanf("%d", &priority);
        while (priority < 0)
        {
            printf("Invalid input! Priority cannot be less than 0. Please enter again.\n");
            printf("Priority: ");
            scanf("%d", &priority);
        }

        printf("Duration: ");
        scanf("%d", &duration);
        while (duration < 0)
        {
            printf("Invalid input! Duration cannot be less than 0. Please enter again.\n");
            printf("Duration: ");
            scanf("%d", &duration);
        }

        add_task_to_list(&head, task_id, deadline, priority, duration);
    }

    printf("\nOriginal task List:\n");
    print_task_list(head);

    selection_sort_tasks(head);

    printf("\nSorted task List:\n");
    print_task_list(head);

    free_task_list(&head);

    return 0;
}
