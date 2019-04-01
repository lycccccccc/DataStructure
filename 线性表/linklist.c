/*顺序表: 链式结构*/
/*单链表*/

    
#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define ERROR 0
#define OK 1


typedef int ElemType;
typedef int Status;


typedef struct Node
{
    ElemType data;
    struct Node *next; 
}Node;

typedef struct Node *LinkList;

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

Status InitList(LinkList *L) 
{ 
    *L = (LinkList)malloc(sizeof(Node)); 
    if(!(*L)){
        return ERROR;
        } 
    (*L)->next = NULL; 

    return OK;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if (!p || j > i){
        return ERROR;
    }

    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p || j > i){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}


Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while(p->next && j < i){
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}

void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next;
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for(i = 0; i < n; i++){
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListTraveres(LinkList L)
{
    LinkList p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main(){
    LinkList L;
    ElemType e;
    //Status i;
    int j;
    InitList(&L);
    printf("InitLength:%d\n", ListLength(L));

    for(j = 1; j <= 5; j++){
        ListInsert(&L, 1, j);
    }
    printf("GetElem:\n");
    ListTraveres(L);

    printf("ListLength:%d\n", ListLength(L));

    GetElem(L, 1, &e);
    printf("GetElem data:%d", e);

    return 0;
}
