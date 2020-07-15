#include<stdio.h>
#include<stdlib.h>
#define tasize 10
int n,count=0;
typedef struct{
	int *base;
	int *top;	
}ta;
void createta(ta &t)
{
	t.base=(int *)malloc(tasize*sizeof(int));
	t.top=t.base; 
}
void createinta(ta &t,int n)
{
	if(n=0)return;
	if(n>0)
	{
		*t.top++=n;
		return createinta(t,n-1);
	}	
} 
void move(ta &a,ta &b,int e)
{
	if(a.top==a.base)
	return;
	e=*--a.top;
	*b.top++=e;
	if(*b.top>*(b.top-1)&&b.top-b.base>tasize)
	{
		printf("�ƶ�����!");
		return;
	}
} 
void hannoi(int n,ta &a,ta &b,ta &c)
{
	int e;
	if(c.top-c.base==n)
	{
		printf("%d\t%d\t",c.top-c.base,n);
		printf("���ƶ���%d��\n",count);
		return;
	}//?
 
/*
	if(n==1)
	{
		move(a,c,e);
	}
*/	 
	hannoi(n-1,a,c,b);
	move(a,c,e);count++;
 	hannoi(n-1,b,a,c);
 	//hannoi(n-1,b,c,a);
	//ÿһ��ִ����ͬ���� 
} 
int main()
{
	ta a,b,c;
	int w;
	printf("���뺺ŵ���Ĳ���:\n");
	scanf("%d",&n);
	w=n;
	printf("%d\n",w);
	createta(a);
	createinta(a,n);
	createta(b);
	createta(c);
	hannoi(w,a,b,c); 
	return 0;
}
