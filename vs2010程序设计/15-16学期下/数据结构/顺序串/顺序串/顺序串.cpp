// ˳��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100
struct st {
   char * ch;      //����ַ������׵�ַ,��i���ַ��洢��  ch[i-1] ��
   int length;       ///���ĳ���
   int strsize;       //����洢�ռ�Ĵ�С,��������ã���������  realloc() �ٷ��䣬���Ӵ洢�ռ�
};
typedef struct st String;
///��������:��ʼ������
String Create_NullString()
{
    String(s);
	s.ch=(char *)malloc(MAXNUM*sizeof(char));   ///��ʼ��˳�򴮵Ĵ洢�ռ䣬�൱������
	s.length=0;      ///��ʼ������
	s.strsize=MAXNUM;          /// ��ʼ����ǰ�洢�ռ������
	return s;
}
///�������ܣ��ж��Ƿ�Ϊ�մ�
int Is_Empty(String s)
{
  if(s.length==0)
	  return 1;
  else
	  return 0;
}
///����������ֵ��������
void Assign_1(String * s1,char s2[])
{
   int i=0;
   while(s2[i]!='\0')                 ///ͳ���ַ������� s2 �ĳ���
	   i++;
   if(i>s1->strsize)					///���洢�ռ䲻���������Ӵ洢�ռ�
   {
	   s1->ch=(char *)realloc(s1->ch,i*sizeof(char));
	   s1->strsize=i;
   }
   s1->length=i;
   for(i=0;i<s1->length;i++)			//�ӵ�һ���ַ���ʼ���������
   {
	   s1->ch[i]=s2[i];
   }
}
////�������ܣ����ַ���������ֵ���ַ�������
void Assign_2(String * s1,String s2)
{
	if(s1->strsize<s2.length)
	{
		s1->ch=(char *)realloc(s1->ch,s2.length*sizeof(char));
		s1->strsize=s2.length;
	}
	s1->length=s2.length;
	for(int i=0;i<s1->length;i++)			//�ӵ�һ���ַ���ʼ�������
	{
		s1->ch[i]=s2.ch[i];
	}
}
///�������ܣ����ַ����ĳ���
int Length(String s)
{
	return(s.length);
}
///�������ܣ��������Ӳ���
void Concat(String *s,String s1,String s2)
{
	int i=0;
	if(s->length<(s1.length+s2.length))			//����洢�ռ䲻�㣬�������µĿռ�
	{
		s->ch=(char *)realloc(s->ch,(s1.length+s2.length)*sizeof(char));
		s->strsize=s1.strsize+s2.strsize;
	}
	s->length=s1.length+s2.length;				//���Ӻ���ַ�������
	for( i=0;i<s1.length;i++)			///��  s1  ���Ƶ� s��
	{
		s->ch[i]=s1.ch[i];
	}
	for(;i<s->length;i++)
	{
		s->ch[i]=s2.ch[i-s1.length];
	}
}
////�������ܣ�ȡ�ִ����ڴ�s�дӵ�i���ַ���ʼ��ȡ��j���������ַ����һ���µ��ִ��������� t �У�
int substr(String s,int i,int j,String * t)
{
	if(i<0||i>s.length ||j<0 ||j>s.length-i+1)
	{	
		printf("����������Ϸ���\n");         ///  ���� i  j �ĺϷ����ж�
		return 0;
	}
	if(t->length<j)         ////��t�Ĵ洢�ռ䲻��ʱ�����Ӵ洢�ռ�
	{
		t->ch=(char *)realloc(t->ch,j*sizeof(char));
		t->strsize=j;
	}
	for(int k=0;k<j;k++)
		t->ch[k]=s.ch[i-1+k];
	t->length=j;
	return 1;
}
///�������ܣ����������������t ���뵽�� s�ĵ�i���ַ�֮ǰ��
int  insert (String * s,int i, String t)
{
	if(i<0 ||i>s->length+1)       //�жϲ���i�ĺϷ���
		return 0;
	if(s->strsize<(s->length+t.length))    
	{													//���Ӵ洢�ռ�
		s->ch=(char *)realloc(s->ch,(s->length+t.length)*sizeof(char));
		s->strsize=s->length+t.length;
	}
	for(j=s->length-1;j>=i;j++)
	{
	  
	}
}
///�������ܣ�ɾ������
int Delete( String * s,int i,int j)
{
	if(i<=0 || i>s->length || j<=0 ||j>s->length-i+1)
	{
	  printf("�����������!\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

