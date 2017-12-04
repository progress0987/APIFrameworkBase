#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init(void)
{
	return S_OK;
}

void imageManager::release(void)
{
}

//빈 비트맵
image * imageManager::addImage(string key, int width, int height)
{
	image* img = findImage(key);
	//이미지가 있으면 해당 이미지 사용
	if (img) return img;

	img = new image;
	if (FAILED(img->init(width, height))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addImage(string key, const char * fileName, int width, int height, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName, width, height, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addImage(string key, const char * fileName, float x, float y, int width, int height, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName,x,y, width, height, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addFrameImage(string key, const char * fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName, width, height,frameX,frameY, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addFrameImage(string key, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName,x,y, width, height,frameX,frameY, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::findImage(string key)
{
	mapImagerIter i = ImageList.find(key);

	//키 값을 찾을경우 해당 키에해당되는 값을 리턴
	if (i != ImageList.end()) {
		return i->second;
	}
	return NULL;
}

BOOL imageManager::deleteImage(string key)
{
	mapImagerIter i = ImageList.find(key);

	//키 값을 찾을경우 해당 키에해당되는 값을 리턴
	if (i != ImageList.end()) {
		i->second->release();
		SAFE_DELETE(i->second);
		ImageList.erase(i);
		return true;
	}
	return false;
}

BOOL imageManager::deleteAll()
{
	mapImagerIter i = ImageList.begin();

	for (; i != ImageList.end();) {
		if (i->second != NULL) {
			i->second->release();
			SAFE_DELETE(i->second);
			i = ImageList.erase(i);
		}
		else
			i++;
	}
	ImageList.clear();
	return TRUE;
}

void imageManager::render(string key, HDC hdc)
{
	image* img = findImage(key);
	if (img) img->render(hdc);
}

void imageManager::render(string key, HDC hdc, int destX, int destY)
{
	image* img = findImage(key);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string key, HDC hdc, int destX, int destY, int sourX, int sourY, int width, int height)
{
	image* img = findImage(key);
	if (img) img->render(hdc, destX, destY,sourX,sourY,width,height);
}
