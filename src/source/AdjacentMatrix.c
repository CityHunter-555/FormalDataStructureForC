#include<stdio.h>
#include "../head/CycleQuqne.h"
#include "../head/AdjacentMatrix.h"
/**
 * 1.��ʼ������
 * @param G �ڽӾ���
 */
void CreateAdjMatrix(AdjacentMatrix *G){
    int i,j,k;
    printf("���붥��������(��)����ͼ������");
    scanf("%d%d%d%*c",&G->vexnum,&G->arcnum,&G->kind);
    for(k=0;k<G->vexnum;k++){
        G->vex[k]='A'+k;
    }for (i = 0;  i<G->vexnum ; i++) {
        for (j = 0; j <G->vexnum; j++) {
            G->arc[i][j]=0;
        }
    }printf("����%d����(��):\n",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        scanf("%d%d",&i,&j);
        G->arc[i][k]=1;
        if(G->kind==0){G->arc[j][i]=1;}
    }
}
/**
 * 2.����ڽӾ������
 * @param G �ڽӾ���
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
 * �ڽӾ����������ȵݹ��㷨
 * @param G �ڽӾ���
 * @param v �����±�
 */
int visitedMatrix[Max];
void DFSAdjMatrix(AdjacentMatrix *G,int v){
    int j;//���ڱ���Ԫ��
    visitedMatrix[v]=1;//��¼���±��Ԫ���ѱ�����
    printf("%c",G->vex[v]);//��ӡ��λ�õĶ���ֵ
    //����ͼ�е�Ԫ��
    for(j=0;j<G->vexnum;j++){
        //����v������j�б����������Ҷ���jδ�����ʹ�
        if(G->arc[v][j]==1&&!visitedMatrix[j]){
            DFSAdjMatrix(G,j);//�Զ���j���з���
        }
    }
}
/**
 * �ڽӾ������ȱ�������
 * @param G �ڽӾ���
 */
void DFSAdjMatrixGraph(AdjacentMatrix *G){
    int i;//���ڱ���Ԫ��
    //��ʼ���������ж��㶼û�����ʹ�
    for(i=0;i<G->vexnum;i++){
        visitedMatrix[i]=0;
    }for(i=0;i<G->vexnum;i++){
        //�������iδ�����ʹ�
        if(!visitedMatrix[i]){ DFSAdjMatrix(G,i);}
    }
}
/**
 * �ڽӾ���Ĺ�ȱ����㷨
 * @param G
 */
void BFSAdjMatrix(AdjacentMatrix *G){
    int i,j;//���ڱ���Ԫ��
    CycleQuene q;//����
    //��ʼ����ͼ�����ж��㶼û�����ʹ�
    for (i=0;i<G->vexnum;i++){
        visitedMatrix[i]=0;
    }InitCycleQuene(&q);//��ʼ������
    //��ÿ��������ѭ��
    for(i=0;i<G->vexnum;i++){
        if(!visitedMatrix[i]){ //�ö���δ�����ʹ������б���
            visitedMatrix[i]=1;//�÷��ʱ��
            printf("%c",G->vex[i]);//��ӡ�ö���i��ֵ
            EnqueneCycleQuene(&q,i);//���ö���i���
            //�����зǿ�ʱ������ѭ��
            while (!EmptyCycleQuene(&q)){
                OutqueneCycleQuene(&q,&i);//����ͷԪ�س��ӣ���ֵ��i
                //������ǰ�ڵ�����Ľڵ�j
                for (j = 0; j < G->vexnum;j++) {
                    //������j�뵱ǰ�ڵ���ڱߣ�����δ�����ʹ�
                    if(G->arc[i][j]==1&&!visitedMatrix[j]){
                        visitedMatrix[j]=1;//�÷��ʱ��
                        printf("%c",G->vex[j]);
                        EnqueneCycleQuene(&q,j);//������j���
                    }
                }
            }
        }
    }
}