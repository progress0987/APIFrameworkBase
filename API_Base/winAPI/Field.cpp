#include "stdafx.h"
#include "Field.h"

/*
	타일들 센터 - WINSIZEX/2,WINSIXEY/2
	맨 처음(왼쪽위) 타일은 무조건 센터에서 타일가로길이 * 가로의 숫자 만큼 떨어짐

*/
void Field::init()
{
	tileset = IMAGEMANAGER->findImage("사막맵타일");
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
	//? 쓸게있나?
}

void Field::render()
{
	if (SUCCEEDED(tileset->c_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND))) {
		//2D그리기 시작

		for (int y = 0; y < TILENUMY; y++) {
			for (int x = 0; x < TILENUMX; x++) {
				int w = tileset->frameWidth;
				int h = tileset->frameHeight;
				D3DXVECTOR2 pos(map[x][y].pos.x - cam->x, map[x][y].pos.y - cam->y);							//좌상단 좌표
				RECT rect = {
					map[x][y].index.x * w,
					map[x][y].index.y * h,
					w + map[x][y].index.x * w,
					h + map[x][y].index.y * h };	//그림의 크기
				D3DXVECTOR3 center(w / 2, h / 2, 0);	//그림의 중심점 - 회전의 중심일듯

				D3DXVECTOR2 scale(1.f, 1.f);						//이미지의 스케일을결정(1이 기본), 중심을 기준으로커짐

				DWORD color = 0xffffffff;							//색들을 출력해줄 정도로 보임(색을바꾸면 해당 색이 좀 빠짐)ARGB순서, A줄이면 이미지흐려짐

				D3DXMATRIX mat;
				D3DXMatrixTransformation2D(
					&mat,						//출력
					NULL,						//스케일링의 중심
					0.0f,						//스케일링 회전률(???) -확인
					&scale,						//스케일링
					NULL,						//회전의 중심
					0.0f,						//회전률
					&pos);						//위치(트랜슬레이션)
				tileset->c_pd3dSprite->SetTransform(&mat);
				tileset->c_pd3dSprite->Draw(
					tileset->c_pd3dTex,
					&rect,
					&center,
					NULL,
					color);
				//D3DXMatrixIdentity(&mat);							//단위행렬로 만들어서 아래서 곱함
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
