#include <iostream>
#include "head.cpp"
using namespace std;
bool InitSLinkList(SLinkList &S){
    S[0].next = -1;
    for(int i=1;i<Maxsize-1;i++)
    {
        S[i].next = -2;
    }
    return true;
}

bool InsertSLinkList(SLinkList &S,int i,Elemtype e){
    if(i<0||i>=Maxsize) return false;
    for(int j=0;j<Maxsize;j++){
        if(S[j].next == i)
        {
            S[j].data = e;
            return true;
        }
    }
    return false;

}
