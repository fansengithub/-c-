// My_client.cpp : 定义控制台应用程序的入口点。
//实现客户端

#include "stdafx.h"
#include<iostream>
#include<WINSOCK2.H>
#include<cstring>
#include<WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")
using namespace std;

#define DES_IP "127.0.0.1"
#define DES_PORT 5000


int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	char buf[1024];     ///发送的字符串
	char Ser_IP[100];
	char Ser_PORT[50];
	cout<<"输入服务器的IP地址\n";
	cin>>Ser_IP;
	cout<<"输入服务器的端口号\n";
	cin>>Ser_PORT;
	getchar();
	SOCKADDR_IN ser_addr;   ///服务器端地址
	WSADATA wsaData;		///该结构是用于接收Windows Socket 的结构信息的
	struct in_addr s;
	WORD wVersionRequired;   // 加载socket动态链接库(dll)
	wVersionRequired=MAKEWORD(2,2);     // 请求2.2版本的WinSock库
	if(WSAStartup(wVersionRequired, &wsaData)!=0)     // 返回值为零的时候是表示成功申请WSAStartup
	{
	   cout<<WSAGetLastError()<<endl;
	   cout<<"初始化失败!\n";
	}
	///创建套接字
	sock=socket(AF_INET,SOCK_STREAM,0);

	inet_pton(AF_INET,DES_IP,(void *)&s);   //IP地址转换函数，可以在将IP地址在“点分十进制”和“二进制整数”之间转换
	ser_addr.sin_addr.S_un.S_addr=s.S_un.S_addr;    //本机任意IP地址
	ser_addr.sin_port=htons(DES_PORT);   // 将DES_PORT转换为网络字节序，调用 htonl(long型)或htons(整型)  
	ser_addr.sin_family=AF_INET;
	memset(ser_addr.sin_zero,0,8);
	//连接函数
	if(connect(sock,(SOCKADDR *)&ser_addr,sizeof(SOCKADDR_IN))!=0)
	{
	    int nError=WSAGetLastError();
		cout<<"连接服务器端失败!\n";
		return 1;
	}
	else
	{
		cout<<"***************************************************************\n\n";
	  cout<<"连接服务器成功，可以发送数据，输入“Q”时断开服务器与客户机的连接！\n\n";
	  cout<<"***************************************************************\n\n";
	}
	while(1)
	{

	  int SentBytes;
	  int RecvBytes;
	 
	  char strRecv[1024]={0};
	  cout<<"输入将要发送的数据：\n";
	  cin>>buf;
	  if(strcmp(buf,"Q")==0)  break;
	  SentBytes=send(sock,buf,strlen(buf),0);
	  if(SentBytes==SOCKET_ERROR)
	  {
	     cout<<"发送失败！请重新建立连接，再次尝试！\n\n";
         break;
	  }
	  if((RecvBytes = recv(sock, strRecv, sizeof(strRecv), 0)) != SOCKET_ERROR)
		{
			strRecv[RecvBytes] = 0;
			cout << "接收： " << strRecv << endl;
		}
	  else
	  {
	    cout<<WSAGetLastError()<<endl;
		cout<<"接收数据失败，请重新建立连接，再次尝试！\n";

		break;
		Sleep(1000);
	  }
	}
	closesocket(sock);     ///关闭套接字，结束TCP对话！
	WSACleanup();
	getchar();
	return 0;
}

