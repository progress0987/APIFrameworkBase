#include "stdafx.h"
#include "Astar.h"


list<ANode> Astar::findPath(ANode * from, ANode * to)
{
	return list<ANode>();
}

Astar::Astar()
{
}


Astar::~Astar()
{
}
//
//#include "stdafx.h"
//#include "aStar.h"
//
//
//
//aStar::aStar()
//{
//}
//
//
//aStar::~aStar()
//{
//}
//
//HRESULT aStar::init(void)
//{
//	_aStarState = ASTAR_STATE_END;//�ʱ�=Ÿ�Ϲ�ġ �Ϸ���
//
//	_selectedType = TILE_TYPE_EMPTY;//��ġ�� Ÿ�� �Ӽ� = ���
//	_selectedTypeColor = RGB(255, 255, 255);		//���� �Ͼ��̷�
//
//	_startPointSet = false;	//�������� ��ġ ����
//	_endPointSet = false;	//�������� ��ġ����
//
//
//
//
//	for (int i = 0; i < TILE_Y; i++)
//	{
//		for (int j = 0; j < TILE_X; j++)
//		{
//			_tile[i][j].type = TILE_TYPE_EMPTY;
//			_tile[i][j].color = RGB(255, 255, 255);
//			_tile[i][j].parent = nullptr;//�θ�Ÿ��
//			_tile[i][j].F = BIGNUM;
//			_tile[i][j].H = 0;//�翬�� ������̴ϱ�
//			_tile[i][j].i = i;
//			_tile[i][j].j = j;
//			_tile[i][j].rc =
//				RectMake(WINSIZEX - (TILE_X + 1)* WIDTH + WIDTH * j,
//					WINSIZEY / 2 - (TILE_Y / 2) * HEIGHT + HEIGHT * i,
//					WIDTH, HEIGHT);//��Ʈ �Ҵ�
//
//		}
//	}
//
//	return S_OK;
//}
//
//void aStar::release(void)
//{
//}
//
//void aStar::update(void)
//{
//	if (_aStarState == ASTAR_STATE_END)//��ġ�� ������ �ʾҴٸ�
//	{
//		tileComposition();//Ÿ���� ��ġ����
//	}
//	//�����̶� ������ ��ġ �Ǿ��ְ� �����̽� ������ �ʱ�ȭ
//	if (KEYMANAGER->isonceKeyDown(VK_SPACE)
//		&& _startPointSet && _endPointSet && _aStarState == ASTAR_STATE_END)
//	{
//		tileInitializing();
//	}
//	//��ġ���̰ų� Ž���߰ų� ���̾����� ���� ����
//	if (_aStarState == ASTAR_STATE_END || _aStarState == ASTAR_STATE_FOUND || _aStarState == ASTAR_STATE_NOWAY)return;
//
//
//	addOpenList();          //���¸���Ʈ�� �߰� �� G�� ���
//	calculateH();           //H���
//	calculateF();           //F���
//	addCloseList();         //Ŭ�����Ʈ�� �߰�
//	checkArrive();          //���� ���� üũ
//}
//
//void aStar::render(void)
//{
//	PatBlt(getMemDc(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
//
//	TextOut(getMemDc(), 15, 15, "1 : empty", strlen("1 : empty"));
//	TextOut(getMemDc(), 15, 35, "2 : Start", strlen("2 : Start"));
//	TextOut(getMemDc(), 15, 55, "3 : End", strlen("3 : End"));
//	TextOut(getMemDc(), 15, 75, "4 : Wall", strlen("4 : Wall"));
//
//
//	char str[128];
//	if (_aStarState == ASTAR_STATE_END)
//		sprintf_s(str, "space press");
//	else if (_aStarState == ASTAR_STATE_FOUND)
//		sprintf_s(str, "way found");
//	else if (_aStarState == ASTAR_STATE_NOWAY)
//		sprintf_s(str, "no way");
//	else if (_aStarState == ASTAR_STATE_SEARCHING)
//		sprintf_s(str, "serching...");
//
//	TextOut(getMemDc(), 15, 150, str, strlen(str));
//
//	HBRUSH newBrush, oldBrush;
//	/*HFONT newFont, oldFont;
//
//	newFont = CreateFont(9, 0, 0, 0, FW_NORMAL, false, false, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
//	PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, "����");
//	*/
//
//
//	for (int i = 0; i < TILE_Y; i++)
//	{
//		for (int j = 0; j < TILE_X; j++)
//		{
//			newBrush = CreateSolidBrush(_tile[i][j].color);
//			oldBrush = (HBRUSH)SelectObject(getMemDc(), newBrush);
//
//
//			Rectangle(getMemDc(), _tile[i][j].rc.left, _tile[i][j].rc.top, _tile[i][j].rc.right, _tile[i][j].rc.bottom);
//			SelectObject(getMemDc(), oldBrush);
//			DeleteObject(newBrush);
//
//			//F�� BIGNUM���� �������� (F/G/H)�� ȭ�鿡 ǥ������
//			if (_tile[i][j].F < BIGNUM)
//			{
//				SetBkMode(getMemDc(), TRANSPARENT);
//				sprintf_s(_tile[i][j].str, "%d", _tile[i][j].F);
//				TextOut(getMemDc(), _tile[i][j].rc.left + 2, _tile[i][j].rc.top + 2, _tile[i][j].str, strlen(_tile[i][j].str));
//
//				sprintf_s(_tile[i][j].str, "%d", _tile[i][j].G);
//				TextOut(getMemDc(), _tile[i][j].rc.left + 2, _tile[i][j].rc.top + 22, _tile[i][j].str, strlen(_tile[i][j].str));
//
//				sprintf_s(_tile[i][j].str, "%d", _tile[i][j].H);
//				TextOut(getMemDc(), _tile[i][j].rc.left + 22, _tile[i][j].rc.top + 22, _tile[i][j].str, strlen(_tile[i][j].str));
//			}
//			if (_tile[i][j].parent == NULL)continue;
//
//			int length = 15;
//
//
//			MoveToEx(getMemDc(), (_tile[i][j].rc.left + _tile[i][j].rc.right) / 2,
//				(_tile[i][j].rc.top + _tile[i][j].rc.bottom) / 2, NULL);
//
//			LineTo(getMemDc(), (_tile[i][j].parent->j - _tile[i][j].j)* length +
//				(_tile[i][j].rc.left + _tile[i][j].rc.right) / 2,
//				(_tile[i][j].parent->i - _tile[i][j].i) * length + (_tile[i][j].rc.top + _tile[i][j].rc.bottom) / 2);
//
//		}
//	}
//
//	//SelectObject(getMemDc(), oldFont);
//	//DeleteObject(newFont);
//
//}
//
//void aStar::tileComposition()
//{
//	if (KEYMANAGER->isonceKeyDown('1')) { _selectedType = TILE_TYPE_EMPTY; _selectedTypeColor = RGB(255, 255, 255); }
//	if (KEYMANAGER->isonceKeyDown('2')) { _selectedType = TILE_TYPE_START; _selectedTypeColor = RGB(100, 255, 100); }
//	if (KEYMANAGER->isonceKeyDown('3')) { _selectedType = TILE_TYPE_END; _selectedTypeColor = RGB(255, 100, 100); }
//	if (KEYMANAGER->isonceKeyDown('4')) { _selectedType = TILE_TYPE_WALL; _selectedTypeColor = RGB(100, 100, 255); }
//
//
//	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
//	{
//		for (int i = 0; i < TILE_Y; i++)
//		{
//			for (int j = 0; j < TILE_X; j++)
//			{
//				if (PtInRect(&_tile[i][j].rc, _ptMouse))
//				{
//					//�������� �� ������ �º�
//					if (_tile[i][j].type == TILE_TYPE_START)_startPointSet = false;
//					if (_tile[i][j].type == TILE_TYPE_END)_endPointSet = false;
//
//					_tile[i][j].type = _selectedType;
//					_tile[i][j].color = _selectedTypeColor;
//
//
//					if (_selectedType == TILE_TYPE_START)
//					{
//						if (_startPointSet)
//						{
//							_tile[_startY][_startX].color = RGB(255, 255, 255);
//							_tile[_startY][_startX].type = TILE_TYPE_EMPTY;
//						}
//						_startPointSet = true;
//						_startX = j;
//						_startY = i;
//					}
//					if (_selectedType == TILE_TYPE_END)
//					{
//						if (_endPointSet)
//						{
//							_tile[_endY][_endX].color = RGB(255, 255, 255);
//							_tile[_endY][_endX].type = TILE_TYPE_EMPTY;
//						}
//						_endPointSet = true;
//						_endX = j;
//						_endY = i;
//					}
//				}
//			}
//		}
//	}
//}
//
//void aStar::tileInitializing()
//{
//	for (int i = 0; i < TILE_Y; i++)
//	{
//		for (int j = 0; j < TILE_X; j++)
//		{
//			if (_tile[i][j].type == TILE_TYPE_EMPTY)                     //�Ϲ�Ÿ��
//			{
//				_tile[i][j].walkable = true;
//				_tile[i][j].listOn = false;
//			}
//			else if (_tile[i][j].type == TILE_TYPE_WALL)                 //��������Ʈ��
//			{
//				_tile[i][j].walkable = false;
//				_tile[i][j].listOn = false;
//			}
//			else if (_tile[i][j].type == TILE_TYPE_START)                //����
//			{
//				_tile[i][j].walkable = true;
//				_tile[i][j].listOn = true;
//				_closeList.push_back(&_tile[i][j]);
//			}
//			else if (_tile[i][j].type == TILE_TYPE_END)                  //����
//			{
//				_endX = j;
//				_endY = i;
//				_tile[i][j].walkable = true;
//				_tile[i][j].listOn = false;
//			}
//		}
//	}
//
//	_aStarState = ASTAR_STATE_SEARCHING;
//	_lastIndex = 0;
//}
//
//void aStar::addOpenList()
//{
//	Ci = _closeList[_lastIndex]->i;		//���������� �߰��� Ŭ���� ����Ʈ�� i - y
//	Cj = _closeList[_lastIndex]->j;		//���������� �߰��� Ŭ���� ����Ʈ�� j - x
//	Cg = _closeList[_lastIndex]->G;		//���������� �߰��� Ŭ���� ����Ʈ�� g
//
//										/*
//										123
//										456
//										789
//										����
//										*/
//	if (Ci != 0)//0��° ���� �ƴϸ� ��ܶ����� ��������
//	{
//		//2
//		if (_tile[Ci - 1][Cj].walkable)//��� ��� Ÿ���� �������� �̾���
//		{
//			if (!_tile[Ci - 1][Cj].listOn)//���¸���Ʈ�� ������ �ȵ� Ÿ���̸�
//			{
//				_tile[Ci - 1][Cj].listOn = true;//���¸���Ʈ�� ���ԵǾ���.
//				_tile[Ci - 1][Cj].color = RGB(220, 255, 220);//
//				_tile[Ci - 1][Cj].G = Cg + 10;//Ÿ���� g���� Ŭ���� ����Ʈ�� ���� G+10
//											  //Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰��� Ÿ�Ϸ� ����
//				_tile[Ci - 1][Cj].parent = _closeList[_lastIndex];
//				_openList.push_back(&_tile[Ci - 1][Cj]);//���¸���Ʈ�� Ǫ��Ǫ�ú��̺�
//
//			}
//			else //���¸���Ʈ�� ������ �Ǿ��ִ� Ÿ���̸�
//			{
//				if (Cg + 10 < _tile[Ci - 1][Cj].G)//���� G������ ���� ��� G���� �۴ٸ�
//				{
//					_tile[Ci - 1][Cj].G = Cg + 10;//���ΰ��
//					_tile[Ci - 1][Cj].parent = _closeList[_lastIndex];
//				}
//			}
//		}
//		//1
//		if (Cj != 0)//�»�� : 0���� ���� �ƴ϶��
//		{
//			//�»�� Ÿ���� �����̳� �Ʒ��� ���� ������
//			if (_tile[Ci - 1][Cj - 1].walkable && _tile[Ci - 1][Cj].walkable && _tile[Ci][Cj - 1].walkable)
//			{
//				if (!_tile[Ci - 1][Cj - 1].listOn)
//				{
//					_tile[Ci - 1][Cj - 1].listOn = true;
//					_tile[Ci - 1][Cj - 1].color = RGB(220, 255, 220);
//					_tile[Ci - 1][Cj - 1].G = Cg + 14;//�밢���̹Ƿ�
//					_tile[Ci - 1][Cj - 1].parent = _closeList[_lastIndex];
//					_openList.push_back(&_tile[Ci - 1][Cj - 1]);
//				}
//				else
//				{
//					if (Cg + 14 < _tile[Ci - 1][Cj - 1].G)
//					{
//						_tile[Ci - 1][Cj - 1].G = Cg + 14;
//						_tile[Ci - 1][Cj - 1].parent = _closeList[_lastIndex];
//					}
//				}
//			}
//		}
//		//3
//		if (Cj != TILE_X - 1)//���� : ������ ���� �ƴϸ�
//		{//���� Ÿ���� �����̳� �Ʒ��� ���� ������
//			if (_tile[Ci - 1][Cj + 1].walkable && _tile[Ci - 1][Cj].walkable && _tile[Ci][Cj + 1].walkable)
//			{
//				if (!_tile[Ci - 1][Cj + 1].listOn)
//				{
//					_tile[Ci - 1][Cj + 1].listOn = true;
//					_tile[Ci - 1][Cj + 1].color = RGB(220, 255, 220);
//					_tile[Ci - 1][Cj + 1].G = Cg + 14;
//					_tile[Ci - 1][Cj + 1].parent = _closeList[_lastIndex];
//					_openList.push_back(&_tile[Ci - 1][Cj + 1]);
//				}
//				else
//				{
//					if (Cg + 14 < _tile[Ci - 1][Cj + 1].G)
//					{
//						_tile[Ci - 1][Cj + 1].G = Cg + 14;
//						_tile[Ci - 1][Cj + 1].parent = _closeList[_lastIndex];
//					}
//				}
//			}
//		}
//	}
//	//4
//	if (Cj != 0)//���� :  0��° ���� �ƴ϶��
//	{
//		if (_tile[Ci][Cj - 1].walkable)//����Ÿ���� �̵����� �ϸ�
//		{
//			if (!_tile[Ci][Cj - 1].listOn)
//			{
//				_tile[Ci][Cj - 1].listOn = true;
//				_tile[Ci][Cj - 1].color = RGB(220, 255, 220);
//				_tile[Ci][Cj - 1].G = Cg + 10;
//				_tile[Ci][Cj - 1].parent = _closeList[_lastIndex];
//				_openList.push_back(&_tile[Ci][Cj - 1]);
//			}
//			else
//			{
//				if (Cg + 10 < _tile[Ci][Cj - 1].G)
//				{
//					_tile[Ci][Cj - 1].G = Cg + 10;
//					_tile[Ci][Cj - 1].parent = _closeList[_lastIndex];
//				}
//			}
//		}
//	}
//	//6
//	if (Cj != TILE_X - 1)//���� : ������ ���� �ƴ϶��
//	{
//		if (_tile[Ci][Cj + 1].walkable)//���� Ÿ���� �̵������ϴٸ�
//		{
//			if (!_tile[Ci][Cj + 1].listOn)
//			{
//				_tile[Ci][Cj + 1].listOn = true;
//				_tile[Ci][Cj + 1].color = RGB(220, 255, 220);
//				_tile[Ci][Cj + 1].G = Cg + 10;
//				_tile[Ci][Cj + 1].parent = _closeList[_lastIndex];
//				_openList.push_back(&_tile[Ci][Cj + 1]);
//			}
//			else
//			{
//				if (Cg + 10 < _tile[Ci][Cj + 1].G)
//				{
//					_tile[Ci][Cj + 1].G = Cg + 10;
//					_tile[Ci][Cj + 1].parent = _closeList[_lastIndex];
//				}
//			}
//		}
//	}
//	if (Ci != TILE_Y - 1)//������ ���� �ƴ϶�� �ϴ� ���� ���
//	{
//		//8
//		if (_tile[Ci + 1][Cj].walkable)//�ϴ� ��� �̵��� �����ϸ�
//		{
//			if (!_tile[Ci + 1][Cj].listOn)
//			{
//				_tile[Ci + 1][Cj].listOn = true;
//				_tile[Ci + 1][Cj].color = RGB(220, 255, 220);
//				_tile[Ci + 1][Cj].G = Cg + 10;
//				_tile[Ci + 1][Cj].parent = _closeList[_lastIndex];
//
//				_openList.push_back(&_tile[Ci + 1][Cj]);
//			}
//			else
//			{
//				if (Cg + 10 < _tile[Ci + 1][Cj].G)
//				{
//					_tile[Ci + 1][Cj].G = Cg + 10;
//					_tile[Ci + 1][Cj].parent = _closeList[_lastIndex];
//				}
//			}
//		}
//		//7
//		if (Cj != 0)// ���ϴ� : 0��° ���� �ƴ϶��
//		{
//			//���ϴ� Ÿ���� �������̳� ���� ���� ������
//			if (_tile[Ci + 1][Cj - 1].walkable && _tile[Ci + 1][Cj].walkable && _tile[Ci][Cj - 1].walkable)
//			{
//				if (!_tile[Ci + 1][Cj - 1].listOn)
//				{
//					_tile[Ci + 1][Cj - 1].listOn = true;
//					_tile[Ci + 1][Cj - 1].color = RGB(220, 255, 220);
//					_tile[Ci + 1][Cj - 1].G = Cg + 14;
//					_tile[Ci + 1][Cj - 1].parent = _closeList[_lastIndex];
//					_openList.push_back(&_tile[Ci + 1][Cj - 1]);
//				}
//				else
//				{
//					if (Cg + 14 < _tile[Ci + 1][Cj - 1].G)
//					{
//						_tile[Ci + 1][Cj - 1].G = Cg + 14;
//						_tile[Ci + 1][Cj - 1].parent = _closeList[_lastIndex];
//					}
//				}
//			}
//		}
//		//9
//		if (Cj != TILE_X - 1)// ���ϴ� :  ������ ���� �ƴ϶��
//		{
//			//���ϴ� Ÿ���� �������̳� ���� �̵� �����ϴٸ�
//			if (_tile[Ci + 1][Cj + 1].walkable && _tile
//				[Ci + 1][Cj].walkable && _tile[Ci][Cj + 1].walkable)
//			{
//				if (!_tile[Ci + 1][Cj + 1].listOn)
//				{
//					_tile[Ci + 1][Cj + 1].listOn = true;
//					_tile[Ci + 1][Cj + 1].color = RGB(220, 255, 220);
//					_tile[Ci + 1][Cj + 1].G = Cg + 14;
//					_tile[Ci + 1][Cj + 1].parent = _closeList[_lastIndex];
//					_openList.push_back(&_tile[Ci + 1][Cj + 1]);
//				}
//				else
//				{
//					if (Cg + 14 < _tile[Ci + 1][Cj + 1].G)
//					{
//						_tile[Ci + 1][Cj + 1].G = Cg + 14;
//						_tile[Ci + 1][Cj + 1].parent = _closeList[_lastIndex];
//					}
//				}
//			}
//		}
//	}
//}
//
//void aStar::calculateH()
//{
//	for (int i = 0; i < _openList.size(); i++)
//	{
//		//��� ����ź�Ÿ��� ���Ѵ�
//		int vertical = (_endX - _openList[i]->j) * 10; //����
//		int horizontal = (_endY - _openList[i]->i) * 10;
//
//		if (vertical < 0) vertical *= -1;		//������ �ݴ�� �����ο�(���밪)
//		if (horizontal < 0)horizontal *= -1;
//
//		_openList[i]->H = vertical + horizontal;//�� H��  : ���� ���ϱ� ����
//
//
//	}
//}
//
//void aStar::calculateF()
//{
//	for (int i = 0; i < _openList.size(); i++)
//	{
//		_openList[i]->F = _openList[i]->G + _openList[i]->H;
//	}
//}
//
//void aStar::addCloseList()
//{
//	if (_openList.size() == 0)//�˻��� ��� ���¸���Ʈ�� ����� 0�̸� ���̻� ã������ - ������(���̻� Ž���� ��尡 ����)
//	{
//		_aStarState = ASTAR_STATE_NOWAY; //��� ����
//		return;			//�۾����
//	}
//
//	int index = 0;					//���� ����Ʈ�� ���� F�� ���� Ÿ���� �ε���
//	int lowest = BIGNUM;			//���� ����Ʈ�� ���� ���� F��
//
//	for (int i = 0; i < _openList.size(); i++)
//	{
//		if (_openList[i]->F < lowest)//���� ����Ʈ�� F�� ���������� ���� �� ������
//
//		{
//			lowest = _openList[i]->F;			//lowest�� F�� �ٲ�
//			index = i;
//		}
//	}
//	_openList[index]->color = RGB(180, 180, 255);//
//
//	_closeList.push_back(_openList[index]);		//Ŭ���� ����Ʈ �߰�
//	_openList.erase(_openList.begin() + index);//Ŭ���� ����Ʈ�� �߰��� Ÿ���� ���� ����Ʈ���� ��������
//
//	_lastIndex++;
//}
//
//void aStar::checkArrive()
//{
//	//Ŭ�����Ʈ�� i j�� ���������� ���ٸ�
//	if (_closeList[_lastIndex]->i == _endY && _closeList[_lastIndex]->j == _endX)
//	{
//		_aStarState = ASTAR_STATE_FOUND;		//���̽��ϰ� ã��
//		_closeList[_lastIndex]->color = RGB(255, 0, 0); //�������� ����
//		showWay(_closeList[_lastIndex]);//��θ� �����ּ�
//	}
//}
//void aStar::showWay(aStarTile * tile)
//{
//	if (!(tile->i == _endY && tile->j == _endX))//�������� �ƴϸ�
//		tile->color = RGB(255, 0, 255);//
//	tile = tile->parent;//Ÿ���� �θ� �����ؼ� showway�Լ��� �ٽ� ����
//
//	if (tile->parent == NULL) {//Ÿ���� �θ� ���������̸� �׸� ������ ����
//		return;
//	}
//
//	else
//		showWay(tile);//�ٽ� �θ���
//
//
//
//}
