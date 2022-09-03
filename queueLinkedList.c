#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
enum error_state{
    FRONT_FAILED = 2,
    DEQUE_FAILED,
};
typedef struct Node
{
    u32 data;
    struct Node* next;
} Node;
Node* head = NULL;
void enque(u32 val)
{
    if (head==NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->data = val;
        head->next = NULL;
    }
    else
    {
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = val;
        tmp->next = NULL;
        Node *cur = head;
        while (cur->next!=NULL)cur = cur->next;
        cur->next = tmp;
    }
}
u32 deque()
{
    if (head)
    {
        u32 val = head->data;
        Node *tmp = head->next;
        free(head);
        head = tmp;
        return val;
    }
    exit(DEQUE_FAILED);
}
u32 front()
{
    if (head)return head->data;
    exit(FRONT_FAILED);
}
void print(){
    if (head){
        Node *tmp = head;
        while (tmp){
            printf("%d ",tmp->data);
            tmp = tmp->next;
        }
        puts("");
        return;
    }
    printf("Queue is empty\n");
}
u32 main(){
    enque(8);
    enque(9);
    enque(10);
    printf("%d\n", front());
    deque();
    printf("%d\n", front());
    deque();
    printf("%d\n",front());
    deque();
    printf("%d\n",front());
    //print();
}
