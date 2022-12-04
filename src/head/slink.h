/**
 * 单链表的定义
 * @param data 数据域
 * @param next 指针域
 */
#ifndef FORMALDATASTRUCTURE_SLINK_H
#define FORMALDATASTRUCTURE_SLINK_H
typedef int ElemType;//在实际问题中，根据需要定义所需的数据类型
typedef struct node{
    ElemType data;
    struct node *next;
}slink;
slink *CreateSlink(int n);
int GenLenSlink(slink *head);
int GetElemSlink(slink *head,int i,ElemType *e);
int LocateSlink(slink *head,ElemType x);
int DeleteSlink(slink *head,int i,ElemType *e);
int InsertSlink(slink *head,int i,ElemType x);
void listSlink(slink *head);
#endif //FORMALDATASTRUCTURE_SLINK_H
