//���鼯��һ�ּ򵥵ļ��ϱ�ʾ��ͨ��������˫�ױ�ʾ����Ϊ���鼯�Ĵ洢�ṹ

#define maxsize 100
int UFsets[maxsize]

void initial(int s[]){
    for(int i=0;i<maxsize;i++)
        s[i] = -1;
}

//���Ҽ���S�е�Ԫ�����ڵ��Ӽ��ϣ������ظ��Ӽ��ϵ����֣�x��
int Find(int s[],int x){
    while(s[x]>=0) x=s[x];
    return x;
}

//��Root1�ϲ���Root2��
void Union(int s[],int Root1,int Root2){
    s[Root1] = Root2;
}
