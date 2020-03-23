#include "head.cpp"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

//typedef char Elemtype;
//typedef struct BiTNode{
//    Elemtype data;
//    struct BiTNode *lchild,*rchild;
//}BiTNode,*BiTree;


void visit(BiTree T){
     if(T) cout<<T->data<<" ";
}

void CreatBTree(BiTree &T){
    char p;
    cin>>p;
    if(p=='#')
        T = NULL;
    else{
        T = new BiTNode;
        T->data = p;
        CreatBTree(T->lchild);
        CreatBTree(T->rchild);
    }
}
//最简单的中序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//层序遍历
void LeverOrder (BiTree T){
    queue<BiTNode*>S;BiTree p = T;
    while(p||!S.empty()){
        if(p){
            S.push(p);
            p = p->lchild;
        }else{
            p = S.front();S.pop();
            visit(p);p=p->rchild;
        }
    }
}
//递归式的先序遍历
void DPreOrder (BiTree T){
    stack<BiTNode *>S;
    BiTree p=T;
    while(p||!S.empty()){
        if(p){
            visit(p);
            S.push(p);
            p = p->lchild;
        }else{
            p = S.top();S.pop();
            p=p->rchild;
        }
    }
}
int main(){
    BiTree T;
    CreatBTree(T);
    DPreOrder(T);
    return 0;
}

