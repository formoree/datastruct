bool visited[maxsize]
void DFSTraverse(Graph G){
    for(int i=0;i<G.vexnum;++i)
        visited[i] = false;
    for(int i=0;i<G.vexnum;++i)
        if(!visited[i])
            DFS(G,i);
}
void DFS(Grapg G, int v){
    visit(v);
    visited[v] = true;
    for(w=RirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            if(!visited[w])
                DFS(G,w);
}

//������ͨ������
//1.������ͼ�У�������һ���ڵ����һ�α��������ܷ��ʵ����н�㣬��ô���ͼ��Ϊ��ͨͼ��
//2.������ͼ�У����ñ��������Ĵ���Ϊ��ͨ�����Ĵ���
