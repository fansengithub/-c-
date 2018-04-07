// My_Serive.cpp : 定义控制台应用程序的入口点。
//服务器代码实现

#include "stdafx.h"
#include<iostream>
#include<WINSOCK2.H>
#include<WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")    //表示链接到WS2_32.lib中
using namespace std;

#define SER_PORT 5000    ///服务器端端口地址
#define SER_IP  "127.0.0.1"     ///服务器端IP地址

DWORD WINAPI ThreadProcessor(LPVOID lpParameter); //接收数据的线程函数  
fd_set fdRead = { 0 };
int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sever;              ///套接字
	SOCKET client;
	char buf[1024];
	///地址信息
	SOCKADDR_IN ser_addr;
	SOCKADDR_IN cli_addr;

	struct in_addr s;
	char IP_s[20];

	int ret;      ///用于保存函数的返回值
	WORD wVersionRequested;
	WSADATA wsaData;				//该结构是用于接收Windows Socket 的结构信息的
	int cliAddrLen;
	wVersionRequested=MAKEWORD(2,2);             ///// 请求2.2版本的WinSock库 
	if(WSAStartup(wVersionRequested,&wsaData) !=0)       // 返回值为零的时候是表示成功申请WSAStartup
	{
	   cout<<"初始化失败！\n";
		   return 1;
	}
	ser_addr.sin_family=AF_INET;
	inet_pton(AF_INET,SER_IP,(void *)&s);
	ser_addr.sin_addr.S_un.S_addr=s.S_un.S_addr;
	ser_addr.sin_port=htons(SER_PORT);      //将“点分十进制” －> “二进制整数”     第一个参数af是地址簇，第二个参数*src是来源地址，第三个参数* dst接收转换后的数据。
	memset(ser_addr.sin_zero,0,8);
	///创建套接字
	sever=socket(AF_INET,SOCK_STREAM,0);
	if(sever==INVALID_SOCKET)
	{
	  cout<<"创建套接字失败！请重新运行!\n";
	  return 1;
	}
	///绑定
	if(bind(sever,(SOCKADDR *)&ser_addr,sizeof(SOCKADDR))!=0)
	{
	  cout<<"绑定失败，请重新连接!";
	  return 1;
	}
	else
	{
	   cout<<"服务器端已启动成功！请使用：";

	}
	///服务器不断的循环，以搜索客户端的连接
	while(1)
	{
	  ///服务器端做好准备
		if(int i=listen(sever,6)!=0)
		{
		  cout<<"listen()连接失败！\n";
		 return 1;
		}
		cliAddrLen=sizeof(SOCKADDR);     //客户端的地址长度
		/// 返回客户端套接字，  cli_addr 为客户端的地址及端口信息
		if ((client = accept(sever, (SOCKADDR *)&cli_addr, &cliAddrLen)) == INVALID_SOCKET)
		{
			cout << "客户端已经断开连接！\n\n";
			break;
		}
		inet_ntop(AF_INET,(void *)&cli_addr.sin_addr,IP_s,16);
		cout<<IP_s<<endl;
		cout<<"*****************************\n";
		cout<<"Client IP:  "<<IP_s<<endl;
		cout<<"\n Client Port:  "<<ntohs(cli_addr.sin_port)<<endl;
		cout<<"*****************************\n";
		//FD_ZERO(&fdRead);
		//FD_SET(client,&fdRead);

		bool bAvail=true;
		///接收数据
		while(bAvail)
		{
		 //  FD_SET(client,&fdRead);       //将client加入到读取集合中 
		//   timeval t={0};         ///当缓冲区里有可读数据才返回，不然阻断程序  
		  // t.tv_usec=1000*500;
		   char sendBuf[1024];
					int RecvBytes = 0;
					do   //循环读取数据，直到缓冲区中的数据读完  
					{
						//接收数据  
						RecvBytes = recv(client, buf, sizeof(buf), 0);
						if (RecvBytes == SOCKET_ERROR || RecvBytes == 0)    ///RecvBytes 代表接收数据的长度
						{
							cout << "数据接收失败或客户端已经断开！\n";
							bAvail = false;
							break;
						}
						buf[RecvBytes] = 0; //给数据串加上结束符  
						//打印收到数据  
						cout << "收到" << RecvBytes << " bytes 数据:  "
							<< buf << endl;
						cout << "发送： ";
						cin.getline(sendBuf, 1024);
						///向客户端发送数据  
						if (send(client, sendBuf, strlen(sendBuf), 0) == -1)
							return -1;
					} while (RecvBytes>0);
			
			//FD_ZERO(&fdRead);
		}
		closesocket(client);
	}


	cout << "end\n";
	//Sleep(5000);

	//FD_CLR(client, &fdRead);
	closesocket(sever);
	WSACleanup();
     getchar();
	return 0;
}

