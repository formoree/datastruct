#include <iostream>
#include <cstdlib>
using namespace std;
//��������˳��洢�Ƚ��ʺ���ȫ���������������ͱȽ��˷Ѵ洢�ռ䣬
//��Ϊ������Ҫ����Ŀռ������䲹ȫΪ��ȫ����������������һ��ͨ��������ʵ�ֶ������Ĵ洢

typedef char Elemtype;
typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void Judge_AVL(BiTree T,int &balance,int &h){
    int bl = 0,br = 0,hl = 0,hr = 0;
    if(T == NULL){
        h = 0;
        balance = 1;
    }
    else if((T->lchild==NULL)&&(T->rchild==NULL)){
        h = 1;
        balance = 1;
    }
    else{
        Judge_AVL(T->lchild,bl,hl);
        Judge_AVL(T->rchild,br,hr);
        if(hl>h2)
            h = hl+1;
        else
            h = hr+1;
        if(abs(hl-hr)<2&&bl==1&&br==1)
            balance = 1;
        else
            balance = 0;
    }
}
