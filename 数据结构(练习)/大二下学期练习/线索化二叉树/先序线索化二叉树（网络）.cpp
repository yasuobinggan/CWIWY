#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef enum pointertag {link,thread};
typedef struct bithnode{
	char data;
	struct bithnode *lchild,*rchild;
	pointertag ltag,rtag;
}bithnode,* bithtree;
bithtree pre;
void creatree(bithtree &s)
{
	char p;scanf("%c",&p);
	if(p=='#')
	{s=NULL;}
	else
{    s=(bithtree)malloc(sizeof(bithnode));
     s->data=p;
     s->ltag=link;
     s->rtag=link;
     creatree(s->lchild);
     creatree(s->rchild);
}
}
void prethreading(bithtree &t)
{
    if(t)
    {
        if(!t->lchild)
        {
            t->ltag=thread;
			t->lchild=pre;        
        }
        if(!pre->rchild)
        {
            pre->rtag=thread;
			pre->rchild=t;       
        }
        pre=t;//��ȡ��ǰ��� 
        if(link==t->ltag) 
            prethreading(t->lchild);
        if(link==t->rtag)
            prethreading(t->rchild);
    }
}
bithtree preorderthreading(bithtree &t)
{
    bithtree s;
    s=(bithtree)malloc(sizeof(bithnode)); 
    s->ltag=link;//ͷ��� 
    s->rtag=thread;
    s->rchild=s; 
    if(!t)
        s->lchild=t;
    else
    {
        s->lchild=t;
        pre=s;
		prethreading(t);
		//β�ڵ㹹��˫������       
        //pre����������һ���ڵ�
		pre->rchild=s;        
        pre->rtag=thread;
        s->rchild=pre;
    }
    return s;
}
void preordertravel(bithtree t)
{
    bithtree p;
    p=t->lchild;
    while(p!=t)
    {
        printf("%c",p->data);
        if(p->ltag==link)
            p=p->lchild;
        else
            p=p->rchild;
    }
}
int main()
{
	bithtree s,t;
	printf("ǰ�����������:\n");
	creatree(s);
	t=preorderthreading(s);//����ͷ��� 
	printf("���ǰ��������������:\n");
	preordertravel(t);
	printf("\n-------------------\n");
    return 0;
} 