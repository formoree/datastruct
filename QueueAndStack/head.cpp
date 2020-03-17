#define maxsize 10
typedef char Elemtype;
typedef struct{
    Elemtype data[maxsize];
    int top;
}SqStack;

//top0+1=top1;
typedef struct {
    Elemtype data[maxsize];
    int top0;
    int top1;
}ShStack;

typedef struct SNode{
    Elemtype data;
    struct SNode *next;
}SNode,*LinkStack,*HLinkStack;

typedef struct {
    Elemtype data[maxsize];
    int prior,rear;
}SqQueue;

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *head,*tail;
}LinkQueue;
