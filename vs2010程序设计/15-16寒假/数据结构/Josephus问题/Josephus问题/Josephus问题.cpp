// Josephus����.cpp : �������̨Ӧ�ó������ڵ㡣
//Լɪ������

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE  1
typedef int DataType;
//�ṹ������
typedef struct SeqList
{
  int MAXNUM;				//˳����е����Ԫ�ظ���
  int n;					//������Ա���Ԫ�ظ���  n<=MAXNUM
  DataType * elem;			//elem[0],elem[1],elem[2],....elem[n-1]������Ա��е�Ԫ��
}* PSeqList;
//typedef struct SeqList  *  PSeqList;
///�������ܣ������µ�˳���
PSeqList  createNullList_seq(int m)
{
     PSeqList palist=(PSeqList)malloc(sizeof(struct SeqList));
	 if(palist!=NULL)
	 {
		 palist->elem=(DataType *)malloc(sizeof(DataType) * m);
		 if(palist->elem)
		 {
			 palist->MAXNUM=m;
			 palist->n=0;
			 return palist;
		 }
		 else
			 free(palist);
	 }
	 printf("Out of space!!\n");		//�����ڴ�ʧ��
	 return NULL;
}
///�ж�palist��ָ���˳����Ƿ�Ϊ�ձ�

int IsNullList_seq(PSeqList palist)
{
	return (palist->n==0);
}
///��x��palist��ָ˳����е��±�
int locate_seq(PSeqList palist,DataType x)
{
	int q;
	for(q=0;q<palist->n;q++)
	{
		if(palist->elem[q]==x)
			return q;
	}
	return -1;
}
//�������ܣ���palist��ָ���˳����У��±�Ϊp��Ԫ��֮ǰ����x
int insertPre_seq(PSeqList palist,int p,DataType x)
{
	int q;
	if(palist->n>=palist->MAXNUM)		//�������
	{
	   printf("Overflow!\n");
	   return 0;
	}
	if(IsNullList_seq(palist))			///���palistָ��ձ�,��˳������
	{
		palist->elem[0]=x;				///����Ԫ��x
		palist->n=1;					///Ԫ�ظ����޸�Ϊ1
		return 1;    
	}
	if(p< 0||p>palist->n)				///����������±�Ϊp��Ԫ��!
	{
	   printf("No exit !\n");
	   return 0;
	}
	for(q=palist->n-1;q>=p;q--)			///�ڲ���λ�ü�֮���Ԫ�ؾ�����һ��λ��
	{
		palist->elem[q+1]=palist->elem[q];
	}
	palist->elem[p]=x;					///����Ԫ��
	palist->n=palist->n+1;				///Ԫ�ظ�����1
    return 1;
}
///�������ܣ���palist��ָ˳�����ɾ���±�Ϊp��Ԫ��
int deleteP_seq(PSeqList palist,int p)
{
  int q;
  if(p<0 ||p>palist->n-1)			//p�ĺϷ����ж�
  {
    printf("Not exist!\n");
	return 0;
  }
  for(q=p;q<palist->n-1;q++)		//��ɾ��Ԫ��֮���Ԫ�ؾ���ǰ�ƶ�һ��λ��
  {
	  palist->elem[q]=palist->elem[q+1];
  }
  palist->n=palist->n-1;
  return 1;
}
///Լɪ����������ʵ��
void  josephus_seq(PSeqList palist,int  s,int m)
{
    int s1,i,w;
	s1=s-1;
	for(i=palist->n;i>0;i--)
	{
	  ///�ҳ��е�Ԫ��
		s1=(s1+m-1)%i;
		w=palist->elem[s1];			//����±�Ϊs1Ԫ�ص�ֵ
		printf("Out element %d \n",w);		//��ӡ�������Ԫ��
		deleteP_seq(palist,s1);				//ɾ�������Ԫ��

	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	PSeqList jos_alist;
	int i;
	int  n,s,m;				///һ��n���ˣ��ִӵ�s���˿�ʼ������������m���˳���,Ȼ�����һ���˴��¿�ʼ������������m���ˣ��ֳ���
	printf("\n  Please input the  values of n  (<100)\n");
	scanf("%d",&n);
	printf("\n Please input the values of s  \n");
	scanf("%d",&s);
	printf("\n Please input the values of m \n");
	scanf("%d",&m);
	jos_alist=createNullList_seq(n);			///�����յ�˳���
	if(jos_alist!=NULL)
	{
	   for(i=0;i<n;i++)						//���Ա�ֵ
		   insertPre_seq(jos_alist,i,i+1);
	   josephus_seq(jos_alist,s,m);
	   free(jos_alist->elem);
	   free(jos_alist);
	}
	return 0;
}

