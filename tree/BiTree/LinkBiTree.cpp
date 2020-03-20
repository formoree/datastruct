#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
//��������˳��洢�Ƚ��ʺ���ȫ���������������ͱȽ��˷Ѵ洢�ռ䣬
//��Ϊ������Ҫ����Ŀռ������䲹ȫΪ��ȫ����������������һ��ͨ��������ʵ�ֶ������Ĵ洢

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
//�㷨���Ӷ�Ϊn

//����ݹ�Ǳ����㷨
void QMidOrder(BiTree T){
    stack<BiTree>S;BiTree p=T;
    while(p||!S.empty()){
        if(p){
            S.push(p);
            p = p->lchild;
        }else{
            p = S.top();
            S.pop();visit(p);
            p = p->rchild;
        }
    }
}

//����ݹ�Ǳ����㷨
void QPreOrder(BiTree T){
    stack<BiTree>S;BiTree p=T;
    while(p||!S.empty()){
        if(p){
            visit(p);
            S.push(p);
            p = p->lchild;
        }else{
            S.pop();
            p = p->rchild;
        }
    }
}

//��α����㷨
void LeverOrder(BiTree T){
    queue<BiTree>Q;
    BiTree p;
    Q.push(T);
    while(!Q.empty()){
        p=Q.front();
        Q.pop();
        visit(p);
        if(p->lchild) Q.push(p->lchild);
        if(p->rchild) Q.push(p->rchild);
    }
}

//�ɱ������й��������
//���У������������������������ܹ�����һ��Ψһ������
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
    QMidOrder(T);
    return 0;
}

