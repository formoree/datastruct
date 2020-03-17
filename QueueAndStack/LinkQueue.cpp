#include <iostream>
#include "head.cpp"
#include <cstdlib>
using namespace std;

void InitLQueue(LinkQueue &S){
    S.head = S.tail = NULL;
}

void EnQueue(LinkQueue &S,Elemtype e){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    if(S.head==NULL){
        S.head = s;
        S.tail = s;
    }else{
        S.tail->next = s;
        S.tail = s;
    }
}

bool DeQueue(LinkQueue &S){
    if(!S.head) return false;
    LinkNode *p = S.head;
    S.head = p->next;
    if(S.tail = p) S.tail = S.head;
    free(p);
    return true;
}

Elemtype GetQtop(LinkQueue &S){
    if(S.head==NULL) return NULL;
    else return S.head->data;
}

void coutQueue(LinkQueue S){
    LinkNode *p = S.head;
    while(p)
    {
        cout<<" "<<p->data;
        p = p->next;
    }
}

int main(){
    LinkQueue S;
    InitLQueue(S);
    EnQueue(S,6);
    EnQueue(S,8);
    DeQueue(S);
    coutQueue(S);
    return 0;
}

