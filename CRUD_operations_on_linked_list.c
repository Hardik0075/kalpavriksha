#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
void insertatstart(int number)
{

    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = number;
        head->next = NULL;
        return;
    }
    else
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = number;
        newnode->next = head;
        head = newnode;
    }
    // 	return newnode;
    return;
}

void insertatPostition(int number, int position)
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
    return;
}

void insertatend(int number)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = number;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    // 	return;
}

void display()
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
    return;
}

void updateatPostition(int num, int position)
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

void updateatend(int num)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->data = num;
    return;
}

void deleteatstart()
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    head = head->next;
    return;
}

void deleteatPostition(int position)
{
    if (position == 1)
    {
        deleteatstart(head);
        return;
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
    return;
}

void deleteatend()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

void freeList()
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
            // 			if(head==NULL) {
            // 				insertatstart(x);
            // 			}
            // 			else
            insertatend(x);
        }
        else if (choice == 2)
        {
            printf("Enter Number to insert at Beginning : ");
            int x;
            scanf("%d", &x);
            insertatstart(x);
        }
        else if (choice == 3)
        {
            printf("Enter position to insert at : ");
            int position;
            scanf("%d", &position);
            printf("Enter Number to insert at a position : ");
            int x;
            scanf("%d", &x);
            if (position == 1)
            {
                insertatstart(x);
            }
            else
                insertatPostition(x, position); // or if n==1 ..call insert at start
        }
        else if (choice == 4)
        {
            printf("Linked lIst looks like : \n");
            display();
        }
        else if (choice == 5)
        {
            printf("insert position to update at : ");
            int position;
            scanf("%d", &position);
            printf("insert number to update : ");
            int x;
            scanf("%d", &x);
            updateatPostition(x, position);
        }
        else if (choice == 6)
        {
            deleteatstart();
        }
        else if (choice == 7)
        {
            deleteatend();
        }
        else if (choice == 8)
        {
            printf("Enter position delete : ");
            int position;
            scanf("%d", &position);
            deleteatPostition(position);
        }
        else
        {
            printf("Invalid Input");
        }
    }
    freeList();
    return 0;
}