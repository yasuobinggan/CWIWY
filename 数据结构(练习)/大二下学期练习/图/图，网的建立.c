#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct mgraph{
	int vexs[max];
	int arcs[max][max];
	int vexnum,arcnum;
}mgraph;
void createmg(mgraph &mg)
{
	int i,j,k;
	printf("����ͼ�ĵ������,��������:\n");
	scanf("%d%d",&mg.vexnum,&mg.arcnum);
	printf("����������:\n");
	for(i=0;i<mg.vexnum;i++)//���� 
	{
		scanf("%d",&mg.vexs[i]);
	}
	
	for(i=0;i<mg.vexnum;i++)//��ʼ���ڽӾ��� 
	{
		for(j=0;j<mg.vexnum;j++)
		{
			mg.arcs[i][j]=0;
		}
	}
	
	printf("���뻡������:\n");//������������ 
	for(i=0;i<mg.arcnum;i++)
	{
		scanf("%d%d",&j,&k);
		mg.arcs[j][k]=1;
	}
} 
int main()
{
	mgraph mg;
	createmg(mg);
	return 0;
}