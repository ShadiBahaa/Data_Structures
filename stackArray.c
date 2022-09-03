#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
enum error_state{
    TOP_FAILED = 2,
    POP_FAILED,
};
typedef struct Stack
{
    u32 index;
    s32 *arr;
} Stack;
void construct(Stack *stk)
{
    stk->index = -1;
    stk->arr = NULL;
}
void push(Stack *stk,u32 val)
{
    stk->arr = (u32*)realloc(stk->arr,(stk->index+2)*sizeof(u32));
    stk->arr[++stk->index] = val;
}
u32 pop(Stack *stk)
{
    if (stk->index!=-1)
    {
        u32 val = stk->arr[stk->index];
        stk->arr = (u32*)realloc(stk->arr,(stk->index)*sizeof(u32));
        stk->index--;
        return val;
    }
    exit(POP_FAILED);
}
u32 top(Stack* stk)
{
    if (stk->index==-1)exit(TOP_FAILED);
    return stk->arr[stk->index];
}
void print(Stack *stk){
    if (stk->index==-1){
        printf("Stack is empty\n");
        return;
    }
    for (s32 cur = stk->index; cur>=0; --cur){
        printf("%d ",stk->arr[cur]);
    }
    printf("\n");
}
u32 main()
{
    Stack stk;
    construct(&stk);
    push(&stk,7);
    push(&stk,8);
    push(&stk,9);
    printf("%d\n",top(&stk));
    pop(&stk);
    printf("%d\n",top(&stk));
    print(&stk);
}
