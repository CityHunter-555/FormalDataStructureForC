/*
 * ˳�����ػ�������
 */
#include <stdio.h>
#include <malloc.h>
#include "../head/sqlist.h"
/**
 * 1.��ʼ������
 * ����һ���յ�˳���L
 */
sqlist InitSqlist(){
    sqlist s;
    s.data=(int*)malloc(sizeof(ElemType)*INITSIZE);//��˳����ַ����һ���ڴ�ռ�
    if(!s.data){
        printf("��ʼ��ʧ��");
        exit(0);
    }//�������ʧ�ܣ�ֱ���˳�����
    s.length=0;//��Ϊ˳����л�û��ʼ��Ԫ�أ������ȳ�ʼ��Ϊ0
    s.listsize=INITSIZE;//��ʼ������ռ�
    return s;//����ʼ����˳�����
}
/**
 * 2.�������
 * ͳ��˳���L�д洢������Ԫ�ظ���
 * @param L ˳���
 * @return (L->length)
 */
int GetLengthSqlist(sqlist *L){
    return (L->length);
}
/**
 * 3.ȡԪ�ز���
 * ȡ��˳���L�ĵ�i��Ԫ��
 * @param L ˳���
 * @param i Ԫ���±�
 * @param e �洢ȡ����Ԫ��
 * @return 1 �����ɹ��ñ�
 */
int GetElemSqlist(sqlist *L,int i,ElemType *e){
    if(i<1||i>L->length){return 0;}/*i������,ȡԪ��ʧ��,����0*/
    *e=L->data[i-1];
    return 1;//ȡԪ�سɹ�,����1
}
/**
 * 4.Ԫ�ض�λ����
 * ��˳���L�в��ҵ�һ����xֵ��ȵ�����Ԫ�ص�λ��
 * ˼·����˳���L�ĵ�1��Ԫ�ؿ�ʼ,������и���ֵx������Ԫ��ֵ�ıȽ�,��ĳ������Ԫ�ص�ֵ�͸���ֵx���,�򷵻ظ�����Ԫ�ص�λ��;��ֱ�����һ������Ԫ��,��ֵ��xֵ�������,�򷵻�0��
 * @param L ˳���
 * @param x ����ֵ
 * @return 0/1 ����ʧ��/�ɹ��ñ�
 */
int LocateSqlist(sqlist *L,ElemType x){
    int i=0;//�ó�ʼ�±�ֵΪ0
    while(i<L->length){
        if(L->data[i]==x){return i+1;}//�ҵ�,����λ��i+1
        else{i++;}
    }return 0;//û�ҵ�,����0
}
/**
 * 5.�������
 * ��˳���L�еĵ�i��λ���ϲ���һ��ֵΪx������Ԫ��
 * ˼·���ڳ���Ϊn��˳����в���һ������Ԫ��ʱ,����ȷ������λ��i�ĺ�����(1<=i<=n+1)��������i����,���λ��Ϊn������Ԫ�ؿ�ʼ,��λ��Ϊn,n-1,...,i������Ԫ�������Ƶ�λ��Ϊn+1,n,...,i+1��λ����,�ճ���i��λ��,�ڸ�λ���ϴ���ֵΪx������Ԫ�ء�
 * ʱ�临�Ӷ�O(n)
 * @param L ˳���
 * @param i ����λ��
 * @param x ����ֵ
 * @return
 */
int InsertSqlist(sqlist *L,int i,ElemType x){
    int j;
    if(i<1||i>L->length+1){return 0;}    //����i����������0
    if(L->length==L->listsize){
        L->data=(ElemType *) realloc(L->data,(L->listsize+1)*(sizeof(ElemType)));
        L->listsize++;                   //���ô洢�ռ䳤��
    }                                    //�洢�ռ䲻��������һ���洢�ռ�
    for(j=L->length-1;j>=i-1;j--) {L->data[j+1]=L->data[j];}//�����Ϊi��֮�������Ԫ�غ���һλ
    L->data[i-1]=x;                  //�����i������x
    L->length++;                     //˳�������1
    return 1;                            //����ɹ�������1
}
/**
 * 6.ɾ������
 * ��˳���L�ĵ�i��Ԫ��ɾ��
 * ˼·���ڳ���Ϊn��˳�����ɾ��һ������Ԫ��ʱ,����ȷ��ɾ��λ��i�ĺ�����(1<=i<=n)����i����,���λ��Ϊi+1������Ԫ�ؿ�ʼ,��λ��Ϊi+1,i+2,...,n������Ԫ�������Ƶ�λ��Ϊi,i+1,...n-1��λ���ϡ�
 * ʱ�临�Ӷ�O(n)
 * @param L
 * @param i
 * @return
 */
int DeleteSqlist(sqlist *L,int i){
    int j;
    if(i<1||i>L->length) {return 0;} //����i����������0
    for(j=i;j<L->length;j++) {L->data[j-1]=L->data[j];}//�����Ϊi��֮�������Ԫ��ǰ��һλ
    L->length--;//˳�����-1
    return 1;//ɾ���ɹ�������1
}

/**
 * 7.�������
 * ���˳���L�ĸ�����Ԫ��ֵ
 * @param L ˳���
 * @return
 */
int ListSqlist(sqlist *L){
    int i;
    for(i=0;i<L->length;i++){
        printf("%d,�±�:%d  ",L->data[i],i);
    }printf("\n");//����ѭ�����˳���
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
    printf("���ֵΪ��");
    printf("%d",L->data[0]);
    printf("\n");
    for(i=2;i<L->length;i++){
        if(L->data[i]>L->data[1]){
            k=L->data[i];
            L->data[i]=L->data[1];
            L->data[1]=k;
        }
    }
    printf("�����ֵΪ��");
    printf("%d",L->data[1]);
    printf("\n");
    return 1;
}

//��ա���ʼ��
void FreeList(sqlist *L) {
    DeleteSqlist(&L, L->length);
    L->length = 0;
    L->listsize = INITSIZE;
}