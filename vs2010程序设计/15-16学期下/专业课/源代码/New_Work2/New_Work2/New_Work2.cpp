// New_Work2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
///����ȫ�ֱ�����
char prog[80],token[8];
char ch;
int syn,p,m=0,n,row,sum=0;
//char *rwtab[6]={"begin","if","then","while","do","end"};
char  * key2[13]={"creat","table","drop","alter","insert","delete","updata","select","grant","revoke","index","view","user"��"int","char"};
char  * rwtab[14]={"creat table","creat index","creat view","creat user","drop table","drop index","drop view","alter table","insert","delete","updata","select","grant","revoke"};
/////�������ܣ�ʵ�ִʷ������У��ַ�����ɨ�蹤��
void scaner()
{
	/*
	����Ϊ����飬�ֱ��Ǳ�ʾ�������֡����ţ���Ӧ����� if   else if  �� else 
	�涨�� �ؼ��� 1     ������ 2       ������  3

	*/ 
	int flage=0;
	for(n=0;n<8;n++) token[n]=NULL;
	ch=prog[p++];
	while(ch==' ')
	{
		ch=prog[p];
		p++;
	}
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))  //�����ǹؼ��ֻ��߱����� 
	{
		m=0;
		while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			token[m++]=ch;
			ch=prog[p++];
		}
		token[m++]='\0';
		p--;
		syn=10;
		for(n=0;n<13;n++)  //��ʶ��������ַ����Ѷ���ı�ʾ�����Ƚϣ� 
		{   
			if(strcmp(token,key2[n])==0)
			{
			//	printf("&&&&&&&&&&&&&&&&&&&");
				syn=n+1;
				printf("%d",syn);
				break;
			}
			//printf("^^^^^^^");
		}
	}
	else if((ch>='0'&&ch<='9'))  //���� 
	{
		{
			sum=0;
			while((ch>='0'&&ch<='9'))
			{
				sum=sum*10+ch-'0';
				ch=prog[p++];
			}
		}
		p--;
		syn=11;
		if(sum>32767)
			syn=-1;
	}
	else switch(ch)   //�����ַ� 
	{
	case'<':m=0;token[m++]=ch;
		ch=prog[p++];
		if(ch=='>')
		{
			syn=21;
			token[m++]=ch;
		}
		else if(ch=='=')
		{
			syn=22;
			token[m++]=ch;
		}
		else
		{
			syn=23;
			p--;
		}
		break;
	case'>':m=0;token[m++]=ch;
		ch=prog[p++];
		if(ch=='=')
		{
			syn=24;
			token[m++]=ch;
		}
		else
		{
			syn=20;
			p--;
		}
		break;
	case':':m=0;token[m++]=ch;
		ch=prog[p++];
		if(ch=='=')
		{
			syn=18;
			token[m++]=ch;
		}
		else
		{
			syn=17;
			p--;
		}
		break;
	case'*':syn=13;token[0]=ch;break;
	case'/':syn=14;token[0]=ch;break;
	case'+':syn=15;token[0]=ch;break;
	case'-':syn=16;token[0]=ch;break;
	case'=':syn=25;token[0]=ch;break;
	case';':syn=26;token[0]=ch;break;
	case'(':syn=27;token[0]=ch;break;
	case')':syn=28;token[0]=ch;break;
	case'#':syn=0;token[0]=ch;break;
	case'\n':syn=-2;break;
	default: syn=-1;break;
	}
}
////�������ܣ�ʵ�ִʷ���������
void Lexical()
{
	p=0;
	row=1;
	printf("�����������䣡����'#'������\n");
	do
	{
		scanf("%c",&ch);
		prog[p++]=ch;
	}
	while(ch!='#');
	p=0;
	do
	{
		scaner();
		switch(syn)
		{
		case 11:  printf("(%d,%d)\n",syn,sum);  break;
		case -1:  printf("Error in row %d!",row); break;
		case -2:  row=row++;   break;
		default :  printf("(%d,%s)\n",syn,token);   break;
		}
	}
	while (syn!=0);
}
int _tmain(int argc, _TCHAR* argv[])
{
	Lexical();
	return 0;
}






