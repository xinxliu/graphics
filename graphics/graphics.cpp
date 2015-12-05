// graphics.cpp : 定义控制台应用程序的入口点。
////////////////////作业说明/////////////////////////////////
///////////////131180003  刘鑫鑫/////////////////////////////
/////请阅读文档“readme.txt”了解这份作业的情况/////////////////

#include "stdafx.h"
#include "FigureManager.h"
#include <stdlib.h>
#include <iostream>
#include "graphics.h"
using std::cout;
int main()
{	
	
	g_Factories.push_back(new LineFactory);
	g_Factories.push_back(new RectangleFactory);
	g_Factories.push_back(new CircleFactory);
	FigureManager manager;
	manager.input();
	//按默认方式显示（按时间顺序显示全部）
	manager.display();  
	//按名称排序显示
	manager.display(byName);
	//仅显示最后一个收录的图形
	manager.display(byName, CURRENT);
	//切换语言为英文
	manager.languageSet(ENGLISH);
	manager.input();
	manager.display();
	manager.display(byName);	
	//收录三角形到图形管理器中，扩展代码见"graphics.h"
	g_Factories.push_back(new TriangleFactory);
	manager.input();
	manager.display(byName);


	system("pause");
	return 0;
}

