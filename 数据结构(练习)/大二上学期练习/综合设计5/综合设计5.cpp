#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
typedef struct bithnode{
	int data;
	bithnode *lchild,*rchild;
}bithnode,*bithtree;
void BTInsert(bithtree &T,int c)
{
	if(T==NULL)
	{
   		T=(bithtree)malloc(sizeof(bithnode));
   		T->data=c;
   		T->lchild=T->rchild=NULL;
	}
	else
	{
   		if(c<T->data)
   		BTInsert(T->lchild,c);
   		else if(c>T->data)
   		BTInsert(T->rchild,c);
	}
}

void CreateBTNode(bithtree &T)
{
   int i,v;
   printf("�����������:\n");
   for(i=0;i<5;i++)
{
  scanf("%d",&v);
  BTInsert(T,v);
}
}
void PrintfBTNode(bithtree &T)
{
 if(T)
 {
   PrintfBTNode(T->lchild);
   printf("%d ",T->data);
   PrintfBTNode(T->rchild);
}
}
int main()
{
	bithtree s;
	s=NULL;
	printf("��������������:\n");
	CreateBTNode(s);
	printf("���������:\n"); 
	PrintfBTNode(s);
	return 0;
}