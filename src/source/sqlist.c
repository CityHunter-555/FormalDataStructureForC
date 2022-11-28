/*
 * 顺序表相关基本操作
 */
#include <stdio.h>
#include <malloc.h>
#include "../head/sqlist.h"
/**
 * 1.初始化操作
 * 创建一个空的顺序表L
 */
sqlist InitSqlist(){
    sqlist s;
    s.data=(int*)malloc(sizeof(ElemType)*INITSIZE);//由顺序表基址开辟一块内存空间
    if(!s.data){
        printf("初始化失败");
        exit(0);
    }//如果申请失败，直接退出程序
    s.length=0;//因为顺序表中还没开始存元素，将长度初始化为0
    s.listsize=INITSIZE;//初始化储存空间
    return s;//将初始化的顺序表返回
}
/**
 * 2.求表长操作
 * 统计顺序表L中存储的数据元素个数
 * @param L 顺序表
 * @return (L->length)
 */
int GetLengthSqlist(sqlist *L){
    return (L->length);
}
/**
 * 3.取元素操作
 * 取出顺序表L的第i个元素
 * @param L 顺序表
 * @param i 元素下标
 * @param e 存储取出的元素
 * @return 1 操作成功置标
 */
int GetElemSqlist(sqlist *L,int i,ElemType *e){
    if(i<1||i>L->length){return 0;}/*i不合理,取元素失败,返回0*/
    *e=L->data[i-1];
    return 1;//取元素成功,返回1
}
/**
 * 4.元素定位操作
 * 在顺序表L中查找第一个与x值相等的数据元素的位置
 * 思路：从顺序表L的第1个元素开始,逐个进行给定值x和数据元素值的比较,若某个数据元素的值和给定值x相等,则返回该数据元素的位序;若直到最后一个数据元素,其值和x值都不相等,则返回0。
 * @param L 顺序表
 * @param x 给定值
 * @return 0/1 操作失败/成功置标
 */
int LocateSqlist(sqlist *L,ElemType x){
    int i=0;//置初始下标值为0
    while(i<L->length){
        if(L->data[i]==x){return i+1;}//找到,返回位序i+1
        else{i++;}
    }return 0;//没找到,返回0
}
/**
 * 5.插入操作
 * 在顺序表L中的第i个位置上插入一个值为x的数据元素
 * 思路：在长度为n的顺序表中插入一个数据元素时,首先确定插入位置i的合理性(1<=i<=n+1)。若参数i合理,则从位序为n的数据元素开始,把位序为n,n-1,...,i的数据元素依次移到位序为n+1,n,...,i+1的位置上,空出第i个位置,在该位置上存入值为x的数据元素。
 * 时间复杂度O(n)
 * @param L 顺序表
 * @param i 插入位置
 * @param x 插入值
 * @return
 */
int InsertSqlist(sqlist *L,int i,ElemType x){
    int j;
    if(i<1||i>L->length+1){return 0;}    //参数i不合理，返回0
    if(L->length==L->listsize){
        L->data=(ElemType *) realloc(L->data,(L->listsize+1)*(sizeof(ElemType)));
        L->listsize++;                   //重置存储空间长度
    }                                    //存储空间不够，增加一个存储空间
    for(j=L->length-1;j>=i-1;j--) {L->data[j+1]=L->data[j];}//将序号为i及之后的数据元素后移一位
    L->data[i-1]=x;                  //在序号i出放入x
    L->length++;                     //顺序表长度增1
    return 1;                            //插入成功，返回1
}
/**
 * 6.删除操作
 * 将顺序表L的第i个元素删除
 * 思路：在长度为n的顺序表中删除一个数据元素时,首先确定删除位置i的合理性(1<=i<=n)。若i合理,则从位序为i+1的数据元素开始,把位序为i+1,i+2,...,n的数据元素依次移到位序为i,i+1,...n-1的位置上。
 * 时间复杂度O(n)
 * @param L
 * @param i
 * @return
 */
int DeleteSqlist(sqlist *L,int i){
    int j;
    if(i<1||i>L->length) {return 0;} //参数i不合理，返回0
    for(j=i;j<L->length;j++) {L->data[j-1]=L->data[j];}//将序号为i及之后的数据元素前移一位
    L->length--;//顺序表长度-1
    return 1;//删除成功，返回1
}

/**
 * 7.输出操作
 * 输出顺序表L的各数据元素值
 * @param L 顺序表
 * @return
 */
int ListSqlist(sqlist *L){
    int i;
    for(i=0;i<L->length;i++){
        printf("%d,下标:%d  ",L->data[i],i);
    }printf("\n");//利用循环输出顺序表
    return 1;
}
/**
 *
 * @param L
 * @return
 */
int OddBehindEven_Sqlist(sqlist *L){
    int i=0,j=L->length-1;
    ElemType temp;
    while(i<j){
        while(i<j&&L->data[i]%2!=0){i++;}
        while(i<j&&L->data[j]%2!=0){j++;}
        if(i<j){
            temp=L->data[i];
            L->data[i]=L->data[j];
            L->data[j]=temp;
        }
    }
}

int MaxSecSqlist(sqlist *L){
    int i,k;
    for(i=1;i<L->length;i++) {
        if (L->data[i] > L->data[0]) {
            k = L->data[i];
            L->data[i] = L->data[0];
            L->data[0] = k;
        }
    }
    printf("最大值为：");
    printf("%d",L->data[0]);
    printf("\n");
    for(i=2;i<L->length;i++){
        if(L->data[i]>L->data[1]){
            k=L->data[i];
            L->data[i]=L->data[1];
            L->data[1]=k;
        }
    }
    printf("次最大值为：");
    printf("%d",L->data[1]);
    printf("\n");
    return 1;
}

//清空。初始化
void FreeList(sqlist *L) {
    DeleteSqlist(&L, L->length);
    L->length = 0;
    L->listsize = INITSIZE;
}