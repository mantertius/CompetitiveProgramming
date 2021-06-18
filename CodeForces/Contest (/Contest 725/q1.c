#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define true 1
#define false 0
#define MAX 1000
#define DEBUG if(1)
typedef struct _node
{
    int data;
    struct _node* next;
    struct _node* previous;
}node;
typedef struct _list
{
    node* head;
    node* tail;
}list;

node* initNode(int n)
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;    
    newnode->previous = NULL;
    return newnode;
}
void insertTail(node* nod,list* li)
{
    if (li->head == NULL)
    {
        li->head = nod;
        li->tail = nod;
    }
    else{
        nod->previous = li->tail;
        li->tail->next = nod->previous;
        li->tail = nod->previous;
    }
}
void removeHead(list* l)
{
    node* aux = l->head;
    l->head->next->previous = NULL;
    l->head = l->head->next;
    free(aux);
}
void removeTail(list* l)
{
    node* aux = l->tail;
    l->tail->previous->next = NULL;
    l->tail= l->tail->previous;
    free(aux);
}
int max(int len, int arr[])
{
    int index = 0;
    int max = arr[0];
    for (int i = 0; i < len; i++)
    {
        if(max < arr[i])
        {
            index = i;
            max = arr[i];
        }
    }
    return index;
}
int min(int len, int arr[])
{
    int index = 0;
    int min = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
        {
            index = i;
            min = arr[i];
        }
    }
    return index;
}
int searchMax(list* l)
{
}
int main()
{
    int nTests;
    int nStones;
    scanf("%d",&nTests);
    for (int i = 0; i < nTests; i++)
    {
        int stonePower[100];
        scanf("%d",&nStones);
        for (int i = 0; i < nStones; i++)
        {
           scanf("%d",&stonePower[i]);
        }
        int maxL,maxR,minL,minR;
        maxL = max(nStones,stonePower)+1;
        maxR = nStones-maxL+1;
        minL = min(nStones,stonePower)+1;
        minR = nStones-minL+1;
        
        DEBUG printf("maxL = %d e maxR = %d\n",maxL,maxR);
        DEBUG printf("minL = %d e minR = %d\n",minL,minR);
        int Max,Min;
        Max = maxL<maxR? maxL:maxR;
        Min = minL<minR? minL:minR;
        printf("%d\n",Max+Min);
    }
    
    return 0;
}