#pragma once

#include "singletonBase.h"
#include "image.h"
#include <map>




class imageManager : public singletonBase<imageManager>
{
private:
	typedef map<string, image*>mapImageList;
	typedef map<string, image*>::iterator mapImagerIter;

	mapImageList ImageList;

public:

	HRESULT init(void);
	void release(void);
	//빈 비트맵
	image* addImage(string key, int width, int height);

	//파일 이미지
	image* addImage(string key, const char* fileName, int width, int height,bool trans, COLORREF transCol);
	image* addImage(string key, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transCol);

	//프레임 이미지
	image* addFrameImage(string key, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol);
	image* addFrameImage(string key, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol);

	//키 값으로 이미지 찾아오는 함수
	image* findImage(string key);

	//이미지 지워주는 함수
	BOOL deleteImage(string key);

	//모든 이미지 삭제
	BOOL deleteAll();
	void render(string key, HDC hdc);
	void render(string key, HDC hdc, int destX, int destY);
	void render(string key, HDC hdc, int destX, int destY,int sourX, int sourY, int width, int height);


	imageManager();
	~imageManager();
};

