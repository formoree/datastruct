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

//遍历连通性问题
//1.在无向图中，对任意一个节点进行一次遍历，若能访问到所有结点，那么这个图就为连通图。
//2.在无向图中，调用遍历函数的次数为连通分量的次数
