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
public:
	Gdiplus::Pen		sel_pen_;	//ѡ��Ļ���
	capture::FontInfo	sel_ft_;	//ѡ�������
protected:
	void Notify(DuiLib::TNotifyUI& msg);
	void ShowTools(const CAtlString& showpart);
};