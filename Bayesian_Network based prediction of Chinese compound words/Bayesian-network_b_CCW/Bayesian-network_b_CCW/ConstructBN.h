#pragma once

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



/*�������ʱ��� ST*/
//��������
struct CPtableI
{
	int cnt;
	double pro;
	CPtableI() {}
	CPtableI(int _cnt)
	{
		cnt = _cnt;
	}
	CPtableI(int _cnt, double _pro)
	{
		cnt = _cnt;
		pro = _pro;
	}
};

//������ͷ
struct  CPtableH
{
	int sumcnt;
	map<string, CPtableI> curCPtableI;

	CPtableH() {}
	CPtableH(int _sumcnt)
	{
		sumcnt = _sumcnt;
	}
	CPtableH(int _sumcnt, map<string, CPtableI> _curCPtableI)
	{
		sumcnt = _sumcnt;
		curCPtableI = _curCPtableI;
	}
};
/*�������ʱ��� ED*/

//������������һ�����
struct Treenode {
	string name;//������ƣ��������ƣ�
	int id;//����ţ����Ա�ţ�

	string value;//��һ���֧��ȡֵ
	int valueid;//��һ���֧��ȡֵ�ı��


	bool flag;//�����(true)ΪҶ�ڵ㣨Ҷ�ڵ�Ϊ·���ϵ�Ŀ���㣩//Ҷ������һ���Ǹ��ʽ��	
	
	int sumcnt;//���ϸ��ʣ����´��ݣ�
	int cnt;//���ʽ��ļ���
	
	double pro;//���ʽ�����������
	

	vector<int> path;//�ڵ�洢��·���ϵĽ�����Ե�ȡֵ
	
	Treenode* child;//��̬�����ڴ�
};


/*
struct Treenode
{
	TreeH Treehead;
	TreeH child[105];//���ӽ��
};
*/


//������Ҷ˹������:һ�����һ������������(��)
struct Node {
	
	int id;//���Ա��
	string name;//������

	//���Ϸֲ���
	map<vector<string>, CPtableI> JPtable;

	//�������ʱ�
	map<vector<string>, CPtableH> CPtable;

	//����������
	Treenode CPtree;

	//��Ե�ֲ���
	map<string, CPtableI> MD;

	//��Ϊ���Ե���������
	vector<Node> parent;
	//���Եĺ�������
	vector<Node> child;

	Node() {}
	Node(int _id, string _name)
	{
		id = _id;
		name = _name;
	}
};



//��õ�������+�������Ա��
vector<int> get_condition_id(int id);



//������Ե�ֲ�����
void construct_MD(int id);

//dfs�������ϸ��ʱ�
void build_JPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &curJPtable);
//�������Ϸֲ���
void construct_JPT(int id);

//dfs���������������ʱ����
void build_CPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable);
//�����������ʱ�
void construct_CPT(int id);

//������Ż�����
void construct_JPT_CPT(int id);

//dfs��������������
void build_CPtree(int id, vector<int> condition, int index, vector<string> curcon, Treenode &curCPtree, int &cnt);
//��������������
void construct_CPtree(int id);


//������Ҷ˹����
void construct_BayesianNW();