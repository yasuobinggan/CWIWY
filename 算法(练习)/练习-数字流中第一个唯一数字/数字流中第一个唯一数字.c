#include<stdio.h>
#define max 100
void createarray(int a[max],int n)
{
	int i;
	printf("����%d������:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
int first_only(int a[max],int n,int end)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=end)
		{
			if(a[i]==flag)//
				flag=0;//0��Ϊ�������в�����ڵ�����,���ӽ�׳�Կ������ýṹ�� 
			else if(flag==0)//
				flag=a[i];//	
		}
		else
		{
			if(flag==0)
				return end;
			return flag;		
		}
		/*
		*/
	}
	if(a[n-1]!=end)
		return -1;
}
int main()
{
	int a[max],n,end;
	printf("�����������ĳ���:\n");
	scanf("%d",&n);
	createarray(a,n);
	printf("������ֹ����:\n");
	scanf("%d",&end);
	printf("����������е�һ��Ψһ������:%d\n",first_only(a,n,end));
	return 0;
}