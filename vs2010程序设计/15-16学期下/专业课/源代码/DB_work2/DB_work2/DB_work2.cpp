
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define N1 10
char  * key2[18]={"create","table","drop","alter","insert","into","delete","from","updata","select","grant","revoke","index","view","user","int","char","values"};
char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};
/////�������ܣ�������ݿ�Ĳ���
void  Function3()
{
	
	char ch;
	char  action[N]="";
	char  get[N1];
	printf("���������ݿ������\n");
	gets(action);
	int word1=-1;     ///��¼�������ĵ�һ���ؼ��ʣ�
	int word2=-1;    ////��¼�������ĵڶ����ؼ���
	int i=0;
	int use=0;
	int j=0;
	int first=-1;
	int sum=0;
	int run=-1;
	int k=0;
	printf("***********************\n");
	int position;
	ch=action[i];
	while(ch==' ')          /////���˵��������Ŀո�
	{
		i++;
		ch=action[i];
	}
	while(ch!='#')
	{
		while(ch==' ')          /////���˵��������Ŀո�
		{
			i++;
			ch=action[i];
		}

		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))     //�����ǹؼ��ֻ��߱�����
		{
			j=0;
			while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			{
				get[j++]=ch;
				i++;
				ch=action[i];
			}
			get[j++]='\0';      ////����ĩβ��ֵ

			for(k=0;k<18;k++)           /////�͹ؼ���������Ԫ�رȽϣ��ҵ�ƥ���ַ���
			{
				if(strcmp(get,key2[k])==0)
				{
					position=k;      ////��¼�¹ؼ��ֵ�λ��

					break;
				}
			}

		}
		else if(ch>='0'&&ch<='9')     ////��ʱ����ʱ
		{
			sum=0;
			while(ch>='0'&&ch<='9')
			{
				sum=sum*10+ch-'0';       ////����������ɵ��ַ���ת��Ϊ10����
				i++;
				ch=action[i];
			}
			printf("(4,%d)\n",sum);
			sum=0;
		}
		else           ///��chΪ�ֽ��ʱ
		{
			printf("(3,%c)\n",ch);
			i++;
			ch=action[i];
		}
		//	length--;
	}
	if(ch=='#')
	{
		printf("(-1,%c)\n",ch);

	} 
}
int _tmain(int argc, _TCHAR* argv[])
{
    
	return 0;
}