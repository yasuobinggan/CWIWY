#include<stdio.h>
#define max 100
void createarray(int a[],int n)
{
	int i;
	printf("����%d������:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
int char_max(int a[],int n)
{
	int i;
	int c_max=a[0];	
	for(i=1;i<=n-1;i++)
	{
		if(a[i]<=1||c_max<=1)
			c_max+=a[i];
		else
			c_max*=a[i];
	}
	return c_max;
}
int main()
{
	int a[max],n;
	printf("�����ַ������ֵĳ���:\n");
	scanf("%d",&n);
	createarray(a,n);
	printf("����ַ������ֵ����ֵ:%d\n",char_max(a,n));
	return 0;
}