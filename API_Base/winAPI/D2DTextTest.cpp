#include "stdafx.h"
#include "D2DTextTest.h"


D2DTextTest::D2DTextTest()
{
}


D2DTextTest::~D2DTextTest()
{
}
D2DTextTest*      D2DTextTest::TextInst = NULL;

void    D2DTextTest::Init(void)
{
	D3DXFONT_DESC DXFont_DESC;
	ZeroMemory(&DXFont_DESC, sizeof(D3DXFONT_DESC));

	DXFont_DESC.Height = 15;                            // ��ü ���� ����
	DXFont_DESC.Width = 15;                             // ��ü ���� ����
	DXFont_DESC.Weight = FW_NORMAL;                     // ���� ���� ( FW_BOLD �ϸ� ���� )
	DXFont_DESC.MipLevels = D3DX_DEFAULT;
	DXFont_DESC.Italic = false;                         // ���ڸ�
	DXFont_DESC.CharSet = DEFAULT_CHARSET;
	DXFont_DESC.OutputPrecision = OUT_DEFAULT_PRECIS;
	DXFont_DESC.Quality = DEFAULT_QUALITY;
	DXFont_DESC.PitchAndFamily = DEFAULT_PITCH;
	DXFont_DESC.FaceName, TEXT("����ü");              // �۾�ü
	m_nMax_X = 1280;                               // ������ �ִ� X
	m_nMax_Y = 960;                                // ������ �ִ� Y
	//D3DXCreateFontIndirect(D3DFRAME->GetDevice(), &DXFont_DESC, &m_pFont);
}

void    D2DTextTest::Print(LPCSTR cSTR, int nX/*���ڿ��� ������ǥ*/, int nY/*���ڿ��� ������ǥ*/, D3DXCOLOR ARGB)
{
	RECT rt = { nX, nY, m_nMax_X, m_nMax_Y };

#ifdef UNICODE // �����ڵ� �κ�
	m_pFont->DrawTextW(0, cSTR, -1, &rt, DT_TOP | DT_LEFT, ARGB);

#else
	m_pFont->DrawTextA(0, cSTR, -1, &rt, DT_TOP | DT_LEFT, ARGB);

#endif
}

D2DTextTest*  D2DTextTest::GetInst(void)
{
	if (!TextInst)
	{
		TextInst = new D2DTextTest;
		//RSCMGR->m_bTEXT_MGR = true;
	}
	return TextInst;
}

void    D2DTextTest::FreeInst(void)
{
	if (TextInst)
	{
		m_pFont->Release();
		delete  TextInst;
		TextInst = NULL;
		//RSCMGR->m_bTEXT_MGR = false;
	}
}
