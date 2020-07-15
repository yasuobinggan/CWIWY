#include<stdio.h>
#include<stdlib.h>
int count=0,i=0;
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
void maxdef(btree tree,int c[16])
{
	if(!tree)
	{
		c[i]=count;
		i++;count--; 
		return;
	}
	count++;
	maxdef(tree->lbt,c);
	maxdef(tree->rbt,c);
}

void xxtrtree(btree tree)//������ȱ��������� 
{
	//printf("�����ǰ����ַ�:\n");
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
	int c[16],j;
	printf("���������:\n");
	createtree(tree);
	maxdef(tree,c);
	for(j=0;j<i;j++)
	{
		printf("%d\t",c[j]);
	}
	return 0;
 } 

