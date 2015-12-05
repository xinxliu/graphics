========================================================================
    控制台应用程序：graphics 项目概述
========================================================================
功能说明：
	1.图形管理类FigureManager中内置Line、Rectangle、Circle三种图形
	2.支持按照名称或添加时间进行排序显示图形
	3.支持中英文切换
	4.支持新增图形，并且新增图形的输入、显示都可以自行定义

源文件说明：
graphics.cpp 为main()函数所在的文件；
graphics.h   为项目扩展性范例（以添加三角形为例）

FigureManager.cpp & FigureManager.h是项目实现的代码，包含FigureManager,Figure,Factory等基类
及其派生类以及用以存储图形信息的Node类的实现代码。

接口说明：
	
		


	图形管理类figureManager：
		函数：
		void languageSet(int Flags = 0):此函数用来进行语言设定，参数Flags由
		枚举类型languageFlags定义：
		    enum languageFlags
			{
				CHINESE = 0,
				ENGLISH = 1,
			};
		默认为CHINESE(0)。通过languageSet(ENGLISH)可以切换为英文。

		static const int checkLanguageFlags()：此函数用来返回每个图形类的唯
		一标识，该标识被定义为一个非负整型数值。

		void input()：此函数用于向图形管理类输入图形。

		void display(int orderFlags = 0,int typeFlags = 0 )：
		此函数用来显示已存储的图形。
		参数orderFlags由枚举类型display_order定义：
			enum display_order
			{
				byTime = 0,
				byName = 1
			};
		默认为byTime(0),按照存储时间顺序来显示，取值为byName时，按照名称排序显示。
		参数typeFlags由枚举类型display_type定义：
			enum display_type
			{
				ALL = 0,
				CURRENT = 1
			};
		默认为ALL(0)，显示全部。CURRENT(1)为显示最近存储的一个图形。
	图形创建管理类Factory:
		函数：
			Figure* figureCreate()；用于创建图形
			string figureName(int flags = 0)；用于得到该图形的名字，flags用于中英文切换

	扩展性：
		可直接继承抽象类figure和Factory扩展并创建新的图形。
		文件"graphics.h"是一个扩展的范例（以三角形为例）
		figure类接口有：
		virtual void figureShow() = 0;
		virtual void figureInput() = 0;
		virtual int checkFigureID() const = 0;
		
		figureShow()是显示图形,显示方式可以自行定义；
		figureInput()是输入图形数据，可以自行定义；
		chenckFigureID()是返回图形的ID，要求是非负整形数值，且不可以和已有的（0，1，2）冲突。
		可通过定义一个整形常量实现。
		