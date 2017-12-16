#include "stdafx.h"
#include "Field.h"

/*
	Ÿ�ϵ� ���� - WINSIZEX/2,WINSIXEY/2
	�� ó��(������) Ÿ���� ������ ���Ϳ��� Ÿ�ϰ��α��� * ������ ���� ��ŭ ������

*/
extern LPDIRECT3D9					g_pD3D;
extern LPDIRECT3DDEVICE9			g_pd3dDevice;
extern LPDIRECT3DSURFACE9			g_pd3dSurface;

void Field::init()
{
	tileset = IMAGEMANAGER->findImage("�縷��Ÿ��");
	float startx = WINSIZEX/2 - (TILEWIDTH*TILENUMX/2), starty = WINSIZEY/2;
	for (int i = 0; i < TILENUMY; i++) {
		for(int j = 0; j < TILENUMX; j++) {
			map[j][i].pos = pointMake(startx+(TILEWIDTH/2*j) -cam->x,starty-(TILEHEIGHT/2*j)-cam->y);
			map[j][i].index = pointMake(rand() % (tileset->getFrameMaxX()+1), rand() % (tileset->getFrameMaxY()+1));
			map[j][i].rc = RectMakeCenter(map[j][i].pos.x, map[j][i].pos.y, TILEWIDTH / 2, TILEHEIGHT / 2);
		}
		startx += TILEWIDTH / 2;
		starty += TILEHEIGHT / 2;
	}
}

void Field::update()
{
	//? �����ֳ�?
}

void Field::render()
{
	if (SUCCEEDED(tileset->c_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND))) {
		//2D�׸��� ����

		for (int y = 0; y < TILENUMY; y++) {
			for (int x = 0; x < TILENUMX; x++) {
				int w = tileset->frameWidth;
				int h = tileset->frameHeight;
				D3DXVECTOR2 pos(map[x][y].pos.x - cam->x, map[x][y].pos.y - cam->y);							//�߽� ��ǥ
				RECT rect = {
					map[x][y].index.x * w,
					map[x][y].index.y * h,
					w + map[x][y].index.x * w,
					h + map[x][y].index.y * h };	//�׸��� ũ��
				D3DXVECTOR3 center(w / 2, h / 2, 0);	//�׸��� �߽��� - ȸ���� �߽��ϵ�

				D3DXVECTOR2 scale(1.f, 1.f);						//�̹����� ������������(1�� �⺻), �߽��� ��������Ŀ��

				DWORD color = 0xffffffff;							//������ ������� ������ ����(�����ٲٸ� �ش� ���� �� ����)ARGB����, A���̸� �̹��������

				D3DXMATRIX mat;
				D3DXMatrixTransformation2D(
					&mat,						//���
					NULL,						//�����ϸ��� �߽�
					0.0f,						//�����ϸ� ȸ����(???) -Ȯ��
					&scale,						//�����ϸ�
					NULL,						//ȸ���� �߽�
					0.0f,						//ȸ����
					&pos);						//��ġ(Ʈ�������̼�)
				tileset->c_pd3dSprite->SetTransform(&mat);
				tileset->c_pd3dSprite->Draw(
					tileset->c_pd3dTex,
					&rect,
					&center,
					NULL,
					color);
				//D3DXMatrixIdentity(&mat);							//������ķ� ���� �Ʒ��� ����
				//c_pd3dSprite->SetTransform(&mat);


			}
		}
		tileset->c_pd3dSprite->End();
	}
}

Field::Field()
{
}


Field::~Field()
{
}
