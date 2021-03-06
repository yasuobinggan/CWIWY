#include<stdio.h>
#include<stdlib.h>
#define m 31
typedef struct btnode{
	int data;
	struct btnode *lbt,*rbt;
}btnode,*btree;
typedef struct{
	int bdata;
	int flag;
}Bdata;
typedef struct{
	Bdata b[m];
	int front;
	int rear;
}qu;
void createqu(qu &queue)
{
	queue.front=queue.rear=0;
}
void enqu(qu &queue,int e)
{
	queue.b[queue.rear].bdata=e;
	queue.rear=(queue.rear+1)%m; 
}
void dequ(qu &queue,Bdata &e)
{
	e=queue.b[queue.front];
	queue.front=(queue.front+1)%m;
}
void create_qu(qu &queue,int n)
{
	int i;int data;
	createqu(queue);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		enqu(queue,data);
		queue.b[i].flag=0;
	}
}

void insert_qu(qu &queue,int data,int flag)//插入队列 
{
	int i;
	for(i=(queue.rear-1);i>=queue.front;i--)
	{
		if(data<=queue.b[i].bdata)
		{
			queue.b[i+1]=queue.b[i];
		}
		else
			break;
	}
	queue.b[i+1].bdata=data;
	queue.b[i+1].flag=flag;	
	queue.rear=(queue.rear+1)%m;
}
 
btree huffmantree(qu &queue)
{
	btree t1,t2;
	btree t[m];//指针数组 
	Bdata d1;
	int i;
	int j=0;//获取节点数组的标记 
	t1=t2=NULL;
	while(queue.front!=queue.rear)
	{
		if(t1==NULL)
		{
			dequ(queue,d1);
			if(d1.flag==0)
			{
				t1=(btree)malloc(sizeof(btnode));
				t1->data=d1.bdata;
				t1->lbt=t1->rbt=NULL;	
			}
			else
			{
				t1=t[d1.flag];
			}
		}
		if(t2==NULL)
		{
			dequ(queue,d1);
			if(d1.flag==0)
			{
				t2=(btree)malloc(sizeof(btnode));
				t2->data=d1.bdata;
				t2->lbt=t2->rbt=NULL;	
			}
			else
			{
				t2=t[d1.flag];	
			}
		}
		if((t1!=NULL)&&(t2!=NULL))
		{
			t[j]=(btree)malloc(sizeof(btnode));
			t[j]->data=t1->data+t2->data;
			t[j]->lbt=t1;
			t[j]->rbt=t2;
			insert_qu(queue,t[j]->data,j);
			t1=t2=NULL;
			j++;
		}	
	}
	return t[j-1];
}

void travel(btree tree)
{
	if(tree)
	{
		printf("%d ",tree->data);
		travel(tree->lbt);
		travel(tree->rbt);
	}
}
 
int main()
{
	qu queue;int n;
	btree T;int i;
	printf("输入哈夫曼构造树的节点数:\n");
	scanf("%d",&n);
	printf("递增顺序输入节点值:\n");
	create_qu(queue,n);
	T=huffmantree(queue);
	printf("前序遍历验证结果:\n");
	travel(T);
	printf("\n");
	return 0;
}