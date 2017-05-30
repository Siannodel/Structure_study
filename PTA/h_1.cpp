#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    List result = (List)malloc(sizeof(struct Node));
    PtrToNode r_p = result;
    //PtrToNode p1 = L1->Next;
    //PtrToNode p2 = L2->Next;
    PtrToNode p1 = L1;
    PtrToNode p2 = L2;
    while(p1->Next!=NULL && p2->Next!=NULL)
    {
        if(p1->Next->Data<=p2->Next->Data)
        {
            r_p->Next = p1->Next;
            p1->Next = p1->Next->Next;
            r_p = r_p->Next;
        }
        else
        {
            r_p->Next = p2->Next;
            p2->Next = p2->Next->Next;
            r_p = r_p->Next;
        }
    }
    while(p1->Next!=NULL)
    {
        r_p->Next = p1->Next;
        p1->Next = p1->Next->Next;
        r_p = r_p->Next;
    }
    while(p2->Next!=NULL)
    {
        r_p->Next = p2->Next;
        p2->Next = p2->Next->Next;
        r_p = r_p->Next;
    }
    return result;
}