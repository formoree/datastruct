#include "head.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

//辅助判断栈满方式：
//1.定义结构体时增加变量length length=maxsize时队满
//2.增加标识符lag=0。增加元素时,lag=1;删除时,lag=0;
//
//同时注意rear++再增加元素的操作方式
void InitSqQueue(SqQueue &Q)
{
    Q.prior=Q.rear=0;
}

bool enQueue(SqQueue &Q,Elemtype e){
    //注意这里的队满判断
    if((Q.rear+1)%maxsize==Q.prior)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%maxsize;
    return false;
}

bool deQueue(SqQueue &Q,Elemtype &e){
    if(Q.rear==Q.prior)
        return false;
    e = Q.data[Q.prior];
    Q.prior = (Q.prior+1)%maxsize;
    return true;
}

