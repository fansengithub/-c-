// New_Client.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <WINSOCK2.H>
#include <STDIO.H>

#pragma  comment(lib,"ws2_32.lib")
#define N 10
///创建RIP 结构体
typedef struct RIP{
	char  aim[N];       ////目的网络---
	int   dis;            //距离
	char jump[N];      //下一跳
	char  host_add[N];          ///存放本地路由地址
  //  RIP * next;   ///形成链表结构
}RIP;

int main(int argc, char* argv[])
{
	///本地路由表初始化
	char add_2[10]="R6";
	int count=0;
	RIP c[N];                  ////结构体数组
	RIP d[N];             ///用于存储接收到的初始路由表，，，并进行预处理
	int count1=0;
	
	//RIP c3;
	strcpy(c[0].aim,"Net2");
	c[0].dis=3;
	//strcpy(c[0].dis,"2");
	strcpy(c[0].host_add,add_2);
	strcpy(c[0].jump,"R4");
	count++;

	strcpy(c[1].aim,"Net3");
	strcpy(c[1].host_add,add_2);
	c[1].dis=4;
	//strcpy(c[1].dis,"3");
	//L->dis=3;
	strcpy(c[1].jump,"R5");
	count++;

	//RIP c2;
	strcpy(c[2].aim,"Net8");
	strcpy(c[2].host_add,add_2);
	c[2].dis=4;
	//strcpy(c[2].dis,"4");
	strcpy(c[2].jump,"R8");
	count++;

	
	///初始化WSA
	WORD sockVersion = MAKEWORD(2,2);
	WSADATA data; 
	if(WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sclient == INVALID_SOCKET)
	{
		printf("invalid socket !");
		return 0;
	}
	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(520);
	char adder_IP[100];
	printf("请输入远程主机的IP地址!\n");
	scanf("%s",adder_IP);
	serAddr.sin_addr.S_un.S_addr = inet_addr(adder_IP);    ////将点分式的IP地址转化为网络序
	printf("************  ");
	printf("端口号：  %d",ntohs(serAddr.sin_port));
	printf("************  ");
	puts(adder_IP);
	// 将套接字sockClient与远程主机相连
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		printf("))))))))))))))))\**************");
		printf("connect error !");
		closesocket(sclient);
		return 0;
	}
	//do{
		/*
		char message[100];
		printf("请输入发送内容：\n");
		scanf("%s",message);
		// char * sendData = "你好，TCP服务端，我是客户端!\n  hello world\n";
		//printf("请输入将要发送的内容：\n");
		
		send(sclient, message, strlen(message), 0);  */
		printf("------------------发送端发送路由表---------------------------\n");
		send(sclient,(char *)&c[0],sizeof(RIP),0);
		Sleep(1000);
		send(sclient,(char *)&c[1],sizeof(RIP),0);
		Sleep(1000);
		send(sclient,(char *)&c[2],sizeof(RIP),0);
		Sleep(1000);



		printf("本机路由表：\n");
		printf("本机路由地址为 R6  \n");
		printf("-----------------------------------------\n");
		printf("目的网络\t\t距离\t\t下一跳\n");
		printf("-----------------------------------------\n");
		for(int i=0;i<count;i++)
		{
			printf("%s\t\t\t%d\t\t%s\n",c[i].aim,c[i].dis,c[i].jump);
		}
		printf("-----------------------------------------\n\n\n");
		char buffer[100]="\0";
	//	RIP recvRIP;
		recv(sclient,buffer,sizeof(buffer),0);
		memcpy(&d[count1],buffer,sizeof(buffer));
	//	printf("socket通信收到的路由表为：\n");
	//	printf("路由地址为  %s\n",d[count1].host_add);
	 //   printf("------------------------------------------\n");
	//	printf("目的网络\t\t距离\t\t下一跳\n");
	//	printf("%s\t\t\t%d\t\t%s\n",d[count1].aim,d[count1].dis,d[count1].jump);
	//	printf("%s   %s   %s   %s\n",recvRIP.aim,recvRIP.dis,recvRIP.jump,recvRIP.host_add);
	//	recvRIP.dis++;                  
	//	strcpy(recvRIP.jump,add_2);
		d[count1].dis++;                             ////对信收到的路由表进行预处理
		strcpy(d[count1].jump,d[count1].host_add);
		count1++;


		char buffer1[100]="\0";
		recv(sclient,buffer1,sizeof(buffer1),0);
		memcpy(&d[count1],buffer1,sizeof(buffer1));
		//printf("%s\t\t\t%d\t\t%s\n",d[count1].aim,d[count1].dis,d[count1].jump);
		d[count1].dis++;
		strcpy(d[count1].jump,d[count1].host_add);
		count1++;

		
		char buffer2[100]="\0";
		recv(sclient,buffer2,sizeof(buffer2),0);
		memcpy(&d[count1],buffer2,sizeof(buffer2));
		//printf("%s\t\t\t%d\t\t%s\n",d[count1].aim,d[count1].dis,d[count1].jump);
		d[count1].dis++;
		strcpy(d[count1].jump,d[count1].host_add);
		count1++;
		//printf("-----------------------------------------\n\n\n");


		printf("\n收到的路由表预处理后为：\n");
		printf("-----------------------------------------\n");
		printf("目的网络\t\t距离\t\t下一跳\n");
		printf("-----------------------------------------\n");
		for(int i=0;i<count1;i++)
		{
			printf("%s\t\t\t%d\t\t%s\n",d[i].aim,d[i].dis,d[i].jump);
		}
		printf("-----------------------------------------\n\n\n");
				
		for(int j=0;j<count1;j++)       ///遍历收到的路由表
		{
			int flage=0;
		   for(int i=0;i<count;i++)            ////遍历本机路由表
		   {
			   if(strcmp(c[i].aim,d[j].aim)==0)				///当本机路由表有网络N时，
			   {
			      flage=1;
				  if(strcmp(c[i].jump,d[j].jump)==0)            ////当下一跳是 X时，则替换原路由表的距离-----2
				  {
					  c[i].dis=d[j].dis;
				  }
				  else if(d[j].dis<c[i].dis)                 ///当收到项目中的距离d小于表中的距离时，更新.------3
				  {
					  c[i].dis=d[j].dis;
					  strcpy(c[i].jump,d[j].jump);
				  }
				  ///第4中情况，什么也不做--------------------------4
			   }
 			   else if(i==(count-1) && flage==0)       ////当遍历完所有本机路由表后，没有发现 网络N时，则添加到本机路由表----1
			   {
				   strcpy(c[count].aim,d[j].aim);
				   strcpy(c[count].host_add,add_2);
				   c[count].dis=d[j].dis;
				   strcpy(c[count].jump,d[j].jump);
	               count++;
				   break;     ///跳出当前循环
			   }
		   }
		}

		printf("更新后的本机路由表：\n");
		printf("本机路由地址为 R6  \n");
		printf("-----------------------------------------\n");
		printf("目的网络\t\t距离\t\t下一跳\n");
		printf("-----------------------------------------\n");
		for(int i=0;i<count;i++)
		{
			printf("%s\t\t\t%d\t\t%s\n",c[i].aim,c[i].dis,c[i].jump);
		}
		printf("-----------------------------------------\n\n\n");
		/*
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if(ret > 0)
		{
			recData[ret] = 0x00;
			printf("接收到服务器发送的数据为：\n");
			printf(recData);
			printf("\n");
		}
		 */
	//}while(1);

	closesocket(sclient);
	WSACleanup();
	getchar();
	return 0;
}



