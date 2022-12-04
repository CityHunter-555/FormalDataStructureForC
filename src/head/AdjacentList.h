//
// Created by ccc on 2022/12/4.
//

#ifndef FORMALDATASTRUCTURE_ADJACENTLIST_H
#define FORMALDATASTRUCTURE_ADJACENTLIST_H
#define MAXVER 10//�趨����ඥ����
/**
 * �ڽӱ�Ķ���
 * @param slink �߻򻡵Ľ������
 * @param ve[] ������Ϣ�ṹ
 * @param vex ������
 * @param edge ��(��)��
 * @param tag ͼ������
 */
typedef char Elemtype;
typedef struct node{
    int num;
    struct node *next;
}slink;
typedef struct {
    struct {
        Elemtype vertex;
        slink *first;
    }ve[MAXVER];
    int vex,edge,tag;
}Adjacentlist;
void CreateAdjacentList(Adjacentlist *G,int n,int m);
void listAdjacentList(Adjacentlist *G);
void DFSAdjList(Adjacentlist *G,int v);
void DFSAdjListGraph(Adjacentlist *G);
void BFSAdjList(Adjacentlist *G,int v);
void BFSAdjListGraph(Adjacentlist *G);
#endif //FORMALDATASTRUCTURE_ADJACENTLIST_H
