#include "head.cpp"
#include <iostream>
using namespace std;

void InitSqStack (SqStack &S)
{
    S.top = -1;
}

bool InsertSqStack(SqStack &S,Elemtype e){
    if(S.top==maxsize-1) {
        cout<<"Õ»Âú"<<endl;
        return false;
    }
    S.top++;
    S.data[S.top] = e;
    return true;
}

bool DeleSqStack(SqStack &S,Elemtype &e)
{
    if(S.top==-1) return false;
    e = S.data[S.top];
    S.top--;
    return true;
}

bool emptySqStack(SqStack S)
{
    if(S.top==maxsize-1) return true;
    else return false;
}

void CreatSqStack(SqStack &S){
    Elemtype a;
    while(!emptySqStack(S)){
        cin>>a;
        if(a==-1) break;
        S.top++;
        S.data[S.top] = a;
    }
}
void coutSqStack (SqStack S){
    for(int i=0;i<=S.top;i++)
    cout<<S.data[i]<<" ";
}

bool StackEmpty(SqStack S){
    if(S.top==-1) return true;
    else return false;
}
