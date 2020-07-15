#include<stdio.h>
#include<stdlib.h>
//int defth=1;
typedef struct btnode{
	int data;
	struct	btnode *lbt;
	struct 	btnode *rbt;
}btnode,*btree;
void createtree(btree &tree)
{
	int e;
	//printf("�����ַ�\n");
	scanf("%d",&e);
	if(e==0)tree=NULL;//return;
	else
	{
		tree=(btnode *)malloc(sizeof(btnode));
		tree->data=e; 
		createtree(tree->lbt);
		createtree(tree->rbt);
	}
}
/*
int travel(btree tree)
{
	int ldefth=0,rdefth=0;
	if(tree==NULL)return defth;
	if(tree->lbt)
		ldefth++;
	if(tree->rbt)
		rdefth++;
	if(ldefth>=rdefth)
		defth=defth+ldefth;	
	if(ldefth<rdefth)
		defth=defth+rdefth;
	return travel(tree);   
}
*/
void travel1(btree tree,int &defth)
{
	int ldefth=0,rdefth=0;
	if(tree==NULL)
	{
		return;
	}
	if(tree->lbt)
		ldefth++;
	if(tree->rbt)
		rdefth++;
	if(ldefth>rdefth)
	{
		defth=defth+ldefth;
		travel1(tree->lbt,defth);
	}
	if(ldefth==rdefth)
	{
		defth=defth+ldefth;
		travel1(tree->lbt,defth);
		travel1(tree->rbt,defth);
	}	
	if(ldefth<rdefth)
	{
		defth=defth+rdefth; 
		travel1(tree->rbt,defth);
	}  
}
void xxtrtree(btree tree)//������ȱ��������� 
{
	printf("�����ǰ����ַ�:\n");
	if(tree==NULL)return;
	printf("%d\n",tree->data); 
	if(tree->lbt!=NULL)
		xxtrtree(tree->lbt);
	if(tree->rbt!=NULL)
		xxtrtree(tree->rbt);
	
}
int main()
{
	btree tree;
	int defth=1;
	printf("���������:\n");
	createtree(tree);
	travel1(tree,defth);
	printf("��������������%d\n",defth);
	return 0;
}
/* 
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);//���������
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);//���������
	else
	j=0;
	return i>j i+1:j+1;
}
*/
