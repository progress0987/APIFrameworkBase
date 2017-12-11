#pragma once
//http://3dapi.com/bs11_2d_basic/ ****** ���� ������
#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma comment(lib,"d3dx9.lib")

class D2DImage
{
	LPD3DXSPRITE		c_pd3dSprite = NULL;		//��������Ʈ����
	LPDIRECT3DTEXTURE9	c_pd3dTex = NULL;			//�ؽ�������
	D3DXIMAGE_INFO		c_ImgInfo;					//�̹�������
	LPD3DXVECTOR2		position;					//�׸� ��ġ
	CHAR*				fileAddress;				//���� �̸�
	LPDIRECT3DDEVICE9	curDev;						//��� ��ġ

	BOOL				framed=FALSE;				//������ ȭ �̹�������
	UINT				frameWidth;					//������ �̹��� ����� ���� ũ��
	UINT				frameHeight;				//������ �̹��� ����� ���� ũ��
	UINT				currentFrameX;				//������ �̹��� ��ȣ(����)
	UINT				currentFrameY;				//������ �̹��� ��ȣ(����)
	UINT				maxFrameX;					//������ ����ȣ(����)
	UINT				maxFrameY;					//������ ����ȣ(����)
public:
	HRESULT init(LPDIRECT3DDEVICE9 dev) { if (curDev == NULL) { curDev = dev; return S_OK; } else return E_FAIL; }
	HRESULT setImage(char* fileName);
	HRESULT setImage(char* fileName, LONG tr);
	HRESULT setImage(char* fileName,BOOL framed,unsigned int frameX,unsigned int frameY, LONG tr=NULL);
	void release();

	///////////////////////////////////������
	void render();
	void render(int destX, int destY);
	void render(int destX, int destY,int sourX,int sourY,int sourW, int sourH);


	void framerender();
	void framerender(int curX,int curY);
	void framerender(int destX, int destY, int curX, int curY);

	void rotatedrender(FLOAT angle = 0.0f);
	void rotatedrender(int destX, int destY,FLOAT angle = 0.0f);
	void rotatedrender(int destX, int destY, int sourX, int sourY, int sourW, int sourH, FLOAT angle = 0.0f);


	void rotatedframerender(int curX, int curY, FLOAT angle = 0.0f);
	void rotatedframerender(int destX, int destY, int curX,int curY,FLOAT angle = 0.0f);
	void superiorrender(D3DXVECTOR2 pos, D3DXVECTOR3 center, D3DXVECTOR2 scale, DWORD color);//�ϴ� �������� ���� �� �߰�



	int getWidth() { return c_ImgInfo.Width; }
	int getHeight() { return c_ImgInfo.Height; }
	int getFrameWidth() { return frameWidth; }
	int getFrameHeight() { return frameHeight; }
	int getFrameMaxX() { return maxFrameX; }
	int getFrameMaxY() { return maxFrameY; }


	D2DImage();
	~D2DImage();
};
