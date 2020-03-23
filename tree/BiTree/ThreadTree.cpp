#include "head.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

//typedef struct ThreadNode{
//    Elemtype data;
//    struct ThreadNode *lchild,*rchild;
//    int ltag,rtag;
//}ThreadNode,*ThreadTree;
// tag 0 ָ��������Һ��� 1 ָ�����ǰ���

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
//����ͺ���������������ǿ��Բ����˽����ǵĴ���ʵ�֣�����ҪŪ�����������ô����

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

