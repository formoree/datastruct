//������������BSTҲ�ƶ��������
//�ص㣺
//1�����������ǿգ���������ÿһ�����С�ڸ��ڵ�
//2�����������ǿգ���������ÿһ�������ڸ��ڵ�
//3��������������Ҳ��һ�Ŷ���������

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
    cout<<"�����ɹ�"<<endl;
    BST_Search(T,2,p);
    if(p->data == 2) cout<<"succeed";
    return 0;
}

