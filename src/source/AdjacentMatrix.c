#include<stdio.h>
#include "../head/CycleQuqne.h"
#include "../head/AdjacentMatrix.h"
/**
 * 1.初始化操作
 * @param G 邻接矩阵
 */
void CreateAdjMatrix(AdjacentMatrix *G){
    int i,j,k;
    printf("输入顶点数，边(或弧)数及图的种类");
    scanf("%d%d%d%*c",&G->vexnum,&G->arcnum,&G->kind);
    for(k=0;k<G->vexnum;k++){
        G->vex[k]='A'+k;
    }for (i = 0;  i<G->vexnum ; i++) {
        for (j = 0; j <G->vexnum; j++) {
            G->arc[i][j]=0;
        }
    }printf("输入%d条边(弧):\n",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        scanf("%d%d",&i,&j);
        G->arc[i][k]=1;
        if(G->kind==0){G->arc[j][i]=1;}
    }
}
/**
 * 2.输出邻接矩阵操作
 * @param G 邻接矩阵
 */
void ListAdjMatrix(AdjacentMatrix *G){
    int i,j;
    for(i=0;i<G->vexnum;i++){
        printf("&6c----",G->vex[i]);
        for(j=0;j<G->vexnum;j++){
            printf("%4d",G->arc[i][j]);
        }
        printf("\n");
    }
}
/**
 * 邻接矩阵的深度优先递归算法
 * @param G 邻接矩阵
 * @param v 顶点下标
 */
int visitedMatrix[Max];
void DFSAdjMatrix(AdjacentMatrix *G,int v){
    int j;//用于遍历元素
    visitedMatrix[v]=1;//记录该下表的元素已被访问
    printf("%c",G->vex[v]);//打印该位置的顶点值
    //遍历图中的元素
    for(j=0;j<G->vexnum;j++){
        //顶点v到顶点j有边项链，并且顶点j未被访问过
        if(G->arc[v][j]==1&&!visitedMatrix[j]){
            DFSAdjMatrix(G,j);//对顶点j进行访问
        }
    }
}
/**
 * 邻接矩阵的深度遍历函数
 * @param G 邻接矩阵
 */
void DFSAdjMatrixGraph(AdjacentMatrix *G){
    int i;//用于遍历元素
    //初始化设置所有顶点都没被访问过
    for(i=0;i<G->vexnum;i++){
        visitedMatrix[i]=0;
    }for(i=0;i<G->vexnum;i++){
        //如果顶点i未被访问过
        if(!visitedMatrix[i]){ DFSAdjMatrix(G,i);}
    }
}
/**
 * 邻接矩阵的广度遍历算法
 * @param G
 */
void BFSAdjMatrix(AdjacentMatrix *G){
    int i,j;//用于遍历元素
    CycleQuene q;//队列
    //初始设置图的所有顶点都没被访问过
    for (i=0;i<G->vexnum;i++){
        visitedMatrix[i]=0;
    }InitCycleQuene(&q);//初始化队列
    //对每个顶点做循环
    for(i=0;i<G->vexnum;i++){
        if(!visitedMatrix[i]){ //该顶点未被访问过，进行遍历
            visitedMatrix[i]=1;//置访问标记
            printf("%c",G->vex[i]);//打印该顶点i的值
            EnqueneCycleQuene(&q,i);//将该顶点i入队
            //当队列非空时，进行循环
            while (!EmptyCycleQuene(&q)){
                OutqueneCycleQuene(&q,&i);//将队头元素出队，赋值给i
                //遍历当前节点以外的节点j
                for (j = 0; j < G->vexnum;j++) {
                    //若顶点j与当前节点存在边，并且未被访问过
                    if(G->arc[i][j]==1&&!visitedMatrix[j]){
                        visitedMatrix[j]=1;//置访问标记
                        printf("%c",G->vex[j]);
                        EnqueneCycleQuene(&q,j);//将顶点j入队
                    }
                }
            }
        }
    }
}