//͸��ͼ��
#pragma once

#include "const.h"
class Layers
{
public:
	Layers(void);
	virtual ~Layers(void);
	class Layer
	{
	public:
		Layer(long nW,long nH);
		virtual ~Layer();
		virtual void draw(HWND win,DuiLib::TEventUI *ev,Gdiplus::Pen *pen,Gdiplus::SolidBrush *br=NULL,Gdiplus::Font *ft=NULL)
		{			}
		virtual void	paint(Gdiplus::Graphics *g,RECT rc);
		virtual void	limitRc(const RECT &rc );
		virtual void	font(const capture::FontInfo &ftInfo);

		Gdiplus::Graphics*		graphic();
		Gdiplus::GraphicsPath*	path();
		void clear();
	public:
		POINT pt_;								//x,y
		capture::FontInfo		ftInfo_;		//
		Gdiplus::Bitmap			*bitmap_;		//ͼ��
		Gdiplus::Pen			*pen_;			//		
		bool					bVisible_;		//��ʾ������
	protected:
		Gdiplus::GraphicsPath	*path_;			//
		Gdiplus::Graphics		*graphic_;		//
		RECT					rclimit_;
		friend Layers;
	};
	//�½�һ��
	Layer*	push(capture::DRAW_CAP cap,long nW,long nH);
	//��ǰͼ��
	Layer*	current();
	//��������ͼ��
	virtual void	paint(Gdiplus::Graphics *g,RECT rc);
	//����
	virtual bool undo();
	//�ָ�
	virtual bool redo();
	void	clear();
	void	move(long nX,long nY);
	long	countLayerVisible();
	Layer*	getLayerAtLast();
	Gdiplus::Bitmap* build(Gdiplus::Bitmap *draw,RECT rc);
	bool	save(Gdiplus::Bitmap *draw,RECT rc,const CAtlString &str);
protected:
	typedef std::vector<Layer*>	Ones;
private:
	Ones			all_;		//���е�ͼ��
	Ones			lst_redo_;	//�ָ��б�
	Layer			*cur_;		//��ǰ��ʹ�õ�ͼ��
	Gdiplus::Bitmap *cur_build_;//��ǰ���ɵ�bitmapͼ
};