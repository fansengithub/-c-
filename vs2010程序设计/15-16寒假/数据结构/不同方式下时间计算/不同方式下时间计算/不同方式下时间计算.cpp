// ��ͬ��ʽ��ʱ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//�������ܣ�ʵ�����ֲ�ͬ��ʽ��ʹ���ڴ�ռ�ʱ�������⡣
//��ʽ1���������ڴ�������1000 0000���ض��ṹ���С���ڴ�ռ䣬Ȼ������ȡ�������и�ֵ������Ȼ���ٷŻء����ʱ�䡣
//��ʽ2��ֱ�ӵ���c��malloc()----free() ����1000 0000�Ρ����ʱ�䡣
//vs�� int �������͵Ĵ�С��   4���ֽ�
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define N 10000000   ///����n�Ĵ�СΪ  1ǧ��
//////ʱ��ṹ��
//�ṹ�嶨��
typedef struct node{
	//char data1;
	short int data1;
	//	int data2;
	//	int data3;
	node * next;
}node;	
///�������ܣ�ִ�е�һ�ַ�ʽ:�Լ�����һ����ڴ棬
int  Action_1()
{
	node * head;
	node * p;
	node * r;
	node * t;
	int i=0;
	SYSTEMTIME t1,t2;			 //���ڼ���ʱ��
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//��ӡ��ʼǰ��ʱ��


	///�ڴ�����
	head =(node *)malloc(N*sizeof(node));
	//head=(node *)malloc(sizeof(node));
	
	p=head;
	//node *flag=head;
	while(i<N)            ///�������һ����ڴ棬ͨ���ṹ������Ϊ������
	{
		//p=&(*head)+i;//*sizeof(node);	
		p->data1=i;
		p->next=&(*p)+1;                       //sizeof(node);
		p=p->next;
		i++;
	}
	p->next=NULL;            ///���һ���ṹ�壬��ָ����Ϊ��
	
	//printf("**********************************");

	///�ڴ�ʹ��

	p=head;
	

	///��һ���ڵ��ʹ��
	p=head->next;
	head->next=NULL;
	head->data1=0;      ////��һ���ڵ������Ԫ�ظ�ֵ
	head->next=p;

	while(p!=NULL)
	{
		if(p->next!=NULL)     ////��p����һ��Ϊ��ʱ
		{
			t=p;
			r=p->next;     ///��p����һ����r����Ϊ��ʱ����r�����ó���
			p=r->next;

			r->data1=0;       ///��rָ��ڵ��ʹ��
			r->next=NULL;

			r=t->next;		///r�ڵ�ʹ����Ϻ󣬽������������
			r->next=p;
			p=t;
		}
		else             //��p����һ��Ϊ��ʱ������pΪ���һ���ڵ㣩
		{
		    t=head;				///��t�ҵ�pǰ��Ľڵ�
			while(t->next!=p)
			{
				t=t->next;
			}

			t->next=NULL;			///���ڵ�p����ȡ����
			p->data1=0;         ///�ӽڵ�p��ʹ��
			p->next=NULL;

			t->next=p;           ///���ڵ�p�Ż�������
		}
	  p=p->next;
	}

	///�ڴ��ͷ�
 	//free(flag);															///----------------------------
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);					///��ӡִ��֮���ʱ��
	time=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;				///����ܹ���ʱ
	printf("�ܹ���ʱ��  %d    ΢��\n",time);
	return time;
}
///�������ܣ��ڶ��д���ʽ:ͨ��forѭ��������ϵͳ����
int Action_2()
{
	
	int i=0;
	node * p=NULL;
	node * head;
	SYSTEMTIME t1,t2;
	int t;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);
	while(i<N)                 /////ֱ�Ӵ�ϵͳ�е���  malloc()  free()  N��
	{
	   head=(node *)malloc(sizeof(node));
	   head->data1=i;
	   free(head);
	   i++;
	}
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);
	t=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;
	printf("�ܹ���ʱ��  %d    ΢��\n",t);
	return t;
}
///��������:���һ�ַ�ʽ�����ʱ��
int _tmain(int argc, _TCHAR* argv[])
{
	
	printf("���������Ϊ�� 10000000\n");
	int t1=0;
	int t2=0;
	t1=Action_1();
	t2=Action_2();
	printf("���ս����  %d",(t2/t1));
	return 0;
}
	
