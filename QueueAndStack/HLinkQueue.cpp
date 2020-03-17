#include <iostream>
#include "head.cpp"
#include <cstdlib>
using namespace std;

void InitHLQueue(LinkQueue &S){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    S.head = S.tail = p;
}

void EnHQueue(LinkQueue &S,Elemtype e){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = NULL;
    S.tail->next = p;
    S.tail = p;
}

bool DeHQueue(LinkQueue &S){
    if(!S.head) return false;
    LinkNode *p = S.head->next;
    S.head->next = p->next;
    free(p);
}

Elemtype Getop(LinkQueue &S){
    if(S.head==NULL) return NULL;
    else return S.head->next->data;
}

void coutHQueue(LinkQueue S){
    LinkNode *p = S.head->next;
    while(p)
    {
        cout<<" "<<p->data;
        p = p->next;
    }
}

int main(){
    LinkQueue S;
    InitHLQueue(S);
    EnHQueue(S,6);
    EnHQueue(S,8);
    DeHQueue(S);
    coutHQueue(S);
    return 0;
}

