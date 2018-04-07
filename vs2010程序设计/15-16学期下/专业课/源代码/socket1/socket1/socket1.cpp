// socket1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
////////////////服务器端代码 sever.cpp  
///一、初始化套接字  
///二、创建套接字  
///三、绑定  
///四、侦听  
///五、接收  
///六、发送  
///七、销毁连接  
////////////////////////////////////////////////////  

#include <iostream>  
#include <WINSOCK2.H> 
#include <WS2tcpip.h>
//#include <cstdlib>  
#pragma comment(lib,"WS2_32.lib")    //表示链接到WS2_32.lib中+
using namespace std;

#define SER_PORT 5000    //服务器端端口地址
#define SER_IP "127.0.0.1"    //服务器端IP地址

DWORD WINAPI ThreadProcessor(LPVOID lpParameter); //接收数据的线程函数  
fd_set fdRead = { 0 };



int _tmain(int argc, _TCHAR* argv[])
{
	 //定义套接字  
	SOCKET sever;    
	SOCKET client;
	char buf[1024];
	//地址信息
	SOCKADDR_IN ser_addr;   
	SOCKADDR_IN cli_addr;   
	    
	struct in_addr s;
	char IP_s[20];

	int ret;   //用于保存函数返回值  
	WORD wVersionRequested;
	WSADATA wsaData;
	int cliAddrLen;
	//#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
	wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)
	{
		cout << "初始化失败！\n";
		return 1;
	}
	ser_addr.sin_family = AF_INET;       //#define AF_INET         2               // internetwork: UDP, TCP, etc.
	inet_pton(AF_INET, SER_IP, (void *)&s);
	ser_addr.sin_addr.S_un.S_addr = s.S_un.S_addr;
	//ser_addr.sin_addr.S_un.S_addr = inet_addr(SER_IP);
	ser_addr.sin_port = htons(SER_PORT);
	memset(ser_addr.sin_zero, 0, 8); //CHAR sin_zero[8]是SOCKADDR_IN的一个成员变量
	///创建套接字  
	sever = socket(AF_INET, SOCK_STREAM, 0);//构造函数
	if (sever == INVALID_SOCKET)
	{
		cout << "创建套接字失败！\n";
		return 1;
	}
	//绑定  
	if (bind(sever, (SOCKADDR *)&ser_addr, sizeof(SOCKADDR)) != 0)
	{
		cout << "绑定失败！\n";
		return 1;
	}
	else
	{
		cout << "服务器端已成功启动......\n\n";
	}

	while (1)   //服务器端继续搜索新的连接  
	{
		//侦听  
		if (int i = listen(sever, 6) != 0)
		{
			cout << "侦听失败: " << WSAGetLastError() << endl;
			return 1;
		}
		cliAddrLen = sizeof(SOCKADDR);//客户端地址长度
		//返回客户端套接字   cli_addr 为客户端的地址及端口信息  
		if ((client = accept(sever, (SOCKADDR *)&cli_addr, &cliAddrLen)) == INVALID_SOCKET)
		{
			cout << "客户端已经断开连接！\n\n";
			break;
		}
		inet_ntop(AF_INET, (void *)&cli_addr.sin_addr, IP_s, 16);
		cout << IP_s << endl;
		cout << "Client Ip: " << IP_s << endl;
		cout << "Client Port: " << ntohs(cli_addr.sin_port) << endl;

		//      ULONG ul=1;  
		///阻塞控制，用了selec选择就不需要用此函数了  
		//      if (ret=ioctlsocket(client,FIONBIO,&ul) == SOCKET_ERROR)  
		//      {  
		//          cout << "Call ioctlsocket function fail !\n";  
		//          return 1;  
		//      }  

		FD_ZERO(&fdRead);  //清空集合  
		FD_SET(client, &fdRead); //将client加入到读取集合中  

		bool bAvail = true;
		///接收数据  
		while (bAvail)
		{
			FD_SET(client, &fdRead); //将client加入到读取集合中  

			///缓冲区里有可读数据才返回，不然阻断程序  
			timeval t = { 0 };
			t.tv_usec = 10000 * 500;
			char sendBuf[1024];
			if ((ret = select(0, &fdRead, NULL, NULL, &t)) <= 0)  //阻塞控制  
			{
				continue;
			}
			if (ret>0)
			{
				if (FD_ISSET(client, &fdRead))  //client in fdRead  
				{
					int RecvBytes = 0;
					do   //循环读取数据，直到缓冲区中的数据读完  
					{
						//接收数据  
						RecvBytes = recv(client, buf, sizeof(buf), 0);
						if (RecvBytes == SOCKET_ERROR || RecvBytes == 0)
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
					//	Sleep(2 * 1000);
					} while (RecvBytes>0);
				}
			}
			FD_ZERO(&fdRead);
		}//while  
		closesocket(client);
	}//while  

	cout << "end\n";
	Sleep(5000);

	FD_CLR(client, &fdRead);
	closesocket(sever);
	WSACleanup();

	getchar();
	//return 0;
	return 0;
}
