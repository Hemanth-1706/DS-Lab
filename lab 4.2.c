#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

// Delete first element
void deleteFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First element deleted\n");
}

// Delete specified element
void deleteSpecified()
{
    struct node *temp, *ptr;
    int key;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    if(head->data == key)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Element deleted\n");
        return;
    }

    temp = head;

    while(temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if(temp->next == NULL)
        printf("Element not found\n");
    else
    {
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);

        printf("Element deleted\n");
    }
}

// Delete last element
void deleteLast()
{
    struct node *temp, *ptr;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
            temp = temp->next;

        ptr = temp->next;
        temp->next = NULL;
        free(ptr);
    }

    printf("Last element deleted\n");
}

// Display linked list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;
    printf("Hemanth Nagesh, 1WA25CS095,03-11-26");


    while(1)
    {
        printf("\n--- SINGLY LINKED LIST ---");
        printf("\n1. Create Linked List");
        printf("\n2. Delete First Element");
        printf("\n3. Delete Specified Element");
        printf("\n4. Delete Last Element");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
                    break;

            case 2: deleteFirst();
                    break;

            case 3: deleteSpecified();
                    break;

            case 4: deleteLast();
                    break;

            case 5: display();
                    break;

            case 6: exit(0);

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}


