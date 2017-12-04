#pragma once
#include "singletonBase.h"
#include <vector>

struct INIData
{
	const char*	subject;	//�׸�			ex)����
	const char*	title;		//����			ex)����
	const char* body;		//��(value)		ex)30
};

class iniDataManager :public singletonBase<iniDataManager>
{
private:
	typedef vector<INIData> iniData;
	typedef vector<INIData>::iterator iniIter;

	typedef vector<iniData> iniDatas;
	typedef vector<iniData>::iterator inisIter;
	iniDatas vIniDatas;

public:

	HRESULT init();
	void release();

	
	//�ڷ��߰�
	void addData(const char* subject, const char* title, const char* body);
	//���̺�
	void iniSave(char* fileName);
	//�ε�
	char* loadDataString(const char* fileName, const char* subject, const char* title);
	int loadDataInteger(const char* fileName, const char* subject, const char* title);


	iniDataManager();
	~iniDataManager();
};

