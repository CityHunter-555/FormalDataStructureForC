#include <stdio.h>
#include <stdlib.h>
#include "../head/CycleQuqne.h"
/**
 * 1.初始化操作
 * 创建一个空循环队列cq
 * @param cq 循环队列
 */
void InitCycleQuene(CycleQuene *cq){
    cq->base=(ElemType *) malloc(MAXCSIZE* sizeof(ElemType));
    cq->front=cq->rear;
}
/**
 * 2.求队列长度操作
 * 计算循环队列中数据元素的个数
 * @param cq 循环队列
 * @return
 */
int GetLengthCycleQuene(CycleQuene *cq){
    return ((cq->rear-cq->front+MAXCSIZE)%MAXCSIZE);
}
/**
 * 3.取队头元素操作
 * 取出循环队列cq的队头元素值
 * @param cq 循环队列
 * @param e 存储取出元素值
 * @return
 */
int GetFrontCycleQuene(CycleQuene *cq,ElemType *e){
    if(cq->front==cq->rear){return 0;}
    *e=cq->base[cq->front];
    return 1;
}
/**
 * 4.入队列操作
 * 在循环队列cq的队尾插入值为x的元素
 * @param cq 循环队列
 * @param x 入队元素值
 * @return
 */
int EnqueneCycleQuene(CycleQuene *cq,ElemType x){
    if((cq->rear+1)%MAXCSIZE==cq->front){return 0;}
    cq->base[cq->rear]=x;
    cq->rear=(cq->rear+1)%MAXCSIZE;
    return 1;
}
/**
 * 5.出队列操作
 * @param cq 循环队列
 * @param e 存储取出的元素值
 * @return
 */
int OutqueneCycleQuene(CycleQuene *cq,ElemType *e){
    if(cq->front==cq->rear){return 0;}
    *e=cq->base[cq->front];
    cq->front=(cq->front+1)%MAXCSIZE;
    return 1;
}
/**
 * 6.判队空操作
 * 判断循环队列cq是否为空
 * @param cq 循环队列
 * @return
 */
int EmptyCycleQuene(CycleQuene *cq){
    if(cq->front==cq->rear){return 1;}
    else {return 0;}
}
/**
 * 7.输出操作
 * 输出循环队列cq从队头到队尾的所有元素
 * @param cq 循环队列
 */
void ListCycleQuene(CycleQuene *cq){
    int i;
    i=cq->front;
    while(i!=cq->rear){
        printf("%4d",cq->base[i]);
        i=(i+1)%MAXCSIZE;
    }
}