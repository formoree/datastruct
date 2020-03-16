#include "head.cpp"
#include <stdlib.h>
#define initsize 10
//ʵ���˶�̬����洢�ռ�
void InitSlist(SqList &L)
{
    L.data = (Elemtype *)malloc(initsize*sizeof(Elemtype));//Elemtype*���͵�data
    L.length = 0;
    L.maxsize = initsize;
}

void IncSList(SqList &L,int incsize)
{
    int *p = L.data;
    L.data = (Elemtype*)malloc((incsize+L.length)*sizeof(Elemtype));
    for(int i=0;i<L.length;i++)
        L.data[i] = p[i];
    free(p);
    L.length+=incsize;
    L.maxsize+=incsize;
}

bool ListInsert(SqList &L,int i,Elemtype e)
{
    //������Χ�������������
    if(i<0||i>L.length) return false;
    //�Ѿ��������ֵ
    if(i>L.maxsize) IncSList(L,initsize);
    for(int j=L.length-1;j>=i;j--)
        L.data[j+1] = L.data[j];
    L.length--;
    return true;
}

bool ListDele(SqList &L,int i,Elemtype &e )
{
    if(i<0||i>L.length) return false;
    e = L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j]=L.data[j+1];
    L.length--;
    return true;
}

int GetElem(int i ,SqList L)
{
    if(i<0||i>L.length) return false;
    return L.data[i-1];
}

int LocateElem(SqList L,Elemtype e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e) return i+1;
    }
    return false;
}


