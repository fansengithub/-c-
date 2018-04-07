// ���Ա��˳��洢�ṹ.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��ѭ������󳤶�Ϊ100�����ʵ��˳���Ĵ��������ң����룬ɾ�������ϲ��㷨
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100    //����˳�����������
#define ElemType int   ///����˳���Ĵ洢���ͣ��������趨
//˳��洢�ṹ�����Ա������
typedef struct
{
   ElemType  elem[MAXSIZE];    //������Ա������
   int length;    // length �����Ա�ĳ���
}SeqList;
///˳���ĳ�ʼ��
SeqList InitList_Seq()
{
   //����һ���յ����Ա�L
	SeqList L;       //����һ��˳���
	L.length=0;      //˳���ĳ���Ϊ0
	return L;   // ���ؿյ�˳���
}

///˳���Ľ���
SeqList CreatList_Seq(SeqList L)
{
    ElemType x;
	scanf(" %d",&x);
	while(x!= -1)      ///�洢˳����Ԫ��
	{
		L.elem[L.length]=x;
		L.length++;
		scanf(" %d",&x);
	}
	return L;
}
///˳���Ĳ���
SeqList ListInsert_Seq(SeqList L,int i,ElemType x)
{
	///��˳���L�ĵ�i��λ�ò���Ԫ��x
	///���ж�˳����Ƿ�����Ȼ���ж�i�Ƿ��ںϷ���Χ�ڣ�
	int j;
	if(L.length==MAXSIZE)
	{
	   printf("���Ѿ�����\��");
	}
	else if(i<1 ||i>L.length)
	{	
		printf("����λ�ô���\n");
	}
	else{
		///��i��λ��֮���Ԫ�����κ���
		for(j=L.length;j>=i;j--)
		{
			L.elem[j]=L.elem[j-1];
		}
		L.elem[i-1]=x;
		L.length++;
	}
	return L;
}
///���Ҳ���
int LocateElem_Seq(SeqList L,ElemType x)
{
	///��˳���L�в���x�����ҵ������ض�Ӧλ�á����򣬷���0
	int  i=0;
	while(i<=L.length && L.elem[i]!=x)
	{
	  i++;
	}
	if(i<=L.length)  return i+1;
	else return 0;
}
//ɾ������
SeqList ListDelete_Seq(SeqList L,int i)
{   ///ɾ��˳����еĵ�i��λ�õ�Ԫ��
  int j;
  if(i<1 || i>L.length)   //���ɾ��λ�õĺϷ���
  {
    printf(" ɾ��λ�ô���\n");
  }
  for(j=i;j<L.length;j++)
  {
	  L.elem[j-1]=L.elem[j];   ///����i��λ��֮���Ԫ��ǰ��
  }
  L.length--;
  return L;
}
///�ϲ�������������Ա�
void MergeList_Seq(SeqList la,SeqList lb)
{
	//��֪˳���la lb�������Ƚ�la lb��Ԫ�ذ��ǵݼ����У��鲢la lb �õ��µ�˳�����Ա�lc,���ǵݼ����У�Ȼ��ȥ���ظ�Ԫ��
   SeqList lc;
   int i,j,k,t;
   i=j=k=0;
   ///�����Ա�la ���ǵݼ���������
   for(i=0;i<la.length-1;i++)
   {
	   for(j=0;j<la.length-1-i;j++)
	   {
		   if(la.elem[j]>la.elem[j+1])
		   {
			   t=la.elem[j];
			   la.elem[j]=la.elem[j+1];
			   la.elem[j+1]=t;
		   }
	   }
   }
   ///�����Ա�lb���ǵݼ�����
   for(i=0;i<lb.length-1;i++)
   {
	   for(j=0;j<lb.length-1-i;j++)
	   {
		   if(lb.elem[j]>la.elem[j+1])
		   {
			   t=lb.elem[j];
			   la.elem[j]=la.elem[j+1];
			   la.elem[j+1]=t;
		   }
	   }
   }
   //// ��la��lb�ϲ�Ϊ���Ա�lc
   i=0;
   j=0;
   while(i<la.length && j<lb.length)
   {
	   if(la.elem[i]<lb.elem[j])
	   {
		   lc.elem[k++]=la.elem[i++];
	   }
	   else  if(la.elem[i]==lb.elem[j])
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
   printf("�ϲ�֮������Ա�˳��Ϊ��\n");
   for(i=0;i<lc.length;i++)
   {
	   printf(" %d ",lc.elem[i]);
   }
   printf("�ϲ�֮������Ա�ĳ���Ϊ��%d \n",lc.length);
}
void meun()
{
	printf("\n\n");
   printf("*************************************\n");
	printf("		1---������һ��˳���͵ڶ���˳���\n");
	printf("		2---��ֵ����Ԫ�أ���һ��˳���\n");
	printf("		3---����Ԫ�أ���һ��˳���\n");
	printf("		4---��λ��ɾ��Ԫ�أ���һ��˳���\n");
	printf("		5---�ϲ�����˳���\n");
	printf("		6---�˳�\n");
	printf("*************************************\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList seqlist,Lb;
	int i,k=0;
	ElemType x;
	int flage=0;   ///��־λ���ڿ��ƴ���������
	while(k!=6)
	{
	   meun();
	   printf("��ѡ����Ӧ����:\n");
	   scanf("%d",&k);
	   getchar();
	   /////////
	   
	   switch(k)
	   {
	   case 1:
		   if(flage==1)
		   {
			   printf("\n �Ѿ������ɹ����������Ƿ����´�����������y or n��");
		       char choice;
			   scanf("%c",&choice);
			   getchar();
			   if(choice=='y' || choice=='Y')
			   {
			        seqlist=InitList_Seq();
		            printf("������һ��˳�������˳����Ԫ�أ�-1�������:\n");
					seqlist=CreatList_Seq(seqlist);
					printf("��һ��˳����Ԫ��Ϊ��");
					for(i=0;i<seqlist.length;i++)
						{
							 printf(" %d ",seqlist.elem[i]);
						}
				   printf("\n ˳���ĳ���Ϊ: %d\n",seqlist.length);
				   Lb=InitList_Seq();
				   printf("�����ڶ���˳�������˳����Ԫ�أ�-1�������:\n");
				   Lb=CreatList_Seq(Lb);
				   printf("�ڶ���˳����Ԫ��Ϊ��");
				   for(i=0;i<Lb.length;i++)
					   printf(" %d ",Lb.elem[i]);
				   printf("\n ˳���ĳ���Ϊ��%d\n",Lb.length);
				   flage=1;
			   }
			  // else if(choice=='n' || choice=='N')
				 
		   }
		   if(flage==0){
		   seqlist=InitList_Seq();
		   printf("������һ��˳�������˳����Ԫ�أ�-1�������:\n");
		   seqlist=CreatList_Seq(seqlist);
		   printf("��һ��˳����Ԫ��Ϊ��");
		   for(i=0;i<seqlist.length;i++)
		   {
			   printf(" %d ",seqlist.elem[i]);
		   }
		   printf("\n ˳���ĳ���Ϊ: %d\n",seqlist.length);
		   Lb=InitList_Seq();
		   printf("�����ڶ���˳�������˳����Ԫ�أ�-1�������:\n");
		   Lb=CreatList_Seq(Lb);
		   printf("�ڶ���˳����Ԫ��Ϊ��");
		   for(i=0;i<Lb.length;i++)
			   printf(" %d ",Lb.elem[i]);
		   printf("\n ˳���ĳ���Ϊ��%d\n",Lb.length);
		   flage=1;
		   }
		   break;
	   case 2:
		   printf("������Ҫ����Ԫ�ص�ֵ����һ��˳���:");
		   scanf("%d",&x);
		   i=LocateElem_Seq(seqlist,x);
		   if(i)
			   printf("��˳����е�λ��Ϊ��%d\n",i);
		   else
			   printf("û���ҵ�");
		   break;
	   case 3:
		   printf("���������Ԫ��λ�ã���һ��˳�����");
		   scanf("%d",&i);
		   printf("���������Ԫ�ص�ֵ��");
		   scanf("%d",&x);
		   seqlist=ListInsert_Seq(seqlist,i,x);
		   printf("��һ��˳���Ԫ��Ϊ��");
		   for(i=0;i<seqlist.length;i++)
		   {
			   printf(" %d",seqlist.elem[i]);
		   }
		   printf("\n  ��ĳ���Ϊ��%d\n",seqlist.length);
		   break;
	   case 4:
		   printf("������ɾ��Ԫ��λ�ã���һ��˳���\n");
		   scanf("%d",&i);
		   seqlist=ListDelete_Seq(seqlist,i);
		   printf("��һ��˳���Ԫ��Ϊ��");
		   for(i=0;i<seqlist.length;i++)
		   {
			   printf(" %d",seqlist.elem[i]);
		   }
		   printf("\n ��ĳ���Ϊ�� %d\n",seqlist.length);
		   break;
	   case 5:
		   MergeList_Seq(seqlist,Lb);
		   break;
	   case 6:
		   exit(0);
	   }
	}
	return 0;
}
