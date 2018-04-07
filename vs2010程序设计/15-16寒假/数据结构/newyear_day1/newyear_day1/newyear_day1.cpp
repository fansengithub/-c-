// newyear_day1.cpp : �������̨Ӧ�ó������ڵ㡣
//
//���ʵ�֣�һ������a�д������������˳���ʵ���������ٵĸ����洢�ռ䣬�������е��������Ա��û�
#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h> 
#define MAXSIZE 100    ///����˳�������洢�ռ�
#define ElemType  int    ///����˳���Ĵ洢���ͣ����Ըı�
typedef struct 
{
  ElemType  elem[MAXSIZE];    ///������Ա������
  int   length;   //  ���Ա�ĳ���
}SeqList;
///�������ܣ����Ա�ĳ�ʼ��,������һ���յ����Ա�
SeqList InitList_Seq()
{
	 SeqList L;
	 L.length=0;
	 return L;
}
///�������ܣ�˳���Ľ���,��˳����е�Ԫ�ظ�ֵ
SeqList CreatList_Seq(SeqList L)
{
   ElemType x;
   scanf("%d",&x);
   while(x!=-1)
   {
	   L.elem[L.length]=x;
	   L.length++;
	   scanf("%d",&x);
   }
   return L;
}
///�������ܣ��ý������򷨽��������Ա���   ����a1a2a3...amb1b2b3..bn
void  Exchange1(SeqList L,int m,int n)
{
   int i,j,w;
   for(i=1;i<=n;i++)
   {
	   w=L.elem[m+i];
	   for(j=m+i-1;j>=i-1;j--)
		   L.elem[j+1]=L.elem[j];
	   L.elem[i-1]=w;
   }
 

   printf("\nǰ�巨֮�����Ա��Ԫ��Ϊ:\n");
   for(i=0;i<n;i++)
	   printf("%d ",L.elem[i]);
   for(i=n;i<L.length-1;i++)
	   printf("%d ",L.elem[i]);
   printf("\n��һ����ĳ���Ϊ%d\n",n);
   printf("\n�ڶ�����ĳ���Ϊ%d\n",m);
}
///�������ܣ���˳����е�Ԫ������
void invert(SeqList *s,int m,int n)
{
    int i,k,x;
	for(i=m;i<(n+1+m)/2;i++)
	{
		x=s->elem[i];
		s->elem[i]=s->elem[n+m-i];
		s->elem[n+m-i]=x;
	}
}
///�������ܣ��������÷���ʵ�ֵڶ��ֱ任
void Exchange2(SeqList * s,int m,int n)
{ 
    int i;
	invert(s,0,n+m);
	invert(s,0,n-1);
	invert(s,n+1,n+m);
	printf("\n ����֮������Ա�Ϊ\n");
	for(i=0;i<n;i++)
		printf("%d ",s->elem[i]);
	for(i=n+1;i<s->length;i++)
		printf("%d ",s->elem[i]);
	printf("\n��һ����ĳ���Ϊ��%d\n",n);
	printf("\n�ڶ�����ĳ���Ϊ��%d\n",m);
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList seqlist,*p;
	int i,k,h;
	ElemType x;
	seqlist=InitList_Seq();
	printf("�Ѿ�����һ��˳������������Ԫ��:\n");
	seqlist=CreatList_Seq(seqlist);
	p=&seqlist;
	for(i=0;i<seqlist.length;i++)
	{
		if(seqlist.elem[i]==0)   ///��һ��˳����������
			   k=i;
	}
	printf("\n��һ��˳����Ԫ��Ϊ\n");
	for(i=0;i<k;i++)
	{
		printf("%d ",seqlist.elem[i]);
	}
	printf("\n��һ��˳���ĳ���Ϊ��%d",k);
	printf("\n�ڶ���˳����Ԫ��Ϊ\n");
	for(i=k+1;i<seqlist.length;i++)
	{
		printf("%d",seqlist.elem[i]);
	}
	h=seqlist.length-k-1;
	printf("\n�ڶ���˳���ĳ���Ϊ��%d",h);



	Exchange1(seqlist,k,h);
	Exchange2(p,k,h);
	printf("\n------------------\n");
	for(i=0;i<seqlist.length;i++)
	{
		printf("%d ",seqlist.elem[i]);
	}
	printf("\n-ttttttttttttttttttttt-----------\n");
	for(i=0;i<p->length;i++)
	{
		printf("%d ",(*p).elem[i]);
	}
	return 0;
}

