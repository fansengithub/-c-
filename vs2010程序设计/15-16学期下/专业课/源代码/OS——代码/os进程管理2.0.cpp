// os���̹���2.0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// os���̹���.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//�������ܣ���ʾ������Ϣ
//**********************************************************************PCB ----------------------
typedef struct pcb    //������ƿ�
{
    char name[10];   //��Ž��̵�����
    char  start2[5];   //��¼���̵���ʼ��ַ
    struct pcb  *next;
	char size[5];       //��¼���̵Ĵ�С
}PCB;
void help_show()
{
  printf("*******************************\n");
  printf("     1.��������\n");
  printf("     2.��ֹ����--------��������ִ�еĳ���\n");
  printf("     3.ʱ��Ƭ��------������ִ�еĽ���װ���������β��������һ���Զ�����ִֵ��̬\n");
  printf("     4.����-----������ִ�еĽ��̲�����������β��\n");
  printf("     5.����-----����������ͷ�ƶ�����������β��\n");
  printf("     6.��ѯ1-----�鿴��������״̬���е����\n");
  printf("     7.��ѯ2-----s2 �鿴�ڴ��ʣ�����\n");
  printf("     0.�˳���\n");
  printf("*******************************\n");
}
///�������ܣ����Զ����ȣ�����̬��ִ��̬��ת��
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
   else printf("�Զ�����ʧ�ܣ�\n");
}
///�������ܣ���������
void  creat_PCB(PCB *ready,PCB *running)
{
  // printf("��ӽ��̣�\n");
  // PCB *ready=NULL;
   int n,i;
  // PCB *head=NULL;
   PCB *p,*q;
   printf("��������Ҫ�����Ľ�������!\n");
   scanf("%d",&n);
   getchar();
   if(n<0) {printf("�������ݴ���\n");;exit(0);}
   else {
    ready=(PCB *)malloc(sizeof(PCB));     //����һ����ͷָ��

   p=ready;

   for(i=1;i<=n;i++)            //ѭ���ṹ��������ָ�������Ľڵ�
   {
       //printf("333333333");
      q=(PCB *)malloc(sizeof(PCB));
      p->next=q;
     // printf("333333333nnnnnnnnnn");
	  //dsp->next=q;
	 // printf(" ffffffffff333333333");
	  p=q;
	  printf("����� %d�����̵�����\n ",i);
	  scanf("%s",&p->name);
	  printf("������ʼ��ַ!\n");
	  scanf("%s",&p->start2);
	  printf("������ռ�ڴ��С\n");
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

///�������ܣ����������̣�ɾ��ִ��״̬����
void detele_PCB(PCB *head)
{
  PCB *q,*p;
  q=head;
  p=q->next;
  q=p;
  free(p);
}
///�������ܣ��������ܣ�������ִ�е�״̬ת�Ƶ�����̬����β��
void block_PCB(PCB *running,PCB *block,PCB *ready)
{
     PCB *q,*p;
     q=running->next;
     if(block==NULL)  q=block->next;   ///����������Ϊ��ʱ��ֱ�Ӳ���
     else {            ///�����в�Ϊ��ʱ���ҵ���β��Ȼ��ӵ���β
            p=block->next;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
        p->next=NULL;
     }
     ///**************��ִ��̬�����½���
     ready_running(ready,running);
}
///�������ܣ����ѹ��ܡ���������ͷ���̵����������β��
void block_ready(PCB *block,PCB *ready)
{
     PCB *q,*p;
     if(block==NULL)  {  printf("��������Ϊ�գ�����ʧ�ܣ�\n");  exit(0);}
     else{
        q=block->next;
        p=ready->next;
        while(p->next!=NULL){ p=p->next;}  ///�ҵ�����̬β����
        p->next=q;
        p->next=NULL;
        q=q->next;
     }
}
///�������ܣ�ʱ��Ƭ���꺯����������ִ��״̬�Ľ��̷������̬β�����������½��̵�ִ��̬��
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
//�ڴ�ռ�ṹ��
typedef struct space
{
   char start[10];
   char large[10];
   struct space *prior,*next;
    int a;//״̬λ��־
}SPACE��     
int main()
{
	 int choice;
//	 PCB *ready,*block,*running;  //������̵�����״̬
	 PCB *block,*running;
	 PCB *ready;
	 ready=block=running=NULL;
	 SPACE  memeory;

	 printf("�����뽫Ҫ�����ڴ����ʼ��ַ��\n");
	 scanf("%d%d",&memory.start,&memory.end);
	 help_show();
	printf("����ѡ��ѡ�\n");
	scanf("%d",&choice);
	while(choice!=0)
    {
	 switch(choice)
	 {
	  case 1:
		 printf("�������̣�\n");
        creat_PCB(ready,running);
		 show_s1(ready,block,running);
		break;
	  case 3:
		 printf("ʱ��Ƭ���꣡\n");
		 time_over(ready,running);
		 show_s1(ready,block,running);
      case 2:
		 printf("��ֹ���̣�\n");
		 detele_PCB(running);
		 show_s1(ready,block,running);
		break;
      case 4:
         printf("��������!\n");
         block_PCB(running,block,ready);
         show_s1(ready,block,running);
         break;
      case 5:
        printf("���ѽ���!\n");
        block_ready(block,ready);
        show_s1(ready,block,running);
        break;
      case 6:
        printf("�鿴�ڴ�״̬!\n");
        show_s1(ready,block,running);
        break;
        default:
            printf("����ѡ���������������");

	  }
	   help_show();
       printf("����ѡ��ѡ�\n");
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
