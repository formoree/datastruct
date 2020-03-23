#define maxsize 10
typedef char Elemtype;

typedef struct {
    Elemtype data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[maxsize];
    int n;
}PTree;
