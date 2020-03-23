#include "head.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

//typedef struct ThreadNode{
//    Elemtype data;
//    struct ThreadNode *lchild,*rchild;
//    int ltag,rtag;
//}ThreadNode,*ThreadTree;
// tag 0 指向的是左右孩子 1 指向的是前后继

void InThread(ThreadTree &p,ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);
        if(p->lchild==NULL){
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild,pre);
    }
}
//先序和后序遍历，所以我们可以不用了解他们的代码实现，但是要弄清楚他们是怎么构造

void CreatInThTree(ThreadTree &T){
    ThreadTree pre = NULL;
    if(T!=NULL){
        InThread(T,pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

void CreatTree(ThreadTree &T){
    char p;
    if(p=='#')
        T = NULL;
    else {
        T = new ThreadNode;
        T->data = p;
        T->ltag = 0;
        T->rtag = 0;
        CreatTree(T->lchild);
        CreatTree(T->rchild);
    }
}

ThreadNode *FirstNode(ThreadNode *p){
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

void visit(ThreadTree T){
    if(T) cout<<" "<<T->data;
}


void Inorder(ThreadNode *T){
    for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
        visit(p);
}


int main(){
    ThreadTree T;
    CreatTree(T);
    CreatInThTree(T);
    Inorder(T);
    return 0;
}

