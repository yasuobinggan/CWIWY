///*
//	MSWT:	
//		���Ȩ������
//		���ڻ���Ϣ(MI)
//		������ı�Ҷ˹��������ϸ��ʷֲ����������С
//	˼��:
//		���ɵ���һ����
//*/
//
////#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//#include<algorithm>
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
////�߽ṹ��
//struct Edge {
//	int u;
//	int v;
//	double wei;
//	Edge(){}
//	Edge(int _u, int _v, double _wei)
//	{
//		u = _u;
//		v = _v;
//		wei = _wei;
//	}
//};
//
//bool cmp(Edge a, Edge b)
//{
//	return a.wei > b.wei;
//}
//
//
////������ʾͼ
//vector<Edge> GV;
////���鼯
//int father[maxn];
////�ڽӾ���洢��Ҷ˹����(ֻ�洢��ϵ)
//int G[maxn][maxn];
////�������
//bool visited[maxn];
////��������
//double d[maxn];
////Ȩ�ؾ���(�洢���ԵĻ���Ϣ)
//double Weight[maxn][maxn];
//
////���Ȩ������
//vector<Edge> MSWT;
//
////��������
//string Name[maxn];
//void initName()
//{
//	Name[0] = "temp";
//
//	Name[1] = "1stWB";Name[2] = "2ndWB";
//	Name[3] = "1stPosB";Name[4] = "2ndPosB";
//	Name[5] = "TWB";
//	
//	Name[6] = "1stWM";Name[7] = "2ndWM";
//	Name[8] = "TWM";
//
//	Name[9] = "1stWS";Name[10] = "2ndWS";
//	Name[11] = "1stPosS";Name[12] = "2ndPosS";
//	Name[13] = "TWS";
//}
//
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
//vector<sample> trainingset;
//int trainingsetsize;
//
////����ȡֵ
//map<int, set<string>> r;
//
//struct MTI {
//	int cnt;
//	double pro;
//	MTI() {}
//	MTI(int _cnt, double _pro)
//	{
//		cnt = _cnt;
//		pro = _pro;
//	}
//};
////��Ե���ʷֲ���
//map<string, MTI> MT[maxn];
//
//struct Pair {
//	int u;
//	int v;
//	Pair() {}
//	Pair(int _u, int _v)
//	{
//		u = _u;
//		v = _v;
//	}
//	friend bool operator<(Pair a, Pair b)
//	{
//		if (a.u != b.u)
//			return a.u < b.u;
//		else
//			return a.v < b.v;
//	}
//};
//struct JPI {
//	int cnt;
//	double pro;
//	JPI() {}
//	JPI(int _cnt, double _pro)
//	{
//		cnt = _cnt;
//		pro = _pro;
//	}
//};
////���ϸ��ʷֲ���
//map < Pair, map<vector<string>, JPI>> JPT;
//
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
//	fin.open("d:\\dataset\\trainingdataset.txt", ios::in);
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
//					r[i].insert(invec[i]);
//			}
//
//			
//		}
//
//		//�������
//		for (map<int, set<string>>::iterator it = r.begin(); it != r.end(); it++)
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
///********************************************�������� ST************************************************************************************************/
////������������(���Ե�ȡֵ���)
////����ѭ��
//map<vector<string>,JPI> build_JPI(int u,int v)
//{
//	map<vector<string>, JPI> curJPI;
//
//	for (set<string>::iterator it = r[u].begin(); it != r[u].end(); it++)
//	{
//		vector<string> cur;
//		cur.clear();
//		cur.push_back(*it);
//		for (set<string>::iterator secondit = r[v].begin(); secondit != r[v].end(); secondit++)
//		{
//			cur.push_back(*secondit);
//			curJPI[cur] = JPI(0, 0);
//			cur.pop_back();
//		}
//	}
//	return curJPI;
//}
//void construct_MT_JPT()
//{
//	for (int u = 1; u <= 13; u++)
//	{
//		//����MD:ѭ������Ŀ������ȡֵ
//		for (set<string>::iterator it = r[u].begin(); it != r[u].end(); it++)
//		{
//			MT[u][*it] = MTI(0, 0);
//		}
//		//�������ϸ��ʱ�
//		for (int v = u + 1; v <= 13; v++)
//		{
//			//cout << "��ǰ���Ϸֲ����" << u << " " << v << endl;
//			JPT[Pair(u, v)] = build_JPI(u, v);
//			
//			//cout << "***************************************" << endl;
//		}
//	}
//}
///********************************************�������� ED************************************************************************************************/
//
//
//
///********************************************����ѵ���� ST**********************************************************************************************/
////�������ݼ���ȡ���ݵ�����(����Ԥ����)
//void get_trainingset()
//{
//	trainingset.clear();
//	//��ѵ����(�ȶ�.txt�ļ�)
//	ifstream fin;
//	fin.open("d:\\dataset\\trainingdataset.txt", ios::in);
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
//			//�������ݼ���
//			for (int id = 1; id <= 13; id++)
//			{
//				//��Ե�ֲ������
//				//cout << "��ǰ���Ľ��: " << Name[id] << "\t��ǰȡֵ:" << invec[id] << endl;
//				 ++MT[id][invec[id]].cnt;
//			
//			}
//			//���ϸ��ʱ����
//			for (int u = 1; u <= 13; u++)
//			{
//				vector<string> cur;
//				cur.clear();
//				cur.push_back(invec[u]);
//				for (int v = u + 1; v <= 13; v++)
//				{
//					cur.push_back(invec[v]);
//					/*
//					for (vector<string>::iterator it = cur.begin(); it != cur.end(); it++)
//					{
//						cout << *it << "\t";
//					}
//					cout << endl;
//					*/
//					cout <<"�����������"<< JPT.count(Pair(u, v)) << "\t";
//					cout << "С����������"<< JPT[Pair(u, v)].count(cur) << "\t";
//					cout <<"����ǰ��"<< JPT[Pair(u, v)][cur].cnt << "\t";
//					
//					JPT[Pair(u, v)][cur].cnt++;
//					
//					cout <<"���ĺ�" << JPT[Pair(u, v)][cur].cnt << endl;
//					cur.pop_back();
//				}
//			}
//
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
///********************************************����ѵ���� ED**********************************************************************************************/
//
//
//
///********************************************��ȡȨ������ ST********************************************************************************************/
////�����б���������
//void cal_pro()
//{
//	//��Ե���ʷֲ�
//	for (int u = 1; u <= 13; u++)
//	{
//		
//		for (map<string, MTI>::iterator it = MT[u].begin(); it != MT[u].end(); it++)
//		{
//			it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
//
//		}
//		
//		//���ϸ��ʷֲ�
//		//cout << "���Ϸֲ���" << endl;
//		for (int v = u + 1; v <= 13; v++)
//		{
//			for (map<vector<string>, JPI>::iterator it = JPT[Pair(u, v)].begin(); it != JPT[Pair(u, v)].end(); it++)
//			{
//				it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
//			}
//		}
//		
//	}
//}
//
//
//
//double get_MI(int u, int v)
//{
//	double score = 0;
//	for (set<string>::iterator it = r[u].begin(); it != r[u].end(); it++)
//	{
//		for (set<string>::iterator secondit = r[v].begin(); secondit != r[v].end(); secondit++)
//		{
//			double px = MT[u][*it].pro;
//			double py = MT[v][*secondit].pro;
//
//			vector<string> cur;
//			cur.clear();
//			cur.push_back(*it); cur.push_back(*secondit);
//			
//			double pxy = JPT[Pair(u, v)][cur].pro;
//				
//			if (pxy != 0)
//			{
//				score += pxy * log(pxy / px / py);
//			}
//			//cout << score << endl;
//		}
//	}
//	return score;
//}
//
//
//void get_Weight()
//{
//	for (int u = 1; u <= 13; u++)
//	{
//		for (int v = u + 1; v <= 13; v++)
//		{
//			double curwei = get_MI(u, v);
//			GV.push_back(Edge(u, v, curwei));
//						
//		}
//	}
//}
///********************************************��ȡȨ������ ED********************************************************************************************/
//
//
///********************************************���MSWT ST************************************************************************************************/
////prim��ȡ���������
//void prim_MSWT(int root)
//{
//	fill(visited, visited + maxn, 0);
//	fill(d, d + maxn, -INF);
//	d[root] = 0;
//	double ans = 0;
//	
//	for (int i = 1; i <= 13; i++)
//	{
//		double MAXD = -INF;
//		int u = -1;
//		for (int id = 1; id <= 13; id++)
//		{
//			if (d[id] > MAXD)
//			{
//				MAXD = d[id];
//				u = id;
//			}
//		}
//
//		visited[u] = true;
//		ans += d[u];
//		
//		for (int v = 1; v <= 13; v++)
//		{
//			if (G[u][v] == 1 && visited[v] == false && Weight[u][v] < d[v])
//			{
//				d[v] = Weight[u][v];
//			}
//		}
//	}
//	cout <<"prim���ɵ����Ȩ��: "<< ans << endl;
//}
//
////���鼯ѹ��·��+����
//int findfather(int u)
//{
//	if (father[u] == u)
//		return u;
//	else
//		return father[u] = findfather(father[u]);
//}
//
////kruskal��ȡ���������
//void kruskal_MSWT()
//{
//	double ans = 0;
//	
//	sort(GV.begin(), GV.end(), cmp);
//	//���鼯��ʼ��
//	for (int id = 1; id <= 13; id++)
//	{
//		father[id] = id;
//	}
//	int curedgenum = 0;
//	for (int i = 0; i < GV.size(); i++)
//	{
//		int fa = findfather(GV[i].u);
//		int fb = findfather(GV[i].v);
//		if (fa != fb)
//		{
//			ans += GV[i].wei;
//			
//			father[fa] = fb;
//			MSWT.push_back(GV[i]);
//			curedgenum++;
//
//			if (curedgenum == n - 1)
//				break;
//		}
//	}
//
//	cout << "MSWTȨ��: " << ans << endl;
//}
///********************************************���MSWT ED************************************************************************************************/
//
//
//
///********************************************���BN ST**************************************************************************************************/
//void dfs(int father, int u)
//{
//	cout << Name[u] << endl;
//	
//	visited[u] = true;
//	Node cur(u, Name[u]);
//	cur.parent.push_back(father);
//
//	for (int v = 1; v <= 13; v++)
//	{
//		if (G[u][v] == 1 && visited[v] == false)
//		{
//			
//			cur.child.push_back(v);			
//			dfs(u,v);
//
//		}
//	}
//	BN.push_back(cur);
//}
//
//void get_BN(int root)
//{
//	//����ͼ-���ڽӾ���
//	for (int i = 0; i < MSWT.size(); i++)
//	{
//		int u = MSWT[i].u;
//		int v = MSWT[i].v;
//		double wei = MSWT[i].wei;
//		
//		G[u][v] = G[v][u] = 1;
//		Weight[u][v] = Weight[v][u] = wei;
//	}
//
//	cout << "���" << endl;
//	//������ȱ���
//	dfs(0, root);
//}
///********************************************���BN ED**************************************************************************************************/
//int main()
//{
//	//��ʼ������
//	memset(G, 1, sizeof(G));
//	fill(Weight[0], Weight[0] + maxn*maxn, 0);
//	initName();
//	
//
//	//����Ԥ����
//	cout << endl;
//	cout << "--------------------------------------����Ԥ����---------------------------------------------" << endl;
//	get_dataset();
//
//
//	//��������
//	construct_MT_JPT();	
//
//
//	//��¼����+����
//	cout << "--------------------------------------����ѵ��-----------------------------------------------" << endl;
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	
//
//	//���Ȩ��+��������ͼ
//	cal_pro();
//	get_Weight();
//
//
//	//������Ȩ������
//	cout << "--------------------------------------����MSWT-----------------------------------------------" << endl;
//	kruskal_MSWT();
//	//prim_MSWT(1);
//	for (vector<Edge>::iterator it = MSWT.begin(); it != MSWT.end(); it++)
//	{
//		cout << it->u << " " << it->v << "\t" << it->wei;
//		cout << endl;
//	}
//
//
//	//��ñ�Ҷ˹����
//	cout << "--------------------------------------�۲챴Ҷ˹����(��)-------------------------------------" << endl;
//	int root;
//	cout << "���������ı��(1<= && <=13)���۲챴Ҷ˹����Ľṹ��" << endl;
//	cin >> root;
//	get_BN(root);
//
//
//	//�������	
//	for (vector<Node>::iterator it = BN.begin(); it != BN.end(); it++)
//	{
//		cout << "***************************************************" << endl;
//		cout << "��ǰ��㣺" << it->name<<endl;
//		cout << "�����Խ�㣺" << endl;
//		for (vector<int>::iterator pit = it->parent.begin(); pit != it->parent.end(); pit++)
//		{
//			cout << Name[*pit] << "\t";
//		}
//		cout << endl;
//		cout << "�������Խ�㣺" << endl;
//		for (vector<int>::iterator cit = it->child.begin(); cit != it->child.end(); cit++)
//		{
//			cout << Name[*cit] << "\t";
//		}
//		cout << endl;
//		cout << "***************************************************" << endl << endl;
//	}
//	
//
//	return 0;
//}