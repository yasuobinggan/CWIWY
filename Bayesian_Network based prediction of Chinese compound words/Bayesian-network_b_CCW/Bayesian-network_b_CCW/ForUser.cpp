#include"InitProblem.h"
#include"GetDataset.h"
#include"TreeEncode.h"
#include"ConstructBN.h"
#include"Training.h"
#include"Inferencing.h"


#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>


using namespace std;


const int maxn = 1005;//��Ҷ˹�����������ܵ����Ը���
const int maxsize = 105;//���Ե����ȡֵ����



map<string, int> feature;//����-�����
map<int, string> Name;//���-������


vector< vector<string> > trainingset;//ѵ����
int trainingsetsize;//ѵ�����Ĵ�С
map< int, set<string> > av;//����ȡֵ
int r[maxn];//����ȡֵ����
vector<Code> HASH;//����ȡֵ�ı���



vector<Node> BN;//��Ҷ˹����
vector<int> tar;//����������Ŀ�����Խ��



int main()
{
	
	//��ʼ��˫���ڴ�ʵ������
	cout << "*************************��ȷ����:ö������**************************************" << endl << endl;
	init_feature_Name();
	
	//����Ԥ����
	cout << "--------------------����Ԥ���� ��ǰ���Ե�ȡֵ:----------------------------------" << endl;
	//��ʼ������ȡֵ��������
	memset(r, 0, sizeof(r));
	get_dataset();
	//Ԥ������ȡֵ����
	for (int id = 1; id <= 13; id++)
	{
		r[id] = av[id].size();
	}
	//����Ŀ�����Խ��
	tar.push_back(5); tar.push_back(8); tar.push_back(13);
	//��Ŀ�����Ե�ȡֵ���б���
	encode();
	//testout();

	//��������
	cout << "---------------------������Ҷ˹���罨������-------------------------------------" << endl;
	clock_t start = clock();
	construct_BayesianNW();
	clock_t end = clock();

	cout << "����ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	

	//���ѵ����
	cout << "-----------------------------ѵ��-----------------------------------------------" << endl;
	get_trainingset();
	train();
	
	
	cout << "-----------------------------���Լ��ƶ�-----------------------------------------" << endl;
	start = clock();
	test();
	end = clock();

	cout << "����ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}


/*

����	H	H	V	V	H	j	j	j	64	64			64	1
ѧ��	D	D	N	N	D	k	k	k	3	3		g	3	1
����	D	D	N	N	D	n	n	n	1	1			1	1
����	E	E	A	A	E	d	d	d	3	3			3	1
����	H	H	D	V	H	e	j	e	16	15			16	1
��֤	H	J	V	V	H	c	a	c	18	4			18	2
����	I	B	V	N	I	b	k	b	8	8			8	2
��ͷ	K	B	N	N	A	d	k	b	6	2	h		2	2
ƻ��	B	B	N	N	B	h	h	h	7	13	g		7	2
����	H	J	V	V	H	j	e	j	24	14	g		24	2
����	H	H	V	V	H	h	h	h	1	4			4	3
����	K	A	N	N	A	d	h	h	6	10	h		10	3
����	B	B	N	N	B	o	p	p	32	29			29	3
ë��	B	B	N	N	B	k	k	q	11	11	g	g	1	3
�ڻ�	B	B	N	N	B	o	b	b	27	2			2	3
����	E	E	A	A	E	b	b	f	19	28			12	4
��һ	D	D	M	M	C	n	n	a	4	3			23	4
����	E	A	B	N	A	d	a	a	26	1	g	g	1	4
����	E	A	B	N	A	d	a	a	26	1	g	g	1	4
Բ��	B	B	N	N	C	b	d	a	4	2	g		23	4
˽��	E	D	A	N	D	d	j	j	55	3	g	g	3	5
�ƹ�	B	A	N	N	A	r	e	e	12	2		g	2	5
����	E	D	A	N	D	a	j	j	3	3			3	5
����	E	D	A	N	D	a	k	k	3	19			19	5
����	D	D	N	N	D	k	k	k	29	19	g		19	5
ϰ��	H	D	V	N	H	g	k	g	6	19			16	6
�Գ�	H	C	V	N	C	j	b	b	12	28		g	28	6
����	H	H	V	V	K	i	f	b	7	8	g		2	6
����	C	H	T	V	C	a	j	a	2	63			11	6
����	H	D	V	N	E	i	b	e	12	6			38	6
���	E	H	A	V	E	d	f	e	20	8			18	7
�Լ�	B	C	N	N	D	k	b	f	2	14	g	g	1	7
ϸ��	E	B	A	N	E	a	h	a	6	10		g	6	7
��Ӧ	H	H	V	V	H	i	i	i	36	18			36	7
ζ��	B	B	N	N	B	g	n	g	6	11			6	7
���	I	B	V	N	B	e	n	n	2	11			11	8
ԭ��	K	D	D	N	D	a	b	b	10	1			1	8
��Ӧ	H	H	V	V	D	b	i	a	3	18	g		25	8
����	K	E	D	A	E	a	d	d	23	4			4	8
����	I	B	V	N	H	h	k	i	3	4			12	8

*/