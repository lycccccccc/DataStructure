/*线性表：顺序结构*/

#include <stdio.h>


#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqlList;

Status InitList(SqlList *L) 
{ 
    L->length=0;
    return OK;
}

Status GetElem(SqlList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length){
        return ERROR;
        }

    *e = L.data[i-1];
    return OK;
}

Status ListInsert(SqlList *L, int i, ElemType e)
{
    int k;
    if (L->length==MAXSIZE){
        return ERROR;
        }
    if (i<1 || i>L->length+1){
        return ERROR;
        }
    if (i<=L->length){
        for (k=L->length-1;k>=i-1;k--){
            L->data[k+1]=L->data[k];
            }
        }
    L->data[i-1] = e;
    L->length++;
    return OK;
    
}

Status ListDelete(SqlList *L, int i, ElemType *e)
{
    int k;
    if (L->length==0){
        return ERROR;
        }
    if (i<1 || i>L->length){
        return ERROR;
        }

    *e=L->data[i-1];

    if (i<L->length){
        for (k=i;k<L->length;k++){
            L->data[k-1]=L->data[k];
        }
    
    L->length--;
    return OK;
    }
}

//遍历数组
Status ListTraveres(SqlList L)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }

    return OK;
}

int main(){
    
    SqlList L;
    ElemType e;
    //int i;
    int j, k;
    InitList(&L);
    printf("初始数组长度:%d\n", L.length);

    for(j=1;j<=5;j++){
        ListInsert(&L, 1, j);
    }
    printf("插入元素后\n");
    ListTraveres(L);

    printf("数组长度:%d\n", L.length);

    return 0;
}




