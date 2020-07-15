#include<stdio.h>
#include<stdlib.h>
#define m 32
typedef struct btnode{
	int tdata;
	struct btnode *lbt;
	struct btnode *rbt;
}btnode,*btree;
typedef struct{
	int data[m];
	int front;
	int rear;
}qu;
typedef struct {
	int ldata;
	int flag;
}list;
void createqu(qu &queue)
{
	queue.front=queue.rear=0;
}
void enqu(qu &queue,int e)
{
	queue.data[queue.rear]=e;
	queue.rear=(queue.rear+1)%m; 
}
void dequ(qu &queue,int &e)
{
	e=queue.data[queue.front];
	queue.front=(queue.front+1)%m;
}
int topqu(qu queue)
{
	int e;
	e=queue.data[queue.front];
	return e;
}
void createxqu(qu &queue,int n)
{
	int i;int data;
	createqu(queue);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		enqu(queue,data);
	}
}
void createzlist(list l[m],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&l[i].ldata);
		l[i].flag=i;
	}
}
int seeklist(list l[m],int n,int e)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(l[i].ldata==e)
		break;
	}
	return l[i].flag;
}
void createnode(btree &tree,int q,int qflag,int pflag)
{
	if(tree==NULL)
	{
		tree=(btree)malloc(sizeof(btnode));
		tree->tdata=q;
		tree->lbt=NULL;
		tree->rbt=NULL;
	}
	else
	{
		if(qflag>pflag)
			createnode(tree->lbt,q,qflag,pflag);
		else
			createnode(tree->rbt,q,qflag,pflag);
	}
	
}
void createtree(qu &queue,list l[],int n,btree &tree)//�Զ��ײ��뽨�� 
{
	int p,q;
	int pflag,qflag;
	dequ(queue,p);
	createnode(tree,p,0,0);//��������ͷ��� 
	while(queue.front!=queue.rear)
	{
		q=topqu(queue);
		qflag=seeklist(l,n,q);
		pflag=seeklist(l,n,p);
		createnode(tree,q,qflag,pflag);
		dequ(queue,p);
	}
}
void travel(btree tree)
{
	if(tree==NULL)return;
	travel(tree->lbt);
	travel(tree->rbt);
	printf("%d ",tree->tdata);
}
int main()
{
	int n;btree tree;
	printf("����������Ľڵ�����:\n");
	scanf("%d",&n);
	qu queue;list l[m];
	printf("������������������:\n");
	createxqu(queue,n);
	printf("������������������:\n");
	createzlist(l,n);
	createtree(queue,l,n,tree);
	printf("�������:\n");
	travel(tree);
	return 0;
}