#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N  100
///删除重复元素
int    Remove_Duplicate(char K_alphabet[N],char middle[N]);

void Show_Matrix(char Matrix[5][5] );
////输入明文或密文
void Input(char input[N])
{
	int i=0;
	int j=0;


   again: scanf("%s",input);
   j=strlen(input);
   for(i=0;i<j;i++)
   {
      if(input[i]<97||input[i]>122)				///合法性检查
	  {
	     printf("输入非法字符，请重新输入!\n");
		 goto again;			
	  }
   }
}
///根据输入秘钥构造响应的字母矩阵
void Creat_Matrix(char secret_key[],char Matrix[5][5])
{
	char middle[N];
	int i=0;
	int j=0;
	int k=0;
	int t=0;
	int count=0;
	int flage=0;
	int compare=97;
//	int length;  
	int  row=0;
	int column=0;
	      
	char Alphabet[27]="abcdefghijklmnopqrstuvwxyz";       ////字Á?母?数ºy组Á¨¦用®?于®¨²存ä?储ä¡é26个?字Á?母?
	char Alp_Middle[27];					//用®?于®¨²记?录?Alpha中D除y去¨£¤重?复¡ä元a素?的Ì?字Á?母?
	char a;
	int flage_1=1;
	int  length=0;
    length=Remove_Duplicate(secret_key,middle);		///除去秘钥中重复字母
 
	for(j=0;j<5;j++)			///向2维数组，中输入数字
    {
	  for(k=0;k<5;k++)
		{
		    if(middle[i]!='j')     ////i与J放在同一位置，所以特殊处理
			{
			  Matrix[j][k]=middle[i];
			  i++;
			}
			else
			{
			 i++;
			 continue;				///不存放j字母
			}
			if(i==length)				///当middle数组中元素存放完毕时跳出循环，并记录下坐标
			{
			  
			  row=j;                     
			  column=k;
			  break;					
			}
	    }
	      if(i==length)				///当Ì¡Àmiddle数ºy组Á¨¦中D的Ì?元a素?遍À¨¦历¤¨²完ª¨º后¨®，ê? 跳¬?出?所¨´有®D循-环¡¤
			{
				
			  row=j;
			  column=k;
			   break;
			}
	 }
	for(j=0;j<27;j++)				///将Alphabet中D在¨²middle中D出?现?的Ì?字Á?母?除y去¨£¤，ê?并¡é保À¡ê存ä?到Ì?Alp_Middle中D
	{
	   a=Alphabet[j];
	   for(k=0;k<length;k++)
	   {
	     if(a==middle[k])
			 flage_1=2;         ///做标记?
	   }
	   if(flage_1==1)				///如果没有在middle中出现保到Alp_Middle中
	   {
	      Alp_Middle[t++]=a;
	   }
	   flage_1=1;
	}
	///队¨®row ,column的Ì?情¨¦况?进?行D判D断?
	if(column==4)     ////当Ì¡À到Ì?达ä?矩?阵¨®行D末?尾2时º¡À，ê?转Áa移°?到Ì?下?一°?行D
	{
	     row++;
		 column=0;
	}
	else
	{
	   column++;            ///直¡À接¨®转Áa到Ì?矩?阵¨®下?一°?个?元a素?   
	}
	for(j=row,i=0;j<5;j++)     ///向¨°矩?阵¨®添¬¨ª加¨®Alp_Middle中D的Ì?元a素?
	{
		if(j!=row) column=0;			///使º1k完ª¨º成¨¦0--4的Ì?循-环¡¤
	  for(k=column;k<5;k++)
	  {
		  if(Alp_Middle[i]=='j')     ////因°¨°为ai与®?j放¤?在¨²矩?阵¨®同ª?一°?位?置?中D。¡ê当Ì¡À为aj时º¡À，ê?跳¬?到Ì?下?一°?元a素?
			  i++;
	       Matrix[j][k]=Alp_Middle[i++];
		  // if(k==4)  k=-1;				///使º1k完ª¨º成¨¦0--4的Ì?循-环¡¤
	  }
	}
	 Show_Matrix( Matrix );
}
///判断第i个字符之前，有没有和它相同的字符   
int Is_First(int i,char K_alphabet[N])   
{ 
	char a=K_alphabet[i];
	int j=0;
	while(j<i)
	{
		if(K_alphabet[j]==a)
		{
			return 0;
		}
		j++;
	}
	return 1;
}
///除去秘钥空间中的字符串中的重复字符
int    Remove_Duplicate(char K_alphabet[N],char middle[N])
{
	int i;
	int j;
	j=0;
	char a;
	int k=strlen(K_alphabet);
	for(i=0;i<k;i++)
	{
		a=K_alphabet[i];
		if(Is_First(i,K_alphabet))			///第一次出现时，直接存入
		{
			middle[j]=a;
			j++;
		}
	}
	
	return  j;       ////返回最终串的总长度
}
///打印矩阵
void Show_Matrix(char Matrix[5][5] )
{
  int i=0;
  int j=0;
  printf("构造矩阵中的元素为：\n");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
	{
	   printf("%c  ",Matrix[i][j]);
	}
	printf("\n");
  }
}
///元素的第i个位置，添加字符
int  Add_Char(char clear_message[N],int i)
{
     int j=0;
	 int k=0;
	 int length=0;
	 int  temp=0;
	 length=strlen(clear_message);
	 k=length;
	 length++;
	 for(j=(k-1);j>=(i-1);j--)
	 {
	   clear_message[j+1]=clear_message[j];   
	 }
	return length;
}
///加密功能
void Encryption_2(char clear_message[N],char  encrypted_message[N],char Matrix[5][5],int length)
{
	char first;
	char second;
   // int length=0;
	 int i=0;
	 int j=0;
	 int k=0;
	 int temp=0;
//	 int   flage=0;
	 int x1,x2,y1,y2;
	 x1=x2=y1=y2=0;       ///x y 分别记录着矩阵中两个元素的对应下表
	//length=strlen(clear_message);
	for(i=0;i<length;i=i+2)                 ////明文中两个，两个进行加密
	{
	 
	  first=clear_message[i];
	  second=clear_message[(i+1)];
	  for(j=0;j<5;j++)						////在矩阵中找到两个字符，并记录下标
	  {
	     for(k=0;k<5;k++)
		 {
		    if(first==Matrix[j][k])   
			{
			   x1=j;
			   y1=k;
			   
			}
			if(second==Matrix[j][k])
			{
			  x2=j;
			  y2=k;
			 
			}
			//if(flage==1)    break;       
		 }
		    ///if(flage==1)    break;
	  }
	  
	  if(x1==x2&&y1!=y2)      ///当两个元素，同行，不同列时
	  {
	    y1++;     ///右边的元素为最终元素
		y2++;
		if(y2==5)  y2=0;     ////行D中D0号?元a素?作Á¡Â为a4的Ì?下?一°?个?元a素?
		if(y1==5)  y1=0;
	  }
	  if(y1==y2&&x1!=x2)      ///同列不同行时
	  {
	    x1++;                  
		x2++;
		if(x1==5)  x1=0;          ////列¢D中D0号?元a素?作Á¡Â为a4的Ì?下?一°?个?元a素?
		if(x2==5)  x2=0;
	  }
	  if(x1!=x2&&y1!=y2)            ////不同行，不同列时
	  {   
			   temp=y1;				///y1  y2  互换
			   y1=y2;
			   y2=temp;
	  }
	  encrypted_message[i]=Matrix[x1][y1];
	  encrypted_message[(i+1)]=Matrix[x2][y2];
	}
	
	printf("加密方法：右移，下移，,,如果字符个数是奇数或者有重复元素，加入'w'，\n");
	
	printf("密文是:\n");
	
	//length=strlen(encrypted_message);
   //puts(encrypted_message);
   for(i=0;i<length;i++)
   {
     printf("%c",encrypted_message[i]);
   }
   printf("\n");
}
////加密功能
void Encryption_1(char clear_message[N],char  encrypted_message[N],char Matrix[5][5])
{
	int length=0;
	int i=0;
					
	length=strlen(clear_message);
	for(i=0;i<(length-1);i++)			///是否有连续的重复字符，如果有，加入w
	{
	   if(clear_message[i]==clear_message[i+1])      
		{   
			length=Add_Char(clear_message,(i+1));
	   }
	}
	if(length%2!=0)      ///明文长度是奇数，加 w 
	{
	  i=length;
	  clear_message[i]='w';                                    //////???????????????????????????????????????????
	  length++;
	}
	Encryption_2(clear_message,encrypted_message,Matrix,length);
}
///解密功能
void Decryption(char clear_message[N],char encrypted_message[N],char Matrix[5][5])
{
    char first;
	char second;
    int length=0;
	 int i=0;
	 int j=0;
	 int k=0;
	 int temp=0;
//	 int   flage=0;
	 int x1,x2,y1,y2;
	 x1=x2=y1=y2=0;       ///x y 两个元素下标
	length=strlen(encrypted_message);
	for(i=0;i<length;i=i+2)                 ////对?明¡Â文?中D两¢?个?字Á?符¤?，ê?两¢?个?字Á?符¤?加¨®密¨¹
	{
	 
	  first=encrypted_message[i];
	  second=encrypted_message[(i+1)];
	  for(j=0;j<5;j++)						////在¨²矩?阵¨®中D找¨°到Ì?对?应®|的Ì?两¢?个?字Á?符¤?，ê?并¡é记?录?下?各¡Â自Á?的Ì?下?标À¨º
	  {
	     for(k=0;k<5;k++)
		 {
		    if(first==Matrix[j][k])   
			{
			   x1=j;
			   y1=k;
			   
			}
			if(second==Matrix[j][k])
			{
			  x2=j;
			  y2=k;
			 
			}
			//if(flage==1)    break;       //当Ì¡À找¨°到Ì?对?应®|元a素?时º¡À，ê?直¡À接¨®跳¬?出?循-环¡¤
		 }
		    ///if(flage==1)    break;
	  }
	  
	  if(x1==x2&&y1!=y2)      ///当Ì¡À两¢?个?元a素?同ª?行D不?同ª?列¢D时º¡À
	  {
		  y1--;
		  y2--;
		  if(y1==-1)  y1=4;
		  if(y2==-1)   y2=4;
	  }
	  if(y1==y2&&x1!=x2)      ///当Ì¡À两¢?个?元a素?同ª?列¢D不?同ª?行D时º¡À
	  {
		 x1--;
		 x2--;
		 if(x1==-1)  x1=4;
		 if(x2==-1)  x2=4;
	  }
	  if(x1!=x2&&y1!=y2)            ////当Ì¡À两¢?个?元a素?不?同ª?行D，ê?不?同ª?列¢D时º¡À
	  {   
			   temp=y1;				///y1  y2  互£¤换?位?置?
			   y1=y2;
			   y2=temp;
	  }
	  clear_message[i]=Matrix[x1][y1];
	  clear_message[(i+1)]=Matrix[x2][y2];
	}
	printf("\n明文是\n");
	//length=strlen(encrypted_message);
   //puts(encrypted_message);
   for(i=0;i<length;i++)
   {
     printf("%c",clear_message[i]);
   }
   printf("\n");
}
/// 菜单
void menu()
{
  printf("\t\t\t*************************\n");
  printf("\t\t\t    1   Playfair 加密\n");
  printf("\t\t\t    2   Playfair 解密\n");
  printf("\t\t\t    3   退出\n");
  printf("\t\t\t*************************\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	char key[N];						///秘钥
	char clear_message_0[N];          ///明文
	char  encrypted_message_0[N];			//密文
	char clear_message_1[N];
    char encrypted_message_1[N];				//解密的明文
	char Matrix[5][5];						///
	printf("输入秘钥\n");
	Input(key);				  ///输º?入¨?密¨¹钥?
	Creat_Matrix(key,Matrix);				///构1造¨¬矩?阵¨®
	
	//Input(encrypted_message);    ///输º?入¨?密¨¹文?
	menu();
	printf("输入选择！\n");
	scanf("%d",&choice);
    while(choice!=3)
	{
	   if(choice==1)         ///加¨®密¨¹过y程¨¬
	   {
		 printf("请输入明文\n");
	     Input(clear_message_0);      ////输º?入¨?明¡Â文?
	     Encryption_1(clear_message_0,encrypted_message_0,Matrix);

	   }
	   else if(choice==2)			///解a密¨¹过y程¨¬
	   {
	    printf("输入密文\n");
		Input(encrypted_message_1);
		Decryption(clear_message_1,encrypted_message_1,Matrix);
	   }
	   else
	   {
	      printf("重新输入\n");
	   }
	 menu();
	printf("输入选择!\n");
	scanf("%d",&choice);
	}
	return 0;
}

