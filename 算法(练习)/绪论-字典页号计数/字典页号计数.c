#include<stdio.h>
#include<stdlib.h>
//ͬ�����ѭ����j���ڲ�ѭ����w 
int jie10(int i)
{
	if(i==0)
	return 1;
	if(i>0)
	return 10*jie10(i-1); 
}
int jie(int n,int i)
{
	if(i==0)
	return 1;
	if(i>0)
	return n*jie(n,i-1);
}

int main()
{
	int v,n,i=0,j,w,count=0,a[10],b[10]={0,0,0,0,0,0,0,0,0,0};
	printf("���������ҳ��:\n");
	scanf("%d",&v);
	while(v)
	{
		n=v%10; 
		v=v/10;
		a[i]=n;
		i++;
	}
	printf("%d\n",i);
	for(j=0;j<i;j++)
	{
		if(j==1)
		b[9]+=j*a[j];
		for(w=0;w<a[j];w++)
		{
			b[w]++;
			if(j==1)
			b[w]+=a[j-1];
		}
	}
 /*	for(j=0;j<i-1;j++)
	{ 
		b[a[i-1]-1]+=a[j];
	}//��ȫҳ�����λ�ļ��� 
*/		
/*	for(j=0;j<10;j++)
	{
		if(a[i-1]==j-1)
		for(w=0;w<j;w++)
		{
			b[w]++;
		}
	}//��ȫ���һλ�ļ��� 
*/	
	for(j=i-1;j>0;j--) 
	{
		for(w=0;w<10;w++)
		{
			b[w]+=(a[i-1])*jie10(i-2);
			b[w]+=jie(i-1,a[i-1]-1);
		}
	}
	//�����λ��ʼ���鲹ȫ
/*	for(j=0;j<9;j++)
	{
		for(w=1;w<=i-1;w++)
		{
			b[j]+=((a[w-1])*jie9(w-1));
		}
	}
*/
	//ÿ��λ�����λ��ȫ	
	printf("���������ʹ��Ƶ��:\n");
	for(j=0;j<10;j++)
	printf("%d\t%d\n",(j+1)%10,b[j]);
	return 0;
} 