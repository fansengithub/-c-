// 5.25串.cpp : 定义控制台应用程序的入口点。
//串的链式存储

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char ch;         ///结构体字符域，存放字符
	struct node * next;  ///结构体指针域，存放指向下一节点的地址
}linkstr;
///函数功能：初始化操作
linkstr * CreateNullString()
{
	linkstr * s;
	s=(linkstr *)malloc(sizeof(linkstr));   //创建链表的头结点
	if(s!=NULL)
	{
		s->next=NULL;    ///头结点的指针域置空
	}
	return s;
}
///函数功能：判断是否为空串
int isempty(linkstr * s)
{
	if(s->next==NULL)  
		return 1;
	else
		return 0;
}
//函数功能：将字符串常量赋值给字符串变量
void stringassign(linkstr * s,char *  t)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	r=s;
	q=s->next;
	int i=0;
	for(i=0;t[i]!='\0';i++)
	{
		if(q!=NULL)    ///原来的连串中有存储空间时
		{
			q->ch=t[i];
			r=q;
			q=q->next;
		}
		else      ///原来的链表中没有节点空间时，与申请存储空间 
		{
			p=(linkstr *)malloc(sizeof(linkstr));
			p->ch=t[i];
			r->next=p;
			r=p;
		}
	}
	r->next=NULL;    
	while(q!=NULL)   ///将原来链表中多余的节点释放
	{
		if(q->next!=NULL)   ///当q不是最后一个节点时
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////当q时最后一个节点时
		{
			free(q);
		}
	}
}
///函数功能：将串变量赋值给串变量
void assign(linkstr * s,linkstr * t)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	linkstr * u;
	p=t->next;
	q=s->next;
	r=s;
	while(p!=NULL)
	{
		if(q!=NULL)   ///原来的链表中有存储空间
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		} 
		else    ///原来的链表中内存空间不足时，申请新的节点
		{
			u=(linkstr *)malloc(sizeof(linkstr));
			u->ch=p->ch;
			r->next=u;
			r=u;
		}
		p=p->next;
	}
	r->next=NULL;
	while(q!=NULL)      ///将原来链表中多余的节点释放
	{
		if(q->next!=NULL)   ///当q不是最后一个节点时
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////当q时最后一个节点时
		{
			free(q);
		}
	}
}
///函数功能：求串的长度
int len(linkstr * s)
{
	linkstr * p;
	int n=0;
	p=s->next;       ///p指向s的第一个节点
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}
//函数功能：串的连接
void concat(linkstr * s,linkstr * s1,linkstr * s2)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	linkstr * t;
	r=s;
	q=s->next;
	p=s1->next;         ///将s1表中的内容复制到串中
	while(p!=NULL)
	{
		if(q!=NULL)     //串s中分配了存储空间
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		}
		else        ///串s中没有分配存储空间，则要申请内存空间
		{
			t=(linkstr *)malloc(sizeof(linkstr));
			t->ch=p->ch;
			r->next=t;       ///将新节点接入链表
			r=t;
		}
		p=p->next;
	}
	p=s2->next;            //将s2表中的内容，追加到s后面
	while(p!=NULL)
	{ 
		if(q!=NULL)        ///如果s链表中还有节点
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		}
		else     ///s表中没有足够的节点，则要新申请节点
		{
			t=(linkstr *)malloc(sizeof(linkstr));
			t->ch=p->ch;
			r->next=t;
			r=t;
		}
		p=p->next;
	}
	r->next=NULL;
	while(q!=NULL)                  ///将s中多余的节点释放
	{
		if(q->next!=NULL)   ///当q不是最后一个节点时
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////当q时最后一个节点时
		{
			free(q);
		}
	}
}
///函数功能：取字串操作
int substr(linkstr * s,int i,int j,linkstr * t)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	linkstr * u;
	int k=0;
	if(i<=0 || i>len(s) || j<=0 ||(i+j-1)>len(s))     ///判断参数 i j 的合法性
	{
		printf("参数不合法！\n");
		return 0;
	}
	for(k=0,p=s;k<i;k++)    ///让p指向s的第i-1个节点
	{
		p=p->next;          
	}
	for(k=0,r=t,q=t->next;k<j;k++)
	{
		if(q!=NULL)            ///原来的链表有存储空间
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		}
		else               ///原来链表中没有存储空间，则要申请新的节点
		{
			u=(linkstr *)malloc(sizeof(linkstr));
			u->ch=p->ch;
			r->next=u;
			r=u;
		}
		p=p->next;
	}
	r->next=NULL;
	while(q!=NULL)      ///将t中多余的节点释放
	{
		if(q->next!=NULL)   ///当q不是最后一个节点时
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////当q时最后一个节点时
		{
			free(q);
		}
	}
}
///函数功能：插入操作
int insert(linkstr * s,int i,linkstr * t)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	int i=0;
	if(i<=0 || i>(len(s)+1))            ///判断参数i的合法性
	{
		printf("参数输入不合法！\n");
		return 0;
	}
	r=s;
	int j=0;
	for( j=0;j<i-1;j++)             ///r指向s的第i-1个节点
	{
		r=r->next;
	}
	p=t->next;                    ///p指向t的第一个节点
	while(p!=NULL)           ///将t复制到r所指向的节点后面
	{
		q=(linkstr *)malloc(sizeof(linkstr));
		q->ch=p->ch;
		q->next=r->next;
		r->next=q;
		r=q;
		p=p->next;
	}
	return 1;
}
///函数功能：删除操作
int Delete(linkstr * s,int i,int j)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	if(i<=0 || i>len(s) ||j<0 ||(i+j-1)>len(s))    ///判断参数i j 的合法性
	{
		printf("输入参数错误！\n");
		return 0;
	}
	p=s;
	for(int k=0;k<i-1;k++)        ///p指向s的第i-1个节点
	{
		p=p->next;
	}
	for(int k=1;k<=j;k++)          ///删除从第i个节点开始的j个节点
	{
		q=p->next;
		p->next=q->next;
		free(q);
	}
	return 1;
}
///函数功能：输出操作
void list(linkstr * s)
{
  linkstr * p;
  p=s->next;
  while(p!=NULL)
  {
	  printf("%c",p->ch);
	  p=p->next;
  }
  printf("\n");
}
///函数功能：找出x中第一个不在y中出现的字符
char comp(linkstr * x, linkstr * y)
{
	linkstr * p;
	linkstr * q;
	p=x->next;
	while(p!=NULL)
	{
		q=y->next;
		while(q!=NULL)
		{
			if(p->ch==q->ch)
				break;
			else
			{
				q=q->next;
			}
		}
		if(q!=NULL)
		{
			p=p->next;
		}
		else if(q==NULL)
		{
			return (p->ch);
		}
	}
	return ('\0');
}
///函数功能：判断两个串是否相等
int equal(linkstr * x,linkstr * y)
{
	linkstr * p;
	linkstr * q;
	while(p!=NULL && q!=NULL && p->ch==q->ch)
	{
		p=p->next;
		q=q->next;
	}
	if(p==NULL && q==NULL)
	{
	  return 1;
	}
	else 
		return 0;
}
///函数功能：顺序串的模式匹配  (Brete-Force)--算法
int index(string s,string t,int pos)
{
    if(pos<1 || pos>s.length || pos>s.length-t.length+1)    ///pos参数合法性检查
		return 0;
	i=pos-1;
	j=0;
	while(i<s.length && j<t.length)
	{
	  if(s.ch[i]==t.ch[j])       ///如果当前字符相等，则继续读取下一字符
	  {
	     i++;
		 j++;
	  }
	  else               ///如果当前字符不等，从新开始下一次匹配
	  {
	     i=i-j+1;
		 j=0;
	  }
	  if(j>=t.length)          //当匹配成功时，返回第一字符的序号
		  return (i-t.length+1);
	  else 
		  return 0;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

