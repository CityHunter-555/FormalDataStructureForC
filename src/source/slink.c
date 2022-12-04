/*
 * ��������ػ�������
 */
#include <stdio.h>
#include <stdlib.h>
#include "../head/slink.h"
/**
 * 1.����һ��������
 * ����һ������n��Ԫ�صĴ�ͷ���ĵ�����head
 * ���㷨��ʱ�临�Ӷ�ΪO(n).��n<1ʱ,������ʱһ����ͷ���Ŀ�����
 * @param n ������Ԫ�ظ���
 * @return slink *head ������
 */
slink *CreateSlink(int n){
    slink *head,*p,*s;/*p����ָ����������,s����ָ���¿��ٽ��*/
    int i;
    p=head=(slink *)malloc(sizeof(slink));/*����ͷ���*/
    for(i=1;i<=n;i++){
        s=(slink *) malloc(sizeof(slink));/*sָ���¿��ٽ��*/
        scanf("%d",&s->data);/*�½��������ֵ*/
        p->next=s;/*���½�����ӵ�p��ָ���ĺ���*/
        p=s;/*pָ����������*/
    }p->next=NULL;/*β����ָ������Ϊ��*/
    return head;/*����ͷ�ڵ�*/
}
/**
 * 2.�������
 * ���ص�����head�ĳ���
 * ˼·������һ�����ͱ���i��Ϊ������,i��ֵΪ0,ָ��pָ���1����㡣��pֵ��Ϊ��,��iֵ��1,ͬʱָ��p�����ƶ�һ��,�ظ���������,ֱ��pΪ��Ϊֹ��i��ֵ��Ϊ����
 * ���㷨��ʱ�临�Ӷ�ΪO(n)��
 * @param head ������
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
 * 3.ȡԪ�ز���
 * ȡ��������head�ĵ�i��Ԫ�ص�ֵ
 * ˼·������ȷ��i��ȡֵ��Χ(1<=i<=n),�ٴӵ�����head�ĵ�1����㿪ʼ,˳�������������,ֱ���ҵ���i�����,���ý���Ԫ��ֵ����
 * ʱ�临�Ӷ�O(n)
 * @param head ������
 * @param i ȡ��Ԫ���±�
 * @param e �洢ȡ����Ԫ��
 * @return
 */
int GetElemSlink(slink *head,int i,ElemType *e){
    slink *p;int j;
    if(i<1){return 0;}//i������,ȡԪ��ʧ��,����0
    p=head->next;j=1;
    while (p!=NULL&&j<i){ //�ӵ�1����㿪ʼ���ҵ�i�����
        p=p->next;j++;
    }if(p==NULL){return 0;}//i��������ĳ���,ȡԪ��ʧ��,����0
    *e=p->data;
    return 1;//ȡԪ�سɹ�,����1
}
/**
 * 4.��λ����
 * ����Ԫ��x�ڵ�����head�е�1�γ��ֵ�λ��
 * ˼·���ӵ�����head�ĵ�1����㿪ʼ,�������ֵx�Ľ��������ֵ�ıȽ�,��ĳ����������ֵ�͸���ֵx���,�򷵻ظý���λ��;��������,�򷵻�0
 * @param head
 * @param x
 * @return
 */
int LocateSlink(slink *head,ElemType x){
    int i=1;
    slink *p=head->next;
    while(p!=NULL&&p->data!=x){ /*�ӵ�1����㿪ʼ����������ֵΪx�Ľ��*/
        p=p->next;i++;
    }if(p){
        return i;
    } else{
        return 0;
    }
}
/**
 * 5.ɾ������
 * ɾ����ͷ��㵥����head�ĵ�i�����
 * ˼·����ȷ��ɾ��λ��i�ĺ�����(1<=i<=n),Ȼ���ڵ�����head���ҵ�Ҫɾ������ǰ�����,����i-1�����,��pָ����,qָ��Ҫɾ���Ľ�㡣ɾ��q��ָ��Ľ������Ϊp->next=q->next;��
 * @param head ������
 * @param i ɾ��λ��
 * @param e ����ɾ�����������ֵ
 * @return
 */
int DeleteSlink(slink *head,int i,ElemType *e){
    slink *p,*q;
    int j;
    if(i<1){return 0;}//i��������0
    p=head;j=0;
    while(p->next!=NULL&&j<i-1){
        p=p->next;j++;//�ӵ�1����㿪ʼ���ҵ�i-1�����,��pָ����
    }
    if(p->next==NULL){return 0;}//����iֵ��������ĳ���,����0
    q=p->next;//qָ���i�����
    p->next=q->next;//p��ָ����ָ��qָ�������һ�����
    *e=q->data;//������������ֵ
    free(q);//�ͷŵ�i�����ռ�õĿռ�
    return 1;//ɾ���ɹ�����1
}
/**
 * 6.�������
 * �ڴ�ͷ���ĵ�����head�ĵ�i�����֮ǰ����һ��ֵΪx���½�㡣
 * @param head ������
 * @param i λ��
 * @param x �����ֵ
 * @return
 */
int InsertSlink(slink *head,int i,ElemType x){
    slink *p,*q;
    int j;
    if(i<1){return 0;}
    p=head;j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;j++; /*�ӵ�1����㿪ʼ���ҵ�i-1�����,��pָ����*/
    }if(p==NULL){return 0;}/*����iֵ����������+1,����0*/
    q=(slink *) malloc(sizeof (slink));
    q->data=x;//����ֵΪx�Ľ��q
    q->next=p->next;//��qָ��Ľ����뵽pָ��Ľ��֮��
    p->next=q;
    return 1;//����ɹ�,����1
}
/**
 * 7.�������
 * �����ͷ���ĵ�����head�е����н��ֵ
 * @param head ������
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
 * 8.�����������������
 * ʵ�ֵ�����a��b�����ӡ����������ʹ��ԭ����������Ĵ洢�ռ䣬�����ٴ洢�ռ�
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