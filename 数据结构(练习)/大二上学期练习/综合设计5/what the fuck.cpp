#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
typedef struct bithnode{
	int data;
	bithnode *lchild,*rchild;
}bithnode,*bithtree;
bithtree treeroot;
void creatroot()
{
	int v;
	treeroot=(bithtree)malloc(sizeof(bithnode));
	printf("������ڵ�ֵ:\n");
	scanf("%d",&v);
	treeroot->data=v; 
} 
void creattree(bithtree &t,int &c)
{
	
	t=(bithtree)malloc(sizeof(bithnode));
	t->data=treeroot->data;
	t->lchild=t->rchild=NULL;
	if(c<t->data)
	{
    	treeroot->data=c;
		creattree(t->lchild,c);
	}
	else if(c>t->data)
    {  
	   treeroot->data=c;
	   creattree(t->rchild,c);
    }
	
}
void travel(bithtree s)
{
	if(s)
	{
		travel(s->lchild);
		printf("%d\t",s->data);
		travel(s->rchild);
	}
} 
int main()
{
	int i;int value;
	bithtree st;
	creatroot();
	printf("����ڵ�ֵ:\n");
	for(i=1;i<=3;i++)
	{
	    scanf("%d",&value);
		creattree(st,value);
	}
	printf("�������������:\n");
	travel(st); 
	return 0;
}