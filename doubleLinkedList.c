#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
typedef struct Node
{
    u32 data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* head = NULL;
u32 len = 0;
void insert(u32 val)
{
    if (head==NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->data = val;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        Node *added = (Node*)malloc(sizeof(Node));
        added->data = val;
        added->prev = tmp;
        added->next = NULL;
        tmp->next = added;
    }
    len++;
}
void update(u32 index, u32 val)
{
    if (index<1 || index>len){printf("Invalid position\n");return;}
    u32 cur = 1;
    Node *tmp = head;
    while (cur!=index)
    {
        cur++;
        tmp = tmp->next;
    }
    tmp->data = val;
}
void print()
{
    Node *cur = head;
    while (cur)
    {
        printf("%d ",cur->data);
        cur= cur->next;
    }
    puts("");
}
void delete(u32 val)
{
    for (Node *cur = head; cur!=NULL; cur=cur->next)
    {
        if (cur->data==val)
        {
            Node *before = cur->prev;
            Node *after = cur->next;
            if (before)before->next = after;
            if (after)after->prev = before;
            free(cur);
            if (before)cur = before;
            else
            {
                head = after;
                cur = head;
            }
        }
    }
}
u32 main()
{
    insert(5);
    insert(6);
    insert(8);
    //update(3,9);
    delete(8);
    print();
}
