// RSA.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
/////�������ܣ��ж�  f  d �Ƿ���
int exgcd( int f,int d,int *result)
{
	int x1,x2,x3,y1,y2,y3,t1,t2,t3,q;
	x1 = y2 = 1;
	x2 = y1 = 0;
	x3 = ( f>=d )?f:d;
	y3 = ( f>=d )?d:f;
	while( 1 )
	{
		if ( y3 == 0 )
		{
			//*result = x3;
			return 0;
		}
		if ( y3 == 1 )
		{
		//	*result = y2;
			return 1;
		}
		q = x3/y3;
		t1 = x1 - q*y1;
		t2 = x2 - q*y2;
		t3 = x3 - q*y3;
		x1 = y1;
		x2 = y2;
		x3 = y3;
		y1 = t1;
		y2 = t2;
		y3 = t3;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int p,q,r,d,e,t,m;
	printf("�������������� p,q: ");
	scanf("%d%d",&p,&q);
	if(exgcd(p,q,&r))
	{
		printf("%d��%d���ء�",p,q);
	}
	else
	{
		printf("%d��%d������.\n",p,q);
	}
	t=(p-1)*(q-1);			////t����    f(n)
	printf("�����tΪ%d\n",t);
	printf("�����빫Կe: ");
	scanf("%d",&e);
	if(e<1||e>t)
	{
		printf("e ����Ҫ������������: ");
		scanf("%d",&e);
	}
	if(exgcd(e,t,&r))
		printf("%d��%d���ء�\n",e,t);
	else
	{
		printf("%d��%d�����ء�\n",e,t);
		printf("e ����Ҫ������������: ");
		scanf("%d",&e);
	}
	d=1;
	while(((e*d)%t)!=1)
		d++;         //
	printf("������˽ԿdΪ%d\n",d);
	return 0;
}

