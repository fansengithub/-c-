// 5.25��.cpp : �������̨Ӧ�ó������ڵ㡣
//������ʽ�洢

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char ch;         ///�ṹ���ַ��򣬴���ַ�
	struct node * next;  ///�ṹ��ָ���򣬴��ָ����һ�ڵ�ĵ�ַ
}linkstr;
///�������ܣ���ʼ������
linkstr * CreateNullString()
{
	linkstr * s;
	s=(linkstr *)malloc(sizeof(linkstr));   //���������ͷ���
	if(s!=NULL)
	{
		s->next=NULL;    ///ͷ����ָ�����ÿ�
	}
	return s;
}
///�������ܣ��ж��Ƿ�Ϊ�մ�
int isempty(linkstr * s)
{
	if(s->next==NULL)  
		return 1;
	else
		return 0;
}
//�������ܣ����ַ���������ֵ���ַ�������
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
		if(q!=NULL)    ///ԭ�����������д洢�ռ�ʱ
		{
			q->ch=t[i];
			r=q;
			q=q->next;
		}
		else      ///ԭ����������û�нڵ�ռ�ʱ��������洢�ռ� 
		{
			p=(linkstr *)malloc(sizeof(linkstr));
			p->ch=t[i];
			r->next=p;
			r=p;
		}
	}
	r->next=NULL;    
	while(q!=NULL)   ///��ԭ�������ж���Ľڵ��ͷ�
	{
		if(q->next!=NULL)   ///��q�������һ���ڵ�ʱ
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////��qʱ���һ���ڵ�ʱ
		{
			free(q);
		}
	}
}
///�������ܣ�����������ֵ��������
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
		if(q!=NULL)   ///ԭ�����������д洢�ռ�
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		} 
		else    ///ԭ�����������ڴ�ռ䲻��ʱ�������µĽڵ�
		{
			u=(linkstr *)malloc(sizeof(linkstr));
			u->ch=p->ch;
			r->next=u;
			r=u;
		}
		p=p->next;
	}
	r->next=NULL;
	while(q!=NULL)      ///��ԭ�������ж���Ľڵ��ͷ�
	{
		if(q->next!=NULL)   ///��q�������һ���ڵ�ʱ
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////��qʱ���һ���ڵ�ʱ
		{
			free(q);
		}
	}
}
///�������ܣ��󴮵ĳ���
int len(linkstr * s)
{
	linkstr * p;
	int n=0;
	p=s->next;       ///pָ��s�ĵ�һ���ڵ�
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}
//�������ܣ���������
void concat(linkstr * s,linkstr * s1,linkstr * s2)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	linkstr * t;
	r=s;
	q=s->next;
	p=s1->next;         ///��s1���е����ݸ��Ƶ�����
	while(p!=NULL)
	{
		if(q!=NULL)     //��s�з����˴洢�ռ�
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		}
		else        ///��s��û�з���洢�ռ䣬��Ҫ�����ڴ�ռ�
		{
			t=(linkstr *)malloc(sizeof(linkstr));
			t->ch=p->ch;
			r->next=t;       ///���½ڵ��������
			r=t;
		}
		p=p->next;
	}
	p=s2->next;            //��s2���е����ݣ�׷�ӵ�s����
	while(p!=NULL)
	{ 
		if(q!=NULL)        ///���s�����л��нڵ�
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		}
		else     ///s����û���㹻�Ľڵ㣬��Ҫ������ڵ�
		{
			t=(linkstr *)malloc(sizeof(linkstr));
			t->ch=p->ch;
			r->next=t;
			r=t;
		}
		p=p->next;
	}
	r->next=NULL;
	while(q!=NULL)                  ///��s�ж���Ľڵ��ͷ�
	{
		if(q->next!=NULL)   ///��q�������һ���ڵ�ʱ
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////��qʱ���һ���ڵ�ʱ
		{
			free(q);
		}
	}
}
///�������ܣ�ȡ�ִ�����
int substr(linkstr * s,int i,int j,linkstr * t)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	linkstr * u;
	int k=0;
	if(i<=0 || i>len(s) || j<=0 ||(i+j-1)>len(s))     ///�жϲ��� i j �ĺϷ���
	{
		printf("�������Ϸ���\n");
		return 0;
	}
	for(k=0,p=s;k<i;k++)    ///��pָ��s�ĵ�i-1���ڵ�
	{
		p=p->next;          
	}
	for(k=0,r=t,q=t->next;k<j;k++)
	{
		if(q!=NULL)            ///ԭ���������д洢�ռ�
		{
			q->ch=p->ch;
			r=q;
			q=q->next;
		}
		else               ///ԭ��������û�д洢�ռ䣬��Ҫ�����µĽڵ�
		{
			u=(linkstr *)malloc(sizeof(linkstr));
			u->ch=p->ch;
			r->next=u;
			r=u;
		}
		p=p->next;
	}
	r->next=NULL;
	while(q!=NULL)      ///��t�ж���Ľڵ��ͷ�
	{
		if(q->next!=NULL)   ///��q�������һ���ڵ�ʱ
		{
			p=q->next;
			free(q);
			q=p;
		}
		else           ////��qʱ���һ���ڵ�ʱ
		{
			free(q);
		}
	}
}
///�������ܣ��������
int insert(linkstr * s,int i,linkstr * t)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	int i=0;
	if(i<=0 || i>(len(s)+1))            ///�жϲ���i�ĺϷ���
	{
		printf("�������벻�Ϸ���\n");
		return 0;
	}
	r=s;
	int j=0;
	for( j=0;j<i-1;j++)             ///rָ��s�ĵ�i-1���ڵ�
	{
		r=r->next;
	}
	p=t->next;                    ///pָ��t�ĵ�һ���ڵ�
	while(p!=NULL)           ///��t���Ƶ�r��ָ��Ľڵ����
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
///�������ܣ�ɾ������
int Delete(linkstr * s,int i,int j)
{
	linkstr * p;
	linkstr * q;
	linkstr * r;
	if(i<=0 || i>len(s) ||j<0 ||(i+j-1)>len(s))    ///�жϲ���i j �ĺϷ���
	{
		printf("�����������\n");
		return 0;
	}
	p=s;
	for(int k=0;k<i-1;k++)        ///pָ��s�ĵ�i-1���ڵ�
	{
		p=p->next;
	}
	for(int k=1;k<=j;k++)          ///ɾ���ӵ�i���ڵ㿪ʼ��j���ڵ�
	{
		q=p->next;
		p->next=q->next;
		free(q);
	}
	return 1;
}
///�������ܣ��������
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
///�������ܣ��ҳ�x�е�һ������y�г��ֵ��ַ�
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
///�������ܣ��ж��������Ƿ����
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
///�������ܣ�˳�򴮵�ģʽƥ��  (Brete-Force)--�㷨
int index(string s,string t,int pos)
{
    if(pos<1 || pos>s.length || pos>s.length-t.length+1)    ///pos�����Ϸ��Լ��
		return 0;
	i=pos-1;
	j=0;
	while(i<s.length && j<t.length)
	{
	  if(s.ch[i]==t.ch[j])       ///�����ǰ�ַ���ȣ��������ȡ��һ�ַ�
	  {
	     i++;
		 j++;
	  }
	  else               ///�����ǰ�ַ����ȣ����¿�ʼ��һ��ƥ��
	  {
	     i=i-j+1;
		 j=0;
	  }
	  if(j>=t.length)          //��ƥ��ɹ�ʱ�����ص�һ�ַ������
		  return (i-t.length+1);
	  else 
		  return 0;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

