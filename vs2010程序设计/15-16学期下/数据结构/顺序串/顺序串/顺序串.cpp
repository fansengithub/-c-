// 顺序串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100
struct st {
   char * ch;      //存放字符串的首地址,第i个字符存储在  ch[i-1] 中
   int length;       ///串的长度
   int strsize;       //分配存储空间的大小,如果不够用，还可以用  realloc() 再分配，增加存储空间
};
typedef struct st String;
///函数功能:初始化操作
String Create_NullString()
{
    String(s);
	s.ch=(char *)malloc(MAXNUM*sizeof(char));   ///初始化顺序串的存储空间，相当于数组
	s.length=0;      ///初始化串长
	s.strsize=MAXNUM;          /// 初始化当前存储空间的容量
	return s;
}
///函数功能：判断是否为空串
int Is_Empty(String s)
{
  if(s.length==0)
	  return 1;
  else
	  return 0;
}
///将串常量赋值给串变量
void Assign_1(String * s1,char s2[])
{
   int i=0;
   while(s2[i]!='\0')                 ///统计字符串常量 s2 的长度
	   i++;
   if(i>s1->strsize)					///若存储空间不够，则增加存储空间
   {
	   s1->ch=(char *)realloc(s1->ch,i*sizeof(char));
	   s1->strsize=i;
   }
   s1->length=i;
   for(i=0;i<s1->length;i++)			//从第一个字符开始，逐个复制
   {
	   s1->ch[i]=s2[i];
   }
}
////函数功能：将字符串变量赋值给字符串常量
void Assign_2(String * s1,String s2)
{
	if(s1->strsize<s2.length)
	{
		s1->ch=(char *)realloc(s1->ch,s2.length*sizeof(char));
		s1->strsize=s2.length;
	}
	s1->length=s2.length;
	for(int i=0;i<s1->length;i++)			//从第一个字符开始逐个复制
	{
		s1->ch[i]=s2.ch[i];
	}
}
///函数功能：求字符串的长度
int Length(String s)
{
	return(s.length);
}
///函数功能：串的连接操作
void Concat(String *s,String s1,String s2)
{
	int i=0;
	if(s->length<(s1.length+s2.length))			//如果存储空间不足，则增加新的空间
	{
		s->ch=(char *)realloc(s->ch,(s1.length+s2.length)*sizeof(char));
		s->strsize=s1.strsize+s2.strsize;
	}
	s->length=s1.length+s2.length;				//连接后的字符串长度
	for( i=0;i<s1.length;i++)			///把  s1  复制到 s中
	{
		s->ch[i]=s1.ch[i];
	}
	for(;i<s->length;i++)
	{
		s->ch[i]=s2.ch[i-s1.length];
	}
}
////函数功能：取字串（在串s中从第i个字符开始，取出j个连续的字符组成一个新的字串，并放在 t 中）
int substr(String s,int i,int j,String * t)
{
	if(i<0||i>s.length ||j<0 ||j>s.length-i+1)
	{	
		printf("输入参数不合法！\n");         ///  参数 i  j 的合法性判断
		return 0;
	}
	if(t->length<j)         ////当t的存储空间不足时，增加存储空间
	{
		t->ch=(char *)realloc(t->ch,j*sizeof(char));
		t->strsize=j;
	}
	for(int k=0;k<j;k++)
		t->ch[k]=s.ch[i-1+k];
	t->length=j;
	return 1;
}
///函数功能：插入操作，（将串t 插入到串 s的第i个字符之前）
int  insert (String * s,int i, String t)
{
	if(i<0 ||i>s->length+1)       //判断参数i的合法性
		return 0;
	if(s->strsize<(s->length+t.length))    
	{													//增加存储空间
		s->ch=(char *)realloc(s->ch,(s->length+t.length)*sizeof(char));
		s->strsize=s->length+t.length;
	}
	for(j=s->length-1;j>=i;j++)
	{
	  
	}
}
///函数功能：删除操作
int Delete( String * s,int i,int j)
{
	if(i<=0 || i>s->length || j<=0 ||j>s->length-i+1)
	{
	  printf("输入参数错误!\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

