#include<stdio.h>
#include<math.h>
int main()
{
	int a1,b1,c1,d1;
	int a,b,c;	
	double t;	
	double x1,x2;
	double n1,n2;
	printf("�Ӹߴε��ʹ��������κ�����ϵ��:\n");
	scanf("%d%d%d%d",&a1,&b1,&c1,&d1);
	a=a1*3;
	b=b1*2;
	c=c1;
	t=sqrt(b*b-(4*a*c));
	if(t<=0)
	{
		printf("���κ����޼�ֵ!\n");
	}
	else
	{
		x1=(-b+t)/(2*a);n1=a1*pow(x1,3)+b1*pow(x1,2)+c1*pow(x1,1)+d1;
		x2=(-b-t)/(2*a);n1=a1*pow(x2,3)+b1*pow(x2,2)+c1*pow(x2,1)+d1;
	}
	printf("��ֵ��%f��ֵ��%f\n",x1,x2); 
	printf("��ֵ%f��ֵ%f\n",n1,n2);
	return 0;
} 