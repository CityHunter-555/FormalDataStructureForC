/**
 * 顺序表的定义
 * @param data 存储空间基地址
 * @param length 顺序表长度(已存入元素个数)
 * @param listsize 当前存储空间容量(能存入元素个数)
 */
#ifndef FORMALDATASTRUCTURE_SQLIST_H
#define FORMALDATASTRUCTURE_SQLIST_H
typedef int ElemType;//在实际问题中，根据需要定义所需的数据类型
#define INITSIZE 10//顺序表存储空间的初始分配量
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
