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
/**
 * 5.删除操作
 * 删除带头结点单链表head的第i个结点
 * 思路：先确定删除位置i的合理性(1<=i<=n),然后在单链表head上找到要删除结点的前驱结点,即第i-1个结点,由p指向它,q指向要删除的结点。删除q所指向的结点的语句为p->next=q->next;。
 * @param head 单链表
 * @param i 删除位序
 * @param e 保存删除结点数据域值
 * @return
 */
int DeleteSlink(slink *head,int i,ElemType *e){
    slink *p,*q;
    int j;
    if(i<1){return 0;}//i不合理返回0
    p=head;j=0;
    while(p->next!=NULL&&j<i-1){
        p=p->next;j++;//从第1个结点开始查找第i-1个结点,由p指向它
    }
    if(p->next==NULL){return 0;}//参数i值超过链表的长度,返回0
    q=p->next;//q指向第i个结点
    p->next=q->next;//p的指针域指向q指向结点的下一个结点
    *e=q->data;//保存结点数据域值
    free(q);//释放第i个结点占用的空间
    return 1;//删除成功返回1
}
/**
 * 6.插入操作
 * 在带头结点的单链表head的第i个结点之前插入一个值为x的新结点。
 * @param head 单链表
 * @param i 位序
 * @param x 插入的值
 * @return
 */
int InsertSlink(slink *head,int i,ElemType x){
    slink *p,*q;
    int j;
    if(i<1){return 0;}
    p=head;j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;j++; /*从第1个结点开始查找第i-1个结点,由p指向它*/
    }if(p==NULL){return 0;}/*参数i值超过链表长度+1,返回0*/
    q=(slink *) malloc(sizeof (slink));
    q->data=x;//创建值为x的结点q
    q->next=p->next;//将q指向的结点插入到p指向的结点之后
    p->next=q;
    return 1;//插入成功,返回1
}
/**
 * 7.输出操作
 * 输出带头结点的单链表head中的所有结点值
 * @param head 单链表
 */
void listSlink(slink *head){
    slink *p;
    p=head->next;
    while(p!=NULL){
        printf("4d%",p->data);
        p=p->next;
    }
    printf("\n");
}
/**
 * 8.连接两个单链表操作
 * 实现单链表a和b的链接。结果链表仍使用原来两个链表的存储空间，不另开辟存储空间
 * @param a
 * @param b
 */
void LinkSlink(slink *a,slink *b){
    slink *p;
    for(p=a;p->next!=NULL;p=p->next);
    p->next=b->next;
    free(b);
}

void MergeSlink(slink *la,slink *lb){

}