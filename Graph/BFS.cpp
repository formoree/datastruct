bool visited[maxsize]
//对非连通图的访问
void BFStraverse(Graph G){
    for(int i=0;i<G.vexnum;++i)
        visit[i] = false;
    queue<vertex> Q;
    for(int i=0;i<G.vexnum;++i)
        if(!visited[i]) BFS(G,i);
}
void BFS(Graph G,int v){
    visit(v);
    visited[v] = true;
    Q.push(v);
    while(!Q.empty()){
        v = Q.front();Q.pop();
        for(w=RirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            if(!visited[w]){
                visit(w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

//应用：解决无权图单源最短路径问题
void BFS_MIN_Distance(Graph G , int u ){
    for(int i=0;i<G.vexnum;++i)
        d[i] = max;
    visited[u] = true;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty()){
        u = Q.front();Q.pop();
        for(w=RirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w)){
            if(!visited[w]){
                d[w] = d[u]+1;
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

//邻接矩阵的广度优先生成树唯一，邻接表法的不唯一（因为邻接表的生成不唯一）
