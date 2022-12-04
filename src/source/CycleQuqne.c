#include <stdio.h>
#include <stdlib.h>
#include "../head/CycleQuqne.h"
/**
 * 1.��ʼ������
 * ����һ����ѭ������cq
 * @param cq ѭ������
 */
void InitCycleQuene(CycleQuene *cq){
    cq->base=(ElemType *) malloc(MAXCSIZE* sizeof(ElemType));
    cq->front=cq->rear;
}
/**
 * 2.����г��Ȳ���
 * ����ѭ������������Ԫ�صĸ���
 * @param cq ѭ������
 * @return
 */
int GetLengthCycleQuene(CycleQuene *cq){
    return ((cq->rear-cq->front+MAXCSIZE)%MAXCSIZE);
}
/**
 * 3.ȡ��ͷԪ�ز���
 * ȡ��ѭ������cq�Ķ�ͷԪ��ֵ
 * @param cq ѭ������
 * @param e �洢ȡ��Ԫ��ֵ
 * @return
 */
int GetFrontCycleQuene(CycleQuene *cq,ElemType *e){
    if(cq->front==cq->rear){return 0;}
    *e=cq->base[cq->front];
    return 1;
}
/**
 * 4.����в���
 * ��ѭ������cq�Ķ�β����ֵΪx��Ԫ��
 * @param cq ѭ������
 * @param x ���Ԫ��ֵ
 * @return
 */
int EnqueneCycleQuene(CycleQuene *cq,ElemType x){
    if((cq->rear+1)%MAXCSIZE==cq->front){return 0;}
    cq->base[cq->rear]=x;
    cq->rear=(cq->rear+1)%MAXCSIZE;
    return 1;
}
/**
 * 5.�����в���
 * @param cq ѭ������
 * @param e �洢ȡ����Ԫ��ֵ
 * @return
 */
int OutqueneCycleQuene(CycleQuene *cq,ElemType *e){
    if(cq->front==cq->rear){return 0;}
    *e=cq->base[cq->front];
    cq->front=(cq->front+1)%MAXCSIZE;
    return 1;
}
/**
 * 6.�жӿղ���
 * �ж�ѭ������cq�Ƿ�Ϊ��
 * @param cq ѭ������
 * @return
 */
int EmptyCycleQuene(CycleQuene *cq){
    if(cq->front==cq->rear){return 1;}
    else {return 0;}
}
/**
 * 7.�������
 * ���ѭ������cq�Ӷ�ͷ����β������Ԫ��
 * @param cq ѭ������
 */
void ListCycleQuene(CycleQuene *cq){
    int i;
    i=cq->front;
    while(i!=cq->rear){
        printf("%4d",cq->base[i]);
        i=(i+1)%MAXCSIZE;
    }
}