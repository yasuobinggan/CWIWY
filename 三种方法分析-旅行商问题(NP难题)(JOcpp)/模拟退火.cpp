#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
#define maxn 33
#define T 20
const double a=0.5;
int minlen=0;

int G[maxn][maxn];//˫��ԳƱ�
typedef struct sheng
{
	int x;
	int y;
}sheng;
sheng s[maxn];//ʡ�ı��1~32
void init_S()//ʡ�ĵ�ͼ����
{
	s[1].x=1;s[1].y=1;
	s[2].x=1;s[2].y=2;
	s[3].x=1;s[3].y=4;
	s[4].x=1;s[4].y=11;

	s[5].x=2;s[5].y=2;
	s[6].x=2;s[6].y=3;
	s[7].x=2;s[7].y=4;
	s[8].x=2;s[8].y=5;
	s[9].x=2;s[9].y=6;
	s[10].x=2;s[10].y=7;
	s[11].x=2;s[11].y=8;
	s[12].x=2;s[12].y=9;
	s[13].x=2;s[13].y=10;

	s[14].x=3;s[14].y=1;
	s[15].x=3;s[15].y=2;
	s[16].x=3;s[16].y=3;
	s[17].x=3;s[17].y=4;
	s[18].x=3;s[18].y=5;
	s[19].x=3;s[19].y=6;

	s[20].x=4;s[20].y=5;
	s[21].x=4;s[21].y=6;

	s[22].x=5;s[22].y=2;
	s[23].x=5;s[23].y=3;
	s[24].x=5;s[24].y=4;
	s[25].x=5;s[25].y=5;
	s[26].x=5;s[26].y=6;
	s[27].x=4;s[27].y=7;

	s[28].x=6;s[28].y=3;
	s[29].x=6;s[29].y=4;
	s[30].x=6;s[30].y=5;

	s[31].x=7;s[31].y=1;
	s[32].x=7;s[32].y=5;

}
void init_G()//��ʼ�������ŷʽ���룩
{
	int i,j;
	for(i=1;i<maxn;i++)
	{
		for(j=1;j<maxn;j++)
		{
			G[i][j]=0;
			int a=0,b=0;

			if(j!=i)
			{
				a=abs(s[i].x-s[j].x);
				b=abs(s[i].y-s[j].y);
				G[i][j]=(int)sqrt(a*a+b*b);
			}
			//cout<<G[i][j]<<" ";
		}
		//cout<<endl;
	}

}

//int G[maxn][maxn];//ŷʽ�����
int list[maxn];
int res[maxn];//������������
void initial_list()//��ʼ��·��
{
	for(int i=1;i<maxn;i++)
		list[i]=i;
}

void swap_list()//�Ŷ���ǰ�����Ž�
{
	int a,b;
	while(true)
	{
		a=rand()%(maxn-1)+1;
		b=rand()%(maxn-1)+1;
		if(a!=1&&b!=1&&a!=b)
			break;
	}
	cout<<"��ǰ����:"<<a<<"\t"<<b<<endl;
	int temp;
	temp=list[a];
	list[a]=list[b];
	list[b]=temp;
}

int compute_curlen()//���㵱ǰ·������
{
	int curlen=0;
	for(int i=1;i<maxn-1;i++)
	{
		curlen+=G[list[i]][list[i+1]];
	}
	curlen+=G[list[maxn-1]][list[1]];//���ϵ���һ����ľ���
	return curlen;
}
void copy_path()//��ȡ���·��
{
	for(int i=1;i<maxn;i++)
		res[i]=list[i];
 }
void simulated_annealing()//ģ���˻�//�����Ż�������ľ������
{
	//minlen=initial_curlen();
	minlen=compute_curlen();
	double t=T;
	int curlen;
	int deltaE;

	int cnt=1;

	while(t>0)
	{
        cout<<cnt++<<endl;
		swap_list();
		curlen=compute_curlen();
		//swap_path(curlen);

		deltaE=curlen-minlen;
		if(deltaE<0)//���ܵ�ǰ��
		{
			minlen=curlen;
			copy_path();
		}
		else//������ʣ��ж��Ƿ���ܵ�ǰ��
		{

			cout<<"exp�Ľ�:"<<-deltaE/t<<endl;
			double p=exp(-deltaE/t);
			double r=((double)(rand()%100)/100);
			cout<<"���ʱȽ�: P:"<<p<<"\t"<<"R:"<<r<<endl;

			if(p>r)//��������ϲ�Ľ�
			{
				minlen=curlen;
				copy_path();
			}

		}
		t*=a;
		cout<<"T:"<<t<<endl;
	}

}
void output()//�������·��
{

	cout<<endl<<"ģ���˻����·����"<<endl;
	for(int i=1;i<maxn;i++)
		cout<<res[i]<<"--";
	cout<<1<<endl;

}
int main()
{
	init_S();
	init_G();
	initial_list();
	srand(time(NULL));//�������
	simulated_annealing();
	output();
	cout<<minlen<<endl;
	return 0;
}
