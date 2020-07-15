#include"TreeEncode.h"
#include"ConstructBN.h"
#include"Inferencing.h"


#include<iostream>
#include<fstream>
#include<sstream>
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


extern vector<Node> BN;//��Ҷ˹����
extern vector<int> tar;//����������Ŀ�����Խ��

extern vector<Code> HASH;//����ȡֵ�ı���

vector<string> testsampleCPtree(vector<string> invec)
{
	vector<string> hypo;//����

	//ƥ��ʻ����
	//���뵽Ҷ�ӽ��
	vector<string> comTWB;

	Treenode curnode = BN[5].CPtree;
	for (vector<Node>::iterator it = BN[5].parent.begin(); it != BN[5].parent.end(); it++)
	{
		int index = find(it->id, invec[it->id]);
		curnode = curnode.child[index];
	}
	
	//ƥ��
	string maxvalue;
	double maxpro = -1.0;

	for (int i = 0; i < 105; i++)
	{
		if (curnode.child[i].pro > maxpro)
		{
			maxvalue = curnode.child[i].value;
			maxpro = curnode.child[i].pro;
		}
	}
	
	hypo.push_back(maxvalue);


	//ƥ��ʻ�����
	//��¼
	vector<string> comTWM;

	curnode = BN[8].CPtree;
	for (vector<Node>::iterator it = BN[8].parent.begin(); it != BN[8].parent.end(); it++)
	{
		int index = find(it->id, invec[it->id]);
		curnode = curnode.child[index];
	}

	//ƥ��
	maxvalue = "";
	maxpro = -1.0;

	for (int i = 0; i < 105; i++)
	{
		if (curnode.child[i].pro > maxpro)
		{
			maxvalue = curnode.child[i].value;
			maxpro = curnode.child[i].pro;
		}
	}

	hypo.push_back(maxvalue);


	//ƥ��ʻ�С��
	//��¼
	vector<string> comTWS;

	curnode = BN[13].CPtree;
	for (vector<Node>::iterator it = BN[13].parent.begin(); it != BN[13].parent.end(); it++)
	{
		int index = find(it->id, invec[it->id]);
		curnode = curnode.child[index];
	}

	//ƥ��
	maxvalue = "";
	maxpro = -1.0;

	for (int i = 0; i < 105; i++)
	{
		if (curnode.child[i].pro > maxpro)
		{
			maxvalue = curnode.child[i].value;
			maxpro = curnode.child[i].pro;
		}
	}

	hypo.push_back(maxvalue);


	return hypo;
}


vector<string> testsample(vector<string> invec)
{
	vector<string> hypo;//����

	//ƥ��ʻ����
	//��¼
	vector<string> comTWB;

	for (vector<Node>::iterator it = BN[5].parent.begin(); it != BN[5].parent.end(); it++)
	{
		comTWB.push_back(invec[it->id]);
	}
	//ƥ��
	string maxvalue;
	double maxpro = -1.0;

	for (map<string, CPtableI>::iterator it = BN[5].CPtable[comTWB].curCPtableI.begin(); it != BN[5].CPtable[comTWB].curCPtableI.end(); it++)
	{
		if (it->second.pro > maxpro)
		{
			maxvalue = it->first;
			maxpro = it->second.pro;
		}
	}

	hypo.push_back(maxvalue);


	//ƥ��ʻ�����
	//��¼
	vector<string> comTWM;

	for (vector<Node>::iterator it = BN[8].parent.begin(); it != BN[8].parent.end(); it++)
	{
		comTWM.push_back(invec[it->id]);
	}

	//ƥ��
	maxvalue = "";
	maxpro = -1.0;

	for (map<string, CPtableI>::iterator it = BN[8].CPtable[comTWM].curCPtableI.begin(); it != BN[8].CPtable[comTWM].curCPtableI.end(); it++)
	{
		if (it->second.pro > maxpro)
		{
			maxvalue = it->first;
			maxpro = it->second.pro;
		}
	}

	hypo.push_back(maxvalue);


	//ƥ��ʻ�С��
	//��¼
	vector<string> comTWS;

	for (vector<Node>::iterator it = BN[13].parent.begin(); it != BN[13].parent.end(); it++)
	{
		comTWS.push_back(invec[it->id]);
	}

	//ƥ��
	maxvalue = "";
	maxpro = -1.0;

	for (map<string, CPtableI>::iterator it = BN[13].CPtable[comTWS].curCPtableI.begin(); it != BN[13].CPtable[comTWS].curCPtableI.end(); it++)
	{
		if (it->second.pro > maxpro)
		{
			maxvalue = it->first;
			maxpro = it->second.pro;
		}
	}

	hypo.push_back(maxvalue);



	return hypo;
}


void test()
{

	//��ѯĿ������������ʱ�
	ifstream fin;
	fin.open("d:\\datasetG\\testdataset.txt", ios::in);



	if (fin)//��ȡ�����ݼ�
	{
		int testsize = 0;//ѵ������С

		string line;//�����ȡһ���ı��ı���
		vector<string> invec;//��ȡ�и����ַ�������

							 //��¼׼ȷ��
		int sumcount = 0;

		double expection = 0;


		//���ж�ȡ
		while (getline(fin, line))
		{
			//�ж�
			if (line == "")
				continue;

			//��'\t'�и��������
			invec.clear();
			int i = 0;
			while (i < line.size())
			{
				int j = i;
				string in;
				in.clear();
				while (line[j] != '\t' && j < line.size())
				{
					in += line[j];
					j++;
				}
				//��inΪ��ʱ,��һ������ֵ���(����С��Ϊ��ʱ)
				if (in == "")
				{
					in = "e";
				}
				invec.push_back(in);
				i = j + 1;
			}

			//�ƶ�+�ƶϽ��
			vector<string> hypo = testsampleCPtree(invec);


			//�ʻ����
			cout << "�ʻ�����׼ȡֵ: " << invec[5] << " ";
			cout << "�ƶϴʻ����ȡֵ" << hypo[0] << "\t|\t";


			//�ʻ�����
			cout << "�ʻ������׼ȡֵ: " << invec[8] << " ";
			cout << "�ƶϴʻ�����ȡֵ" << hypo[1] << "\t|\t";

			//�ʻ�С��
			cout << "�ʻ�С���׼ȡֵ: " << invec[13] << " ";
			cout << "�ƶϴʻ�С��ȡֵ" << hypo[2] << endl;



			//��������
			double curexpection = 0;
			if (invec[5] == hypo[0])
			{
				curexpection += 1;
			}
			if (invec[8] == hypo[1])
			{
				curexpection += 1;
			}
			if (invec[13] == hypo[2])
			{
				curexpection += 1;
			}

			curexpection /= 3;
			expection += curexpection;


			//ƥ�����
			if (invec[5] == hypo[0] && invec[8] == hypo[1] && invec[13] == hypo[2])
			{
				sumcount++;
			}


			++testsize;
		}

		//���ģ�͵�׼ȷ��,����
		cout << endl << "********************************************************************" << endl;
		cout << "��ǰģ�͵���ȫ׼ȷ��: " << (double)sumcount / (double)testsize << endl;
		cout << "��ǰģ�͵�����: " << ((double)1 / (double)testsize) * expection << endl;

		fin.close();

	}
	else
		cout << "dataset doesn't exist!" << endl;
}

