#include"ConstructBN.h"
#include"TreeEncode.h"

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

extern map< int, set<string> > av;//����ȡֵ
extern vector<Code> HASH;//����ȡֵ�ı���

extern vector<Node> BN;//��Ҷ˹����
extern vector<int> tar;//����������Ŀ�����Խ��

/**************************************************************������ ST********************************************************************************/
//������Ե�ֲ�����
void construct_MD(int id)
{
	//����MD:ѭ������Ŀ������ȡֵ
	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
	{
		BN[id].MD[*it] = CPtableI(0, 0);
	}

}

//��õ�������+�������Ա��
vector<int> get_condition_id(int id)
{
	vector<int> condition;
	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		condition.push_back(it->id);
	}
	return condition;
}

//dfs���������������ʱ����
void build_CPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable)
{
	if (index == condition.size())
	{
		curCPtable[curcon] = CPtableH(0);

		//�����ڶ�������
		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
		{
			curCPtable[curcon].curCPtableI[*it] = CPtableI(0);
		}

		return;
	}

	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
	{
		curcon.push_back(*it);
		build_CPtable(id, condition, index + 1, curcon, curCPtable);
		curcon.pop_back();
	}
}

//�����������ʱ���
void construct_CPT(int id)
{
	vector<int> condition = get_condition_id(id);
	
	int index = 0;//�±���Ʒ���
	vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
	curcon.clear();

	cout <<" �������ʱ��������:";

	//dfs����
	build_CPtable(id, condition, index, curcon, BN[id].CPtable);

	cout << "\t�������ʱ��С: " << BN[id].CPtable.size() << endl;
}

//dfs���������������ʱ����
void build_JPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &curJPtable)
{
	if (index == condition.size())
	{
		curJPtable[curcon] = CPtableI(0);

		return;
	}

	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
	{
		curcon.push_back(*it);
		build_JPtable(id, condition, index + 1, curcon, curJPtable);
		curcon.pop_back();
	}
}

//�������Ϸֲ�����
void construct_JPT(int id)
{
	vector<int> condition = get_condition_id(id);
	condition.push_back(id);

	int index = 0;//�±���Ʒ���
	vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
	curcon.clear();

	cout << " ���ϸ��ʷֲ����������:";

	//dfs����
	build_JPtable(id, condition, index, curcon, BN[id].JPtable);

	cout << "\t���ϸ��ʷֲ����С: " << BN[id].JPtable.size() << endl;

}

//ͳһ����******************************************************************************************
void build_CPtable_JPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable, map<vector<string>, CPtableI> &curJPtable)
{
	if (index == condition.size())
	{
		curCPtable[curcon] = CPtableH(0);

		
		vector<string> curj = curcon;
		//�����ڶ�������
		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
		{
			//�������ʱ�ڶ�������
			curCPtable[curcon].curCPtableI[*it] = CPtableI(0);
			

			//���ϸ��ʷֲ�����
			curj.push_back(*it);
			curJPtable[curj] = CPtableI(0);
			curj.pop_back();

		}

		return;
	}

	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
	{
		curcon.push_back(*it);
		build_CPtable_JPtable(id, condition, index + 1, curcon, curCPtable, curJPtable);
		curcon.pop_back();
	}


}

void construct_JPT_CPT(int id)
{
	vector<int> condition = get_condition_id(id);
	//condition.push_back(id);

	//�����������ʱ�*******************************************
	int index = 0;//�±���Ʒ���
	vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
	curcon.clear();

	cout << " �������ʱ��������\t���ϸ��ʷֲ����������";
	//dfs����
	build_CPtable_JPtable(id, condition, index, curcon, BN[id].CPtable, BN[id].JPtable);

	cout << "\t�������ʱ��С: " << BN[id].CPtable.size() << endl; cout << "\t���ϸ��ʷֲ����С: " << BN[id].JPtable.size() << endl;

	
	
}
/**************************************************************������ ED********************************************************************************/



/**************************************************************�������������� ST************************************************************************/
void build_CPtree(int id, vector<int> condition, int index, vector<string> curcon, Treenode &curCPtree, int &cnt)
{
	if (index == condition.size())//���ʽ��
	{
		curCPtree.sumcnt = 0;
		curCPtree.cnt = 0;
		curCPtree.pro = 0;
		curCPtree.child = NULL;

		cnt++;
		//�������
		/*
		//if(id==13)
		//{
			cout << "�������ɣ�";
			for (vector<string>::iterator it = curcon.begin(); it != curcon.end(); it++)
			{
				cout << *it << "\t";
			}
			cout << endl;	
		//}
		*/

		return;
	}
	else//������֧���
	{
		curCPtree.id = condition[index];
		if (index == condition.size())//Ҷ�ӽ��
			curCPtree.flag = true;
		else//Ҷ�ӽ������
			curCPtree.flag = false;
		curCPtree.sumcnt = 0;
		curCPtree.cnt = 0;
		curCPtree.pro = 0;
		curCPtree.child = new Treenode[105];
		
		for (int i = 0; i < 75; i++)
		{
			if (HASH[curCPtree.id].sti[i] != "")
			{
				Treenode childnode;
				childnode.value = HASH[curCPtree.id].sti[i];
				childnode.valueid = i;

				curcon.push_back(childnode.value);
				build_CPtree(id, condition, index + 1, curcon, childnode, cnt);
				//����
				//TODO
				curCPtree.child[i] = childnode;
				curcon.pop_back();
			}
			
		}

	}

}

