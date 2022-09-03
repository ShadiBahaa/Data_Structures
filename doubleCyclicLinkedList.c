#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
typedef struct Node
{
    u32 data;
    struct Node* next;
    struct Node* prev;
} Node;
Node *tail = NULL;
u32 len = 0;
void insert(u32 val)
{
    if (tail==NULL)
    {
        tail = (Node *)malloc(sizeof(Node));
        tail->data = val;
        tail->next=tail;
        tail->prev=tail;
        len++;
        return;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    Node *nx = tail->next;
    Node *pre = tail->prev;
    tmp->data = val;
    tmp->next = nx;
    tmp->prev = tail;
    tail->next = tmp;
    //pre->next = tmp;
    nx->prev = tmp;
    tail = tmp;
    len++;
}
void delete(u32 val)
{
    if (!tail)return;
    if (tail->next==tail && tail->data==val)
    {
        free(tail);
        tail = NULL;
        len--;
        return;
    }
    //Node *prev = tail;
    Node *tmp = tail->next;
    while (tmp!=tail)
    {
        if (tmp->data==val)
        {
            //printf("tmp %d\n",tmp->data);
            Node *pre = tmp->prev;
            //printf("pre %d\n",pre->data);
            Node *nex = tmp->next;
            //printf("nex %d\n",nex->data);
            pre->next = nex;
            //printf("pre %d\n",pre->data);
            nex->prev = pre;
            //printf("nex %d\n",nex->data);
            free(tmp);
            len--;
            tmp = nex;
            //printf("tmp2 %d\n",tmp->data);
        }
        else
        {
            tmp = tmp->next;
        }
    }
    if (tmp->data==val)
    {
        Node *pre = tmp->prev;
        Node *nex = tmp->next;
        pre->next = nex;
        nex->prev = pre;
        free(tmp);
        len--;
        tail = pre;
    }
    if (tail->next==tail && tail->data==val)
    {
        free(tail);
        tail = NULL;
    }
}
void update(u32 index, u32 val)
{
    if (index<1 || index>len){printf("Invalid position\n");return;}
    Node *head = tail->next;
    u32 cur = 1;
    while (cur!=index)
    {
        cur++;
        head = head->next;
    }
    head->data = val;
}
void print()
{
    if (!tail)return;
    Node *tmp = tail->next;
    while (tmp!=tail)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("%d ",tmp->data);
    puts("");
}
u32 main()
{
    insert(5);
    insert(6);
    insert(7);
    insert(5);
    insert(7);
    insert(6);
    insert(6);
    insert(5);
    insert(7);
    update(3,8);
    print();
    //delete(7);
    delete(5);
    //delete(6);
    print();

}
