#ifndef FORMALDATASTRUCTURE_ADJACENTMATRIX_H
#define FORMALDATASTRUCTURE_ADJACENTMATRIX_H
#define Max 10//预设最多定点数
/**
 * 邻接矩阵的简化定义
 * @param vexnum 顶点数
 * @param arcnum 边或弧数
 * @param kind 图的种类
 * @param vex[] 存顶点信息的一维数组
 * @param arc[][] 存边(或弧)信息的二维数组
 */
typedef struct {
    int vexnum,arcnum,kind;
    char vex[Max];
    int arc[Max][Max];
}AdjacentMatrix;
extern int visitedMatrix[Max];
void CreateAdjMatrix(AdjacentMatrix *G);
void ListAdjMatrix(AdjacentMatrix *G);
void DFSAdjMatrix(AdjacentMatrix *G,int v);
void DFSAdjMatrixGraph(AdjacentMatrix *G);
void BFSAdjMatrix(AdjacentMatrix *G);
#endif //FORMALDATASTRUCTURE_ADJACENTMATRIX_H
