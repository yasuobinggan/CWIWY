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
//#include<iostream>
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
//using namespace std;
//
///*******************************************���ݽṹ ST*************************************************************************************************/
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
//		s_1stWB = a;
//		s_2ndWB = b;
//		s_1stPosB = c;
//		s_2ndPosB = d;
//		s_TWB = e;
//		s_1stWM = f;
//		s_2ndWM = g;
//		s_TWM = h;
//		s_1stWS = i;
//		s_2ndWS = j;
//		s_1stPosS = k;
//		s_2ndPosS = l;
//		s_TWS = m;
//		mode = n;
//	}
//};
//
//vector<sample> trainingset;//ѵ����
//int trainingsetsize;
//map<int, set<string>> av;//����ȡֵ
//
///*�������ʱ��� ST*/
////ͨ�ñ���
//struct CPtableI
//{
//	int count;
//	double pro;
//	CPtableI() {}
//	CPtableI(int _count)
//	{
//		count = _count;
//	}
//	CPtableI(int _count, double _pro)
//	{
//		count = _count;
//		pro = _pro;
//	}
//};
///*�������ʱ��� ED*/
////������������һ�����
//struct Treenode {
//	string name;//������ƣ��������ƣ�
//	double id;//����ţ����Ա�ţ�
//
//	bool flag;//����Ƿ�ΪҶ�ڵ㣨Ҷ�ڵ�Ϊ·���ϵ�Ŀ���㣩;�ж��ǲ��Ǹ��ʽ��
//	int value;//��һ���֧��ȡֵ
//
//	double conpro;//���ʽ��洢�������ʵ�����
//	int pro;//���ʽ��洢���ո��ʵ�����
//
//	vector<int> path;//�ڵ�洢��·���ϵĽ�����Ե�ȡֵ
//	vector<Treenode> child;//���ӽ��
//};
//
////������Ҷ˹������:һ�����һ������������(��)
//struct Node {
//	int id;//���Ա��
//	string name;//������
//
//	//�������ʱ�
//	map<vector<string>, CPtableI> CPtable;
//	//map<CPtableH, map<vector<string>, CPtableI>> CPtable;
//	//map<CPtableH, unordered_map<string, CPtableI>> CPtable;
//
//	//����������
//	Treenode CPtree;
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
///*******************************************���ݽṹ ED*************************************************************************************************/
//
//
//
///********************************************����Ԥ���� ST*************************************************************************************************/
////�������ݼ���ȡ���ݵ�����(����Ԥ����)
//void get_dataset()
//{
//
//	ifstream fin;
//	fin.open("d:\\dataset.txt", ios::in);
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
//		for (map<int, set<string>>::iterator it = av.begin(); it != av.end(); it++)
//		{
//			cout << "��ǰid��" << it->first;// << "��ǰ����: " << BN[it->first].name;
//			cout << "��ǰ��С��"<<it->second.size() << endl;
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
///********************************************����Ԥ���� ED*************************************************************************************************/
//
//
//
///********************************construct_BN  ST*******************************************************************************************************/
///*
////�������ʱ�ĵ�һ����ͷ
//struct CPtableH {
//	string tarval;//Ŀ��ȡֵ
//	int tarcount;//Ŀ���Ե����
//	double tarpro;//Ŀ���Ե����
//	CPtableH(){}
//	CPtableH(string _tarval, int _tarcount,double _tarpro)
//	{
//		tarval = _tarval;
//		tarcount = _tarcount;
//		tarpro = _tarpro;
//	}
//	friend bool operator <(CPtableH a, CPtableH b)
//	{
//		return a.tarval < b.tarval;
//	}
//};
////�������ʱ�ڶ�����ͷ
////�������ʱ�ڶ�������
//struct CPtableI
//{
//	int concount;//��������
//	double conpro;//��������
//	CPtableI(){}
//	CPtableI(int _concount, double _conpro)
//	{
//		concount = _concount;
//		conpro = _conpro;
//	}
//};
//*/
//
///*
////��õ������Ե��������Ա��
//vector<int> get_condition_id(int id)
//{
//vector<int> condition;
//for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//{
//condition.push_back(it->id);
//}
//return condition;
//}
//
////dfs�������ɶ�������(bfs���ɶ�������)
//void build_CPtableI(vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &secondCPtable)
//{
//if (index == condition.size())
//{
//secondCPtable[curcon] = CPtableI(0, 0);
//return;
//}
//
////cout << condition[index] << endl;
//
//for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//{
//curcon.push_back(*it);
//build_CPtableI(condition, index + 1, curcon, secondCPtable);
//curcon.pop_back();
//}
//}
//
////�ܹ�������
//void construct_CPtable(int id)
//{
//vector<int> condition = get_condition_id(id);
//
////��������Ϊ��
//if (condition.size() == 0)
//{
//map<vector<string>, CPtableI> secondCPtable;//��������
////ѭ������Ŀ������ȡֵ
//for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//{
//BN[id].CPtable[CPtableH(*it, 0, 0)] = secondCPtable;//��������
//}
//}
////�������Ϊ��
//else
//{
////������������
//int index = 0;//�±���Ʒ���
//vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
//map<vector<string>, CPtableI> secondCPtable;//��������
//curcon.clear(); secondCPtable.clear();
////�ݹ麯��
//build_CPtableI(condition, index, curcon, secondCPtable);
//
////ѭ������Ŀ������ȡֵ
//for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//{
//BN[id].CPtable[CPtableH(*it, 0, 0)] = secondCPtable;//��������
//}
//}
//
//}
//*/
//
///*****************construct_CPtable ST*********************/
////��õ�������+�������Ա��
//vector<int> get_condition_id(int id)
//{
//	vector<int> condition;
//	condition.push_back(id);
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//	return condition;
//}
//
////dfs���������������ʱ����
///*
//void build_CPtableH(vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &curCPtable)
//{
//	if (index == condition.size())
//	{
//		curCPtable[curcon] = CPtableI(0, 0);
//
//		//�������
//		for (vector<string>::iterator itstring = curcon.begin(); itstring != curcon.end(); itstring++)
//		{
//			cout << *itstring << "\t";
//		}
//		cout << endl;
//
//
//		return;
//	}
//
//	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//	{
//		curcon.push_back(*it);
//		build_CPtableH(condition, index + 1, curcon, curCPtable);
//		curcon.pop_back();
//	}
//}
//*/
//
////bfs�����������ʱ����
//void build_CPtableH(vector<int> condition, int index, vector<string> rootcon, map<vector<string>, CPtableI> &curCPtable)
//{
//	queue<vector<string>> q;
//	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//	{
//		rootcon.push_back(*it);
//		q.push(rootcon);
//		rootcon.pop_back();
//	}
//	while (!q.empty())
//	{
//		vector<string> curcon = q.front();
//		q.pop();
//		if (curcon.size() != condition.size())
//		{
//			for (set<string>::iterator it = av[condition[curcon.size()]].begin(); it != av[condition[curcon.size()]].end(); it++)
//			{
//				curcon.push_back(*it);
//				q.push(curcon);
//				curcon.pop_back();
//			}
//		}
//
//		else
//		{
//			curCPtable[curcon] = CPtableI(0);
//			//�������
//			/*
//			for (vector<string>::iterator it = curcon.begin(); it != curcon.end(); it++)
//			{
//				cout << *it << "\t";
//			}
//			cout << endl;
//			*/
//		}
//
//	}
//}
//
////�ܹ�������
//void construct_CPtable(int id)
//{
//	vector<int> condition = get_condition_id(id);
//
//	//����MD:ѭ������Ŀ������ȡֵ
//	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//	{
//		BN[id].MD[*it] = CPtableI(0, 0);
//	}
//
//	//����CPtable:
//	//����Ϊ��
//	if (condition.size() == 1)
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
//		//dfs����
//		//build_CPtableH(condition, index, curcon, BN[id].CPtable);
//
//		//bfs����
//		build_CPtableH(condition, index, curcon, BN[id].CPtable);
//
//		cout << " \t�������ʱ��С: " << BN[id].CPtable.size() << endl;
//
//	}
//
//}
///*****************construct_CPtable ED*********************/
//
///*****************construct_CPtree ST**********************/
///*
//vector<int> get_condition(int id)
//{
//	vector<int> condition;
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//	return condition;
//}
//*/
///*****************construct_Cptree ED**********************/
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
//	WM1.child.push_back(WS1); WS1.parent.push_back(WM1);
//	WM2.child.push_back(WS2); WS2.parent.push_back(WM2);
//	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
//	WS2.child.push_back(TWS); TWS.parent.push_back(WS2);
//	PosS1.child.push_back(TWS); TWS.parent.push_back(PosS1);
//	PosS2.child.push_back(TWS); TWS.parent.push_back(PosS2);
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
//		construct_CPtable(id);
//		/*
//		if (BN[id].CPtable.size() != 0)
//		{
//
//		cout << "id: " << id << "��������: " << BN[id].name << endl;
//		for (map<vector<string>, CPtableI>::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//		vector<string> curstring = it->first;
//		for (vector<string>::iterator itstring = curstring.begin(); itstring != curstring.end(); itstring++)
//		{
//		cout << *itstring << "\t";
//		}
//		cout << endl;
//		}
//		}
//		*/
//	}
//	//������: ÿ����������������,��Ե�ֲ���(ֻ���ռ䲻��������)
//	/*
//	for (int id = 1; id <= 13; id++)
//	{
//
//	}
//	*/
//
//}
///*****************************construct_BN ED***********************************************************************************************************/
//
//
//
///********************************get_Trainingset  ST****************************************************************************************************/
////��������
//void count_CPtable_MD(int id, vector<string> invec)
//{
//	//��Ե�ֲ���
//	BN[id].MD[invec[id]].count++;
//
//	//����������ȡ->�������ʱ�
//	cout <<BN[id].name<< " ����������ȡ��ȡֵ: " << endl;
//	if (BN[id].parent.size() != 0)
//	{
//		vector<string> com;
//		cout << invec[id] << "\t";
//		com.push_back(invec[id]);
//		for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//		{
//			cout << invec[it->id] << "\t";
//			com.push_back(invec[it->id]);
//		}
//		cout <<"����: "<< BN[id].CPtable.count(com) ;
//
//		BN[id].CPtable[com].count++;
//
//		cout <<"\t" << BN[id].CPtable[com].count;
//
//		cout << endl;
//
//	}
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
//	fin.open("d:\\trainingdataset.txt", ios::in);
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
//			//��ȡÿ�����Խ���ȡֵ
//			for (int i = 1; i <= 14; i++)
//			{
//				if (invec[i].size() <= 2)
//					av[i].insert(invec[i]);
//			}
//
//			//�������ݼ���
//			for (int id = 1; id <= 13; id++)
//			{
//				cout << "********************************************" << endl;
//				count_CPtable_MD(id, invec);
//				cout << "********************************************" << endl;
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
//		it->second.pro = (double)it->second.count / (double)trainingsetsize;
//		//cout << " " << id << " " << it->second.pro<<endl;
//	}
//	if (BN[id].parent.size() != 0)
//	{
//		//�������ʷֲ�
//		for (map<vector<string>, CPtableI>::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//			it->second.pro = (double)it->second.count / (double)trainingsetsize;
//			if (it->second.count != 0)
//			{
//
//				//double a = it->second.count;
//				//double b = trainingsetsize;
//				//cout << a / b;
//
//				//cout<<it->second.count<<" "<<trainingsetsize<<" "<<it->second.pro<<endl;
//
//			}
//
//		}
//	}
//
//
//}
//
////��ѵ������
//void trainBN()
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		train_CPtable_MD(id);
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
//	//ƥ��ʻ����
//	//��¼
//	vector<vector<string>> comTWB;
//
//	for (set<string>::iterator it = av[5].begin(); it != av[5].end(); it++)
//	{
//		vector<string> curcomTWB;
//
//		curcomTWB.push_back(*it);
//		for (vector<Node>::iterator secondit = BN[5].parent.begin(); secondit != BN[5].parent.end(); secondit++)
//		{
//			curcomTWB.push_back(invec[secondit->id]);
//		}
//		comTWB.push_back(curcomTWB);
//	}
//	//ƥ��
//	string maxvalue;
//	double maxpro = -1.0;
//
//	for (vector<vector<string>>::iterator it = comTWB.begin(); it != comTWB.end(); it++)
//	{
//		if (BN[5].CPtable[*it].pro > maxpro)
//		{
//			maxvalue = (*it)[0];
//			maxpro = BN[5].CPtable[*it].pro;
//		}
//	}
//	hypo.push_back(maxvalue);
//
//
//
//	//ƥ��ʻ�����
//	//��¼
//	vector<vector<string>> comTWM;
//
//	for (set<string>::iterator it = av[8].begin(); it != av[8].end(); it++)
//	{
//		vector<string> curcomTWM;
//
//		curcomTWM.push_back(*it);
//		for (vector<Node>::iterator secondit = BN[8].parent.begin(); secondit != BN[8].parent.end(); secondit++)
//		{
//			curcomTWM.push_back(invec[secondit->id]);
//		}
//		comTWM.push_back(curcomTWM);
//	}
//	//ƥ��
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (vector<vector<string>>::iterator it = comTWM.begin(); it != comTWM.end(); it++)
//	{
//		if (BN[8].CPtable[*it].pro > maxpro)
//		{
//			maxvalue = (*it)[0];
//			maxpro = BN[8].CPtable[*it].pro;
//		}
//	}
//	hypo.push_back(maxvalue);
//
//
//	//ƥ��ʻ�С��
//	//��¼
//	vector<vector<string>> comTWS;
//
//	for (set<string>::iterator it = av[13].begin(); it != av[13].end(); it++)
//	{
//		vector<string> curcomTWS;
//
//		curcomTWS.push_back(*it);
//		for (vector<Node>::iterator secondit = BN[13].parent.begin(); secondit != BN[13].parent.end(); secondit++)
//		{
//			curcomTWS.push_back(invec[secondit->id]);
//		}
//		comTWS.push_back(curcomTWS);
//	}
//	//ƥ��
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (vector<vector<string>>::iterator it = comTWS.begin(); it != comTWS.end(); it++)
//	{
//		if (BN[13].CPtable[*it].pro > maxpro)
//		{
//			maxvalue = (*it)[0];
//			maxpro = BN[13].CPtable[*it].pro;
//		}
//	}
//	hypo.push_back(maxvalue);
//
//	return hypo;
//}
//
//void test()
//{
//	cout << "--------------------------���Լ��ƶ�----------------------------------" << endl;
//
//	//��ѯĿ������������ʱ�
//	ifstream fin;
//	fin.open("d:\\testdataset.txt", ios::in);
//
//	//��¼׼ȷ��
//	int count = 0;
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
//			//�ƶ�+�ƶϽ��
//			vector<string> hypo=testsample(invec);
//
//
//			//�ʻ����
//			cout << "�ʻ�����׼ȡֵ: " << invec[5] << " ";
//			cout << "�ƶϴʻ����ȡֵ" << hypo[0] << "\t|\t";
//
//
//			//�ʻ�����
//			cout << "�ʻ������׼ȡֵ: " << invec[8] << " ";
//			cout << "�ƶϴʻ�����ȡֵ" << hypo[1]<<"\t|\t";
//
//			//�ʻ�С��
//			cout << "�ʻ�С���׼ȡֵ: " << invec[13] << " ";
//			cout << "�ƶϴʻ�С��ȡֵ" << hypo[2]<<endl;
//
//			if (invec[5] == hypo[0] && invec[8] == hypo[1] && invec[13] == hypo[2])
//			{
//				count++;
//			}
//
//
//		}
//
//		cout << endl << "********************************************************************" << endl;
//		cout << "��ǰģ�͵�׼ȷ��: " << (double)count / (double)trainingsetsize << endl;
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
//
///*****************************testout ���������� �������ST*********************************************************************************************/
///*
////���ÿ�����Խ����������ʱ���
//void travelCPtable(int id)
//{
//
//	//��������Ϊ��
//	if ( BN[id].parent.size() == 0 )
//		return;
//
//	map<CPtableH, map<vector<string>, CPtableI>>::iterator it = BN[id].CPtable.begin();
//	map<vector<string>, CPtableI> secondmap = it->second;
//
//	for (map<vector<string>, CPtableI>::iterator secondit = secondmap.begin(); secondit != secondmap.end(); secondit++)
//	{
//		for (int i = 0; i < secondit->first.size(); i++)
//		{
//			cout << secondit->first[i] << "\t";
//		}
//		cout << endl;
//	}
//
//	//map<vector<string>,CPtableI>::iterator secondit = it->second;
//}
//void testout()
//{
//	cout << "�������!" << endl;
//
//	for (vector<Node>::iterator it = BN.begin(); it != BN.end(); it++)
//	{
//		if (it->id != 0)
//		{
//			cout << "��ǰid: " << it->id << "��ǰ����: " << it->name<<endl;
//			cout << "����ڶ�������" << endl;
//			travelCPtable(it->id);
//			cout << "*********************************" << endl;
//		}
//
//	}
//}
//*/
///******************************testout ���������� �������ED********************************************************************************************/
//
//
//
//int main()
//{
//	//����Ԥ����
//	cout << "����Ԥ���� ��ǰ���Ե�ȡֵ:" << endl;
//	get_dataset();
//	//���������޻�ͼ+����
//	cout << "--------------------------------------------------------------------------------" << endl;
//	construct_BayesianNW();
//
//	//testout();//��������������
//
//	//(���������ʱ�+��Ե�ֲ�����м���)
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	cout <<"ѵ������С:\t" <<trainingsetsize << endl;
//	/*
//	cout <<"ѵ������С��"<<(int)trainingset.size()<<endl;
//	//�������ѵ����
//	int count = 0;
//	for (vector<sample>::iterator it = trainingset.begin(); it != trainingset.end(); it++)
//	{
//		cout << ++count;
//		cout << it->s_word << "\t" << it->s_1stWB << "\t" << it->s_2ndWB << "\t" << it->s_1stPosB << "\t" << it->s_2ndPosB << "\t" << it->s_TWB << "\t";
//		cout << it->s_1stWM << "\t" << it->s_2ndWM << "\t" << it->s_TWM << "\t";
//		cout << it->s_1stWS << "\t" << it->s_2ndWS << "\t" << it->s_1stPosS << "\t" << it->s_2ndPosS << "\t" << it->s_TWS << "\t";
//		cout << it->mode;
//		cout << endl;
//	}
//	*/
//
//	//ѵ������
//	cout << "--------------------------------------------------------------------------------" << endl;
//	trainBN();
//	/*
//	for (int id = 1; id <= 13; id++)
//	{
//
//		cout <<endl<<BN[id].name<< " ��Ե�ֲ������" << endl;
//		for (map<string, CPtableI>::iterator it = BN[id].MD.begin(); it != BN[id].MD.end(); it++)
//		{
//
//			cout <<"��ǰȡֵ: "<<it->first<<" count: "<<it->second.count<<" pro:"<< it->second.pro << endl;
//		}
//		cout << "********************************************" << endl;
//
//		cout << endl << "�������ʱ�" << endl;
//		for (map <vector<string>, CPtableI> ::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//			cout << "cur: ";
//			vector<string> cursv = it->first;
//			for (vector<string>::iterator itstring = cursv.begin(); itstring != cursv.end(); itstring++)
//			{
//				cout << *itstring << " ";
//			}
//			cout<< " pro: " << it->second.pro << " ";
//			cout << endl;
//		}
//
//		cout << endl;
//
//	}
//	*/
//
//	//�ƶ�
//	test();
//
//	return 0;
//}
