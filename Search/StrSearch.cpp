int index(SString S,SString T,int pos){
    int i=pos,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            i++;j++;
        }
        else {
            i=i-j+2;//ģʽ�����Ӵ�����һλ
            j=1;
        }
        if(j>T.length) return i-T.length;
        else return 0;
    }
}//ģʽƥ�䳤��j

//KMP�㷨
void get_next(String T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(T.ch[j]==T.ch[i]||j==0) {
            next[i]=j;
            i++;j++;
        }
        else j = next[j];//jһֱָ��ǰ��׺��ͬʱ�����һ��Ԫ��
    }
}
int index(SString S,SString T,intnext[],int pos){
    int i=pos,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            i++;j++;
        }
        else j=next[j];//j=j-[(j-1)-mov[j-1]] ������next���任���γ����������ʽ�����Ƽ�һ
        if(j>T.length) return i-T.length;
        else return 0;
    }
}



