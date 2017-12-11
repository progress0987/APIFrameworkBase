#pragma once
#include "gameNode.h"
#include "progressBar.h"


enum LOAD_KIND {
	LOAD_KIND_IMAGE_0,		//���̹���
	LOAD_KIND_IMAGE_1,		//�Ϲ��̹���
	LOAD_KIND_IMAGE_2,		//�Ϲ��̹����ε� ��ǥ����
	LOAD_KIND_FRAMEIMAGE_0,	//������
	LOAD_KIND_FRAMEIMAGE_1,	//���� �����ѵ� ��ǥ����
	LOAD_KIND_SOUND,
	LOAD_KIND_END,
};

struct ImageResouce {
	string keyName;				//�̹��� Ű��
	const char* fileName;		//�����̸�
	float x, y;					//��ġ��ǥ
	int width, height;			//���μ��� ũ��
	bool trans;					//������
	COLORREF transCol;			//���� ��
};

class loadItem {
private:
	LOAD_KIND kind;
	ImageResouce imgResource;
public:
	HRESULT initForImage(string keyName, int width, int height);
	HRESULT initForImage(string keyName, const char* filename, int width, int height, BOOL trans = FALSE, COLORREF transcol = FALSE);
	HRESULT initForImage(string keyName, const char* filename,float x, float y, int width, int height,BOOL trans = FALSE,COLORREF transcol = FALSE);

	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transcol = FALSE);
	HRESULT initForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transcol = FALSE);

	LOAD_KIND getLoadingKind() { return this->kind; }

	ImageResouce getImageResource(){ return this->imgResource; }
	loadItem();
	~loadItem();
};

class loading
{
private:
	typedef vector<loadItem*> items;
	typedef vector<loadItem*>::iterator itemsIter;

	items _vitems;

	image* bg;
	progressBar* loadingbar;
	int currGauge;
public:
	loading();
	~loading();

	void loadImage(string keyName, int width, int height);
	void loadImage(string keyName, const char* fileName, int width, int height, BOOL trans = FALSE, COLORREF col = FALSE);

	//void loadFrameImage(string keyName, const char* fileName, int width, int height, ...);

	//BOOL loadingDone();
	//vector<loadItem*>

};

