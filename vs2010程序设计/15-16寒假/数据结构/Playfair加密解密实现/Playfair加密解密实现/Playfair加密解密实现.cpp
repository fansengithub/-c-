// Playfair加密解密实现.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N  100
int    Remove_Duplicate(char K_alphabet[N],char middle[N]);

void Show_Matrix(char Matrix[5][5] );
////函数功能：用户输入明文或密文
void Input(char input[N])
{
	int i=0;
	int j=0;
   //printf("请输入密钥，明文或者密文！(输入小写字母)\n");

   again: scanf("%s",input);
   j=strlen(input);
   for(i=0;i<j;i++)
   {
      if(input[i]<97||input[i]>122)				///输入合法性检查
	  {
	     printf("输入明文或者密文中有非法字符，请重新输入！（输入小写字母）\n");
		 goto again;			//当输入非法字符时，跳到输入代码，重新输入！
	  }
   }
}
///函数功能：根据输入的密钥构造相应的字母矩阵
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
	      
	char Alphabet[27]="abcdefghijklmnopqrstuvwxyz";       ////字母数组用于存储26个字母
	char Alp_Middle[27];					//用于记录Alpha中除去重复元素的字母
	char a;
	int flage_1=1;
	int  length=0;
    length=Remove_Duplicate(secret_key,middle);		///除去密钥中的重复字母
  //  length=strlen(middle);     ///记录下数组长度
	
	
	for(j=0;j<5;j++)			///向二维数组赋值
    {
	  for(k=0;k<5;k++)
		{
		    if(middle[i]!='j')     ////i与j放在同一个数组位置中，所以要特殊处理
			{
			  Matrix[j][k]=middle[i];
			  i++;
			}
			else
			{
			 i++;
			 continue;				///跳出本次循环
			}
			if(i==length)				///当middle数组中的元素遍历完后， 跳出所有循环
			{
			  
			  row=j;                     ////用row,column分别记录下矩阵中元素的具体位置
			  column=k;
			  break;					//此时，j  k  分别代表二维数组中，最后一个元素的位置
			}
	    }
	      if(i==length)				///当middle数组中的元素遍历完后， 跳出所有循环
			{
				
			  row=j;
			  column=k;
			   break;
			}
	 }
	//   多余代码
	/*        
	for(j=0;j<5;j++)				///在矩阵中找到元素按字母表顺序最后出现的元素
	{
	  for(k=0;k<5;k++)
	  {
		  flage=Matrix[j][k];
		  if(flage>compare)  compare=flage;      ///通过ascII比较字母先后顺序
		  if(count==(length-1))  break;				///当middle数组中的元素遍历完后，跳出循环
	     count++;
	  }
	     if(count==(length-1))  break;				///当middle数组中的元素遍历完后，跳出循环
	}   */
	for(j=0;j<27;j++)				///将Alphabet中在middle中出现的字母除去，并保存到Alp_Middle中
	{
	   a=Alphabet[j];
	   for(k=0;k<length;k++)
	   {
	     if(a==middle[k])
			 flage_1=2;         ///做标记
	   }
	   if(flage_1==1)				///如果a没有在middle中出现，保存到Alp_Middle中
	   {
	      Alp_Middle[t++]=a;
	   }
	   flage_1=1;
	}
	///队row ,column的情况进行判断
	if(column==4)     ////当到达矩阵行末尾时，转移到下一行
	{
	     row++;
		 column=0;
	}
	else
	{
	   column++;            ///直接转到矩阵下一个元素   
	}
	for(j=row,i=0;j<5;j++)     ///向矩阵添加Alp_Middle中的元素
	{
		if(j!=row) column=0;			///使k完成0--4的循环
	  for(k=column;k<5;k++)
	  {
		  if(Alp_Middle[i]=='j')     ////因为i与j放在矩阵同一位置中。当为j时，跳到下一元素
			  i++;
	       Matrix[j][k]=Alp_Middle[i++];
		  // if(k==4)  k=-1;				///使k完成0--4的循环
	  }
	}
	 Show_Matrix( Matrix );
}
///函数功能：判断K中第i个字符之前有没有与它相同的字符     
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
///函数功能：去除密钥空间字符串中的重复元素
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
		if(Is_First(i,K_alphabet))			///当a时第一个出现的字符时
		{
			middle[j]=a;
			j++;
		}
	}
	//length=j;
	//j=j-2;       //middle数组中最后两个不是字母，所以-2
	//return j;				///返回middle的长度
	return  j;
}
///函数功能：打印矩阵
void Show_Matrix(char Matrix[5][5] )
{
  int i=0;
  int j=0;
  printf("矩阵中的元素为: \n");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
	{
	   printf("%c  ",Matrix[i][j]);
	}
	printf("\n");
  }
}
///函数功能：在数组c中第i个位置添加元素'z'
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
	   clear_message[j+1]=clear_message[j];    ///一个一个向后串
	 }
	 clear_message[i]='z';
	return length;
}
///函数功能：求解密文的具体实现
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
	 x1=x2=y1=y2=0;       ///x y 分别记录矩阵中两个元素对应的下标
	//length=strlen(clear_message);
	for(i=0;i<length;i=i+2)                 ////对明文中两个字符，两个字符加密
	{
	 
	  first=clear_message[i];
	  second=clear_message[(i+1)];
	  for(j=0;j<5;j++)						////在矩阵中找到对应的两个字符，并记录下各自的下标
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
			//if(flage==1)    break;       //当找到对应元素时，直接跳出循环
		 }
		    ///if(flage==1)    break;
	  }
	  
	  if(x1==x2&&y1!=y2)      ///当两个元素同行不同列时
	  {
	    y1++;     ///右边的元素左为密文元素
		y2++;
		if(y2==5)  y2=0;     ////行中0号元素作为4的下一个元素
		if(y1==5)  y1=0;
	  }
	  if(y1==y2&&x1!=x2)      ///当两个元素同列不同行时
	  {
	    x1++;                  
		x2++;
		if(x1==5)  x1=0;          ////列中0号元素作为4的下一个元素
		if(x2==5)  x2=0;
	  }
	  if(x1!=x2&&y1!=y2)            ////当两个元素不同行，不同列时
	  {   
			   temp=y1;				///y1  y2  互换位置
			   y1=y2;
			   y2=temp;
	  }
	  encrypted_message[i]=Matrix[x1][y1];
	  encrypted_message[(i+1)]=Matrix[x2][y2];
	}
	
	printf("加密原则：如果明文个数是单数，加密时给字符串最后面添加 'z';\n");
	printf("          如果明文中有重复字母，中间加'z';\n\n\n");
	printf("经过加密操作后，得到的密文是：\n");
	
	//length=strlen(encrypted_message);
   //puts(encrypted_message);
   for(i=0;i<length;i++)
   {
     printf("%c",encrypted_message[i]);
   }
   printf("\n");
}
////函功能：实现加密功能
void Encryption_1(char clear_message[N],char  encrypted_message[N],char Matrix[5][5])
{
	int length=0;
	int i=0;
					///加密过程中，用到两个字符
	length=strlen(clear_message);
	for(i=0;i<(length-1);i++)			///检查数组中是否有重复元素，如果有重复元素，中间添加w
	{
	   if(clear_message[i]==clear_message[i+1])      
		{   
			length=Add_Char(clear_message,(i+1));
	   }
	}
	if(length%2!=0)      ///判断字符串的长度为奇数，，给末尾加  z  频率分析中，z的使用频率最小
	{
	  i=length;
	  clear_message[i]='z';                                    //////???????????????????????????????????????????
	  length++;
	}
	Encryption_2(clear_message,encrypted_message,Matrix,length);
}
///函数功能：实现解密功能
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
	 x1=x2=y1=y2=0;       ///x y 分别记录矩阵中两个元素对应的下标
	length=strlen(encrypted_message);
	for(i=0;i<length;i=i+2)                 ////对明文中两个字符，两个字符加密
	{
	 
	  first=encrypted_message[i];
	  second=encrypted_message[(i+1)];
	  for(j=0;j<5;j++)						////在矩阵中找到对应的两个字符，并记录下各自的下标
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
			//if(flage==1)    break;       //当找到对应元素时，直接跳出循环
		 }
		    ///if(flage==1)    break;
	  }
	  
	  if(x1==x2&&y1!=y2)      ///当两个元素同行不同列时
	  {
		  y1--;
		  y2--;
		  if(y1==-1)  y1=4;
		  if(y2==-1)   y2=4;
	  }
	  if(y1==y2&&x1!=x2)      ///当两个元素同列不同行时
	  {
		 x1--;
		 x2--;
		 if(x1==-1)  x1=4;
		 if(x2==-1)  x2=4;
	  }
	  if(x1!=x2&&y1!=y2)            ////当两个元素不同行，不同列时
	  {   
			   temp=y1;				///y1  y2  互换位置
			   y1=y2;
			   y2=temp;
	  }
	  clear_message[i]=Matrix[x1][y1];
	  clear_message[(i+1)]=Matrix[x2][y2];
	}
	printf("经过解密操作后，得到的明文是：\n");
	//length=strlen(encrypted_message);
   //puts(encrypted_message);
   for(i=0;i<length;i++)
   {
	   if((i==(length-1))&&clear_message[i]=='z')       ////与奇数个字符对应判断！
		   break;
     printf("%c",clear_message[i]);
   }
   printf("\n");
}
/// 函数功能：实现菜单展示
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
	char key[N];						///密钥
	char clear_message_0[N];          ///明文
	char  encrypted_message_0[N];			//密文       0 号明文，密文，用于加密
	char clear_message_1[N];
    char encrypted_message_1[N];				//1 号明文，密文用于解密
	char Matrix[5][5];						///最终求解的矩阵
	printf("请输入密钥！（输入小写字母！）\n");
	Input(key);				  ///输入密钥
	Creat_Matrix(key,Matrix);				///构造矩阵
	
	//Input(encrypted_message);    ///输入密文
	menu();
	printf("请输入选择!\n");
	scanf("%d",&choice);
    while(choice!=3)
	{
	   if(choice==1)         ///加密过程
	   {
		 printf("请输入明文！（输入小写字母！）\n");
	     Input(clear_message_0);      ////输入明文
	     Encryption_1(clear_message_0,encrypted_message_0,Matrix);

	   }
	   else if(choice==2)			///解密过程
	   {
	    printf("请输入密文！（输入小写字母！）\n");
		Input(encrypted_message_1);
		Decryption(clear_message_1,encrypted_message_1,Matrix);
	   }
	   else
	   {
	      printf("输入错误！请重新输入！\n");
	   }
	 menu();
	printf("请输入选择!\n");
	scanf("%d",&choice);
	}
	return 0;
}

