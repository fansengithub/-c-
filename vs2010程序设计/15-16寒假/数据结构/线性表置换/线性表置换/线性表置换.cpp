// ���Ա��û�.cpp : �������̨Ӧ�ó������ڵ㡣
//
///  �������ܣ���֪�����д�����������Ա����һ���㷨���þ������ٵĸ����ռ佫�����е��������Ա��λ�û�����ʵ�֣�a1,a2,a3,a4��,(b1,b2,b3,b4)-->(b1,b2,b3,b4),��a1,a2,a3,a4)
//
//�����㷨   1---ǰ���㷨   2---�����㷨
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100      ///����˳�����������
#define ElemType  int     ///��Ӫ˳���Ĵ洢���ͣ�����������
typedef struct
{
   ElemType elem[MAXSIZE];    ///������Ա������
   int length;   ///���Ա�ĳ���
}SeqList;

///˳���ĳ�ʼ��
SeqList InitList_Seq()
{
  ///����һ���յ����Ա�ʱ�临�Ӷ�Ϊ0��1��
	SeqList L;
	L.length=0;
	return L;
}
///˳���Ľ���
SeqList CreatList_Seq(SeqList L)
{
  ElemType x;
  scanf("%d",&x);
  while(x!= -1)
  {
	  L.elem[L.length]=x;
	  L.length++;
	  scanf("%d",&x);
  }
  return L;
}
////�û��㷨1��ǰ�����㷨��
void Exchange1(SeqList  s,int m,int n)
{
   int i,j,w;
   //������w����һ��Ԫ�أ�Ȼ�����ν�ǰ���Ԫ�غ���һλ��������w
   for(i=0;i<n;i++)
   {
	   w=s.elem[i+m+1];
	   for(j=m+i-1;j>=i;j--)
	   {
		   s.elem[j+1]=s.elem[j];
	   }
	   s.elem[i]=w;
   }
   printf("ǰ�巨֮������Ա�Ԫ��Ϊ��\n");
   for(i=0;i<n;i++)
   {
	   printf(" %d",s.elem[i]);
   }
   for(i=n;i<s.length-1;i++)
   {
	   printf(" %d",s.elem[i]);
   }
   printf("\n ��һ��˳���ĳ���Ϊ�� %d \n",n);
   printf("\n �ڶ���˳���ĳ���Ϊ�� %d\n",m);
}
void invert(SeqList * s,int m,int n)
{
    int i,k,x;
	for(i=m;i<(n+1+m)/2;i++)
	{
		x=s->elem[i];
		s->elem[i]=s->elem[n+m-i];
		s->elem[n+m-i]=x;
	}
}

///�û��㷨2��
void Exchange2(SeqList  *s,int m,int n)
{
   int i;
   invert(s,0,n+m);
   invert(s,0,n-1);
   invert(s,n+1,n+m);
   printf("\n �û�����֮�����Ա�Ԫ��Ϊ��");
     for(i=0;i<n;i++)
	 {
		 printf(" %d ",s->elem[i]);
	 }
	 for(i=n+1;i<s->length;i++)
		 printf(" %d ",s->elem[i]);
	 printf("\n��һ����ĳ���Ϊ��  %d\n",n);
	 printf("�ڶ�����ĳ���Ϊ�� %d\n",m);
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList  seqlist, *p;
	int i,k,h;
	ElemType  x;
	seqlist=InitList_Seq();
	printf("����һ��˳���������˳����Ԫ�أ�  \n");
	seqlist=CreatList_Seq(seqlist);
	p=&seqlist;
	for(i=0;i<seqlist.length;i++)
	{
		if(seqlist.elem[i]==0)    ///��ֵΪ0ʱ�������һ��˳����������
			k=i;    ///��k��¼�����У���һ��˳���Ԫ�صĸ���
	}
	printf("��һ�����Ա�Ԫ��Ϊ��\n");
	for(i=0;i<k;i++)
	{
		printf(" %d ",seqlist.elem[i]);
	}
	printf("\n��ĳ���Ϊ�� %d\n",k);
	printf("�ڶ������Ա�Ԫ��Ϊ�� \n");
	for(i=k+1;i<seqlist.length;i++)
		printf(" %d ",seqlist.elem[i]);
	h=seqlist.length-k-1;    ///����ڶ���˳�����Ԫ�ظ���
	printf("\n��ĳ���ΪΪ��%d\n ",h);
	Exchange1(seqlist,k,h);
	Exchange2(p,k,h);
	return 0;
}

