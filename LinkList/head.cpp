#define Maxsize 10
typedef int Elemtype;
typedef struct SqList{
    Elemtype *data;
    int maxsize;
    int length;
}SqList;

typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode ,*LinkList;

typedef struct DLNode{
    Elemtype data;
    struct DLNode *next,*prior;
}DLNode,*DLinkList;

typedef struct Node{
    Elemtype data;
    int next;//��һ��Ԫ�ص������±�
}SLinkList[Maxsize];

