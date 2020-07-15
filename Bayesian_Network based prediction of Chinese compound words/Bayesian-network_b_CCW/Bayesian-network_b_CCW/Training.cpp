#include"GetDataset.h"
#include"TreeEncode.h"
#include"ConstructBN.h"
#include"Training.h"

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

extern map<string, int> feature;//����-�����
extern map<int, string> Name;//���-������


extern vector< vector<string> > trainingset;//ѵ����
extern int trainingsetsize;//ѵ�����Ĵ�С

extern map< int, set<string> > av;//����ȡֵ
extern int r[];//����ȡֵ����
extern vector<Code> HASH;//����ȡֵ�ı���


extern vector<int> tar;//����������Ŀ�����Խ��
extern vector<Node> BN;//��Ҷ˹����


//���������������м���
void count_CPtree(int id, vector<string> invec)
{
	vector<int> curcondition;
	vector<string> com;

	cout << "��ǰ������ȡֵ��ţ���Ӧ��" << Name[id] << "����";
	cout << "��ǰȡֵ��";
	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		curcondition.push_back(it->id);
		com.push_back(invec[it->id]);

		cout << invec[it->id] << "\t";
	}


	Treenode* curnode = &BN[id].CPtree;
	
	for (int i = 0; i < com.size(); i++)
	{
		int index = find(curcondition[i], com[i]);
		//cout << index << "\t";
		curnode = &(curnode->child[index]);
	}
	(curnode->sumcnt)++;

	cout << invec[id];
	Treenode* leafnode = &(curnode->child[find(id, invec[id])]);
	leafnode->sumcnt = curnode->sumcnt;
	(leafnode->cnt)++;

	cout << "\t\t\t\t";
	cout << "SUMCNT��" << leafnode->sumcnt << "  CNT��" << leafnode->cnt;
	cout << endl;
}

//���������������ĸ���
void cal_CPtree(int id, int depth, Treenode &curCPtree)
{
	if (depth == BN[id].parent.size() + 1)
	{
		if (curCPtree.sumcnt != 0)
		{
			curCPtree.pro = (double)curCPtree.cnt / (double)curCPtree.sumcnt;
			cout << "��ǰ���ʣ�" << curCPtree.pro << endl;
		}
		else if (curCPtree.sumcnt == 0)
		{
			curCPtree.pro = 1 / (double)r[id];
		}
		
		return;
	}
	else
	{
		for (int i = 0; i < 75; i++)
		{
			if (HASH[curCPtree.id].sti[i] != "")
			{
				cal_CPtree(id, depth + 1, curCPtree.child[i]);
			}
			
		}
	}
}

//�����ϸ��ʷֲ�����м���
void count_JPtable(int id, vector<string> invec)
{
	
	
	//����������ȡ��ǰ�������->�������ʱ�
	vector<string> com;

	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		com.push_back(invec[it->id]);
	}
	com.push_back(invec[id]);


	//�������
	cout << "�����Ƿ����: " << BN[id].JPtable.count(com) << "\t";
	cout << "��ֵ:" << BN[id].JPtable[com].cnt << "\t";

	++BN[id].JPtable[com].cnt;
	
	cout << "���ĺ�:" << BN[id].JPtable[com].cnt << "\t";
	cout << endl;

}

//��ȡѵ����
void get_trainingset()
{
	trainingset.clear();
	//��ѵ����(�ȶ�.txt�ļ�)
	ifstream fin;

	fin.open("d:\\datasetG\\trainingdataset.txt", ios::in);

	//TODO
	//cout << "���ϸ��ʱ����: " << endl;

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
			//�ж�
			if (line == "")
				continue;

			invec.clear();
			int i = 0;

			//��'\t'�и��������
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

				//����
				invec.push_back(in);
				i = j + 1;
			}


			//�������ݼ���
			for (int id = 1; id <= 13; id++)
			{
				//��Ե�ֲ������
				//TODO
				//BN[id].MD[invec[id]].cnt++;

				//���ϸ��ʷֲ������
				if (id == 5 || id == 8 || id == 13)
				{
					//TODO
					//count_JPtable(id, invec);

					cout << "����������������" << endl;
					count_CPtree(id, invec);
					
				}
				//cout << endl;
			}
			
			//����ѵ����
			vector<string> instance;
			for (int i = 0; i <= 14; i++)
			{
				instance.push_back(invec[i]);
			}
			trainingset.push_back(instance);
			
		}


		trainingsetsize = trainingset.size();
		cout << "ѵ������С:\t" << trainingsetsize << endl;
		fin.close();

	}
	else
		cout << "dataset doesn't exist!" << endl;

}

