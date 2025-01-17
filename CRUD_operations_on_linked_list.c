#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insertatstart(node *head, int number)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = number;
        head->next = NULL;
        return head;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = number;
    newnode->next = head;
    return newnode;
}

node *insertatPostition(node *head, int number, int position)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = number;
    newnode->next = NULL;
    int i = 1;
    node *temp = head;
    while (i != position - 1 && temp->next != NULL)
    {
        i++;
        temp = temp->next;
    }
    if (i == position - 1)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid Location \n");
    }
    return head;
}

node *insertatend(node *head, int number)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = number;
    newnode->next = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}

void updateatstart(node *head, int num)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = num;
        head->next = NULL;
    }
    head->data = num;
}

void updateatPostition(node *head, int num, int position)
{
    if (position == 1)
    {
        updateatstart(head, num);
        return;
    }
    int i = 1;
    node *temp = head;
    while (i != position && temp->next != NULL)
    {
        i++;
        temp = temp->next;
    }
    if (i == position)
    {
        temp->data = num;
    }
    else
    {
        printf("Invalid Location \n");
    }
}

void updateatend(node *head, int num)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->data = num;
}

node *deleteatstart(node *head)
{

    if (head == NULL)
    {
        printf("Empty list\n");
        return head;
    }
    head = head->next;
    return head;
}

node *deleteatPostition(node *head, int position)
{
    if (position == 1)
    {
        head = deleteatstart(head);
        return head;
    }
    int i = 1;
    node *temp = head;
    while (i != position - 1 && temp->next != NULL)
    {
        i++;
        temp = temp->next;
    }
    if (i == position - 1)
    {
        temp->next = temp->next->next;
        // temp->next= newnode;
    }
    else
    {
        printf("Invalid Location \n");
    }
    return head;
}

node *deleteatend(node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return head;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

void freeList(node *head)
{
    node *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    int operations;
    printf("Insert NUmber of Opeartion : ");
    scanf("%d", &operations);
    node *head = NULL;
    while (operations--)
    {
        int choice;
        printf("Insert Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter Number to insert at end : ");
            int x;
            scanf("%d", &x);
            if (head == NULL)
            {
                head = insertatstart(head, x);
            }
            else
                head = insertatend(head, x);
        }
        else if (choice == 2)
        {
            printf("Enter Number to insert at Beginning : ");
            int x;
            scanf("%d", &x);
            head = insertatstart(head, x);
        }
        else if (choice == 3)
        {
            printf("Enter position to insert at : ");
            int position;
            scanf("%d", &position);
            printf("Enter Number to insert at a position : ");
            int x;
            scanf("%d", &x);
            head = insertatPostition(head, x, position); // or if n==1 ..call insert at start
        }
        else if (choice == 4)
        {
            printf("Linked lIst looks like : \n");
            display(head);
        }
        else if (choice == 5)
        {
            printf("insert position to update at : ");
            int position;
            scanf("%d", &position);
            printf("insert number to update : ");
            int x;
            scanf("%d", &x);
            updateatPostition(head, x, position);
        }
        else if (choice == 6)
        {
            head = deleteatstart(head);
        }
        else if (choice == 7)
        {
            head = deleteatend(head);
        }
        else if (choice == 8)
        {
            printf("Enter position delete : ");
            int position;
            scanf("%d", &position);
            head = deleteatPostition(head, position);
        }
        else
        {
            printf("Invalid Input");
        }
    }
    freeList(head);
    return 0;
}