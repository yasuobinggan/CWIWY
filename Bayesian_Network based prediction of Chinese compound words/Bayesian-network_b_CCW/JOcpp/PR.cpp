////�������޻�ͼ��˳��������
//
//
///**
//* ���ϸ��ʷֲ�:P(1st WB,2nd WB,1st PosB,2nd PosB,1st WM,2nd WM,1st WS,2nd WS,1st PosS,2nd PosS,TWB,TWM,TWS)
//*			   P(1st WB)P(2ndWB)P(1stPosB)P(2ndPosB)   * P(TWB |1st WB,2nd WB,1st PosB,2nd PosB)
//*		       P(1st WM|1st WB)P(2nd WM|2nd WB)        * P(TWM |1st WM,2nd WM)
//*		       P(1st WS|1st WM)P(2nd WS|2nd WM)P(1st PosS)P(2nd PosS)* P(TWS |1st WS,2nd WS,1st PosS,2nd PosS)
//*/
//
///**
//* �����Ը���:
//* 1��P(1st WB);
//* 2��P(2nd WB);
//* 3��P(1st PosB);
//* 4��P(2nd PosB);
//* 5��P(TWB)= P(TWB |1st WB,2nd WB,1st PosB,2nd PosB)*P(1stWB)*P(2ndWB)*P(1stPosB)*P(2ndPosB)
//* 6��P(1st WM)= P(1st WM|1st WB)*P(1st WB)
//* 7��P(2nd WM)= P(2nd WM|2nd WB)*P(2nd WB)
//* 8��P(TWM) = P(TWM |1st WM,2nd WM)*P(1st WM)*P(2nd WM)
//* 9��P(1st WS) = P(1st WS|1st WM)*P(1st WM)
//* 10��P(2nd WS) = P(2nd WS|2nd WM)*P(2nd WM)
//* 11��P(1st PosS)
//* 12��P(2nd PosS)
//* 13��P(TWS) = P(TWS |1st WS,2nd WS,1st PosS,2nd PosS)*P(1st WS)*P(2nd WS)*P(1st PosS)*P(2nd PosS)
//*/
//
//
////JOcpp
////#include<bits/stdc++.h>
//
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<string>
//#include<cstring>
//#include<map>
//#include<unordered_map>
//#include<set>
//#include<unordered_set>
//#include<ctime>
//
//using namespace std;
//
//
///*******************************************���ݽṹ ST*************************************************************************************************/
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
//vector<sample> trainingset;//ѵ����
//int trainingsetsize;
//map< int, set<string> > av;//����ȡֵ
//
//						   /*�������ʱ��� ST*/
//						   //��������
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
///*�������ʱ��� ED*/
//
//
//
//
////������Ҷ˹������:һ�����һ������������(��)
//struct Node {
//	int id;//���Ա��
//	string name;//������
//
//				//�������ʱ�
//	map<vector<string>, CPtableH> CPtable;
//
//	//��Ե�ֲ���
//	map<string, CPtableI> MD;
//
//	//��Ϊ���Ե���������
//	vector<Node> parent;
//	//���Եĺ�������
//	vector<Node> child;
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
//
//
//const int INF = 0x3f3f3f3f;//�����
//
//						   //��Ҷ˹�����������ܵ����Ը���
//const int maxn = 1005;
//
////�ڽӾ���洢��Ҷ˹����(ֻ�洢��ϵ)
//int G[maxn][maxn];
////Ŀ������
//vector<int> tar;
////�������
//bool visited[maxn];
////��������
//int d[maxn];
//
//
///*******************************************���ݽṹ ED*************************************************************************************************/
//
//
//
///********************************************����Ԥ���� ST**********************************************************************************************/
////�������ݼ���ȡ���ݵ�����(����Ԥ����)
//void get_dataset()
//{
//
//	ifstream fin;
//	fin.open("d:\\datasetG\\dataset.txt", ios::in);
//
//	if (fin)//��ȡ�����ݼ�
//	{
//		string line;//�����ȡһ���ı��ı���
//		vector<string> invec;//��ȡ�и����ַ�������
//		int count = 0;
//		map<string, int> cnt;
//		cnt.clear();
//
//		//���ж�ȡ
//		while (getline(fin, line))
//		{
//			if (line == "")
//				continue;
//			//cout << line << endl;
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
//				/******************************************/
//				//��inΪ��ʱ,��һ������ֵ���(����С��Ϊ��ʱ)
//				if (in == "")
//				{
//					in = "e";
//				}
//				/*****************************************/
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
//		}
//
//
//		//�������
//
//		for (map<int, set<string> >::iterator it = av.begin(); it != av.end(); it++)
//		{
//			cout << "��ǰid��" << it->first;// << "��ǰ����: " << BN[it->first].name;
//			cout << "��ǰ��С��" << it->second.size() << endl;
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
//
///********************************construct_BN  ST*******************************************************************************************************/
///*****************construct_CPtable ST*********************/
////��õ�������+�������Ա��
//vector<int> get_condition_id(int id)
//{
//	vector<int> condition;
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//	return condition;
//}
//
//
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
//
////�ܹ�������
//void construct_CPtable(int id)
//{
//	vector<int> condition = get_condition_id(id);
//
//
//	//����CPtable:
//	//����Ϊ��
//	if (condition.size() == 0)
//	{
//		return;
//	}
//	//������Ϊ��
//	else
//	{
//		int index = 0;//�±���Ʒ���
//		vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
//		curcon.clear();
//
//		cout << "�������ʱ��������:";
//
//		//dfs����
//		build_CPtable(id, condition, index, curcon, BN[id].CPtable);
//
//		cout << " \t�������ʱ��С: " << BN[id].CPtable.size() << endl;
//
//	}
//
//}
///*****************construct_CPtable ED*********************/
//
//
////������Ҷ˹����
//void construct_BayesianNW()
//{
//	//�������
//	Node temp(0, "temp");
//	Node WB1(1, "1stWB");
//	Node WB2(2, "2ndWB");
//	Node PosB1(3, "1stPosB");
//	Node PosB2(4, "2ndPosB");
//	Node TWB(5, "TWB");
//	Node WM1(6, "1stWM");
//	Node WM2(7, "2ndWM");
//	Node TWM(8, "TWM");
//	Node WS1(9, "1stWS");
//	Node WS2(10, "2ndWS");
//	Node PosS1(11, "1stPosS");
//	Node PosS2(12, "2ndPosS");
//	Node TWS(13, "TWS");
//
//	//���������ϵ
//	/*
//	MWST��ϵ��
//	PosB1.parent.push_back(WB1); WB1.child.push_back(PosB1);
//	WM1.parent.push_back(WS1); WS1.child.push_back(WM1);
//	PosS2.parent.push_back(WS1); WS1.child.push_back(PosS2);
//	PosB2.parent.push_back(WB2); WB2.child.push_back(PosB2);
//	TWB.parent.push_back(WB2); WB2.child.push_back(TWB);
//	WB2.parent.push_back(WM2); WM2.child.push_back(WB2);
//	WM2.parent.push_back(TWS); TWS.child.push_back(WM2);
//	TWM.parent.push_back(TWS); TWS.child.push_back(TWM);
//	WS2.parent.push_back(TWS); TWS.child.push_back(WS2);
//	PosS1.parent.push_back(TWS); TWS.child.push_back(PosS1);
//	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
//	WB1.child.push_back(WS1); WS1.parent.push_back(WB1);
//	*/
//
//	WB1.child.push_back(TWB); TWB.parent.push_back(WB1);
//	WB2.child.push_back(TWB); TWB.parent.push_back(WB2);
//	PosB1.child.push_back(TWB); TWB.parent.push_back(PosB1);
//	PosB2.child.push_back(TWB); TWB.parent.push_back(PosB2);
//
//	WB1.child.push_back(WM1); WM1.parent.push_back(WB1);
//	WB2.child.push_back(WM2); WM2.parent.push_back(WB2);
//	TWB.child.push_back(TWM); TWM.parent.push_back(TWB);
//	WM1.child.push_back(TWM); TWM.parent.push_back(WM1);
//	WM2.child.push_back(TWM); TWM.parent.push_back(WM2);
//
//
//	//TWM.child.push_back(TWS); TWS.parent.push_back(TWM);
//	WM1.child.push_back(WS1); WS1.parent.push_back(WM1);
//	WM2.child.push_back(WS2); WS2.parent.push_back(WM2);
//	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
//	WS2.child.push_back(TWS); TWS.parent.push_back(WS2);
//	PosS1.child.push_back(TWS); TWS.parent.push_back(PosS1);
//	PosS2.child.push_back(TWS); TWS.parent.push_back(PosS2);
//
//
//	//�����뱴Ҷ˹����(�Ժ���ŷ���+����)
//	BN.push_back(temp);
//	BN.push_back(WB1); BN.push_back(WB2);
//	BN.push_back(PosB1); BN.push_back(PosB2);
//	BN.push_back(TWB);
//	//
//	BN.push_back(WM1); BN.push_back(WM2);
//	BN.push_back(TWM);
//	//
//	BN.push_back(WS1); BN.push_back(WS2);
//	BN.push_back(PosS1); BN.push_back(PosS2);
//	BN.push_back(TWS);
//
//	//����:
//	//����һ: ÿ�������������ʱ�,��Ե�ֲ���(ֻ���ռ䲻��������)
//	for (int id = 1; id <= 13; id++)
//	{
//		cout << "id: " << id << "��������: " << BN[id].name << endl;
//		if (id == 5 || id == 8 || id == 13)
//		{
//			construct_CPtable(id);
//		}
//		//����MD:ѭ������Ŀ������ȡֵ
//		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//		{
//			BN[id].MD[*it] = CPtableI(0, 0);
//		}
//	}
//
//}
///*****************************construct_BN ED***********************************************************************************************************/
//
//
//
///********************************get_Trainingset  ST****************************************************************************************************/
////��������
//void count_CPtable(int id, vector<string> invec)
//{
//	//����������ȡ��ǰ�������->�������ʱ�
//
//	vector<string> com;
//
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		//cout << invec[it->id] << " ";
//		com.push_back(invec[it->id]);
//	}
//
//
//	cout << "sumcnt:" << BN[id].CPtable[com].sumcnt << "\t";
//	++BN[id].CPtable[com].sumcnt;
//	cout << "Gsumcnt:" << BN[id].CPtable[com].sumcnt << "\t";
//
//	cout << "cnt:" << BN[id].CPtable[com].curCPtableI[invec[id]].cnt << "\t";
//	++BN[id].CPtable[com].curCPtableI[invec[id]].cnt;
//	cout << "Gcnt:" << BN[id].CPtable[com].curCPtableI[invec[id]].cnt << "\t";
//
//
//}
//
//
////��ȡѵ����
//void get_trainingset()
//{
//	trainingset.clear();
//	//��ѵ����(�ȶ�.txt�ļ�)
//	ifstream fin;
//	fin.open("d:\\datasetG\\trainingdataset.txt", ios::in);
//
//	if (fin)//��ȡ�����ݼ�
//	{
//		string line;//�����ȡһ���ı��ı���
//		vector<string> invec;//��ȡ�и����ַ�������
//		int count = 0;
//		map<string, int> cnt;
//		cnt.clear();
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
//			//�������ݼ���
//			for (int id = 1; id <= 13; id++)
//			{
//				//��Ե�ֲ������
//				BN[id].MD[invec[id]].cnt++;
//
//				//�������ʱ����
//				if (BN[id].parent.size() != 0)
//				{
//					if (id == 5 || id == 8 || id == 13)
//					{
//						count_CPtable(id, invec);
//					}
//
//
//				}
//
//			}
//			//����ѵ����
//			sample s = sample(invec[0], invec[1], invec[2], invec[3], invec[4], invec[5], invec[6], invec[7], invec[8], invec[9], invec[10], invec[11], invec[12], invec[13], invec[14]);
//			trainingset.push_back(s);
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
///********************************get_Trainingset  ED****************************************************************************************************/
//
//
//
///**************************************************train_CPtable ST*************************************************************************************/
////���и��ʼ���
//void train_CPtable_MD(int id)
//{
//	//��Ե�ֲ�����
//	for (map<string, CPtableI>::iterator it = BN[id].MD.begin(); it != BN[id].MD.end(); it++)
//	{
//		it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
//		//cout << " " << id << " " << it->second.pro<<endl;
//	}
//	//��������
//	if (BN[id].parent.size() != 0)
//	{
//
//		for (map<vector<string>, CPtableH>::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//
//			for (map<string, CPtableI>::iterator secondit = it->second.curCPtableI.begin(); secondit != it->second.curCPtableI.end(); secondit++)
//			{
//
//				if (it->second.sumcnt != 0)
//				{
//					//cout << secondit->second.cnt << "\t" << it->second.sumcnt << endl;
//					secondit->second.pro = (double)secondit->second.cnt / (double)it->second.sumcnt;
//					//cout << "cur: " << secondit->second.pro << endl;
//				}
//				else
//				{
//					secondit->second.pro = (double)1 / (double)av[id].size();
//				}
//
//
//			}
//		}
//	}
//
//
//}
//
//
////��ѵ������
//void trainBN()
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		cout << "�������\t" << id << endl;
//		train_CPtable_MD(id);
//		cout << "***************************************" << endl;
//	}
//}
///**************************************************train_CPtable ED*************************************************************************************/
//
//
//
///**************************************************test(�ƶ�) ST****************************************************************************************/
//vector<string> testsample(vector<string> invec)
//{
//	vector<string> hypo;//����
//
//						//ƥ��ʻ����
//						//��¼
//	vector<string> comTWB;
//
//	for (vector<Node>::iterator it = BN[5].parent.begin(); it != BN[5].parent.end(); it++)
//	{
//		comTWB.push_back(invec[it->id]);
//	}
//	//ƥ��
//	string maxvalue;
//	double maxpro = -1.0;
//
//	for (map<string, CPtableI>::iterator it = BN[5].CPtable[comTWB].curCPtableI.begin(); it != BN[5].CPtable[comTWB].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxvalue = it->first;
//			maxpro = it->second.pro;
//		}
//	}
//
//	hypo.push_back(maxvalue);
//
//	//ƥ��ʻ�����
//	//��¼
//	vector<string> comTWM;
//
//	for (vector<Node>::iterator it = BN[8].parent.begin(); it != BN[8].parent.end(); it++)
//	{
//		comTWM.push_back(invec[it->id]);
//	}
//
//	//ƥ��
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (map<string, CPtableI>::iterator it = BN[8].CPtable[comTWM].curCPtableI.begin(); it != BN[8].CPtable[comTWM].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxvalue = it->first;
//			maxpro = it->second.pro;
//		}
//	}
//
//	hypo.push_back(maxvalue);
//
//	//ƥ��ʻ�С��
//	//��¼
//	vector<string> comTWS;
//
//	for (vector<Node>::iterator it = BN[13].parent.begin(); it != BN[13].parent.end(); it++)
//	{
//		comTWS.push_back(invec[it->id]);
//	}
//
//	//ƥ��
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (map<string, CPtableI>::iterator it = BN[13].CPtable[comTWS].curCPtableI.begin(); it != BN[13].CPtable[comTWS].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxvalue = it->first;
//			maxpro = it->second.pro;
//		}
//	}
//
//	hypo.push_back(maxvalue);
//
//	return hypo;
//}
//
//
//void test()
//{
//
//	//��ѯĿ������������ʱ�
//	ifstream fin;
//	fin.open("d:\\dataset\\testdataset.txt", ios::in);
//
//
//
//	if (fin)//��ȡ�����ݼ�
//	{
//		int testsize = 0;//ѵ������С
//
//		string line;//�����ȡһ���ı��ı���
//		vector<string> invec;//��ȡ�и����ַ�������
//
//							 //��¼׼ȷ��
//		int sumcount = 0;
//
//		double expection = 0;
//
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
//				invec.push_back(in);
//				i = j + 1;
//			}
//
//			//�ƶ�+�ƶϽ��
//			vector<string> hypo = testsample(invec);
//
//
//			//�ʻ����
//			cout << "�ʻ�����׼ȡֵ: " << invec[5] << " ";
//			cout << "�ƶϴʻ����ȡֵ" << hypo[0] << "\t|\t";
//
//
//			//�ʻ�����
//			cout << "�ʻ������׼ȡֵ: " << invec[8] << " ";
//			cout << "�ƶϴʻ�����ȡֵ" << hypo[1] << "\t|\t";
//
//			//�ʻ�С��
//			cout << "�ʻ�С���׼ȡֵ: " << invec[13] << " ";
//			cout << "�ƶϴʻ�С��ȡֵ" << hypo[2] << endl;
//
//
//
//			//��������
//			double curexpection = 0;
//			if (invec[5] == hypo[0])
//			{
//				curexpection += 1;
//			}
//			if (invec[8] == hypo[1])
//			{
//				curexpection += 1;
//			}
//			if (invec[13] == hypo[2])
//			{
//				curexpection += 1;
//			}
//
//			curexpection /= 3;
//			expection += curexpection;
//
//
//			//ƥ�����
//			if (invec[5] == hypo[0] && invec[8] == hypo[1] && invec[13] == hypo[2])
//			{
//				sumcount++;
//			}
//
//
//			++testsize;
//		}
//
//		//���ģ�͵�׼ȷ��,����
//		cout << endl << "********************************************************************" << endl;
//		cout << "��ǰģ�͵���ȫ׼ȷ��: " << (double)sumcount / (double)testsize << endl;
//		cout << "��ǰģ�͵�����: " << ((double)1 / (double)testsize) * expection << endl;
//
//		fin.close();
//
//	}
//	else
//		cout << "dataset doesn't exist!" << endl;
//}
///**************************************************test(�ƶ�) ED****************************************************************************************/
//
//
//void initProblem()
//{
//	//��ʼ�����Ա��
//	feature["temp"] = 0;
//	feature["1stWB"] = 1; feature["2ndWB"] = 2;
//	feature["1stPosB"] = 3; feature["2ndPosB"] = 4;
//	feature["TWB"] = 5;
//
//	feature["1stWM"] = 6; feature["2ndWM"] = 7;
//	feature["TWM"] = 8;
//
//	feature["1stWS"] = 9; feature["2ndWS"] = 10;
//	feature["1stPosS"] = 11; feature["2ndPosS"] = 12;
//	feature["TWS"] = 13;
//
//	for (map<string, int>::iterator it = feature.begin(); it != feature.end(); it++)
//	{
//		Name[it->second] = it->first;
//	}
//}
//
//
////˫���ڴ������ܺ���
//void BN_CP_construct()
//{
//	cout << "*************************��ȷ����:ö������**************************************" << endl << endl;
//	//����Ԥ����
//	cout << "--------------------����Ԥ���� ��ǰ���Ե�ȡֵ:----------------------------------" << endl;
//	get_dataset();
//
//
//	//���������޻�ͼ+����
//	cout << "---------------------������Ҷ˹���罨������-------------------------------------" << endl;
//	tar.push_back(5); tar.push_back(8); tar.push_back(13);
//	construct_BayesianNW();
//
//
//	//ѵ��(��ȷ����:ö������)
//	cout << "-----------------------------ѵ���������ʱ�-------------------------------------" << endl;
//	//(���������ʱ�+��Ե�ֲ�����м���)
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	cout << "ѵ������С:\t" << trainingsetsize << endl;
//	//ѵ������
//	trainBN();
//
//	//�ƶ�
//	cout << "-----------------------------���Լ��ƶ�-----------------------------------------" << endl;
//	clock_t start = clock();
//	test();
//	clock_t end = clock();
//
//	cout << "Running Time��" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
//}
//
//
///**************************************************������Ԫ ST****************************************************************************************/
////�����ṹ��
//struct Function {
//
//	unordered_set<int> label;//���������ı��
//
//
//	bool flag;//trueΪ���ʺ���
//	int head;//��¼���ʺ�����Ŀ��
//	map<vector<string>, double> value;//�Ǹ��ʺ���
//
//	Function() {}
//	Function(bool _flag, int _head)
//	{
//		flag = _flag;
//		head = _head;
//	}
//
//};
//
//vector<Function> Fset;//��������
//
//
//					  //��ʼ����������
//void initFset()
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		//��Ϊ���ʺ���
//		Function curF(true, id);
//		cout << "HEAD: " << id;
//		curF.label.insert(id);
//
//		for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//		{
//			cout << "\t" << it->id;
//			curF.label.insert(it->id);
//		}
//		cout << endl;
//	}
//}
//
//
//vector<int> get_order(int st, int E, int Q)
//{
//	//d����ĺ���Ϊ���ڽ��ı������
//	fill(d, d + maxn, 0);
//	stack<int> s;
//	vector<int> order;
//
//	d[st] = 1;
//
//	for (int id = 1; id <= 13; id++)
//	{
//		int MAX = 0;
//		int maxi;
//
//		for (int u = 1; u <= 13; u++)
//		{
//			if (d[u] > MAX && visited[u] == false)
//			{
//				MAX = d[u];
//				maxi = u;
//			}
//		}
//
//
//		//cout<<"cur��"<<maxi<<"\t��ǰ���ڸ�����"<<d[maxi]<<endl;
//		if (maxi != E && maxi != Q)
//		{
//			s.push(maxi);
//		}
//		visited[maxi] = true;
//
//
//		//cout<<"����"<<endl;
//		for (int v = 1; v <= 13; v++)
//		{
//			if (visited[v] == false && G[maxi][v] == 1)
//			{
//				//cout<<v<<"\t";
//				d[v]++;
//			}
//		}
//		cout << endl;
//	}
//
//	//ջ����
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		order.push_back(s.top());
//		s.pop();
//	}
//
//
//	return order;
//}
//
////FsetΪ��������
//void Elim(int Z)
//{
//	vector<Function> proFset;
//	vector<Function> curFset;
//
//	for (vector<Function>::iterator it = Fset.begin(); it != Fset.end(); it++)
//	{
//		if (it->label.find(Z) != it->label.end())
//		{
//			proFset.push_back(*it);
//		}
//		else
//		{
//			curFset.push_back(*it);
//		}
//	}
//	//��proFset���� һ�� ����
//
//
//	Fset = curFset;
//}
//
//
//void VE(int E, string e, int Q, vector<int> order)
//{
//	while (!order.empty())
//	{
//		int Z = order.front();
//		vector<int>::iterator it = order.begin();
//		order.erase(it);
//
//		Elim(Z);
//	}
//	//TODO
//	//���
//
//}
//
//
//void PRtest()
//{
//	memset(G, 0, sizeof(G));
//	memset(visited, false, sizeof(visited));
//
//	//������ϵ��������ͼ
//	G[1][5] = 1; G[5][1] = 1;
//	G[2][5] = 1; G[5][2] = 1;
//	G[3][5] = 1; G[5][3] = 1;
//	G[4][5] = 1; G[5][4] = 1;
//
//	G[1][6] = 1; G[6][1] = 1;
//	G[2][7] = 1; G[7][2] = 1;
//	G[5][8] = 1; G[8][5] = 1;
//	G[6][8] = 1; G[8][6] = 1;
//	G[7][8] = 1; G[8][7] = 1;
//
//	G[6][9] = 1; G[9][6] = 1;
//	G[7][10] = 1; G[10][7] = 1;
//	G[9][13] = 1; G[13][9] = 1;
//	G[10][13] = 1; G[13][10] = 1;
//	G[11][13] = 1; G[13][11] = 1;
//	G[12][13] = 1; G[13][12] = 1;
//
//	int E; string e;
//	int Q;
//
//	cout << "����֤�ݱ����ı�ź�ȡֵ���ο�����Ԥ�������ݣ���" << endl;
//	cin >> E >> e;
//	cout << "�����ѯ�����ı�ţ�" << endl;
//	cin >> Q;
//
//	//��ʼ������
//	initFset();
//	//��ʼ����Ԫ˳��
//	int st;
//	while (true)
//	{
//		st = rand() % 13 + 1;
//		if (st != E || st != Q)
//			break;
//	}
//	vector<int> order = get_order(st, E, Q);
//	//������Ԫ
//	VE(E, e, Q, order);
//
//}
///**************************************************������Ԫ ED****************************************************************************************/
//
//
//
//int main()
//{
//
//	srand(time(NULL));//�������
//	BN_CP_construct();
//	//PRtest();
//
//	return 0;
//}
//
