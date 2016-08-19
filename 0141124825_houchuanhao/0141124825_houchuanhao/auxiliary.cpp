#include"auxiliary.h"
string auxiliary::getPath()
{
		char strModule[256];
		GetModuleFileName(NULL, strModule, 256); //得到当前模块路径

		CString str = CString(strModule);
		int l = str.GetLength();


		for (int i = l - 1; i > 0; i--)
		{

			if (str[i] != 92)
			{
				str = str.Left(i);
			}
			else{
				break;
			}
		}
		return str;
}