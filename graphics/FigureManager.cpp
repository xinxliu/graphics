#include "stdafx.h"
#include "FigureManager.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
vector<Factory*> g_Factories;

//中文支持测试
//中文支持测试
//中文支持测试
int FigureManager::_languageFlags = 0;

void FigureManager::languageSet(int Flags)
{
	_languageFlags = Flags;
}

const int FigureManager::checkLanguageFlags()
{
	return _languageFlags;
}

int Factory::_FacCount = 0;
void FigureManager::input()
{
	int flags;
	output();
	cin >> flags;
	if (flags == -1)
	{
		output(2);
		return;
	}
	do
	{
		if ((flags >= 0) && (flags < Factory::_FacCount))
		{
			_count++;
			if (isEmpty())
			{
				_end = new Node;
				_begin->next = _end;
			}
			else
			{
				Node *temp = new Node;
				_end->next = temp;
				_end = temp;
			}
			_end->pointer = g_Factories[flags]->figureCreate();
			_end->pointer->figureInput();
			output(3);
			output();
		}
		else
		{
			output(1);
		}

	} while (cin >> flags, flags != -1);
	output(2);

}

void FigureManager::display(int orderFlags, int typeFlags)
{
	if (_count == 0)
	{
		if (_languageFlags == 0)
		{
			cout << "尚未收录任何图形！" << endl;
		}
		else if (_languageFlags == 1)
		{
			cout << "There is no figure at all!" << endl;
		}
		return;
	}
	if (typeFlags == ALL)
	{
		if (orderFlags == byTime)
		{
			if (_languageFlags == 0)
			{
				cout << "共有" << _count << "个图形" << endl;
			}
			else if (_languageFlags == 1)
			{
				cout << "there are " << _count << " figures" << endl;
			}
			Node *tmp = _begin;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				tmp->pointer->figureShow();
			}
		}
		else if (orderFlags == byName)
		{
			if (_languageFlags == 0)
			{
				cout <<endl<< "共有" << _count << "个图形";
				cout << endl << "按照名称排序: " << endl;
							}
			else if (_languageFlags == 1)
			{
				cout <<endl<< "there are " << _count << " figures";
				cout << endl << "Sorted by Name: " << endl;
				
			}

			for (int tmpID = 0, tmpCnt = 0; tmpCnt < _count; tmpID++)
			{
				Node *tmp = _begin;
				while (tmp->next != NULL)
				{
					tmp = tmp->next;
					if (tmp->pointer->checkFigureID() == tmpID)
					{
						tmp->pointer->figureShow();
						++tmpCnt;
					}
				}
			}
		}
	}
	else if (typeFlags == CURRENT)
	{
		if (checkLanguageFlags() == 0)
		{
			cout << endl << "模式：输出当前值" << endl;
		}
		else if (checkLanguageFlags() == 1)
		{
			cout << endl << "mode:output CURRENT" << endl;
		}
		if (_count != 0)
		{
			_end->pointer->figureShow();
		}
	}
}

bool FigureManager::isEmpty()
{
	if (_begin == _end)
	{
		return true;
	}
	return false;
}

void FigureManager::output(int flags)
{
	if (flags == 0)
	{
		if (_languageFlags == 0)
		{

			cout << endl << "请输入图形的种类：" << endl;
			for (int i = 0; i < Factory::_FacCount; i++)
			{
				cout << i << ": " << g_Factories[i]->figureName(0) << endl;
			}
			cout << "-1: 结束" << endl;
		}
		else if (_languageFlags = 1)
		{
			cout << endl << "please input the kind of the figure:" << endl;
			for (int i = 0; i < Factory::_FacCount; i++)
			{
				cout << i << ": " << g_Factories[i]->figureName(1) << endl;
			}
			cout << "-1: end of input" << endl << endl;
		}
	}
	else if (flags == 1)
	{
		if (_languageFlags == 0)
		{
			cout << endl << "请输入有效的数字！" << endl << endl;
		}
		else if (_languageFlags == 1)
		{
			cout << endl << "please input valid number!" << endl << endl;
		}
	}
	else if (flags == 2)
	{
		if (_languageFlags == 0)
		{
			cout << endl << "退出输入状态中..." << endl;
			cout << "退出成功！" << endl << endl;
		}
		else if (_languageFlags == 1)
		{
			cout << endl << "exit inputing..." << endl;
			cout << "exiting successful!" << endl << endl;
		}
	}
	else if (flags == 3)
	{
		if (_languageFlags == 0)
		{
			cout << endl << "数据保存中..." << endl;
			cout << "数据保存成功！" << endl << endl;
		}
		if (_languageFlags == 1)
		{
			cout << endl << "saving data..." << endl;
			cout << "succeed saving data!" << endl << endl;
		}
	}
}

void Line::figureShow()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "线段(" << x1 << "," << y1 << ","
			<< x2 << "," << y2 << ")" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "Line(" << x1 << "," << y1 << ","
			<< x2 << "," << y2 << ")" << endl;
	}
}

void Line::figureInput()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "请输入线段的起点和终点坐标(x1,y1,x2,y2)" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "please input the start and end point(x1,y1,x2,y2)"
			<< endl;
	}
	cin >> x1 >> y1 >> x2 >> y2;
}

int Line::checkFigureID() const
{
	return figureID;
}

void Rectangle::figureShow()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "矩形(" << left << "," << top << ","
			<< right << "," << bottom << ")" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "Rectangle(" << left << "," << top << ","
			<< right << "," << bottom << ")" << endl;
	}
}

void Rectangle::figureInput()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "请输入矩形的左上角和右下角坐标(x1,y1,x2,y2)" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "please input the the leftup and rightdown point(x1,y1,x2,y2)" << endl;
	}
	cin >> left >> top >> right >> bottom;
}

void Circle::figureShow()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "圆(" << x << "," << y << ","
			<< radius << ")" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "Circle(" << x << "," << y << ","
			<< radius << ")" << endl;
	}
}

void Circle::figureInput()
{
	if (FigureManager::checkLanguageFlags() == 0)
	{
		cout << "请输入圆的圆心坐标和半径(x，y，radius)" << endl;
	}
	else if (FigureManager::checkLanguageFlags() == 1)
	{
		cout << "please input the center and radius(x,y,radius)" << endl;
	}
	cin >> x >> y >> radius;
}

