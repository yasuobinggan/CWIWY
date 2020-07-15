#pragma once
//ͷ�ļ�ֻ������һ��
/*
��ȡѵ����
*/

/**
* �����Ը���:
* 1��P(1st WB);
* 2��P(2nd WB);
* 3��P(1st PosB);
* 4��P(2nd PosB);
* 5��P(TWB)= P(TWB |1st WB,2nd WB,1st PosB,2nd PosB)*P(1stWB)*P(2ndWB)*P(1stPosB)*P(2ndPosB)
* 6��P(1st WM)= P(1st WM|1st WB)*P(1st WB)
* 7��P(2nd WM)= P(2nd WM|2nd WB)*P(2nd WB)
* 8��P(TWM) = P(TWM |1st WM,2nd WM)*P(1st WM)*P(2nd WM)
* 9��P(1st WS) = P(1st WS|1st WM)*P(1st WM)
* 10��P(2nd WS) = P(2nd WS|2nd WM)*P(2nd WM)
* 11��P(1st PosS)
* 12��P(2nd PosS)
* 13��P(TWS) = P(TWS |1st WS,2nd WS,1st PosS,2nd PosS)*P(1st WS)*P(2nd WS)*P(1st PosS)*P(2nd PosS)
*/

#pragma once
//#include<fstream>
//#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

struct sample {
	string s_word;//ѵ���ʻ�
	string s_1stWB;//��һ���������
	string s_2ndWB;//�ڶ����������
	string s_1stPosB;//��һ���Դ���
	string s_2ndPosB;//�ڶ����Դ���
	string s_TWB;//Ŀ��ʻ����
	string s_1stWM;//��һ����������
	string s_2ndWM;//�ڶ�����������
	string s_TWM;//Ŀ��ʻ�����
	string s_1stWS;//��һ������С��
	string s_2ndWS;//�ڶ�������С��
	string s_1stPosS;//��һ����С��
	string s_2ndPosS;//�ڶ�����С��
	string s_TWS;//Ŀ��ʻ�С��
	string mode;//���ʷ�ʽ���

	sample() {}
	sample(string input, string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m, string n)
	{
		s_word = input;
		s_1stWB = a;
		s_2ndWB = b;
		s_1stPosB = c;
		s_2ndPosB = d;
		s_TWB = e;
		s_1stWM = f;
		s_2ndWM = g;
		s_TWM = h;
		s_1stWS = i;
		s_2ndWS = j;
		s_1stPosS = k;
		s_2ndPosS = l;
		s_TWS = m;
		mode = n;
	}
};


void get_dataset();