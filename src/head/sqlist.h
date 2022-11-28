/**
 * ˳���Ķ���
 * @param data �洢�ռ����ַ
 * @param length ˳�����(�Ѵ���Ԫ�ظ���)
 * @param listsize ��ǰ�洢�ռ�����(�ܴ���Ԫ�ظ���)
 */
#ifndef FORMALDATASTRUCTURE_SQLIST_H
#define FORMALDATASTRUCTURE_SQLIST_H
typedef int ElemType;//��ʵ�������У�������Ҫ�����������������
#define INITSIZE 10//˳���洢�ռ�ĳ�ʼ������
typedef struct {
    ElemType *data;
    int length;
    int listsize;
}sqlist;
sqlist InitSqlist();
int GetLengthSqlist(sqlist *L);
int GetElemSqlist(sqlist *L,int i,ElemType *e);
int LocateSqlist(sqlist *L,ElemType x);
int InsertSqlist(sqlist *L,int i,ElemType x);
int DeleteSqlist(sqlist *L,int i);
int ListSqlist(sqlist *L);
int OddBehindEven_Sqlist(sqlist *L);
#endif //FORMALDATASTRUCTURE_SQLIST_H
