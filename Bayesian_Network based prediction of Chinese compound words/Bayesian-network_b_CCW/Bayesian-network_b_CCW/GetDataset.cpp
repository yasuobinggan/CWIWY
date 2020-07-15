#include"GetDataset.h"
#include"ConstructBN.h"
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


extern map< int, set<string> > av;//����ȡֵ


//�������ݼ���ȡ���ݵ�����(����Ԥ����)
void get_dataset()
{

	ifstream fin;
	fin.open("d:\\datasetG\\dataset.txt", ios::in);

	if (fin)//��ȡ�����ݼ�
	{
		string line;//�����ȡһ���ı��ı���
		vector<string> invec;//��ȡ�и����ַ�������
		int count = 0;
		map<string, int> cnt;
		cnt.clear();

		//���ж�ȡ
		while (getline(fin, line))
		{
			if (line == "")
				continue;
			//cout << line << endl;
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
				/******************************************/
				//��inΪ��ʱ,��һ������ֵ���(����С��Ϊ��ʱ)
				if (in == "")
				{
					in = "e";
				}
				/*****************************************/
				invec.push_back(in);
				i = j + 1;
			}

			//��ȡÿ�����Խ���ȡֵ
			for (int i = 1; i <= 14; i++)
			{
				if (invec[i].size() <= 2)
					av[i].insert(invec[i]);
			}

		}


		//�������

		for (map<int, set<string> >::iterator it = av.begin(); it != av.end(); it++)
		{
			cout << "��ǰid��" << it->first;// << "��ǰ����: " << BN[it->first].name;
			cout << "��ǰ��С��" << it->second.size() << endl;
			for (set<string>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
			{
				cout << *itset << " ";
			}
			cout << endl;
			cout << endl;
		}


		fin.close();

	}
	else
		cout << "dataset doesn't exist!" << endl;

}


