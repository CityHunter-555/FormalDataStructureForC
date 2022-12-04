#include <stdio.h>
#include <stdlib.h>
#include "../head/AdjacentList.h"
/**
 * 初始化操作
 * @param G 邻接链表
 * @param n 顶点数
 * @param m 图的类型:0为无向,1为有向
 */
void CreateAdjacentList(Adjacentlist *G,int n,int m){
    int i,e=0;slink *p,*q,*s;char x,y;
    G->vex=n;G->tag=m;
    for(i=0;i<n;i++){
        G->ve[i].vertex=i+'A';G->ve[i].first=NULL;}//初始化邻接表
    printf("输入边(x-->y):\n");//用大写字母表示顶点
    scanf("%c%c",&x,&y);//输入边或弧
    while((x!=' ')&&(y!=' ')){  //遇空格结束
        e++;//统计边或弧的数目
        s=(slink * )malloc(sizeof(slink));
        s->num=y-'A';//生成结点，插入相应链表且按结点值升序
        if(G->ve[x-'A'].first==NULL){ //插入到空链表
            G->ve[x-'A'].first=s;
            s->next=NULL;
        }else{
            p=G->ve[x-'A'].first;//插入到第一个结点前
            if(p->num>s->num){
                s->next=p;G->ve[x-'A'].first=s;
            }else{ //先找位置，再插入
                q=p->next;
                while(q!=NULL&&s->num>q->num){p=q;q=q->next;}
                p->next=s;s->next=q;
            }
        }
        if(!G->tag){ //m=0，建立无向图邻接表
            s=(slink *) malloc(sizeof(slink));
            s->num=x-'A';
            if(G->ve[y-'A'].first==NULL){
                G->ve[y-'A'].first=s;
                s->next=NULL;
            }else{
                p=G->ve[y-'A'].first;
                if(p->num>s->num){s->next=p;G->ve[y-'A'].first=s;}
                else{
                    q=p->next;
                    while(q!=NULL&&s->num>q->num){p=q;q=q->next;}
                    p->next=s;s->next=q;
                }
            }
        }
        getchar();
        scanf("%c%c",&x,&y);
    }G->edge=e;
}
void listAdjacentList(Adjacentlist *G){
    int i;slink *p;
    for(i=0;i<G->vex;i++){
        printf("%d:%c--->",i,G->ve[i].vertex);
        p=G->ve[i].first;
        while(p){
            printf("%3d",p->num);
            p=p->next;
        }printf("\n");
    }
}
/**
 * 邻接表的深度优先递归算法
 * @param G 邻接表
 * @param v 顶点下标
 */
int visitedList[MAXVER];
void DFSAdjList(Adjacentlist *G,int v){
    slink *p;
    printf("%3c",G->ve[v].vertex);
    visitedList[v]=1;
    p=G->ve[v].first;
    while(p){
        if(!visitedList[p->num]){
            DFSAdjList(G,p->num);
        }p=p->next;
    }
}
void DFSAdjListGraph(Adjacentlist *G){
    int i;
    //初始化设置所有顶点都没被访问过
    for(i=0;i<G->vex;i++){
        visitedList[i]=0;
    }
    for(i=0;i<G->vex;i++){
        if(!visitedList[i]){ DFSAdjList(G,i);}
    }
}
void BFSAdjList(Adjacentlist *G,int v){
    int quene[MAXVER],front,rear,i;
    slink *p;
    front=rear=0;
    quene[rear++]=v;
    while(front!=rear){
        v=quene[front++];
        printf("%c->",G->ve[v].vertex);
        visitedList[v]=1;
        p=G->ve[v].first;
        while(p!=NULL){
            for(i=0;i<rear;i++){
                if(p->num==quene[i]){ break;}
                if(i>=rear){
                    quene[rear++]=p->num;
                }p=p->next;
            }
        }
    }
}
void BFSAdjListGraph(Adjacentlist *G){
    int i;
    //初始化设置所有顶点都没被访问过
    for(i=0;i<G->vex;i++){
        visitedList[i]=0;
    }
    for(i=0;i<G->vex;i++){
        if(!visitedList[i]){ BFSAdjList(G,i);}
    }
}