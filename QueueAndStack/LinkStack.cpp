#include <iostream>
#include "head.cpp"
#include <cstdlib>
using namespace std;

bool InitLinkStack(LinkStack &S)
{
    S = NULL;
    return true;
}

bool CreatLinkList(LinkStack &S){
    Elemtype a;
    if(S==NULL){
       SNode *p = (SNode*)malloc(sizeof(SNode));
       cin>>a;
       p->data = a;
       p->next = NULL;
       S = p;
    }
    while(1){
        cin>>a;
        if(a==-1) return false;
        SNode *p = (SNode*)malloc(sizeof(SNode));
        p->data = a;
        p->next = S;
        S = p;
    }
    return true;
}

bool DeleLinkList(LinkStack &S){
    if(S==NULL) return false;
    SNode *p = S;
    S = p->next;
    free(p);
    return true;
}

bool InsertLinkList(LinkStack &S,Elemtype e){
    SNode *p = (SNode*)malloc(sizeof(SNode));
    p->data = e;
    p->next = S;
    S = p;
    return true;
}


void coutLinkStack(LinkStack S)
{
    SNode *p = S;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    LinkStack S;
    InitLinkStack(S);
    CreatLinkList(S);
    InsertLinkList(S,8);
    coutLinkStack(S);
    return 0;
}
