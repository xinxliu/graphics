#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_
#include <string>
#include <vector>
using std::vector;
using std::string;
//define flags for display language
enum languageFlags
{
	CHINESE = 0,
	ENGLISH = 1,
};
//define flags for display order
enum display_order
{
	byTime = 0,
	byName = 1
};
//define flags for display type
//ALL:display all the figures
//CURRENT:the most recent figure
enum display_type
{
	ALL = 0,
	CURRENT = 1
};

class Figure
{
public:
	virtual void figureShow() = 0;
	virtual void figureInput() = 0;
	virtual int checkFigureID() const = 0;
};

class Node
{
public:
	Node() :
		pointer(NULL),
		next(NULL)
	{

	}
	~Node()
	{

	}
	Figure *pointer;
	Node *next;
};

class FigureManager
{
public:
	FigureManager() :
		_count(0)
	{
		_begin = new Node;
		_end = _begin;
	}
	~FigureManager()
	{
		while (_begin != NULL)
		{
			Node *tmp = _begin;
			_begin = _begin->next;
			delete tmp->pointer;
			delete tmp;
		}
	}
	void languageSet(int Flags = 0);
	static const int checkLanguageFlags();
	virtual void input();
	//orderFlags decide the display order
	//orderType decide the display type:current or all
	void display(int orderFlags = 0, int typeFlags = 0);
private:
	bool isEmpty();
	//0:tips for shape inputing
	//1:invalid number inputing
	//2:-1 exiting
	//3:saving success
	void output(int flags = 0);
	Node *_begin;
	Node *_end;
	int _count;
	static int _languageFlags;
};

class Line :public Figure
{
public:
	Line() :
		figureID(0)
	{

	}
	const int figureID;
	double x1, y1, x2, y2;
	void figureShow();
	void figureInput();
	int checkFigureID() const;
};

class Rectangle :public Figure
{
public:
	Rectangle() :
		figureID(1)
	{

	}
	const int figureID;
	double left, top, right, bottom;
	void figureShow();
	void figureInput();
	int checkFigureID() const
	{
		return figureID;
	}
};

class Circle :public Figure
{
public:
	Circle() :
		figureID(2)
	{

	}
	const int figureID;
	double x, y, radius;
	void figureShow();
	void figureInput();
	int checkFigureID() const
	{
		return figureID;
	}
};

class Factory
{
public:
	virtual Figure* figureCreate() = 0;
	virtual string figureName(int flags = 0) = 0;
	static int _FacCount;
};

class LineFactory :public Factory
{
public:
	LineFactory()
	{
		_FacCount++;
	}
	Figure *figureCreate()
	{
		return new Line;
	}
	string figureName(int flags)
	{
		if (flags == CHINESE)
		{
			return "线段";
		}
		else if (flags == ENGLISH)
		{
			return "Line";
		}
		return "flags error";
	}
};

class RectangleFactory :public Factory
{
public:
	RectangleFactory()
	{
		_FacCount++;
	}
	Figure *figureCreate()
	{
		return new Rectangle;
	}
	string figureName(int flags)
	{
		if (flags == CHINESE)
		{
			return "矩形";
		}
		else if (flags == ENGLISH)
		{
			return "Rectangle";
		}
		return "flags error";
	}
};

class CircleFactory :public Factory
{
public:
	CircleFactory()
	{
		_FacCount++;
	}
	Figure *figureCreate()
	{
		return new Circle;
	}
	string figureName(int flags)
	{
		if (flags == ENGLISH)
		{
			return "Circle";
		}
		else if (flags == CHINESE)
		{
			return "圆";
		}
	}
};

extern vector<Factory*> g_Factories;

#endif
