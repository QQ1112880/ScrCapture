#ifndef DRAWGRAPH_H_
#define DRAWGRAPH_H_
#include "Define.h"
#include "RectEx.h"

class IGraph
{
public:
	IGraph(){
		m_penWidth = 1;
	}
	virtual ~IGraph(){
	}
	
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd) = 0;
	virtual void DrawGraph(HDC hDC) = 0;
	virtual bool PtInRect(const POINT& pt) = 0;
	virtual void SetPen(int nPenWidth, COLORREF dwPenColor, const RectX& rcRgn) {
		m_penWidth = nPenWidth;
		m_penColor = Gdiplus::Color(GetBValue(dwPenColor), GetGValue(dwPenColor), GetRValue(dwPenColor));
		m_canvasRc = rcRgn;
	}
	virtual RectX GetRectX() {
		return m_itemRc;
	}
protected:
	RectX m_itemRc;
	RectX m_canvasRc;//������С
	int m_penWidth;
	Gdiplus::Color m_penColor;
};

//==========GraphRectangle============
class GraphRectangle : public IGraph
{
public:
	GraphRectangle(){
	}
	~GraphRectangle(){
	}
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
};

//==========GraphEllipse============
class GraphEllipse : public IGraph
{
public:
	GraphEllipse() {
	}
	~GraphEllipse() {
	}
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
};


//==========GraphLine============
class GraphLine : public IGraph
{
public:
	GraphLine() {
	}
	~GraphLine() {
	}
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
};



//==========GraphArrow============
class GraphArrow : public IGraph
{
public:
	GraphArrow() {
	}
	~GraphArrow() {
	}
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
private:
	void LineArrow(HDC pDC, POINT p1, POINT p2, double theta, double alpha, int length, COLORREF clr, int size);
};



//==========GraphScrawl============
class GraphScrawl : public IGraph
{
public:
	GraphScrawl() {
	}
	~GraphScrawl() {
	}
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
private:
	std::vector<POINT> m_pointList;
};


//==========GraphHighlight============
class GraphHighlight : public IGraph
{
public:
	GraphHighlight() {
	}
	~GraphHighlight() {
	}
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
private:
	std::vector<POINT> m_pointList;
};


//==========GraphMosaic============
class GraphMosaic : public IGraph
{
public:
	GraphMosaic() {
	}
	~GraphMosaic() {
	}
	static Gdiplus::Bitmap* s_maskBitmap;
	static void SetMaskBitMap(Gdiplus::Bitmap* bitMap);
public:
	virtual void ResetGraphPos(POINT ptStart, POINT ptEnd);
	virtual bool PtInRect(const POINT& pt);
	virtual void DrawGraph(HDC hDC);
private:
	std::vector<POINT> m_pointList;
};


//==========GraphFactory============
class GraphFactory
{
public:
	GraphFactory(){}
	virtual ~GraphFactory(){}
public:
	static IGraph* CreateGraph(ACTION_OP op);
};

#endif // !COMPONENT_H_