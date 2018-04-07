// os进程管理2.0.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// os进程管理.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//函数功能：显示帮助信息
//**********************************************************************PCB ----------------------
typedef struct pcb    //程序控制块
{
    char name[10];   //存放进程的名字
    char  start2[5];   //记录进程的起始地址
    struct pcb  *next;
	char size[5];       //记录进程的大小
}PCB;
void help_show()
{
  printf("*******************************\n");
  printf("     1.创建进程\n");
  printf("     2.终止进程--------结束正在执行的程序\n");
  printf("     3.时间片到------将正在执行的进程装入就绪队列尾部，将下一个自动调度值执行态\n");
  printf("     4.阻塞-----将正在执行的进程插入阻塞队列尾部\n");
  printf("     5.唤醒-----将阻塞队列头移动到就绪队列尾部\n");
  printf("     6.查询1-----查看三个进程状态队列的情况\n");
  printf("     7.查询2-----s2 查看内存的剩余情况\n");
  printf("     0.退出！\n");
  printf("*******************************\n");
}
///函数功能：（自动调度）就绪态向执行态的转移
void  ready_running(PCB *ready,PCB *running)
{
   PCB *q;
   if(running==NULL||ready!=NULL)
   {
	   //q=ready->next;
	   running=ready;
	   ready=ready->next;
	   running->next->next=NULL;
   }
   else printf("自动调度失败！\n");
}
///函数功能：创建进程
void  creat_PCB(PCB *ready,PCB *running)
{
  // printf("添加进程！\n");
  // PCB *ready=NULL;
   int n,i;
  // PCB *head=NULL;
   PCB *p,*q;
   printf("输入你想要创建的进程数量!\n");
   scanf("%d",&n);
   getchar();
   if(n<0) {printf("输入数据错误！\n");;exit(0);}
   else {
    ready=(PCB *)malloc(sizeof(PCB));     //创建一个表头指针

   p=ready;

   for(i=1;i<=n;i++)            //循环结构用来创建指定个数的节点
   {
       //printf("333333333");
      q=(PCB *)malloc(sizeof(PCB));
      p->next=q;
     // printf("333333333nnnnnnnnnn");
	  //dsp->next=q;
	 // printf(" ffffffffff333333333");
	  p=q;
	  printf("输入第 %d个进程的名字\n ",i);
	  scanf("%s",&p->name);
	  printf("输入起始地址!\n");
	  scanf("%s",&p->start2);
	  printf("输入所占内存大小\n");
	  scanf("%s",&p->size);
   }
   printf("**************");
   p->next=NULL;
   if(running==NULL)
   {
       printf("ppppppppp");
       ready_running(ready,running);
   }
   }
}

void show_s1(PCB *ready,PCB *block,PCB *running)
{
  printf("*************************");
   PCB *q;
   q=ready;
   if(q!=NULL)
   {
      printf("the station of ready:\n");
   }
   while(q!=NULL)
   {
       q=q->next;
	   printf("%s  ",q->name);
   }
   printf("\n");
   q=block;
   if(q!=NULL)
   {
      printf("the station of ready:\n");
     while(q!=NULL)
     {
         q=q->next;
	     printf("%s  ",q->name);
     }
   }
   printf("\n");
   q=running;
   if(q!=NULL)
   {
      printf("the station of ready:\n");
         while(q!=NULL)
    {
       q=q->next;
	   printf("%s  ",q->name);
    }
   }

}

///函数功能：（结束进程）删除执行状态进程
void detele_PCB(PCB *head)
{
  PCB *q,*p;
  q=head;
  p=q->next;
  q=p;
  free(p);
}
///函数功能：阻塞功能，将正在执行的状态转移到阻塞态队列尾部
void block_PCB(PCB *running,PCB *block,PCB *ready)
{
     PCB *q,*p;
     q=running->next;
     if(block==NULL)  q=block->next;   ///当阻塞队列为空时，直接插入
     else {            ///当队列不为空时，找到队尾，然后接到队尾
            p=block->next;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
        p->next=NULL;
     }
     ///**************将执行态调入新进程
     ready_running(ready,running);
}
///函数功能：唤醒功能。将阻塞队头进程调入就绪队列尾部
void block_ready(PCB *block,PCB *ready)
{
     PCB *q,*p;
     if(block==NULL)  {  printf("阻塞队列为空，唤醒失败！\n");  exit(0);}
     else{
        q=block->next;
        p=ready->next;
        while(p->next!=NULL){ p=p->next;}  ///找到就绪态尾部，
        p->next=q;
        p->next=NULL;
        q=q->next;
     }
}
///函数功能：时间片用完函数（将正在执行状态的进程放入就绪态尾部，并调入新进程到执行态）
void time_over(PCB *ready,PCB *running ){
  PCB *p;
  PCB *head1=running;
  PCB *head2=ready;
  p=head2;
  while(p->next!=NULL)
  {
      p=p->next;
  }
  p->next=head1->next;
  head1->next=NULL;
  running->next=ready->next;
}
///***************************************************************SPC-----------------------
//内存空间结构体
typedef struct space
{
   char start[10];
   char large[10];
   struct space *prior,*next;
    int a;//状态位标志
}SPACE；     
int main()
{
	 int choice;
//	 PCB *ready,*block,*running;  //定义进程的三种状态
	 PCB *block,*running;
	 PCB *ready;
	 ready=block=running=NULL;
	 SPACE  memeory;

	 printf("请输入将要开辟内存的起始地址！\n");
	 scanf("%d%d",&memory.start,&memory.end);
	 help_show();
	printf("输入选择选项！\n");
	scanf("%d",&choice);
	while(choice!=0)
    {
	 switch(choice)
	 {
	  case 1:
		 printf("创建进程！\n");
        creat_PCB(ready,running);
		 show_s1(ready,block,running);
		break;
	  case 3:
		 printf("时间片用完！\n");
		 time_over(ready,running);
		 show_s1(ready,block,running);
      case 2:
		 printf("终止进程！\n");
		 detele_PCB(running);
		 show_s1(ready,block,running);
		break;
      case 4:
         printf("阻塞进程!\n");
         block_PCB(running,block,ready);
         show_s1(ready,block,running);
         break;
      case 5:
        printf("唤醒进程!\n");
        block_ready(block,ready);
        show_s1(ready,block,running);
        break;
      case 6:
        printf("查看内存状态!\n");
        show_s1(ready,block,running);
        break;
        default:
            printf("输入选项错误请重新输入");

	  }
	   help_show();
       printf("输入选择选项！\n");
	   scanf("%d",&choice);
	 }

	return 0;
}


/*

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/
