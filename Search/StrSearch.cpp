int index(SString S,SString T,int pos){
    int i=pos,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            i++;j++;
        }
        else {
            i=i-j+2;//模式串中子串下移一位
            j=1;
        }
        if(j>T.length) return i-T.length;
        else return 0;
    }
}//模式匹配长度j

//KMP算法
void get_next(String T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(T.ch[j]==T.ch[i]||j==0) {
            next[i]=j;
            i++;j++;
        }
        else j = next[j];//j一直指向前后缀相同时的最后一个元素
    }
}
int index(SString S,SString T,intnext[],int pos){
    int i=pos,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            i++;j++;
        }
        else j=next[j];//j=j-[(j-1)-mov[j-1]] 经过对next集变换后形成了现在这个式子右移加一
        if(j>T.length) return i-T.length;
        else return 0;
    }
}



