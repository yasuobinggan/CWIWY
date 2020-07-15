#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct mgraph{
	int vexs[max];
	int arcs[max][max];
	int vexnum,arcnum;//���������� 
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
void dfs(int vex,int visit[],mgraph mg)//vex�ڵ��� 
{
	int i;
	visit[vex]=1;
	printf("%d\t",vex);
	for(i=0;i<mg.vexnum;i++)
	{
		if(!mg.vexs[vex][i])
			dfs(i,visit,mg);
	} 
} 
int main()
{
	mgraph mg;
	int visit[max],i;
	for(i=0;i<max;i++)
		visit[i]=0;
	createmg(mg);
	dfs(mg.vexs[0],visit,mg);//mg.vexs[0]�ӵ�һ���ڵ���� 
	return 0;
}