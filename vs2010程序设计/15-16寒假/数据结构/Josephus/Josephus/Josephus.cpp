// Josephus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

#define FALSE  0
#define TRUE   1
typedef int  DataType;				//定义数据类型为整形
typedef struct Node							//单链表节点类型
{
   DataType info;
   struct Node * link;
}Node,  *PNode;

struct LinkList					//单链表类型定义
{
    PNode head;					///指向单链表的第一个节点
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

