#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int k=0;//��¼��һ�е����һ���б� 
	int a[10][10];
/*	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			a[i][j]=0;
		}
	}
*/	
	
	a[0][0]=1;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j-1<0)
				a[i][j]=a[i-1][j]+0;
			else if(j>k)
				a[i][j]=a[i-1][j-1]+0;
			else//�����±�Խ�� 
		 		a[i][j]=a[i-1][j]+a[i-1][j-1]; 
		}
		k=i;
	}
	
	//���������� 
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
} 