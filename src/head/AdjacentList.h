//
// Created by ccc on 2022/12/4.
//

#ifndef FORMALDATASTRUCTURE_ADJACENTLIST_H
#define FORMALDATASTRUCTURE_ADJACENTLIST_H
#define MAXVER 10//设定的最多顶点数
/**
 * 邻接表的定义
 * @param slink 边或弧的结点类型
 * @param ve[] 顶点信息结构
 * @param vex 顶点数
 * @param edge 边(或弧)数
 * @param tag 图的类型
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
