#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct BiTNode
{
    char c;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct
{
    BiTree x;
    int flag;
}snode;
typedef struct
{
    snode sdata[100];//����ջ 
    int top;
}Stack;
int Empty(Stack s)//�ж�ջ�Ƿ�Ϊ��(s.top==-1,ջ����)(s.top==0,ջΪ��) 
{
    if(s.top==-1) return 1;
    else return 0;
}
void Pop(Stack &s,BiTree R)          //ȡջ��Ԫ��,flag=1��־�Ѿ���ȡ��һ��
{
    R=s.sdata[s.top].x;
    s.sdata[s.top].flag=1;
}
void Out(Stack &s,BiTree R)         //ȡջ��Ԫ�أ�����ջ��Ԫ�س�ջ
{
    R=s.sdata[s.top].x;
    s.top--;
}
void In(Stack &s,BiTree R)          //Ԫ����ջ��flag=0��־��δ��ȡ��
{
    s.top++;
    s.sdata[s.top].x=R;
    s.sdata[s.top].flag=0;
}
void CreateBiTree(BiTree T)
{
    char ch;
    Stack s;
    T=NULL;
    s.top=-1;
    BiTree R=T;
    BiTree p;//��Ϊ����Ľڵ� 
    do
    {
        cin>>ch;
        if(Empty(s)&&ch=='#')//ջΪ�� 
            return;
        else if(ch!='#')
        {
            p=(BiTree)malloc(sizeof(BiTNode));
            p->c=ch;
            if(Empty(s))
            {
                T=p;
                R=p;
            }
            else if(s.sdata[s.top].flag==0)//ջ��Ԫ��δ��ȡ�� 
            {
                Pop(s,R);
                R->lchild=p;
            }
            else//ջ��Ԫ�ر�ȡ�� 
            {
                Out(s,R);
                R->rchild=p;
            }
            In(s,p);
        }
        else
        {
            if(s.sdata[s.top].flag==0)
            {
                Pop(s,R);
				R->lchild=NULL;
            }
            else
            {
                Out(s,R);
                R->rchild=NULL;
            }
        }
    }while(s.top!=-1);
}
void trtree(BiTree T)
{
	
} 
int main()
{
    BiTree T;
    CreateBiTree(T);
}