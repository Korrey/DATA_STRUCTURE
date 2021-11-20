#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} SqList;

int InitList_Sq(SqList *L);                         //初始化一个空顺序表
void Traverse(SqList *L);                           //遍历
void Destroy(SqList *L);                            //销毁
void Clear(SqList *L);                              //清空
int GetLength(SqList *L);                           //获取长度
int IsEmpty(SqList *L);                             //是否为空
int GetElem(SqList *L, int i, ElemType *e);         //根据i的位置获取对应的值
int LocateElem(SqList *L, ElemType e);              //根据元素值匹配查找，返回序号，未找到返回0
int ListInsert_Sq(SqList *L, int i, ElemType e);    //插入
int ListDelete_Sq(SqList *L, int i);                //根据序号删除某个元素
int MergeList_Sq(SqList LA, SqList LB, SqList *LC); //有序表合并(顺序表实现)
int AppendList_Sq(SqList *L, ElemType e);           //追加

int main()
{
    SqList A;
    SqList B;
    SqList C;

    InitList_Sq(&A);
    InitList_Sq(&B);

    AppendList_Sq(&A, 1);
    AppendList_Sq(&A, 3);
    AppendList_Sq(&A, 5);
    AppendList_Sq(&A, 7);
    AppendList_Sq(&A, 8);
    AppendList_Sq(&A, 9);

    AppendList_Sq(&B, 2);
    AppendList_Sq(&B, 4);
    AppendList_Sq(&B, 6);

    MergeList_Sq(A, B, &C);
    Traverse(&A);
    Traverse(&B);
    Traverse(&C);

    return 0;
}

int InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);

    if (!L->elem)
        exit(-1);

    L->length = 0;

    return 1;
}

void Destroy(SqList *L)
{
    if (L->elem)
        free(L->elem);
}

void Clear(SqList *L)
{
    L->length = 0;
}

int GetLength(SqList *L)
{
    return L->length;
}

int IsEmpty(SqList *L)
{
    if (L->length == 0)
        return 1;

    return 0;
}

int GetElem(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return 0;

    *e = L->elem[i - 1];
    return 1;
}

int LocateElem(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
        if (L->elem[i] == e)
            return i + 1;

    return 0;
}

int ListInsert_Sq(SqList *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length == MAXSIZE)
        return 0;

    for (int j = L->length - 1; i - 1 <= j; j--)
        L->elem[j + 1] = L->elem[j];

    L->elem[i - 1] = e;
    L->length++;
    return 1;
}

int ListDelete_Sq(SqList *L, int i)
{
    if (i < 1 || i > L->length)
        return 0;

    for (int j = i; j < L->length - 1; j++)
        L->elem[j - 1] = L->elem[j];

    L->length--;

    return 1;
}

int MergeList_Sq(SqList LA, SqList LB, SqList *LC)
{
    ElemType *pa = LA.elem;
    ElemType *pb = LB.elem;

    LC->length = LA.length + LB.length;
    LC->elem = (ElemType *)malloc(LC->length * sizeof(ElemType));

    ElemType *pc = LC->elem;

    ElemType *pa_last = LA.elem + LA.length - 1;
    ElemType *pb_last = LB.elem + LB.length - 1;

    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }

    while (pa <= pa_last)
        *pc++ = *pa++;
    while (pb <= pb_last)
        *pc++ = *pb++;

    return 1;
}

void Traverse(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->elem[i]);
    printf("\n");
}

int AppendList_Sq(SqList *L, ElemType e)
{
    L->elem[L->length] = e;
    L->length++;

    return 1;
}
