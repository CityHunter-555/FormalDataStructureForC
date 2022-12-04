
#ifndef FORMALDATASTRUCTURE_CYCLEQUQNE_H
#define FORMALDATASTRUCTURE_CYCLEQUQNE_H
#define MAXCSIZE 100 /*���пռ��ʼ������*/
typedef int ElemType;/*������Ҫ������������*/
/**
 * ѭ�����ж���
 * @param *base ����ַ
 * @param front ��ͷָ��
 * @param rear ��βָ��
 */
typedef struct {
    ElemType *base;
    int front;
    int rear;
}CycleQuene;
void InitCycleQuene(CycleQuene *cq);
int GetLengthCycleQuene(CycleQuene *cq);
int GetFrontCycleQuene(CycleQuene *cq,ElemType *e);
int EnqueneCycleQuene(CycleQuene *cq,ElemType x);
int OutqueneCycleQuene(CycleQuene *cq,ElemType *e);
int EmptyCycleQuene(CycleQuene *cq);
void ListCycleQuene(CycleQuene *cq);
#endif //FORMALDATASTRUCTURE_CYCLEQUQNE_H
