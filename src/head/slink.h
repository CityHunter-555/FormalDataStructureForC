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
#endif //FORMALDATASTRUCTURE_SLINK_H
