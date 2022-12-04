
#ifndef FORMALDATASTRUCTURE_CYCLEQUQNE_H
#define FORMALDATASTRUCTURE_CYCLEQUQNE_H
#define MAXCSIZE 100 /*队列空间初始分配量*/
typedef int ElemType;/*根据需要定义数据类型*/
/**
 * 循环队列定义
 * @param *base 基地址
 * @param front 队头指针
 * @param rear 队尾指针
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
