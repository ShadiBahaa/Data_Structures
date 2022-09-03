#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
enum error_state{
    TOP_FAILED = 2,
    POP_FAILED,
};
typedef struct Node
{
    u32 data;
    struct Node* next;
} Node;
Node* head = NULL;
void push(u32 val)
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
        tmp->next = head;
        head = tmp;
    }
}
u32 pop()
{
    if (head)
    {
        u32 val = head->data;
        Node *tmp = head->next;
        free(head);
        head = tmp;
        return val;
    }
    exit(POP_FAILED);
}
u32 top()
{
    if (head)return head->data;
    exit(TOP_FAILED);
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
    printf("Stack is empty\n");
}
u32 main()
{
    push(9);
    push(8);
    push(7);
    pop();
    pop();
    pop();
    pop();
    print();
}
