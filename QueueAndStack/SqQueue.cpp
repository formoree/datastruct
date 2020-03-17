#include "head.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

//�����ж�ջ����ʽ��
//1.����ṹ��ʱ���ӱ���length length=maxsizeʱ����
//2.���ӱ�ʶ��lag=0������Ԫ��ʱ,lag=1;ɾ��ʱ,lag=0;
//
//ͬʱע��rear++������Ԫ�صĲ�����ʽ
void InitSqQueue(SqQueue &Q)
{
    Q.prior=Q.rear=0;
}

bool enQueue(SqQueue &Q,Elemtype e){
    //ע������Ķ����ж�
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

