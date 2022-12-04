/**
 * ������Ķ���
 * @param data ������
 * @param next ָ����
 */
#ifndef FORMALDATASTRUCTURE_SLINK_H
#define FORMALDATASTRUCTURE_SLINK_H
typedef int ElemType;//��ʵ�������У�������Ҫ�����������������
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
