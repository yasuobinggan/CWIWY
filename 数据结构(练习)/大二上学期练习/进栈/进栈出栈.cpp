#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef struct{
int *base;  //�����׵�ַ(ջ��ָ�� )
int *top;   //ջ��ָ��
int stacksize; //ջ����
}SqStack;
void InitStack(SqStack &S){ // ����һ����ջS 
  S.base= (int*) malloc (STACK_INIT_SIZE *sizeof(int));
  if (!S.base)  printf("wrong");   // �洢����ʧ�� 
  S.top= S.base;            // ��ջ����Ϊ 0 
  S.stacksize= STACK_INIT_SIZE; // ��ʼ�洢���� 
     } //InitStack
void Push(SqStack &S, int e){ //����Ԫ��eΪ�µ�ջ��Ԫ�� 
 
 *S.top++=e; 
 } 
void Pop(SqStack &S,int &e){ // ��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ�������� OK ��
 //���򷵻� ERROR 
 
if(S.top==S.base) printf("wrong");  // ջ��
 e=*--S.top; 
 printf("%d",e); 
 } 
 int main()
 {
 	SqStack S1;int i;int j;
    InitStack(S1);
    scanf("%d",&i);
 	Push(S1,i);
 	Pop(S1,j);
	 printf("%d",j); 
 	return 0;
 }  