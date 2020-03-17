#include <iostream>
#include "SqStack.cpp"

bool bracketCheck(char str[],int length){
    SqStack S;
    InitSqStack(S);
    for(int i=0;i<length;i++){
        if((str[i]=='{')||(str[i]=='(')||(str[i]=='['))
            InsertSqStack(S,str[i]);
        else{
            if(StackEmpty(S)) return false;

            char out;
            DeleSqStack(S, out);
            if((str[i]=='}')&&(out!='{')) return false;
            if((str[i]==']')&&(out!='[')) return false;
            if((str[i]==')')&&(out!='(')) return false;
        }
    return StackEmpty(S);

    }
}

int main()
{
    char str[2],a;
    for(int i=0;i<2;i++)
        {
            cin>>a;
            str[i] = a;
        }
    if(bracketCheck(str,2)) cout<<"Æ¥Åä³É¹¦";
    else cout<<"Æ¥ÅäÊ§°Ü";

    return 0;
}
