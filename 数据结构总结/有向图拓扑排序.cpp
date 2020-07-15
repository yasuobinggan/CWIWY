#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct mgraph {
	int vexs[max];
	int arcs[max][max];
	int vexnum, arcnum;//���������� 
}mgraph;

void createmg(mgraph &mg)
{
	int i, j, k;
	printf("����ͼ�ĵ������,��������:\n");
	scanf_s("%d%d", &mg.vexnum, &mg.arcnum);
	printf("����������:\n");
	for (i = 0; i<mg.vexnum; i++)//��һά�� 
	{
		scanf_s("%d", &mg.vexs[i]);
	}

	for (i = 0; i<mg.vexnum; i++)//��ʼ����ά�ڽӾ��� 
	{
		for (j = 0; j<mg.vexnum; j++)
		{
			mg.arcs[i][j] = 100;
		}
	}

	printf("���뻡������ͻ���Ȩֵ:\n");//������������ 
	for (i = 0; i<mg.arcnum; i++)
	{
		scanf_s("%d%d", &j, &k);
		scanf_s("%d", &mg.arcs[j][k]);
	}
}
int T(int w, int select[], int n)
{
	int i = 0;
	while (i < n)
	{
		if (w != select[i])
			i++;
		else
			break;
	}
	if (i == n)return 1;//���������ﷵ����ֵ
	else return 0;//�������ﷵ��0

}
int indegree_0(mgraph &mg,int select[],int n)
{
	int i, j, k;
	int count;
	for (i = 0; i < mg.vexnum; i++) 
	{
		count = 0;
		if(T(i,select,n))
		{ 
			for (j=0;j<mg.vexnum;j++)
			{
				if(mg.arcs[i][j]==100)
					count++;
			}
			if (count == mg.vexnum)
			{
				printf("%d\t", mg.vexs[i]);//i�޸�mg.vexs[i]
				select[n] = i;
				for (k = 0; k < mg.vexnum; k++)
				{
					mg.arcs[k][i] = 100;
				}
				return i;
			}
		}
	}
	if (i == mg.vexnum)
		return -1;
}
void  Topolo_Sort(mgraph &mg)
{
	int select[max], n=0;//n�����Ϊ�ж����������Ƿ����
	//int count=0;//�ж�����ͼ���Ƿ���ڻ�
	int point;//���ܷ���ֵ
	while (n < mg.vexnum)
	{
		point=indegree_0(mg, select, n);
		n++;
		if (point == -1 && n < mg.vexnum)
		{
			printf("�����������!����ͼ�д��ڻ�\n");
			break;
		}
	}
}
int main()
{
	mgraph mg;
	printf("��������ͼ---\n");
	createmg(mg);
	printf("�������ͼ����������:\n");
	Topolo_Sort(mg);
	return 0;
}