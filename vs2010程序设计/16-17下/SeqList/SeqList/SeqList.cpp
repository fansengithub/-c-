// SeqList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
///���Ա�Ĵ��������ң����룬ɾ�����ϲ�����
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100     ///�������б�洢���������
#define  ElemTye int     ///����˳���洢������
///˳��洢�ṹ���Ա�
typedef struct
{
   ElemTye  elem[MAXSIZE];     ///������Ա������
   int length;                 ///���Ա�ĳ���
}SeqList;
///˳���ĳ�ʼ��    sequence ˳���   list ����
SeqList InitList_Seq()         ///����һ���յ����Ա�
{
    SeqList    L;
    L.length=0;
    return L;
}

///˳���Ľ���,���������Ԫ��
SeqList  CreatList_Seq(SeqList L)
{
    ElemTye  x;
    scanf("%d",&x);
    while(x!=-1)
    {
      L.elem[L.length]=x;
      L.length++;
      scanf("%d",&x);
    }
    return L;
}

///˳���Ĳ������,���L��iλ�ò���Ԫ��x
SeqList   ListInsert_Seq(SeqList L,int i,ElemTye x)
{
   int  j;
   if(L.length==MAXSIZE)                   ///���к����Լ��
    printf("���Ա��Ѿ�������");
   else if(i<1||i>L.length)
    printf("����λ�ô���");
   else
    {
        for(j=L.length;j>=i;j--)      ///˳���ĵ�i��Ԫ�أ����κ���
        {
           L.elem[j]=L.elem[j-1];
        }
        L.elem[i-1]=x;
        L.length++;
    }
    return L;
}
///˳���Ĳ��Ҳ���--
//-���Ҹ������Ա�L�еĸ���ֵx�����ҵ����򷵻�Ԫ������Ϊ�ã����򣬷���0
int  LocateElem_Seq(SeqList L,ElemTu)
{
	int i=0;
	while(i<=L.length)
	return 0;
}
///��ӡ���Ա���Ԫ��
void  Show_SeqList(SeqList L)
{
    printf("��ǰ����Ԫ��Ϊ��\n");
    for(int i=0;i<L.length;i++)
    {
        printf(" %d",L.elem[i]);
    }
    printf("\n��ǰ���Ա�ĳ���Ϊ�� %d\n",L.length);
}
///��ӡ�˵�����
void Menu()
{
     printf("\n******************************\n");
   printf("    1---����һ�����Ա�\n");
   printf("    2---����Ԫ��\n");
   printf("    3---�˳�\n");
   printf("******************************\n");
}
/*
///c����ʵ�Σ��βΣ�ֵ������֤
#include<stdio.h>
void fun(int x,int y)
{
   int tmp;
   tmp=x;
   x=y;
   y=tmp;
   printf("x = %d,y = %d\n",x,y);
}
int main()
{
   int a,b;
        ///!!!!!!!!!!!!!!!!!!
   printf("������һ������ a!\n");
   scanf("%d",&a);
   printf("������һ������ b!\n");
   scanf("%d",&b);
   printf("����fun()֮ǰ��\n");
   printf("a = %d,b = %d\n",a,b);
   printf("����fun()֮��\n");
   fun(a,b);
    printf("a = %d,b = %d",a,b);
   return 0;
}  */


int _tmain(int argc, _TCHAR* argv[])
{
	 SeqList seqlist;
   int k=0;
    int x,y;    ///����Ԫ�ؽ�Ҫ�õ���
    x=y=0;
   while(k!=3)
   {
     Menu();
     printf("�����뽫Ҫִ�в�����Ӧ���!\n");
     scanf("%d",&k);
     switch(k)
     {
       case 1:
       seqlist=InitList_Seq();
       printf("����һ��˳�������˳�����Ԫ�أ�-1�������������\n");
       seqlist=CreatList_Seq(seqlist);
       Show_SeqList(seqlist);
       break;
       case 2:
        printf("�����뽫Ҫ����Ԫ�ص�ֵ��\n");
        scanf("%d",&x);
        printf("�����뽫Ҫ�����λ��!\n");
        scanf("%d",&y);
        seqlist=ListInsert_Seq(seqlist,y,x);
        Show_SeqList(seqlist);
        break;
        case 3: exit(0);
     }
   }
   return 0;
	
}

