// socket.cpp : 定义控制台应用程序的入口点。
//客户端代码

#include "stdafx.h"
#include <iostream>  
#include <WINSOCK2.H>  
#include <cstring>  
#include <WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")  
using namespace std;

#define DES_IP "127.0.0.1"  
#define DES_PORT 5000  

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	char buf[1024]; //发送的字串  
	SOCKADDR_IN ser_addr;//服务器端地址
	WSADATA wsaData;       // 这结构是用于接收Wjndows Socket的结构信息的 
	struct in_addr s;
	WORD wVersionRequired;
	wVersionRequired = MAKEWORD(2, 2);         // 请求2.2版本的WinSock库
	if (WSAStartup(wVersionRequired, &wsaData) != 0)      // 返回值为零的时候是表示成功申请WSAStartup 
	{
		cout << WSAGetLastError() << endl;
		cout << "初始化失败！\n";
		//  return 1;  
	}

	//if (sock = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_IP,NULL,0,1))  
	// 创建套接字  
	// SOCKET socket(int af, int type, int protocol);  
    // 第一个参数，指定地址簇(TCP/IP只能是AF_INET，也可写成PF_INET)  
    // 第二个，选择套接字的类型(流式套接字)，第三个，特定地址家族相关协议（0为自动）  
	sock = socket(AF_INET, SOCK_STREAM, 0);
	//  if (sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)==INVALID_SOCKET)  
	//  {  
	//      cout << "创建套接字失败！\n\n";  
	//      return 1;  
	//      }  

	inet_pton(AF_INET, DES_IP, (void *)&s);
	ser_addr.sin_addr.S_un.S_addr = s.S_un.S_addr;		///本机任意IP地址
	//ser_addr.sin_addr.S_un.S_addr = inet_addr(DES_IP);
	ser_addr.sin_port = htons(DES_PORT);   // 将DES_PORT转换为网络字节序，调用 htonl(long型)或htons(整型)  
	ser_addr.sin_family = AF_INET;
	memset(ser_addr.sin_zero, 0, 8);
	//连接  
	if (connect(sock, (SOCKADDR *)&ser_addr, sizeof(SOCKADDR_IN)) != 0)
	{
		int nError = WSAGetLastError();
		cout << "连接服务器端失败\n";
		return 1;
	}
	else
	{
		cout << "成功连接服务器，可以开始发送数据，输入\"exit\"时断开连接\n\n";
	}
	//发送数据  
	do
	{
		int SentBytes;
		int RecvBytes;
		char strRecv[1024] = { 0 };
		cout << "发送：";
		cin >> buf;
		if (strcmp(buf, "exit") == 0) break;
		SentBytes = send(sock, buf, strlen(buf), 0);
		if (SentBytes == SOCKET_ERROR)   ///发送失败  
		{
			cout<< "发送数据失败！\n\n";
			break;
		}
		//      else //发送成功  
		//      {  
		//          cout << buf <<endl;  
		//      }  
		if ((RecvBytes = recv(sock, strRecv, sizeof(strRecv), 0)) != SOCKET_ERROR)
		{
			strRecv[RecvBytes] = 0;
			cout << "接收： " << strRecv << endl;
		}
		else
		{
			cout << WSAGetLastError() << endl;
			cout << "接收数据失败！\n";
		}
		Sleep(1000);
	} while (1);
	closesocket(sock);
	WSACleanup();

	getchar();
	return 0;
}



