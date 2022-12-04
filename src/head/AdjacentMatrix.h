#ifndef FORMALDATASTRUCTURE_ADJACENTMATRIX_H
#define FORMALDATASTRUCTURE_ADJACENTMATRIX_H
#define Max 10//Ԥ����ඨ����
/**
 * �ڽӾ���ļ򻯶���
 * @param vexnum ������
 * @param arcnum �߻���
 * @param kind ͼ������
 * @param vex[] �涥����Ϣ��һά����
 * @param arc[][] ���(��)��Ϣ�Ķ�ά����
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
