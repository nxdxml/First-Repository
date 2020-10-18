/*
code by �ܵ���
vscode
2020-10-16

��������1
4 5
9 7 4 3
8 6 5 2 1

��������2
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
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e); //����ǰ��
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e); //����ǰ��
Status ListInsert(LinkList L, int i, ElemType e);              //��iǰ����e
Status ListDelete(LinkList L, int i, ElemType &e);
void ListTraverse(LinkList L);

void CreateList1(LinkList &L, int n);//��λ�� �ڵ���ڱ�ͷ
void CreateList2(LinkList &L, int n);//˳λ�� �ڵ���ڱ�β
void MergeList(LinkList La, LinkList &Lb, LinkList &Lc); //La,Lb�ǵݼ����У��ϲ�La,Lb�õ�Lc

int main()
{
    //
    LinkList La,Lb,Lc;
    cout<<"�ֱ�����La,Lb����: ";
        int len_a,len_b;
        cin>>len_a>>len_b;
    cout<<"���ǵݼ�˳����������"<<endl;
    cout<<"La:";
        CreateList2(La,len_a);
    cout<<"Lb:";
        CreateList2(Lb,len_b);
    cout<<"La,Lb����������£�"<<endl;
    cout<<"La:";
        ListTraverse(La);
    cout<<"Lb:";
        ListTraverse(Lb);
    MergeList(La,Lb,Lc);
    cout<<"�ϲ����Lc: ";
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
    cout<<"����"<<n<<"��ֵ��";
    for(int i=1;i<=n;i++){
        P_New=(LinkList)malloc(sizeof(LNode));
        cin>>P_New->data;
        P_tail->next=P_New;
        P_tail=P_tail->next;
    }
    P_tail->next=nullptr;
}


void MergeList(LinkList La, LinkList &Lb, LinkList &Lc)
{ // bҪ����
    //ָ���׽ڵ�
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
    pc_tail->next=pa?pa:pb;//pa������Ϊpa����Ϊpb
    free(Lb);
    Lb=nullptr;
}