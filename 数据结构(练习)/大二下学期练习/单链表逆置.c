#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*link;
void createlink(link &l,int n)
{
	int i;link s;link p;
	l=(link)malloc(sizeof(lnode));
	l->next=NULL;
	s=l;
	for(i=0;i<n;i++)
	{
		p=(link)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=s->next;
		s->next=p;
		s=p;
	}
}

void inverselink(link &l,int n,link &il)
{
	int i;int w;
	w=n-2;
	link p,q;//q���p����һ���ڵ� 
	link s;//�����������ͷ�����ڵ� 
	
	while(n-2>=0)
	{
		p=l->next;
		for(i=1;i<=n-2;i++) 
		{
			p=p->next;
		}//�ҵ������ڶ����ڵ� 
		q=p->next; 
		p=q->next;
		p->next=NULL;
		if(n=w)
		{
			s=q;
		}	 
		n--; 
	}
	 //il->next=NULL;
	// il->next=s;
	while(s)
	{
		printf("%d ",s->data);
		s=s->next;
	}
}
//�����磩�����ڵ�����ʱ������ס��ָ��ָ��������ڵ�
//ֱ���������ڵ㲻���� 
void travellink(link l)
{
	link p;
	p=l->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;		
	}
	//printf("%d",p->data);	
}  
int main()
{
	link l;
	int n;
	int q;
	link il;
	il=(link)malloc(sizeof(lnode));
	il->next=NULL;
	printf("����Ҫ�������������:\n");
	scanf("%d",&n);
	printf("��������:\n");
	createlink(l,n);
	printf("�������:\n"); 
	travellink(l);
	inverselink(l,n,il);
	printf("\n������ú������:\n");
	travellink(il);
	return 0;
}