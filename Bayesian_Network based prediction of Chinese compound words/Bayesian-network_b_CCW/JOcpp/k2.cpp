///*
//	k2:
//		���ڽṹ�ĸ���
//	˼��:
//		�Ż�����
//*/
//
////#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<string>
//#include<cstring>
//#include<map>
//#include<unordered_map>
//#include<set>
//#include<fstream>
//#include<sstream>
//
//using namespace std;
//
///*******************************************���ݽṹ ST*************************************************************************************************/
//
//const int INF = 0x3f3f3f3f;//�����
//
////��Ҷ˹�����������ܵ����Ը���
//const int maxn = 1005;
//
////��ǰ����ı�Ҷ˹�������������
//int n = 13;
//
////�ڽӾ���洢��Ҷ˹����(ֻ�洢��ϵ)
//int G[maxn][maxn];
////�������
//bool visited[maxn];
//
//
//map<string, int> feature;
//map<int, string> Name;
//
//struct sample {
//	string s_word;//ѵ���ʻ�
//	string s_1stWB;//��һ���������
//	string s_2ndWB;//�ڶ����������
//	string s_1stPosB;//��һ���Դ���
//	string s_2ndPosB;//�ڶ����Դ���
//	string s_TWB;//Ŀ��ʻ����
//	string s_1stWM;//��һ����������
//	string s_2ndWM;//�ڶ�����������
//	string s_TWM;//Ŀ��ʻ�����
//	string s_1stWS;//��һ������С��
//	string s_2ndWS;//�ڶ�������С��
//	string s_1stPosS;//��һ����С��
//	string s_2ndPosS;//�ڶ�����С��
//	string s_TWS;//Ŀ��ʻ�С��
//	string mode;//���ʷ�ʽ���
//
//	sample() {}
//	sample(string input, string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m, string n)
//	{
//		s_word = input;
//		s_1stWB = a; s_2ndWB = b;
//		s_1stPosB = c; s_2ndPosB = d;
//		s_TWB = e;
//		s_1stWM = f; s_2ndWM = g;
//		s_TWM = h;
//		s_1stWS = i; s_2ndWS = j;
//		s_1stPosS = k; s_2ndPosS = l;
//		s_TWS = m;
//		mode = n;
//	}
//};
//
//
////��������
//struct CPtableI
//{
//	int cnt;
//	double pro;
//	CPtableI() {}
//	CPtableI(int _cnt)
//	{
//		cnt = _cnt;
//	}
//	CPtableI(int _cnt, double _pro)
//	{
//		cnt = _cnt;
//		pro = _pro;
//	}
//};
//
////������ͷ
//struct  CPtableH
//{
//	int sumcnt;
//	map<string, CPtableI> curCPtableI;
//
//	CPtableH() {}
//	CPtableH(int _sumcnt)
//	{
//		sumcnt = _sumcnt;
//	}
//	CPtableH(int _sumcnt, map<string, CPtableI> _curCPtableI)
//	{
//		sumcnt = _sumcnt;
//		curCPtableI = _curCPtableI;
//	}
//};
//
////������Ҷ˹������:һ�����һ������������(��)
//struct Node {
//	int id;//���Ա��
//	string name;//������
//
//	//�������ʱ�
//	map<vector<string>, CPtableH> CPtable;
//
//	//��Ե�ֲ���
//	map<string, CPtableI> MD;
//
//	//��Ϊ���Ե���������
//	vector<int> parent;
//	//���Եĺ�������
//	vector<int> child;
//
//	Node() {}
//	Node(int _id, string _name)
//	{
//		id = _id;
//		name = _name;
//	}
//};
//
////��Ҷ˹����
//vector<Node> BN;
//
////ѵ����
//vector<vector<string>> trainingset;
//int trainingsetsize;
//
////����ȡֵ
//map<int, set<string>> av;
//
//
////����ȡֵ����
//int r[maxn];
//
////���Ը�����ȡֵ����
//vector<int> q[maxn];
//
////ǰ������
//set<int> Pre[maxn];
//
////�����Խ������
//set<int> Pa[maxn];
//
///*******************************************���ݽṹ ED*************************************************************************************************/
//
//
//
///********************************************����Ԥ���� ST**********************************************************************************************/
//void get_dataset()
//{
//	//��ѵ����(�ȶ�.txt�ļ�)
//	ifstream fin;
//	fin.open("d:\\dataset\\dataset.txt", ios::in);
//
//	if (fin)//��ȡ�����ݼ�
//	{
//		string line;//�����ȡһ���ı��ı���
//		vector<string> invec;//��ȡ�и����ַ�������
//
//		//���ж�ȡ
//		while (getline(fin, line))
//		{
//			//�ж�
//			if (line == "")
//				continue;
//
//			//��'\t'�и��������
//			invec.clear();
//			int i = 0;
//			while (i < line.size())
//			{
//				int j = i;
//				string in;
//				in.clear();
//				while (line[j] != '\t' && j < line.size())
//				{
//					in += line[j];
//					j++;
//				}
//				//��inΪ��ʱ,��һ������ֵ���(����С��Ϊ��ʱ)
//				if (in == "")
//				{
//					in = "e";
//				}
//
//				invec.push_back(in);
//				i = j + 1;
//			}
//
//			//��ȡÿ�����Խ���ȡֵ
//			for (int i = 1; i <= 14; i++)
//			{
//				if (invec[i].size() <= 2)
//					av[i].insert(invec[i]);
//			}
//
//
//		}
//
//		//�������
//		for (map<int, set<string>>::iterator it = av.begin(); it != av.end(); it++)
//		{
//			cout << "��ǰ����id��" << it->first;
//			cout << "��ǰ����ȡֵ������" << it->second.size() << endl;
//			for (set<string>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
//			{
//				cout << *itset << " ";
//			}
//			cout << endl;
//			cout << endl;
//		}
//
//
//		fin.close();
//
//	}
//	else
//		cout << "dataset doesn't exist!" << endl;
//
//}
///********************************************����Ԥ���� ED**********************************************************************************************/
//
//
///********************************************����ѵ���� ST**********************************************************************************************/
////�������ݼ���ȡ���ݵ�����(����Ԥ����)
//void get_trainingset()
//{
//	trainingset.clear();
//	//��ѵ����(�ȶ�.txt�ļ�)
//	ifstream fin;
//	fin.open("d:\\dataset\\dataset.txt", ios::in);
//
//	if (fin)//��ȡ�����ݼ�
//	{
//		string line;//�����ȡһ���ı��ı���
//		vector<string> invec;//��ȡ�и����ַ�������
//
//		//���ж�ȡ
//		while (getline(fin, line))
//		{
//			//�ж�
//			if (line == "")
//				continue;
//
//			//��'\t'�и��������
//			invec.clear();
//			int i = 0;
//			while (i < line.size())
//			{
//				int j = i;
//				string in;
//				in.clear();
//				while (line[j] != '\t' && j < line.size())
//				{
//					in += line[j];
//					j++;
//				}
//				//��inΪ��ʱ,��һ������ֵ���(����С��Ϊ��ʱ)
//				if (in == "")
//				{
//					in = "e";
//				}
//
//				invec.push_back(in);
//				i = j + 1;
//			}
//
//
//
//			//����ѵ����
//			//sample s = sample(invec[0], invec[1], invec[2], invec[3], invec[4], invec[5], invec[6], invec[7], invec[8], invec[9], invec[10], invec[11], invec[12], invec[13], invec[14]);
//			
//			vector<string> instance;
//			for (int i = 0; i <= 14; i++)
//			{
//				instance.push_back(invec[i]);
//			}
//			trainingset.push_back(instance);
//
//		}
//
//		fin.close();
//
//	}
//	else
//		cout << "dataset doesn't exist!" << endl;
//
//}
///********************************************����ѵ���� ED**********************************************************************************************/
//
//
//
///********************************************k2 ST******************************************************************************************************/
////dfs���������������ʱ����
//void build_CPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable)
//{
//	if (index == condition.size())
//	{
//		curCPtable[curcon] = CPtableH(0);
//
//		//�����ڶ�������
//		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//		{
//			curCPtable[curcon].curCPtableI[*it] = CPtableI(0);
//		}
//
//		return;
//	}
//
//	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//	{
//		curcon.push_back(*it);
//		build_CPtable(id, condition, index + 1, curcon, curCPtable);
//		curcon.pop_back();
//	}
//}
//
////�����Ķ�ȡ����
//void generate_nij_nijk(int id,vector<int> condition, map<vector<string>, CPtableH> &curCPtable)
//{
//	//�����ɱ���
//	int index = 0;//�±���Ʒ���
//	vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
//	curcon.clear();
//
//	//cout << "��ǰ�������ʱ��������: "<<id<<endl;
//	//dfs����
//	build_CPtable(id, condition, index, curcon, curCPtable);
//
//
//	//�����ݽ���(����)
//	for (vector<vector<string>>::iterator it = trainingset.begin(); it != trainingset.end(); it++)
//	{
//		vector<string> value = *it;
//		vector<string> convalue;
//		for (vector<int>::iterator secondit = condition.begin(); secondit != condition.end(); secondit++)
//		{
//			convalue.push_back(value[*secondit]);
//		}
//		
//		//cout << "SCNT����ǰ��"<< curCPtable[convalue].sumcnt;
//		curCPtable[convalue].sumcnt++;
//		//cout << "\tSCNT���ĺ�" << curCPtable[convalue].sumcnt;
//		
//		//cout << "\tCNT����ǰ��" << curCPtable[convalue].curCPtableI[value[id]].cnt;
//		curCPtable[convalue].curCPtableI[value[id]].cnt++;
//		//cout << "\tCNT���ĺ�" << curCPtable[convalue].curCPtableI[value[id]].cnt;
//
//		//cout << endl;
//
//	}
//
//}
//
//double cal_factor_1(int nij,int ri)
//{
//	double factor = 1;
//	
//	int st = nij + ri - 1;
//	while (nij > 0)
//	{
//		factor *= st;
//		--st;
//		--nij;
//	}
//
//	return factor;
//}
//
//int cal_factor_2(int nijk)
//{
//		
//	double factor = 1;
//	
//	while (nijk > 0)
//	{
//		factor *= nijk;
//		--nijk;
//	}
//
//	return factor;
//}
//
////�����ɱ���+�ټ���
//double getscore(int id,set<int> curPa)
//{	
//	vector<int> condition;
//	
//	for (set<int>::iterator it = curPa.begin(); it != curPa.end(); it++)
//	{
//		condition.push_back(*it);
//	}
//
//	//�������ʱ�
//	map<vector<string>, CPtableH> CPtable;
//
//	//�Լ������Ԥ����
//	generate_nij_nijk(id, condition, CPtable);
//
//	
//
//	cout << Name[id] << endl;
//	int flag1 = 0;//�ж�����Ƿ���ȷ
//	int flag2 = 0;//�ж�����Ƿ���ȷ
//
//
//	//����
//	double score = 0;
//	//����(����ѭ��)
//	for (map<vector<string>, CPtableH>::iterator it = CPtable.begin(); it != CPtable.end(); it++)
//	{
//		
//		double curscore = 1;
//		for (map<string, CPtableI>::iterator secondit = it->second.curCPtableI.begin(); secondit != it->second.curCPtableI.end(); secondit++)
//		{			
//			
//			
//			double factor2 = cal_factor_2(secondit->second.cnt);
//			if (factor2 != 0)
//			{
//				//curscore += log(cal_factor_2(secondit->second.cnt));
//				curscore *= factor2;
//			}
//
//		}
//		
//		if (it->second.sumcnt != 0)
//		{
//			//flag2 += it->second.sumcnt;
//			//cout << it->second.sumcnt << endl;
//		}
//
//		//curscore *= log(1 / cal_factor_1(it->second.sumcnt, r[id]));
//		curscore *= 1 / cal_factor_1(it->second.sumcnt, r[id]);
//		
//		
//		score += log(curscore);
//
//	}
//	
//
//	//cout << "flag1:" << flag1 << "\t" << "flag2:" << flag2 << endl;
//
//	return score;
//}
//void k2(int limit)
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		Pa[id].clear();
//		//�����Խ��Ϊ�յ����⴦��
//		cout << id << " old���� ";
//		//double Pold = getscore(id, Pa[id]);
//		double Pold = -INF;
//		cout << Pold << endl;
//
//		bool OKToProcced = true;
//		set<int> curPa = Pa[id];
//
//		while (OKToProcced == true && Pa[id].size() < limit && !Pre[id].empty())
//		{
//
//			
//			set<int>::iterator it = Pre[id].begin();
//			curPa.insert(*it);
//			
//			//�������
//			cout << endl << "����curPa��" << endl;
//			for (set<int>::iterator it = curPa.begin(); it != curPa.end(); it++)
//			{
//				cout << Name[*it] << "\t";
//			}
//			//cout << endl;
//
//			Pre[id].erase(it);
//
//			double Pnew = getscore(id, curPa);
//			//���
//			cout << id << " new���� "<< Pnew << endl;
//
//
//			if (Pnew > Pold)
//			{
//				Pold = Pnew;
//
//				Pa[id] = curPa;
//			}
//			else
//				OKToProcced = false;
//
//		}
//		//���
//		cout << "--------" << endl;
//		cout << "������֣�" << Pold << endl;
//		cout << endl;
//		cout << Name[id] << "�ĸ����" << endl;
//		for (set<int>::iterator it = Pa[id].begin(); it != Pa[id].end(); it++)
//		{
//			cout << Name[*it] << "\t\t";
//		}
//		cout << endl;
//		cout << endl;
//		cout << "******************************************" << endl;
//			
//	
//	}
//}
///********************************************k2 ED******************************************************************************************************/
//
//
//int main()
//{
//	//��ʼ������
//	//��ʼ������ȡֵ��������
//	memset(r, 0, sizeof(r));
//	//��ʼ�����Ա��
//	feature["temp"] = 0;
//	feature["1stWB"] = 1;feature["2ndWB"] = 2;
//	feature["1stPosB"] = 3;feature["2ndPosB"] = 4;
//	feature["TWB"] = 5;
//
//	feature["1stWM"] = 6;feature["2ndWM"] = 7;
//	feature["TWM"] = 8;
//
//	feature["1stWS"] = 9;feature["2ndWS"] = 10;
//	feature["1stPosS"] = 11;feature["2ndPosS"] = 12;
//	feature["TWS"] = 13;
//	
//	for (map<string, int>::iterator it = feature.begin(); it != feature.end(); it++)
//	{
//		Name[it->second] = it->first;
//	}
//	
//
//	//����Ԥ����
//	cout << endl;
//	cout << "--------------------------------------����Ԥ����---------------------------------------------" << endl;
//	get_dataset();
//
//
//	//Ԥ���ʼ���˳��
//	cout << "--------------------------------------Ԥ��˳��-----------------------------------------------" << endl;
//	cout << "�������Խ��˳��(1<=&&<=" << n << ")��" << endl;
//
//	vector<int> order;
//	order.push_back(0);
//	//1 2 3 4 5 6 7 8 9 10 11 12 13
//
//	for (int i = 1; i <= n; i++)
//	{
//		int id;
//		cin >> id;
//		order.push_back(id);
//		
//		for (int pi = 1; pi < i; pi++)
//		{
//			Pre[id].insert(order[pi]);
//		}
//	}
//
//	//�������
//	for (int i = 1; i <= n; i++)
//	{
//		for (set<int>::iterator it = Pre[i].begin(); it != Pre[i].end(); it++)
//		{
//			cout << *it << "\t";
//		}
//		cout << endl;
//	}
//
//
//
//	//Ԥ������ȡֵ����
//	for (int id = 1; id <= 13; id++)
//	{
//		r[id] = av[id].size();
//	}
//
//
//	//����ѵ����
//	cout << "--------------------------------------����ѵ����---------------------------------------------" << endl;
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//
//
//	//k2����
//	cout << "--------------------------------------k2����-------------------------------------------------" << endl;
//	int limit;
//	cout << "����ÿ�����Խ��ĸ�����������ޣ�" << endl;
//	cin >> limit;
//	cout << "******************************************" << endl;
//	k2(limit);
//
//
//	//��ñ�Ҷ˹����
//	cout << "--------------------------------------�۲챴Ҷ˹����------------------------------------------" << endl;
//	//get_BN();
//	//�������
//	cout << "////////////////////////////////////////////////////////////" << endl;
//	cout << "/////////////////////////�������///////////////////////////" << endl;
//	cout << "////////////////////////////////////////////////////////////" << endl;
//	for (int id = 1; id <= 13; id++)
//	{
//		cout << Name[id] << " �����Խ�㣺" << endl;
//		for (set<int>::iterator it = Pa[id].begin(); it != Pa[id].end(); it++)
//		{
//			cout << Name[*it] << "\t\t";
//		}
//		cout << endl << "******************************************************" << endl;
//	}
//
//	return 0;
//}
