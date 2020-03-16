#include "head.cpp"
#include <cstdlib>
#include <iostream>
using namespace std;
//为了书写方便，通常采用头指针法 这里我们在训练时两种方法都写上
//typedef struct LNode{
//    Elemtype data;
//    struct LNode *next;
//}LNode ,*LinkList;

bool HInitList(LinkList &L)
{
    L = (LNode*)malloc(sizeof(LNode)); //只申请一个结点，不用相乘
    if(L==NULL) return false;
    L->next = NULL;
    return true;
}

bool InitList(LinkList &L,Elemtype e)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->data = e;
    L->next = NULL;
    return true;
}

bool HSgListInsert(LinkList &L,Elemtype e,int i)
{
    if(i<0) return false;
    int j=0;
    LNode *p;
    LNode *q = (LNode*)malloc(sizeof(LNode));
    q->data = e;
    p = L;
    while(p&&j<i-1){
        p = p->next;
        j++;
    }
    if(p==NULL) return false;
    q->next = p->next;
    p->next = q;
    return true;
}

bool SgListInsert(LinkList &L, int i ,Elemtype e){
    if(i==1){
        LNode *q = (LNode*)malloc(sizeof(LNode));
        q->data = e;
        q->next = L;
        L = q;
        return true;
    }

    if(i<0) return false;
    int j=1;
    LNode *p;
    LNode *q = (LNode*)malloc(sizeof(LNode));
    q->data = e;
    p = L;
    while(p&&j<i-1){
        p = p->next;
        j++;
    }
    if(p==NULL) return false;
    q->next = p->next;
    p->next = q;
    return true;
}

bool deleElem(LinkList &p){
  if(p->next) {
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
  }
  if(p->next == NULL) cout<<"尾节点 无法删除";
  return true;
}

bool insertElem(LinkList &p,Elemtype e){
    LNode *q = (LNode*)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

LNode* locElem(LinkList L,Elemtype e)
{
    LNode *p=L;
    while(p){
        if(p->data == e) return p;
        p = p->next;
    }

    cout<<"未找到值为e的结点"<<endl;
    return NULL;
}

bool eptList(LinkList L){
    if(L->next) return false;
    else return true;
}

int listLength (LinkList L){
    LNode *p = L;
    int n=-1;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}

void headinsert(LinkList &L){
    int e;
    while(1)
    {
        cin>>e;
        if(e==-1) break;
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = e;
        p->next = L->next;
        L->next = p;
    }
}

void tailinsert(LinkList &L){
    LNode *tail=L;
    int e;
    while(1){
        cin>>e;
        if(e==-1) break;
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = e;
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }
}

void PriList(LinkList L)
{
    LNode *p = L->next;
    while(p){
        cout<<" "<<p->data;
        p = p->next;
    }
}

int main(){
    LinkList L;
    HInitList(L);
    tailinsert(L);
    PriList(L);
    return 0;

}
