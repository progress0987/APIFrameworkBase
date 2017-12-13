#pragma once

#include "singletonBase.h"
#include "D2DImage.h"
#include <map>




class imageManager : public singletonBase<imageManager>
{
private:
	typedef map<string, D2DImage*>mapImageList;
	typedef map<string, D2DImage*>::iterator mapImagerIter;

	mapImageList ImageList;

public:

	HRESULT init(void);
	void release(void);

	//���� �̹���
	D2DImage* addImage(string key,LPDIRECT3DDEVICE9 dev, const char* fileName,bool trans=false, COLORREF transCol=NULL);

	//������ �̹���
	D2DImage* addFrameImage(string key, LPDIRECT3DDEVICE9 dev,const char* fileName,  int frameX, int frameY, bool trans=false, COLORREF transCol=NULL);

	//Ű ������ �̹��� ã�ƿ��� �Լ�
	D2DImage* findImage(string key);

	//�̹��� �����ִ� �Լ�
	BOOL deleteImage(string key);

	//��� �̹��� ����
	BOOL deleteAll();

	imageManager();
	~imageManager();
};

