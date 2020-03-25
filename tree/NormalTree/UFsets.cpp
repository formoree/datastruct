//并查集：一种简单的集合表示，通常用树的双亲表示法作为并查集的存储结构

#define maxsize 100
int UFsets[maxsize]

void initial(int s[]){
    for(int i=0;i<maxsize;i++)
        s[i] = -1;
}

//查找集合S中单元素所在的子集合，并返回该子集合的名字（x）
int Find(int s[],int x){
    while(s[x]>=0) x=s[x];
    return x;
}

//将Root1合并到Root2上
void Union(int s[],int Root1,int Root2){
    s[Root1] = Root2;
}
