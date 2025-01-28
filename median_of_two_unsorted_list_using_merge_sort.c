#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(node **head, int data)
{
    node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *current = *head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

node *get_middle_node(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *slow_pointer = head;
    node *fast_pointer = head->next;
    while (fast_pointer != NULL && fast_pointer->next != NULL)
    {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }

    return slow_pointer;
}

node *merge_sorted_lists(node *left, node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data < right->data)
    {
        left->next = merge_sorted_lists(left->next, right);
        return left;
    }
    else
    {
        right->next = merge_sorted_lists(left, right->next);
        return right;
    }
}

node *merge_sort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *middle = get_middle_node(head);
    node *left_half = head;
    node *right_half = middle->next;
    middle->next = NULL;

    left_half = merge_sort(left_half);
    right_half = merge_sort(right_half);

    return merge_sorted_lists(left_half, right_half);
}

void print_list(node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

double find_median(node *head)
{
    if (head == NULL)
    {
        printf("List is empty. No median.\n");
        return 0;
    }

    node *current = head;
    int count = 0;

    while (current)
    {
        count++;
        current = current->next;
    }

    current = head;
    int middle_index = count / 2;

    if (count % 2 == 1)
    {
        for (int index = 0; index < middle_index; index++)
        {
            current = current->next;
        }
        return current->data;
    }
    else
    {
        for (int index = 0; index < middle_index - 1; index++)
        {
            current = current->next;
        }
        double median = (current->data + current->next->data) / 2.0;
        return median;
    }
}

void free_list(node *head)
{
    while (head != NULL)
    {
        node *temporary_node = head;
        head = head->next;
        free(temporary_node);
    }
}

int main()
{
    node *list1 = NULL, *list2 = NULL;

    printf("Enter the number of elements in List 1: ");
    int number_of_elements_in_list1;
    scanf("%d", &number_of_elements_in_list1);
    if (number_of_elements_in_list1 < 0)
    {
        printf("Number of elements cannot be negative.\n");
        return 0;
    }

    printf("Enter the elements of List 1: \n");
    for (int index = 0; index < number_of_elements_in_list1; index++)
    {
        int data;
        printf("Enter data : ");
        scanf("%d", &data);
        insert_at_end(&list1, data);
    }

    printf("Enter the number of elements in List 2: \n");
    int number_of_elements_in_list2;
    scanf("%d", &number_of_elements_in_list2);
    if (number_of_elements_in_list2 < 0)
    {
        printf("Number of elements cannot be negative.\n");
        return 0;
    }

    printf("Enter the elements of List 1: ");
    for (int index = 0; index < number_of_elements_in_list2; index++)
    {
        int data;
        printf("Enter data : ");
        scanf("%d", &data);
        insert_at_end(&list2, data);
    }

    list1 = merge_sort(list1);
    list2 = merge_sort(list2);

    node *merged_list = merge_sorted_lists(list1, list2);

    printf("Merged List: ");
    print_list(merged_list);

    double median = find_median(merged_list);
    printf("Median: %.2f\n", median);
    free_list(merged_list);
    return 0;
}
