
/*
#include<stdio.h>
int main()
{
	
	int a[3]={1,2,3};
	int * point;
	point=a;
	printf("%d\n",a);
	printf("%d",&a);
	printf("********");
	printf("%d",point);
	printf("********");
	printf("%d",&point);
	/*int a;
	printf("«Î ‰»Îa\n");
	scanf("%d",&a);
	printf("hello,vs2010---%d\n",a);
	printf("---------");
	getchar();   
	int i=0;
	for( i=0;i<100;i++)
	{
	  printf("%d\n",i);
	}
	system("pause");
	
  return 0;
}
*/



#include<iostream>
using namespace std;
int main()
{
	float w=0;
	float x,y;
	int l;
	int r;
	cin>>l>>r;
	w=(float)180*l/r;
	x=r*cos(w);
	y=r*sin(w);
    return 0;
}