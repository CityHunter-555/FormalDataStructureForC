#include <stdio.h>
#include <stdlib.h>
#include "../head/AdjacentList.h"
/**
 * ��ʼ������
 * @param G �ڽ�����
 * @param n ������
 * @param m ͼ������:0Ϊ����,1Ϊ����
 */
void CreateAdjacentList(Adjacentlist *G,int n,int m){
    int i,e=0;slink *p,*q,*s;char x,y;
    G->vex=n;G->tag=m;
    for(i=0;i<n;i++){
        G->ve[i].vertex=i+'A';G->ve[i].first=NULL;}//��ʼ���ڽӱ�
    printf("�����(x-->y):\n");//�ô�д��ĸ��ʾ����
    scanf("%c%c",&x,&y);//����߻�
    while((x!=' ')&&(y!=' ')){  //���ո����
        e++;//ͳ�Ʊ߻򻡵���Ŀ
        s=(slink * )malloc(sizeof(slink));
        s->num=y-'A';//���ɽ�㣬������Ӧ�����Ұ����ֵ����
        if(G->ve[x-'A'].first==NULL){ //���뵽������
            G->ve[x-'A'].first=s;
            s->next=NULL;
        }else{
            p=G->ve[x-'A'].first;//���뵽��һ�����ǰ
            if(p->num>s->num){
                s->next=p;G->ve[x-'A'].first=s;
            }else{ //����λ�ã��ٲ���
                q=p->next;
                while(q!=NULL&&s->num>q->num){p=q;q=q->next;}
                p->next=s;s->next=q;
            }
        }
        if(!G->tag){ //m=0����������ͼ�ڽӱ�
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
 * �ڽӱ��������ȵݹ��㷨
 * @param G �ڽӱ�
 * @param v �����±�
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
    //��ʼ���������ж��㶼û�����ʹ�
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
    //��ʼ���������ж��㶼û�����ʹ�
    for(i=0;i<G->vex;i++){
        visitedList[i]=0;
    }
    for(i=0;i<G->vex;i++){
        if(!visitedList[i]){ BFSAdjList(G,i);}
    }
}