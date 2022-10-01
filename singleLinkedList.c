/*
linked list signle:
insert idx
delete idx
search val
updata idx val
sort
print
circular
doubley:
update
insert
delete
*/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
enum error_state
{
    SEARCH_FAILED = 2,
};
typedef struct Node
{
    u32 data;
    struct Node* next;
} Node;
Node* head = NULL;
u32 len = 0;
void insert_last(u32 val)
{
    if (head==NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->data = val;
        head->next = NULL;
    }
    else
    {
        Node*tmp = (Node*)malloc(sizeof(Node));
        tmp->data = val;
        tmp->next = NULL;
        Node* cur = head;
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next = tmp;
    }
    len++;
}
void print()
{
    Node *tmp = head;
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    puts("");
}
void delete_first()
{
    if (head==NULL)
    {
        return;
    }
    Node* tmp = (head)->next;
    free(head);
    head = tmp;
    len--;
}
void delete_last()
{
    if(head != NULL)
    {
        if(head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            Node* temp = head;
            while(temp->next->next != NULL)
                temp = temp->next;
            Node* lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}
void insert_first(u32 value)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = head;
    head = tmp;
    len++;
}
void insert_pos(u32 index, u32 val)
{
    if (index<1 || index>len+1)
    {
        printf("invalid position\n");
        return;
    }
    if (!head)
    {
        head = (Node*)malloc(sizeof(Node));
        (head)->data = val;
        (head)->next = NULL;
    }
    else
    {
        Node *added = (Node *)malloc(sizeof(Node));
        added->data = val;
        if (index==1)
        {
            added->next =(head);
            (head) = added;
        }
        else
        {
            u32 cur = 1;
            Node *tmp = (head);
            while (tmp && cur<index-1)
            {
                cur++;
                tmp = tmp->next;
            }
            Node *after = tmp->next;
            tmp->next = added;
            added->next = after;
        }
    }
    printf("Node with value %d inserted succefully at index %d\n",val,index);
    len++;
}
void delete_pos(u32 index)
{
    if (index<1 || index>len)
    {
        printf("invalid position\n");
        return;
    }
    if (index==1)
    {
        delete_first();
        return;
    }
    Node* prev = NULL;
    Node* tmp = head;
    u32 cur = 1;
    while (cur!=index)
    {
        prev = tmp;
        tmp= tmp->next;
        cur++;
    }
    prev->next = tmp->next;
    free(tmp);
    tmp = NULL;
}
u8 search(u32 val)
{
    for (Node *cur = head; cur!=NULL; cur=cur->next)
    {
        if (cur->data==val)return 1;
    }
    exit(SEARCH_FAILED);
}
void update(u32 index, u32 val)
{
    if (index<1 || index>len){
        printf("invalid position\n");
        return;
    };
    u32 cur = 1;
    Node *tmp = head;
    while (cur!=index)
    {
        cur++;
        tmp = tmp->next;
    }
    tmp->data = val;
}
void sort()
{
    for (Node *first = head; first!=NULL; first= first->next)
    {
        Node* mini = first;
        for (Node * second=first->next; second !=NULL; second=second->next)
        {
            if (second->data<mini->data)mini = second;
        }
        u32 val = first->data;
        first->data = mini->data;
        mini->data = val;
    }
}
u32 main()
{

    insert_pos(1,5);
    insert_pos(2,3);
    insert_pos(1,9);
    update(1,23);
    sort();
    //printf("%d\n",search(43));
    print();
    delete_pos(3);
    print();
}
