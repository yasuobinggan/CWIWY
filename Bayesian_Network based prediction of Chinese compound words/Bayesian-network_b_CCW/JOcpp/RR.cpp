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
//#include<cstdio>
//#include<cstdlib>
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
//vector<vector<string>> trainingset;//ѵ����
//int trainingsetsize;
//map< int, set<string> > av;//����ȡֵ
//
///*�������ʱ��� ST*/
////��������
//struct CPtableI
//{
//	int cnt;
//	double pro;
//	int boxsum;
//	CPtableI() {}
//	CPtableI(int _cnt)
//	{
//		cnt = _cnt;
//	}
//
//	CPtableI(int _cnt, int _boxsum)
//	{
//		cnt = _cnt;
//		pro = _boxsum;
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
//	//�������ʱ�
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
////��Ҷ˹�����������ܵ����Ը���
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
////�������ݼ���ȡ���ݵ�����(����Ԥ����)
//void get_dataset()
//{
//
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
//			cout << "��ǰ����id��" << it->first;// << "��ǰ����: " << BN[it->first].name;
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
//
///********************************construct_BN  ST*******************************************************************************************************/
///*****************construct_CPtable ST*********************/
////��õ�ǰ���Ե�����ɷ�̺(����MSWT)(����ͼ����ʹ��setȥ��)
//vector<int> get_condition_id(int id)
//{
//	vector<int> condition;
//	
//	if(id!=13)
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//
//	for (vector<Node>::iterator it = BN[id].child.begin(); it != BN[id].child.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//
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
//			curCPtable[curcon].curCPtableI[*it] = CPtableI(0,0);
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
//		cout << id << "\t" << Name[id] << "�������ʱ��������:";
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
//	Node WB1(1, "1stWB");Node WB2(2, "2ndWB");
//	Node PosB1(3, "1stPosB");Node PosB2(4, "2ndPosB");
//	Node TWB(5, "TWB");
//	
//	Node WM1(6, "1stWM");Node WM2(7, "2ndWM");
//	Node TWM(8, "TWM");
//	
//	Node WS1(9, "1stWS");Node WS2(10, "2ndWS");
//	Node PosS1(11, "1stPosS");Node PosS2(12, "2ndPosS");
//	Node TWS(13, "TWS");
//
//	//���������ϵ
//	
//	//MWST��ϵ��
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
//		construct_CPtable(id);
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
//	if (id != 13)
//		for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//		{
//			com.push_back(invec[it->id]);
//		}
//
//	for (vector<Node>::iterator it = BN[id].child.begin(); it != BN[id].child.end(); it++)
//	{
//		com.push_back(invec[it->id]);
//	}
//
//
//	//�������
//	cout << "�����Ƿ����: " << BN[id].CPtable.count(com) << "\t";
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
//	cout << endl;
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
//				//TODO
//				count_CPtable(id, invec);
//
//			}
//			//����ѵ����
//			
//			trainingset.push_back(invec);
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
//void train_CPtable(int id)
//{
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
//		
//					secondit->second.pro = (double)secondit->second.cnt / (double)it->second.sumcnt;
//					
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
//		cout << "������ظ���\t" << id << endl;
//		train_CPtable(id);
//		cout << "***************************************" << endl;
//	}
//}
///**************************************************train_CPtable ED*************************************************************************************/
//
//
//
////˫���ڴ������ܺ���
//void BN_CP_construct()
//{
//	cout << "*************************��ȷ����:ö������**************************************" << endl << endl;
//	//����Ԥ����
//	initProblem();
//	cout << "--------------------����Ԥ���� ��ǰ���Ե�ȡֵ:----------------------------------" << endl;
//	get_dataset();
//
//
//	//���������޻�ͼ+����
//	cout << "---------------------������Ҷ˹���罨������-------------------------------------" << endl;
//	
//	construct_BayesianNW();
//
//
//	//ѵ��(��ȷ����:ö������)
//	cout << "-----------------------------ѵ������������ʱ�-------------------------------------" << endl;
//	//(���������ʱ�+��Ե�ֲ�����м���)
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	cout << "ѵ������С:\t" << trainingsetsize << endl;
//	
//	//ѵ������
//	trainBN();
//
//	
//}
//
//
//
///*******************************************************RRtest ST***************************************************************************************/
////֤�ݱ����ṹ��
//struct Evi {
//	int E;
//	string e;
//	Evi() {}
//	Evi(int _E, string _e)
//	{
//		E = _E;
//		e = _e;
//	}
//};
//
//
////��ȡ��һ������
//vector<string> get_randomsample(vector<Evi> evidence)
//{
//	vector<string> temp;
//	for (vector<vector<string>>::iterator it = trainingset.begin(); it != trainingset.end(); it++)
//	{
//		vector<Evi>::iterator secondit;
//		for (secondit = evidence.begin(); secondit != evidence.end(); secondit++)
//		{
//			if ((*it)[secondit->E] != secondit->e)
//			{
//				break;
//			}
//		}
//		if (secondit == evidence.end())
//		{
//			temp = (*it);
//			(*it) = trainingset[0];
//			trainingset[0] = temp;
//
//			break;
//		}
//		/*
//		if ((*it)[E] == e)
//		{
//			temp = (*it);
//			(*it) = trainingset[0];
//			trainingset[0] = temp;
//
//			break;
//		}
//		*/
//	}
//	return trainingset[0];
//}
//
//
////��ȡ�����ı���
//vector<int> get_feature(vector<Evi> evidence)
//{
//	vector<int> feature;
//
//	for (int i = 1; i <= 13; i++)
//	{
//		vector<Evi>::iterator it;
//		for (it = evidence.begin(); it != evidence.end(); it++)
//		{
//			if (i == it->E)
//				break;
//		}
//		if (it == evidence.end())
//		{
//			feature.push_back(i);
//		}
//	}
//	return feature;
//}
//
//
////�������̶�
//struct CValue {
//	string value;
//	int boxsum;
//	CValue(){}
//	CValue(string _value,int _boxsum)
//	{
//		value = _value;
//		boxsum = _boxsum;
//	}
//};
//
//
//bool cmp(CValue a, CValue b)
//{
//	return a.boxsum < b.boxsum;
//}
//
//
////��������
//void Sampling(int id, vector<string> &cur)
//{
//	cout << "**********************************" << endl;
//	vector<int> curcondition = get_condition_id(id);
//	vector<string> com;
//
//	for (vector<int>::iterator it = curcondition.begin(); it != curcondition.end(); it++)
//	{
//		com.push_back(cur[*it]);
//	}
//
//	//TODO������Ϊ���̶�
//	//���ң�ֻ��ȡһ��ֵ
//	string maxvalue = "";
//	int maxpro = -1;
//	/*
//	for (map<string, CPtableI>::iterator it = BN[id].CPtable[com].curCPtableI.begin(); it != BN[id].CPtable[com].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxpro = it->second.pro;
//			maxvalue = it->first;
//			
//		}
//	}
//	*/
//	
//
//
//	//�������̶�
//	vector<CValue> box;
//	
//	int boxsum = 0;
//	for (map<string, CPtableI>::iterator it = BN[id].CPtable[com].curCPtableI.begin(); it != BN[id].CPtable[com].curCPtableI.end(); it++)
//	{
//		boxsum += it->second.cnt;
//		it->second.boxsum = boxsum;
//		box.push_back(CValue(it->first, boxsum));
//	}
//
//	sort(box.begin(), box.end(), cmp);
//
//	if (boxsum != 0)
//	{
//		int randomchose = rand() % boxsum + 1;
//		for (vector<CValue>::iterator it = box.begin(); it != box.end(); it++)
//		{
//			if (randomchose <= it->boxsum)
//			{
//				maxvalue = it->value;
//				break;
//			}
//		}
//		//��ֵ
//		cout << Name[id] << "���ĵ�ֵ" << maxvalue << endl;
//		cur[id] = maxvalue;
//	}
//	
//	
//}
//
//
////�������
//void RRtest()
//{
//	cout << "�����������" << endl;
//
//	int Q, E;
//	string q, e;
//	cout << "�����ѯ������� ��ѯ����ȡֵ��" << endl;
//	cin >> Q >> q;
//
//	cout << "����֤�ݱ������ ֤�ݱ���ȡֵ��" << endl;
//	vector<Evi> evidence;
//	while (cin >> E >> e)
//	{
//		evidence.push_back(Evi(E, e));
//	}
//	
//	//���ɱ���
//	unordered_map<string,int> valuecount;
//	for (set<string>::iterator it = av[Q].begin(); it != av[Q].end(); it++)
//	{
//		valuecount[*it] = 0;
//	}
//
//	
//	int mq = 0;
//
//	vector<int> feature = get_feature(evidence);
//
//	vector<string> head = get_randomsample(evidence);
//	
//	for (unordered_map<string, int>::iterator it = valuecount.begin(); it != valuecount.end(); it++)
//	{
//		if (head[Q] == it->first)
//		{
//			it->second++;
//			break;
//		}
//		
//	}
//
//	if (head[Q] == q)
//	{
//		mq++;
//	}
//
//	for (int i = 1; i < trainingset.size(); i++)
//	{
//		cout << endl << "��" << i + 1 << "������---------------------------------" << endl;
//		vector<string> cur = head;
//		for (vector<int>::iterator it = feature.begin(); it != feature.end(); it++)
//		{
//			Sampling(*it, cur);
//		}
//
//		//�������
//		cout << Name[Q] << ": " << q << "==" << cur[Q] << endl;
//
//		if (cur[Q] == q)
//		{
//			mq++;
//			cout << "mq����";
//		}
//
//		for (unordered_map<string, int>::iterator it = valuecount.begin(); it != valuecount.end(); it++)
//		{
//			if (cur[Q] == it->first)
//			{
//				it->second++;
//				break;
//			}
//
//		}
//
//		head = cur;
//		cout << endl;
//	}
//
//
//
//	//������
//	double pro = (double)mq / (double)trainingsetsize;
//	cout << "///////////////////////////////////////////////////" << endl;
//	cout << "�ƶϽ����" << endl;
//	cout << "P(" << Name[Q] << "=" << q << "|"; 
//	for (vector<Evi>::iterator secondit = evidence.begin(); secondit != evidence.end(); secondit++)
//	{
//		cout << Name[secondit->E] << "=" << secondit->e << " ";
//	}
//	cout << ")=" << pro << endl;
//	
//	
//	cout << "�������" << endl;
//	int outsum = 0;
//	for (unordered_map<string, int>::iterator it = valuecount.begin(); it != valuecount.end(); it++)
//	{
//		cout << it->second << "\t";
//		//outsum += it->second;
//		pro = (double)it->second / (double)trainingsetsize;
//		cout << "P(" << Name[Q] << "=" << it->first << "|";
//		for (vector<Evi>::iterator secondit = evidence.begin(); secondit != evidence.end(); secondit++)
//		{
//			cout << Name[secondit->E] << "=" << secondit->e << " ";
//		}
//		cout<<")=" << pro << endl;
//
//	}
//	cout << "SUM��" << outsum << endl;
//}
///*******************************************************RRtest ED***************************************************************************************/
//int main()
//{
//	
//	srand(time(NULL));//�������
//	BN_CP_construct();
//	RRtest();
//	
//	return 0;
//}
//
