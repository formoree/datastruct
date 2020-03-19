#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
//二叉树的顺序存储比较适合完全二叉树，其他类型比较浪费存储空间，
//因为我们需要另外的空间来将其补全为完全二叉树，所以我们一般通过链表来实现二叉树的存储

typedef char Elemtype;
typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void visit(BiTree T){
    if(T) cout<<" "<<T->data;
}

void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    }
}
//算法复杂度为n

//中序递归非遍历算法
void QPreOrder(BiTree T){
    stack<BiTree>S;BiTree p=T;
    if(p||!S.empty()){
        if(p){
            S.push(p);
            p = p->lchild;
        }else{
            S.pop();visit(p);
            p = p->rchild;
        }
    }
}

//层次遍历算法
void LeverOrder(BiTree T){
    queue<BiTree>Q;
    BiTree p;
    Q.push(T);
    if(!Q.empty()){
        p=Q.front();
        Q.pop();
        visit(p);
        if(p->lchild) Q.push(p->lchild);
        if(p->rchild) Q.push(p->rchild);
    }
}

//由遍历序列构造二叉树
//后（中）序遍历序列与中序遍历序列能够构造一个唯一二叉树
void CreatBTree(BiTree &T)
{
    char p;
    cin>>p;
    if(p=='#')
        T=NULL;
    else{
        T = new BiTNode;
        T->data = p;
        CreatBTree(T->lchild);
        CreatBTree(T->rchild);
    }
}

int main(){
    BiTree T;
    CreatBTree(T);
    LeverOrder(T);
    return 0;
}

