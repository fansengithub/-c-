// ���Ա�1.cpp : �������̨Ӧ�ó������ڵ㡣
//
//˳������󳤶�Ϊ100�����ʵ��˳���Ĵ��������ң����룬ɾ�������ϲ��㷨��
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100   ///����˳�����������
typedef struct 
{
  int elem[MAXSIZE];
  int length;
}SeqList;

//˳���ĳ�ʼ��
SeqList InitList_Seq()
{
   SeqList L;
   L.length=0;
   return L;
}

////˳���Ľ���
SeqList CreateList_Seq(SeqList L)
{
  int x;
  scanf("%d",&x);
  while(x!=-1){
	  L.elem[L.length]=x;
	  L.length++;
	  scanf("%d",&x);
  }
  return  L;
}
///˳���Ĳ���
SeqList ListInsert_Seq(SeqList L,int i,int x){
	int j;
	if(L.length==MAXSIZE)
	{
	   printf("˳�������");
	}
	else if (i<1||i>L.length)
	{
	  printf("����λ�ó���");
	}
	else
	{
		for(j=L.length;j>=i;j--)
		{
			L.elem[j]=L.elem[j-1];
		}
		L.elem[j-1]=x;
		L.length++;
		return L;
	}
}

///�����㷨
int LocateElem_Seq(SeqList L,int x)
///�����Ա�L���ҵ�Ԫ��ֵΪx������Ԫ�أ�����ҵ��򷵻ظ�Ԫ�ص�λ�ã����򷵻�0
{
   int  i=0;
   while(i<=L.length&&L.elem[i]!=x){
     i++;
   }
   if(i<=L.length)   return i+1;
   else return 0;
}

//�������ܣ��ϲ��㷨
//��֪���Ա�la��lb�����Ƚ���������Ȼ��ϲ�Ϊһ�±���ȥ���ظ���Ԫ��
SeqList MergeList_Seq(SeqList la,SeqList lb)
{
  int i,j,k;
  ///���Ƚ�la lb �ֱ�ǵݼ�����
  for(i=0;i<la.length-1;i++)
  {
	  for(j=0;j<la.length-i-1;j++)
	  {
		  if(la.elem[j]>la.elem[j+1])
		  {
			  k=la.elem[j];
			  la.elem[j]=la.elem[j+1];
			  la.elem[j+1]=k;
		  }
	  }
  }

  ////lb����
    for(i=0;i<lb.length-1;i++)
  {
	  for(j=0;j<lb.length-i-1;j++)
	  {
		  if(lb.elem[j]>lb.elem[j+1])
		  {
			  k=lb.elem[j];
			  lb.elem[j]=lb.elem[j+1];
			  lb.elem[j+1]=k;
		  }
	  }
  }
	///�ϲ�la,lb������
	i=0;j=0;
	k=0;
	SeqList lc=InitList_Seq();
	while(i<la.length&&j<lb.length)
	{
		if(la.elem[i]<lb.elem[j])
		{
			lc.elem[k++]=la.elem[i++];   
		}
		else if(la.elem[i]=lb.elem[j])
		{
		   lc.elem[k++]=la.elem[i++];
		   j++;
		}
		else 
		{
		    lc.elem[k++]=lb.elem[j++];
		}
	}
	while(i<la.length)
	{
	    lc.elem[k++]=la.elem[i++];
	}
	while(j<lb.length)
	{
	   lc.elem[k++]=lb.elem[j++];
	}
	lc.length=k;
	printf("�ϲ�֮���˳���Ϊ\n");
	for(i=0;i<lc.length;i++)
		printf("%d ",&lc.elem[i]);
	printf("�ϲ�֮��ı���Ϊ��\n");
	printf("%d",&lc.length);
} 
///exchange �㷨
//��֪һ���Ա��к���A1.A2.A3������AN��b1.b2...bn,����㷨�����Ա��Ϊb1.b2.b3...bn,a1.a2.a3
void Exchange1(SeqList s,int m,int n)
{
	int k;
	int j;
	int w;
   for(k=1;k<=n;k++)
   {
	   w=s.elem[m+k-1];
	   for(j=m+k-1;j>=k;j--)
		   s.elem[j+1]=s.elem[j];
	   s.elem[k-1]=w;
   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList seqlist,lb;
	int i,k;
	i=0;
	k=0;
	printf("*****************************\n");
	printf("1----������һ��˳���͵ڶ���˳���\n");
	printf("2----��ֵ���ң���һ��˳���\n");
	printf("3----����Ԫ�أ���һ��˳���\n");
	printf("4----��λ��ɾ��Ԫ�أ���һ��Ԫ�أ�\n");
	printf("5----�ϲ�����˳���\n");
	printf("6----�˳�");
	while(k!=6)
	{
	   printf("��������ز���ѡ��\n");
	   scanf("%d",&k);
	   switch(k)
	   {
	   case 1:

	   case 2:
	   case 3:
	   }
	}
	return 0;
}

