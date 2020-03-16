#include <iostream>
#include "head.cpp"
#include <cstdlib>
using namespace std;

bool InitDLinkList(DLinkList &L){
    //对于DLinkLit与DLNode的使用，分别用来强调链表还是结点
    L =(DLNode*)malloc(sizeof(DLNode));
    if(L==NULL) return false;
    L->next = L->prior = NULL;
    return true;
}

bool InsertDList(DLinkList &L,int i ,Elemtype e)
{
    if(i<0) return false;
    DLNode*p = L;
    int j =0;
    while(p&&j<i-1){
        j++;
        p = p->next;
    }
    if(p==NULL) return false;
    DLNode*q =(DLNode*)malloc(sizeof(DLNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    q->prior= p;
    if(q->next != NULL)
    q->next->prior = q;
    return true;
}

bool DeleDList(DLinkList &L,int i )
{
    if(i<0) return false;
    DLNode*p = L;
    int j =0;
    while(p&&j<i-1){
        j++;
        p = p->next;
    }
    if(p==NULL) return false;
    DLNode*q =p->next;
    p->next = q->next;
    if(p->next!=NULL)
    p->next->prior = p;
    free(q);
    return true;
}

bool CreatDLNode(DLinkList &L){
    int a;
    while(1){
        cin>>a;
        if(a==-1) break;
        DLNode*p =(DLNode*)malloc(sizeof(DLNode));
        p->data = a;
        p->next = L->next;
        L->next = p;
        p->prior= L;
        if(p->next!=NULL)
        p->next->prior = p;
    }
    return true;
}

void coutDList(DLinkList L)
{
    DLNode *p = L->next;
    while(p)
    {
        cout<<" "<<p->data;
        p = p->next;
    }
}
int main()
{
    DLinkList L;
    InitDLinkList(L);
    CreatDLNode(L);
    InsertDList(L,1,1);
    coutDList(L);
    return 0;
}

