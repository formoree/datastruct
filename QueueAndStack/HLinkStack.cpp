#include <iostream>
#include "head.cpp"
#include <cstdlib>
using namespace std;

bool InitHLinkStack(HLinkStack &S)
{
    S = (SNode*)malloc(sizeof(SNode));
    if(S==NULL) return false;
    S->next = NULL;
    return true;
}

bool CreatHLinkList(HLinkStack &S){
    Elemtype a;
    while(1){
        cin>>a;
        if(a==-1) return false;
        SNode *p = (SNode*)malloc(sizeof(SNode));
        p->data = a;
        p->next = S->next;
        S->next = p;
    }
    return true;
}

bool DeleHLinkList(HLinkStack &S){
    if(!S->next) return false;
    SNode *p = S->next;
    S->next = p->next;
    free(p);
    return true;
}

bool InsertHLinkList(HLinkStack &S,Elemtype e){
    SNode *p = (SNode*)malloc(sizeof(SNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return true;
}


void coutHLinkStack(HLinkStack S)
{
    SNode *p = S->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    HLinkStack S;
    InitHLinkStack(S);
    CreatHLinkList(S);
    DeleHLinkList(S);
    InsertHLinkList(S,3);
    coutHLinkStack(S);
    return 0;
}
