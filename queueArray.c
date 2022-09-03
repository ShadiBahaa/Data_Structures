#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
enum error_state{
    FRONT_FAILED = 2,
    DEQUE_FAILED
};
typedef struct Queue
{
    u32 index;
    s32 *arr;
} Queue;
void construct(Queue *que)
{
    que->index = -1;
    que->arr = NULL;
}
void enque(Queue *que,u32 val)
{
    que->arr = (u32*)realloc(que->arr,(que->index+2)*sizeof(u32));
    que->arr[++que->index] = val;
}
u32 deque(Queue *que)
{
    if (que->index!=-1)
    {
        u32 val = que->arr[0];
        que->arr = que->arr+1;
        que->index--;
        return val;
    }
    exit(DEQUE_FAILED);
}
u32 front(Queue* que)
{
    if (que->index==-1)exit(FRONT_FAILED);
    return que->arr[0];
}
void print(Queue *que){
    if (que->index==-1){
        printf("Queue is empty\n");
        return;
    }
    for (s32 cur = 0; cur<=que->index; ++cur){
        printf("%d ",que->arr[cur]);
    }
    printf("\n");
}
u32 main()
{
    Queue que;
    construct(&que);
    enque(&que,9);
    enque(&que,8);
    enque(&que,7);
    printf("%d\n",front(&que));
    print(&que);
    deque(&que);
    deque(&que);
    deque(&que);
    deque(&que);
    print(&que);
}
