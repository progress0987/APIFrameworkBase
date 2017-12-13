#pragma once

//http://www.gisdeveloper.co.kr/?p=3897

struct ANode {
	int x, y;			//좌표
	DWORD N, S, E, W;	//북,남,동,서 의 가중치 값
	ANode* Parent;		//부모 노드
	//DWORD Depth;		//분기로부터 받아온 깊이
	DWORD F, G, H;		//F : 총 값, G : 시점에서 현재까지의 값, H : 현재에서 종점까지의 값
};


class Astar
{
private:
	list<ANode> CQueue;		//닫힌 큐
	list<ANode> OQueue;		//열린 큐
	ANode* Sour;			//시작 노드
	ANode* Cur;
	ANode* Dest;			//목적지 노드
	ANode** Map;			//현재의 맵
	int depth;
public:
	void setMap(ANode** begin) { Map = begin; }
	list<ANode> findPath(ANode* from, ANode* to);
	Astar();
	~Astar();
};

