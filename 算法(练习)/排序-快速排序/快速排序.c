#include<stdio.h>
#define max 100
void createarray(int a[],int n)
{
	int i;
	printf("����%d������:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void quick_sort1(int a[],int &key_n,int start,int end)//���������е�һ������//������Ǵ���һ�������в������������������ 
{
	int i,j;
	int key,temp;
	//int key,key_n,temp;
	int flag=0;
	key=a[start];
	key_n=start;
	i=start;j=end;
	while(i<j)
	{
		if(flag==0)
		{
			if(a[j]<key)
			{
				temp=a[j];
				a[j]=a[key_n];
				a[key_n]=temp;
				key_n=j;
				flag=1;
			}
			else
				j--;
		}
		if(flag==1)
		{
			if(a[i]>key)
			{
				temp=a[i];
				a[i]=a[key_n];
				a[key_n]=temp;
				key_n=i; 
				flag=0;
			}
			else
				i++;
		}		
	} 
}
void quick_sort(int a[],int key_n,int start,int end)
{
	if(start<end)
	{
		quick_sort1(a,key_n,start,end);
		quick_sort(a,key_n,start,key_n-1);
		quick_sort(a,key_n,key_n+1,end);	
	}
} 
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int n,a[max];
	printf("��������ĳ���:\n");
	scanf("%d",&n);
	createarray(a,n);
	//quick_sort1(a,0,n-1);//��֤һ���������ȷ�� 
	quick_sort(a,0,0,n-1);//��ʼ����,��������
	printarray(a,n); 
	return 0;
}
// 