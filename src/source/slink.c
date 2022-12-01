/*
 * 单链表相关基本操作
 */
#include <stdio.h>
#include <stdlib.h>
#include "../head/slink.h"
/**
 * 1.建立一个单链表
 * 创建一个含有n个元素的带头结点的单链表head
 * 该算法的时间复杂度为O(n).当n<1时,建立的时一个带头结点的空链表。
 * @param n 单链表元素个数
 * @return slink *head 单链表
 */
slink *CreateSlink(int n){
    slink *head,*p,*s;/*p用于指向新链入结点,s用于指向新开辟结点*/
    int i;
    p=head=(slink *)malloc(sizeof(slink));/*创建头结点*/
    for(i=1;i<=n;i++){
        s=(slink *) malloc(sizeof(slink));/*s指向新开辟结点*/
        scanf("%d",&s->data);/*新结点数据域赋值*/
        p->next=s;/*将新结点连接到p所指结点的后面*/
        p=s;/*p指向新链入结点*/
    }p->next=NULL;/*尾结点的指针域置为空*/
    return head;/*返回头节点*/
}
/**
 * 2.求表长操作
 * 返回单链表head的长度
 * 思路：设置一个整型变量i作为计数器,i初值为0,指针p指向第1个结点。若p值不为空,则i值增1,同时指针p往后移动一次,重复上述操作,直到p为空为止。i的值即为表长。
 * 该算法的时间复杂度为O(n)。
 * @param head 单链表
 * @return n
 */
int GenLenSlink(slink *head){
    slink *p;int n;
    p=head->next;n=0;
    while(p!=NULL){
        n++;p=p->next;
    }return n;
}
/**
 * 3.取元素操作
 * 取出单链表head的第i个元素的值
 * 思路：首先确定i的取值范围(1<=i<=n),再从单链表head的第1个结点开始,顺序逐个往后搜索,直到找到第i个结点,将该结点的元素值带回
 * 时间复杂度O(n)
 * @param head 单链表
 * @param i 取出元素下标
 * @param e 存储取出的元素
 * @return
 */
int GetElemSlink(slink *head,int i,ElemType *e){
    slink *p;int j;
    if(i<1){return 0;}//i不合理,取元素失败,返回0
    p=head->next;j=1;
    while (p!=NULL&&j<i){ //从第1个结点开始查找第i个结点
        p=p->next;j++;
    }if(p==NULL){return 0;}//i超过链表的长度,取元素失败,返回0
    *e=p->data;
    return 1;//取元素成功,返回1
}
/**
 * 4.定位操作
 * 查找元素x在单链表head中第1次出现的位置
 * 思路：从单链表head的第1个结点开始,逐个给定值x的结点数据域值的比较,若某结点数据域的值和给定值x相等,则返回该结点的位序;若不存在,则返回0
 * @param head
 * @param x
 * @return
 */
int LocateSlink(slink *head,ElemType x){
    int i=1;
    slink *p=head->next;
    while(p!=NULL&&p->data!=x){ /*从第1个结点开始查找数据域值为x的结点*/
        p=p->next;i++;
    }if(p){
        return i;
    } else{
        return 0;
    }
}