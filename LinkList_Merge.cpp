/*
code by 周邓磊
vscode
2020-10-16

测试数据1
4 5
9 7 4 3
8 6 5 2 1

测试数据2
5 5
7 6 2 2 1
9 8 8 7 5
*/

#include <bits/stdc++.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef int ElemType;
typedef int Status;

using namespace std;

struct LNode
{
    ElemType data;
    LNode *next;
};
typedef LNode *LinkList;

void InitList(LinkList &L);
void DestroyList(LinkList &L);
void ClearList(LinkList &L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L, int i, ElemType &e);
int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e); //返回前驱
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e); //返回前驱
Status ListInsert(LinkList L, int i, ElemType e);              //再i前插入e
Status ListDelete(LinkList L, int i, ElemType &e);
void ListTraverse(LinkList L);

void CreateList1(LinkList &L, int n);//逆位序 节点插在表头
void CreateList2(LinkList &L, int n);//顺位序 节点插在表尾
void MergeList(LinkList La, LinkList &Lb, LinkList &Lc); //La,Lb非递减排列，合并La,Lb得到Lc

int main()
{
    //
    LinkList La,Lb,Lc;
    cout<<"分别输入La,Lb长度: ";
        int len_a,len_b;
        cin>>len_a>>len_b;
    cout<<"按非递减顺序输入链表"<<endl;
    cout<<"La:";
        CreateList2(La,len_a);
    cout<<"Lb:";
        CreateList2(Lb,len_b);
    cout<<"La,Lb遍历结果如下："<<endl;
    cout<<"La:";
        ListTraverse(La);
    cout<<"Lb:";
        ListTraverse(Lb);
    MergeList(La,Lb,Lc);
    cout<<"合并后得Lc: ";
    ListTraverse(Lc);
    system("PAUSE");
    return 0;
}

void ListTraverse(LinkList L){
    LinkList p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


void CreateList2(LinkList &L, int n){
    int i;
    LinkList P_New,P_tail;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=nullptr;
    P_tail=L;
    cout<<"输入"<<n<<"个值：";
    for(int i=1;i<=n;i++){
        P_New=(LinkList)malloc(sizeof(LNode));
        cin>>P_New->data;
        P_tail->next=P_New;
        P_tail=P_tail->next;
    }
    P_tail->next=nullptr;
}


void MergeList(LinkList La, LinkList &Lb, LinkList &Lc)
{ // b要销毁
    //指向首节点
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc_tail;

    Lc = pc_tail = La;
    while (pa && pb)
    {
        if (pa->data > pb->data)
        {
            pc_tail->next = pa;
            pc_tail = pa;
            pa = pa->next;
        }
        else
        {
            pc_tail->next = pb;
            pc_tail = pb;
            pb = pb->next;
        }
    }
    pc_tail->next=pa?pa:pb;//pa存在则为pa否则为pb
    free(Lb);
    Lb=nullptr;
}