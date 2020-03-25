//二叉排序树：BST也称二叉查找树
//特点：
//1）若左子树非空，左子树的每一个结点小于根节点
//2）若右子树非空，右子树的每一个结点大于根节点
//3）左右子树本身也是一颗二叉排序树

#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Elemtype;
typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

void BST_Creat(BSTree &T){
    int p;
    cin>>p;
    if(p == 0)
        T = NULL;
    else
        T = new BSTNode;
        T->data = p;
        BST_Creat(T->lchild);
        BST_Creat(T->rchild);
}

BSTNode* BST_Search(BSTree T,Elemtype key,BSTNode *&p){
    p = NULL;
    while(T!=NULL&&key!=T->data){
        p = T;
        if(key< T->data) T = T->lchild;
        else T->rchild;
    }
    return T;
}

int main (){
    BSTree T;
    BSTNode *p=NULL;
    BST_Creat(T);
    cout<<"创建成功"<<endl;
    BST_Search(T,2,p);
    if(p->data == 2) cout<<"succeed";
    return 0;
}

