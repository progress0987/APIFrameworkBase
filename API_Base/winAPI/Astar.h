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

