// graphics.cpp : �������̨Ӧ�ó������ڵ㡣
////////////////////��ҵ˵��/////////////////////////////////
///////////////131180003  ������/////////////////////////////
/////���Ķ��ĵ���readme.txt���˽������ҵ�����/////////////////

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
	//��Ĭ�Ϸ�ʽ��ʾ����ʱ��˳����ʾȫ����
	manager.display();  
	//������������ʾ
	manager.display(byName);
	//����ʾ���һ����¼��ͼ��
	manager.display(byName, CURRENT);
	//�л�����ΪӢ��
	manager.languageSet(ENGLISH);
	manager.input();
	manager.display();
	manager.display(byName);	
	//��¼�����ε�ͼ�ι������У���չ�����"graphics.h"
	g_Factories.push_back(new TriangleFactory);
	manager.input();
	manager.display(byName);


	system("pause");
	return 0;
}

