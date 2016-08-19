
#include<iostream>
#include "stdafx.h"
#include "string"
using namespace std;
class auxiliary  //辅助类
{
public:
	static string getPath(); //获取路径
	static string readIni(CString iniPath,CString path); //读取配置文件
	static void play(CString musicPath); //播放音乐
	static void stop(); //停止播放音乐
	static void decode(CString answer); //给答案解码
	static double getScore(); //获取成绩
	static void outputPdf();//生成pdf文件
};