void construct_CPtree(int id)
{
	vector<int> condition = get_condition_id(id);
	condition.push_back(id);

	//��������������*******************************************
	int index = 0;//�±���Ʒ���
	vector<string> curcon;//��ǰ·���ϵ�����ȡֵ
	curcon.clear();
	int cnt = 0;

	cout << Name[id] << "\t�������������ɣ�" << endl;

	//dfs����
	build_CPtree(id, condition, index, curcon, BN[id].CPtree, cnt);

	//cout << BN[id].CPtree.id << endl;
	cout << "�������ʱ�����ɣ��ײ�����С��" << cnt << endl;
}
/**************************************************************�������������� ED************************************************************************/


//������Ҷ˹����
void construct_BayesianNW()
{
	//�������
	Node temp(0, "temp");

	Node WB1(1, "1stWB");
	Node WB2(2, "2ndWB");
	Node PosB1(3, "1stPosB");
	Node PosB2(4, "2ndPosB");
	Node TWB(5, "TWB");
	Node WM1(6, "1stWM");
	Node WM2(7, "2ndWM");
	Node TWM(8, "TWM");
	Node WS1(9, "1stWS");
	Node WS2(10, "2ndWS");
	Node PosS1(11, "1stPosS");
	Node PosS2(12, "2ndPosS");
	Node TWS(13, "TWS");

	//MWST��ϵ��
	/*
	PosB1.parent.push_back(WB1); WB1.child.push_back(PosB1);
	WM1.parent.push_back(WS1); WS1.child.push_back(WM1);
	PosS2.parent.push_back(WS1); WS1.child.push_back(PosS2);
	PosB2.parent.push_back(WB2); WB2.child.push_back(PosB2);
	TWB.parent.push_back(WB2); WB2.child.push_back(TWB);
	WB2.parent.push_back(WM2); WM2.child.push_back(WB2);
	WM2.parent.push_back(TWS); TWS.child.push_back(WM2);
	TWM.parent.push_back(TWS); TWS.child.push_back(TWM);
	WS2.parent.push_back(TWS); TWS.child.push_back(WS2);
	PosS1.parent.push_back(TWS); TWS.child.push_back(PosS1);
	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
	WB1.child.push_back(WS1); WS1.parent.push_back(WB1);
	*/	

	
	//���������ϵ
	WB1.child.push_back(TWB); TWB.parent.push_back(WB1);
	WB2.child.push_back(TWB); TWB.parent.push_back(WB2);
	PosB1.child.push_back(TWB); TWB.parent.push_back(PosB1);
	PosB2.child.push_back(TWB); TWB.parent.push_back(PosB2);

	WB1.child.push_back(WM1); WM1.parent.push_back(WB1);
	WB2.child.push_back(WM2); WM2.parent.push_back(WB2);
	TWB.child.push_back(TWM); TWM.parent.push_back(TWB);
	WM1.child.push_back(TWM); TWM.parent.push_back(WM1);
	WM2.child.push_back(TWM); TWM.parent.push_back(WM2);

	WM1.child.push_back(WS1); WS1.parent.push_back(WM1);
	WM2.child.push_back(WS2); WS2.parent.push_back(WM2);

	
	//TWM.child.push_back(TWS); TWS.parent.push_back(TWM);
	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
	WS2.child.push_back(TWS); TWS.parent.push_back(WS2);
	PosS1.child.push_back(TWS); TWS.parent.push_back(PosS1);
	PosS2.child.push_back(TWS); TWS.parent.push_back(PosS2);
	


	//�����뱴Ҷ˹����(�Ժ���ŷ���+����)
	BN.push_back(temp);
	BN.push_back(WB1); BN.push_back(WB2);
	BN.push_back(PosB1); BN.push_back(PosB2);
	BN.push_back(TWB);
	//
	BN.push_back(WM1); BN.push_back(WM2);
	BN.push_back(TWM);
	//
	BN.push_back(WS1); BN.push_back(WS2);
	BN.push_back(PosS1); BN.push_back(PosS2);
	BN.push_back(TWS);

	//������Ե�ֲ���:
	
	//����һ: ÿ�������������ʱ�,��Ե�ֲ���(ֻ���ռ䲻��������)
	/*
	for (int id = 1; id <= 13; id++)
	{
		cout << "id: " << id << "��������: " << BN[id].name << "\t��Ե���ʷֲ����������: "<<endl;
		construct_MD(id);
	}
	
	//����Ҫ�����ƶϵ����Ϸֲ���+�����ֲ���
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		cout << BN[*it].name << endl;
		//construct_JPT(*it);
		//construct_CPT(*it);
		construct_JPT_CPT(*it);
	}
	*/

	//������:��������������
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		construct_CPtree(*it);
	}
}