//�����Ե���ʷֲ���ĸ���
void cal_MDpro(int id)
{
	for (map<string, CPtableI>::iterator it = BN[id].MD.begin(); it != BN[id].MD.end(); it++)
	{
		it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
		if (it->second.pro != 0)
		{
			//�������
			cout << Name[id] << ": " << it->first << "\tEP: " << it->second.pro << endl;
		}
			
	}
	
}

void cal_MD()
{
	cout << "ѵ����Ե���ʱ�: **************************************************" << endl;

	for (int id = 1; id <= 13; id++)
	{
		cal_MDpro(id);
	}

}

//�������ϸ��ʷֲ�
void cal_JPpro(int id)
{
	for (map<vector<string>, CPtableI>::iterator it = BN[id].JPtable.begin(); it != BN[id].JPtable.end(); it++)
	{
		it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
		if (it->second.pro != 0)
		{
			vector<string> out = it->first;
			for (vector<string>::iterator secondit = out.begin(); secondit != out.end(); secondit++)
			{
				cout << *secondit << "\t";
			}
			cout << "\tJP: " << it->second.pro << endl;
		}
			
	}
}

void cal_JPtable()
{
	cout << "ѵ�����ϸ��ʱ�: **************************************************" << endl;
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		cout << Name[*it] <<"\t"<< endl;
		cal_JPpro(*it);
	}
}

//������������
double cal_mulJP(int id, vector<string> con)
{
	double mulJP = 1;

	int index = 0;//con�ķ��ʱ��

	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		if (BN[it->id].MD[con[index]].pro == 0)
		{
			return 0.0;
		}
		//cout << BN[it->id].MD[con[index]].pro << "\t";
		mulJP *= BN[it->id].MD[con[index]].pro;

		index++;
	}

	return mulJP;
}

void cal_CPpro(int id)
{
	for (map<vector<string>, CPtableI>::iterator it = BN[id].JPtable.begin(); it != BN[id].JPtable.end(); it++)
	{
		
		vector<string> convalue = it->first;

		string tarvalue = convalue.back();
		convalue.pop_back();
		//�������
		/*
		cout << endl << "����ȡֵ��\t";
		for (vector<string>::iterator it = convalue.begin(); it != convalue.end(); it++)
		{
			cout << *it << "\t";
		}
		//cout << endl;
		cout << "Ŀ��\t" << Name[id] << "\t" << tarvalue << endl;
		*/

		
		//��ȡ�������ϸ���
		double factor1 = it->second.pro;
		//���
		/*
		if(factor1 != 0)
			cout << "��һ����: " << factor1 << endl;
		*/
		

		//��ȡ��ĸ��Ե��������
		double factor2 = cal_mulJP(id, convalue);
		//���
		/*
		cout << endl;
		if(factor2 != 0)
			cout << "�ڶ�����: " << factor2 << "\t";
		*/
		
		//�������ʼ���+���뵽��Ӧ����

		//����ֵ�Ĵ���
		if (factor2 == 0)
		{
			//�������
			//cout << "\tr" << id << "  " << r[id] << endl;
			
			BN[id].CPtable[convalue].curCPtableI[tarvalue].pro = (1 / (double)r[id]);
			//cout << " *0*\tCP: " << BN[id].CPtable[convalue].curCPtableI[tarvalue].pro << endl;
		}
		else
		{
			BN[id].CPtable[convalue].curCPtableI[tarvalue].pro = (factor1 / factor2);
			
			//�������
			//cout << " *jisuan*\tCP: " << BN[id].CPtable[convalue].curCPtableI[tarvalue].pro << endl;
		}


		//�������
		/*
		if (BN[id].CPtable[convalue].curCPtableI[tarvalue].pro != 0)
		{
			cout << "CP: " << BN[id].CPtable[convalue].curCPtableI[tarvalue].pro << endl;
		}
		*/
		
	}
}

void cal_CPtable()
{
	cout << "ѵ���������ʱ�: **************************************************" << endl;
	for (vector<int>::iterator it=tar.begin(); it != tar.end(); it++)
	{
		cal_CPpro(*it);
	}
}


//��ѵ������
void train()
{
	/*
	cal_MD();
	cal_JPtable();
	cal_CPtable();
	*/

	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		cal_CPtree(*it, 0, BN[*it].CPtree);
	}
	
}