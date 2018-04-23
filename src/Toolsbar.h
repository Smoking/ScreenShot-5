#pragma once

#include "PaintPlusUI.h"
class ToolsbarUI : public PaintPlusUI<DuiLib::CHorizontalLayoutUI>
				 , public DuiLib::INotifyUI
{
public:
	ToolsbarUI(void);
	~ToolsbarUI(void);
	void Init();
	void SetVisible(bool bVisible = true);
	void SetPos(RECT rc);
	void DoPaint(HDC hDC, const RECT& rcPaint);
	void Event(DuiLib::TEventUI& event);
	void SetUserINI(const CString& ini);	
	void LoadFromINI(capture::DRAW_CAP cap,const CString& ini);
	void SetCurShape(capture::DRAW_CAP cap);
	void SaveShapeINI();
	void AppearFromStore();
public:
	Gdiplus::Pen		sel_pen_;	//ѡ��Ļ���
	capture::FontInfo	sel_ft_;	//ѡ�������
protected:
	void Notify(DuiLib::TNotifyUI& msg);
	void ShowTools(const CAtlString& showpart);
	ARGB GetDefaultColor();
	LONG GetDefaultSize();
protected:
	class DrawConfig{
	public:
		capture::DRAW_CAP shape_;	//ͼ��
		Gdiplus::Color	  color_;   //��ɫ
		long			  size_;    //��С
	};
	typedef std::map<capture::DRAW_CAP,DrawConfig> STORE;
	bool				hasInit_;
	CString				userINI_;
	STORE				param_;
	capture::DRAW_CAP   cur_cap_;
};