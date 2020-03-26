#include <iostream>
#include <cstdlib>
using namespace std;
//二叉树的顺序存储比较适合完全二叉树，其他类型比较浪费存储空间，
//因为我们需要另外的空间来将其补全为完全二叉树，所以我们一般通过链表来实现二叉树的存储

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
