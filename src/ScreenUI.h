#pragma once

#include "Const.h"
#include "Layers.h"
#include "Cursor.h"
#include "PaintPlusUI.h"

class ToolsbarUI;
class ScreenUI : public Layout
{
public:
	ScreenUI();
	virtual ~ScreenUI();
	void Init();
	const RECT& GetPos() const;
protected:
	//duilib
	void DoPaint(HDC hDC, const RECT& rcPaint);
	void Event(DuiLib::TEventUI& event);
	void SetPos(RECT rc);
protected:
	RECT	FindWinRect(const POINT &pt);
	UINT	GetControlFlags() const;
	bool	CanMove( const RECT& rc );
	void	Move(long x,long y);
	void	UpdateTrackDotPos();
	void	UpdateToolsPos();
	void	TrackDotMove(const DuiLib::TEventUI& ev);
	void	VisibleTrackDot(bool bV);
	bool	PtInSel(POINT pt);
	CAtlString	DoSave(bool bShowDlg);
	void	CopyToClipboard(const CAtlString& file);
	void  CopyBitmapToClipboard();
private:
	CAtlString					savepath_;
	DuiLib::CControlUI	*ui_move_;		//��ק�Ŀؼ�
	RECT							rcTrue_;		//ͨ��ms�õ�client rcû�а�����������������ֵ
	Layers						layers_;		//���Ʋ�
	Layers::Layer				*draw_layer;	//��ͼ��

	Cursor						cursor_;		//ָ��
	Gdiplus::Bitmap			*cur_screen_;	//��ǰ��Ļbitmap
	RECT							cur_sel_;		//��ǰѡ������
	std::vector<RECT>	top_wins_;		//���ж��㴰��
	long							draw_states_;	//��ͼ״̬
	POINT						cur_pt_;		//����ĵ�ǰָ�����ڹ������õ�MOUSEMOVE�¼��������Ч��
	capture::DRAW_CAP	draw_cap_;		//����ͼ��
	ToolsbarUI				*tools_;			
	//
	DuiLib::CControlUI	*showrc_;		//��ʾrect����
	LONG						lclicktm_;		//��갴��ʱ��
};