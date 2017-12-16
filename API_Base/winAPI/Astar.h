#pragma once

//http://www.gisdeveloper.co.kr/?p=3897

struct ANode {
	int x, y;			//��ǥ
	DWORD N, S, E, W;	//��,��,��,�� �� ����ġ ��
	ANode* Parent;		//�θ� ���
	//DWORD Depth;		//�б�κ��� �޾ƿ� ����
	DWORD F, G, H;		//F : �� ��, G : �������� ��������� ��, H : ���翡�� ���������� ��
};


class Astar
{
private:
	list<ANode> CQueue;		//���� ť
	list<ANode> OQueue;		//���� ť
	ANode* Sour;			//���� ���
	ANode* Cur;
	ANode* Dest;			//������ ���
	ANode** Map;			//������ ��
	int depth;
public:
	void setMap(ANode** begin) { Map = begin; }
	list<ANode> findPath(ANode* from, ANode* to);
	Astar();
	~Astar();
};


#pragma once
#include"gameNode.h"

#define TILE_X 20//����
#define TILE_Y 20//����
#define WIDTH  40//Ÿ�ϰ��α���
#define HEIGHT 40//Ÿ�ϼ��α���
#define BIGNUM 5000//����� ū F��(�ʱⰪ)

//Ÿ���� �Ӽ��� ���غ���
enum TILE_TYPE
{
	TILE_TYPE_EMPTY,		//��Ÿ��(�������� �ִ°�)
	TILE_TYPE_START,		//����
	TILE_TYPE_END,			//��
	TILE_TYPE_WALL			//��ֹ�
};

//���°�
enum ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,		//�˻���
	ASTAR_STATE_FOUND,			//�߰�
	ASTAR_STATE_NOWAY,			//�������
	ASTAR_STATE_END				//Ÿ�� ��ġ �Ϸ� ��
};

//Ÿ�� ����ü
struct aStarTile
{
	RECT rc;
	COLORREF color;
	bool walkable;			//���������̛X��
	bool listOn;			//���¸���Ʈ�� �߰� �Ǿ���
	int i, j;				//�迭�� �ε���

	int F = 0;
	int G = 0;
	int H = 0;
	char str[128];
	aStarTile* parent;		//�θ�Ÿ�� �ּ�
	TILE_TYPE type;//Ÿ�� �Ӽ�

};


class aStar : public gameNode
{

private:

	aStarTile _tile[TILE_X][TILE_Y];
	vector<aStarTile*>_openList;
	vector<aStarTile*> _closeList;


	ASTAR_STATE _aStarState;


	TILE_TYPE _selectedType;		//Ÿ�� ��ġ�Ҷ� ����� �Ӽ��༮
	COLORREF _selectedTypeColor;	//Ÿ�� ��ġ�Ҷ� ����� Ÿ�ϻ�	


	int _startX, _startY;		//���������� i,j
	int _endX, _endY;			//����
	int _lastIndex;				//���� ���߿� �߰��� Ŭ���� ����Ʈ�� �ε���

	bool _startPointSet;		//���������� ��ġ �Ǿ���
	bool _endPointSet;			//���������� ��ġ �Ǿ���

	int Ci;						//���������� �߰��� Ŭ���� ����Ʈ�� i
	int Cj;						//���������� �߰��� Ŭ���� ����Ʈ�� j
	int Cg;						//���������� �߰��� Ŭ���� ����Ʈ�� g

public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	void tileComposition();//Ÿ�� ��ġ
	void tileInitializing();//Ÿ�� ��ġ�� �Ӽ��� �°� Ÿ���� �ʱ�ȭ
	void addOpenList();		//���¸���Ʈ �߰�
	void calculateH();		//���¸���Ʈ �� Ÿ���� H���
	void calculateF();		//���¸���Ʈ �� Ÿ���� F���
	void addCloseList();		//���� ���� F ������ Ŭ���� ����Ʈ���߰�
	void checkArrive();		//�����ߴ��� ���� üũ

	void showWay(aStarTile* tile);//���� �� ���������� ���������� �մ� ��θ� ��������
	aStar();
	~aStar();
};

