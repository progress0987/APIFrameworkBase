#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"

effectManager::effectManager()
{
}


effectManager::~effectManager()
{
}

HRESULT effectManager::init(void)
{

	return S_OK;
}

void effectManager::release(void)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		mIter = vIter->begin();
		for (; mIter != vIter->end();)
		{
			if (mIter->second.size() != 0)
			{
				iterEffects vArrIter = mIter->second.begin();
				for (; vArrIter != mIter->second.end(); ++vArrIter)
				{
					(*vArrIter)->release();
					delete *vArrIter;
					vArrIter = mIter->second.erase(vArrIter);
				}
			}
			else
			{
				++mIter;
			}
		}
	}
}

void effectManager::update(void)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			iterEffects vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				(*vArrIter)->update();
			}
		}
	}
}

void effectManager::render(void)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			iterEffects vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				(*vArrIter)->render();
			}
		}
	}
}


void effectManager::addEffect(string effectName, const char* imageName, int imageWidth, int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer)
{
	D2DImage* img;
	arrEffects vEffectBuffer;
	arrEffect mArrEffect;

	//키 값이 있다면
	if (IMAGEMANAGER->findImage(imageName))
	{
		//그것을 쓴다
		img = IMAGEMANAGER->findImage(imageName);
	}
	else
	{
		//img = IMAGEMANAGER->addImage(imageName, imageName, imageWidth, imageHeight, true, RGB(255, 0, 255));
	}

	//버퍼만큼 생성
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new Effect);
		vEffectBuffer[i]->init(img, effectWidth, effectHeight, fps, elapsedTime);
	}

	//페어!!!!
	mArrEffect.insert(pair<string, arrEffects>(effectName, vEffectBuffer));

	_vTotalEffects.push_back(mArrEffect);
}


void effectManager::play(string effectName, int x, int y)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			if (!(mIter->first == effectName)) break;

			iterEffects vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				if ((*vArrIter)->getIsRunning()) continue;

				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}
}
