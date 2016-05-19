#ifndef _GRAPHICD_H_
#define _GRAPHICS_H_

#include "FigureManager.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

class Triangle :public Figure
{
public:
	Triangle() :
		figureID(3)
	{

	}
	const int figureID;
	double x1, y1, x2, y2, x3, y3;
	void figureShow();
	void figureInput();
	int checkFigureID() const
	{
		return figureID;
	}
};

void Triangle::figureShow()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "三角形(" << x1 << "," << y1 << ","
			<< x2 << "," << y2 << "," << x3 << "," << y3 << ")" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "Triangle(" << x1 << "," << y1 << ","
			<< x2 <<","<< y2<<"," << x3<<"," << y3 << ")" << endl;
	}
}

void Triangle::figureInput()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "请输入三角形的三个坐标(x1,y1,x2,y2,x3,y3)" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "please input the three point(x1,y1,x2,y2,x3,y3)" << endl;
	}
	cin >> x1 >> y1 >> x2>>y2>>x3>>y3;
}

class TriangleFactory :public Factory
{
public:
	TriangleFactory() 
	{
		_FacCount++;
	}
	Figure *figureCreate()
	{
		return new Triangle;
	}
	string figureName(int flags)
	{
		if (flags == ENGLISH)
		{
			return "Triangle";
		}
		else if (flags == CHINESE)
		{
			return "三角形";
		}
	}
};


#endif