#pragma once
#include<vector>
#include<string>

using namespace std;

//��������������
void count_CPtree(int id, vector<string> invec);

//�����������������
void cal_CPtree(int id, int depth, Treenode &curCPtree);

//��������
void count_JPtable(int id, vector<string> invec);

//��ȡѵ����
void get_trainingset();

//�����Ե����
void cal_MDpro(int id);
void cal_MD();


//�������ϸ���
void cal_JPpro(int id);
void cal_JPtable();


//���ñ�Ե�ֲ�����������������
//������������
double cal_mulJP(int id, vector<string> con);
void cal_CPpro(int id);
void cal_CPtable();


//��ѵ������
void train();