// Josephus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

#define FALSE  0
#define TRUE   1
typedef int  DataType;				//������������Ϊ����
typedef struct Node							//������ڵ�����
{
   DataType info;
   struct Node * link;
}Node,  *PNode;

struct LinkList					//���������Ͷ���
{
    PNode head;					///ָ������ĵ�һ���ڵ�
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

