
#include<iostream>
#include "stdafx.h"
#include "string"
using namespace std;
class auxiliary  //������
{
public:
	static string getPath(); //��ȡ·��
	static string readIni(CString iniPath,CString path); //��ȡ�����ļ�
	static void play(CString musicPath); //��������
	static void stop(); //ֹͣ��������
	static void decode(CString answer); //���𰸽���
	static double getScore(); //��ȡ�ɼ�
	static void outputPdf();//����pdf�ļ�
};