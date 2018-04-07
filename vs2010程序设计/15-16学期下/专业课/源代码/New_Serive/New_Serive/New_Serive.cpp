// New_Serive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>
#include<string.h>
#define N 10
#pragma comment(lib,"ws2_32.lib")

///创建RIP 结构体
typedef struct RIP{
	char  aim[N];       ////目的网络---
	int   dis;            //距离
	char jump[N];      //下一跳
	char  host_add[N];          ///存放本地路由地址
	// RIP * next;   ///形成链表结构
}RIP;
int main(int argc, char* argv[])
{

	//本机路由表初始化
	int count_s=0;      ///用于记录--链表节点个数
	char address[N]="R4";     ///存放本地路由地址

	RIP s[N];
	RIP  t[N];      ///用于接受socket发过来的结构体
	int count1=0;        ///  标记socket发过来结构体数组下标
	strcpy(s[0].aim,"Net1");
	s[0].dis=3;
	//strcpy(s[0].dis,"6");
	strcpy(s[0].host_add,address);
	strcpy(s[0].jump,"R1");
	count_s++;

	strcpy(s[1].aim,"Net2");
	strcpy(s[1].host_add,address);
	s[1].dis=4;
	//strcpy(s[1].dis,"3");
	//L->dis=3;
	strcpy(s[1].jump,"R2");
	count_s++;

	strcpy(s[2].aim,"Net3");
	s[2].dis=1;
	//strcpy(s[2].dis,"55");
	strcpy(s[2].jump,"R7");
	strcpy(s[2].host_add,address);
	count_s++;



	/*
	RIP * L=(RIP *)malloc(sizeof(RIP));       ////第一个节点
	count++;
	strcpy(L->aim,"net1");
	strcpy(L->host_add,address);
	strcpy(L->dis,"3");
	//L->dis=3;
	strcpy(L->jump,"a");
	L->next=NULL;

	RIP * p=(RIP *)malloc(sizeof(RIP));
	count++;
	strcpy(p->aim,"net2");
	strcpy(p->host_add,address);
	strcpy(p->dis,"4");
	//p->dis=2;
	strcpy(p->jump,"b");
	p->next=NULL;

	RIP * q;
	q=L; 
	while(q->next!=NULL)            ///照到链表的最后一个节点
	{
	q=q->next;
	}
	q->next=p;


	p=(RIP *)malloc(sizeof(RIP));
	count++;
	strcpy(p->aim,"net3");
	strcpy(p->host_add,address);
	strcpy(p->dis,"2");
	//p->dis=2;
	strcpy(p->jump,"c");
	p->next=NULL;

	q=L; 
	while(q->next!=NULL)            ///照到链表的最后一个节点
	{
	q=q->next;
	}
	q->next=p;

	*/
	//初始化WSA,设置socket版本 为（2，2）
	WORD sockVersion = MAKEWORD(2,2);
	WSADATA  wsaData;
	if(WSAStartup(sockVersion, &wsaData)!=0)
	{
		return 0;
	}

	//创建套接字
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  //系统函数socket 参数分别是TCP类型IPV4，流失套接字 第一个参数，指定地址簇(TCP/IP只能是AF_INET，也可写成PF_INET)  
	// 第二个，选择套接字的类型(流式套接字)，第三个，特定地址家族相关协议（0为自动）
	if(slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	//绑定IP和端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(520);

	//sin.sin_addr.S_un.S_addr = INADDR_ANY; 
	sin.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	printf("----------------------\n");
	//puts(inet_ntoa(S_asin_addr));
	//ipAddr.S_un.S_addr = inet_addr("127.0.0.1");
	// 套接字sockSrv与本地地址相连 
	if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}

	// 将套接字设置为监听模式（连接请求）， listen()通知TCP服务器准备好接收连接  
	//开始监听
	if(listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	//循环接收数据
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255]; 
	int flage=1;
	while (flage==1)
	{
		// accept()，接收连接，等待客户端连接  
		printf("等待连接...\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

		printf("接受到一个连接发出请求的IP地址为：%s \t\t", inet_ntoa(remoteAddr.sin_addr));
		if(strcmp(inet_ntoa(remoteAddr.sin_addr),"127.0.0.1")!=0)
		{
			printf("IP地址输入错误，请重新连接！\n");
			//return 0;
		}
		printf("发出的端口地址为：%d   \n", ntohs(sin.sin_port));
		if(sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}

		//while(true)
		//{
			///****************************************************
			//RIP * L;
			//	RIP *q;
			/*
			printf("本地路由地址为：    %s\n",L->host_add);
			printf("本路路由表为：\n");
			printf("目的网络		距离		下一跳\n");
			q=L;
			while(q!=NULL)
			{
			printf("%s        \t\t%s \t\t%s\n",q->aim,q->dis,q->jump);
			q=q->next;
			}   */
			//接收数据
			// recv(), 在套接字上接收数据

			/*
			int ret = recv(sClient, revData, 255, 0);        
			if(ret > 0)
			{
			revData[ret] = 0x00;
			printf("接收到客户端发送的数据为：\n");
			printf(revData);
			printf("\n");
			}   */

			printf("本机路由表：\n");
			printf("本机路由地址为 R4  \n");
			printf("-----------------------------------------\n");
			printf("目的网络\t\t距离\t\t下一跳\n");
			printf("-----------------------------------------\n");
			for(int i=0;i<count_s;i++)
			{
				printf("%s\t\t\t%d\t\t%s\n",s[i].aim,s[i].dis,s[i].jump);
			}
			printf("-----------------------------------------\n\n\n");
			char buffer[100]="\0";
			//	RIP recvRIP;
			recv(sClient,buffer,sizeof(buffer),0);
			memcpy(&t[count1],buffer,sizeof(buffer));
			//printf("socket通信收到的路由表为：\n");
			//printf("路由地址为  %s\n",t[count1].host_add);
			//printf("------------------------------------------\n");
			//printf("目的网络\t\t距离\t\t下一跳\n");
			//printf("%s\t\t\t%d\t\t%s\n",t[count1].aim,t[count1].dis,t[count1].jump);
			//	printf("%s   %s   %s   %s\n",recvRIP.aim,recvRIP.dis,recvRIP.jump,recvRIP.host_add);
			//	recvRIP.dis++;                  
			//	strcpy(recvRIP.jump,add_2);
			t[count1].dis++;                             ////对信收到的路由表进行预处理
			strcpy(t[count1].jump,t[count1].host_add);
			count1++;


			char buffer1[100]="\0";
			recv(sClient,buffer1,sizeof(buffer1),0);
			memcpy(&t[count1],buffer1,sizeof(buffer1));
			//printf("%s\t\t\t%d\t\t%s\n",t[count1].aim,t[count1].dis,t[count1].jump);
			t[count1].dis++;
			strcpy(t[count1].jump,t[count1].host_add);
			count1++;


			char buffer2[100]="\0";
			recv(sClient,buffer2,sizeof(buffer2),0);
			memcpy(&t[count1],buffer2,sizeof(buffer2));
			//printf("%s\t\t\t%d\t\t%s\n",t[count1].aim,t[count1].dis,t[count1].jump);
			t[count1].dis++;
			strcpy(t[count1].jump,t[count1].host_add);
			count1++;
			//printf("-----------------------------------------\n\n\n");


			printf("\n收到的路由表预处理后为：\n");
			printf("-----------------------------------------\n");
			printf("目的网络\t\t距离\t\t下一跳\n");
			printf("-----------------------------------------\n");
			for(int i=0;i<count1;i++)
			{
				printf("%s\t\t\t%d\t\t%s\n",t[i].aim,t[i].dis,t[i].jump);
			}
			printf("-----------------------------------------\n\n\n");

			for(int j=0;j<count1;j++)       ///遍历收到的路由表
			{
				int flage=0;
				for(int i=0;i<count_s;i++)            ////遍历本机路由表
				{
					if(strcmp(s[i].aim,t[j].aim)==0)				///当本机路由表有网络N时，
					{
						flage=1;
						if(strcmp(s[i].jump,t[j].jump)==0)            ////当下一跳是 X时，则替换原路由表的距离
						{
							s[i].dis=t[j].dis;
						}
						else if(t[j].dis<s[i].dis)                 ///当收到项目中的距离d小于表中的距离时，更新.
						{
							s[i].dis=t[j].dis;
							strcpy(s[i].jump,t[j].jump);
						}
					}
					else if(i==(count_s-1) && flage==0)       ////当遍历完所有本机路由表后，没有发现 网络N时，则添加到本机路由表
					{
						strcpy(s[count_s].aim,t[j].aim);
						strcpy(s[count_s].host_add,address);
						s[count_s].dis=t[j].dis;
						strcpy(s[count_s].jump,t[j].jump);
						count_s++;
						break;     ///跳出当前循环
					}
				}
			}

			printf("更新后的本机路由表：\n");
			printf("本机路由地址为 R4  \n");
			printf("-----------------------------------------\n");
			printf("目的网络\t\t距离\t\t下一跳\n");
			printf("-----------------------------------------\n");
			for(int i=0;i<count_s;i++)
			{
				printf("%s\t\t\t%d\t\t%s\n",s[i].aim,s[i].dis,s[i].jump);
			}
			printf("-----------------------------------------\n\n\n");


			printf("**********************************");

			// send(), 在套接字上发送数据  
			//发送数据

			/*
			RIP L;
			memcpy(L.aim,"net1",sizeof("net1"));
			memcpy(L.dis,"4",sizeof("4"));
			memcpy(L.jump,"a",sizeof("a"));
			memcpy(L.host_add,"w",sizeof("w"));
			L.next=NULL;  */
			//memcpy(L.next,"",sizeof(""));   
			//	printf("%s   %s   %s   %s",L.aim,L.dis,L.jump,L.host_add);  

			// char * sendData = "你好，TCP客户端！\n";
			//printf("发送结构体！！\n");
			printf("----------------本机发送路由表-----------------\n");
			send(sClient,(char *)&s[0],sizeof(RIP),0);
			Sleep(1000);
			send(sClient,(char *)&s[1],sizeof(RIP),0);
			Sleep(1000);
			send(sClient,(char *)&s[2],sizeof(RIP),0);
			Sleep(1000);
			/*char message[100];
			printf("请输入将要发送的数据：\n");
			scanf("%s",message);
			send(sClient, message, strlen(message), 0);  */
		//}
	}

	closesocket(sClient);
	closesocket(slisten);
	WSACleanup();
	return 0;
}



