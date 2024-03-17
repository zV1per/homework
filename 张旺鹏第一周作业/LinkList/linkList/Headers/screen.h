#pragma once
#include "button.h"
#include <graphics.h>
#include "linkedlist.h"

class screen
{
private:
	button addpiont, deletepiont,invert,upsidedown,search,num1, num2, num3, num4, num5, num6, num7, num8, num9, num0, numok, numdelete;
	linkedlist a;
	void init();
	void draw_line();
	void draw_list();
	void draw();
public:
	screen() :
		addpiont(20, 20, 250, 100, L"添加节点", 60),
		deletepiont(20, 170, 250, 100, L"删除节点", 60),
		invert(20, 320, 250, 100, L"奇偶调换", 60),
		upsidedown(20, 470, 250, 100, L"前后颠倒", 60),
		search(20, 620, 250, 100, L"搜索数据", 60),
		num1(350, 340, 120, 80, L"1", 80),
		num2(520, 340, 120, 80, L"2", 80),
		num3(690, 340, 120, 80, L"3", 80),
		num4(350, 440, 120, 80, L"4", 80),
		num5(520, 440, 120, 80, L"5", 80),
		num6(690, 440, 120, 80, L"6", 80),
		num7(350, 540, 120, 80, L"7", 80),
		num8(520, 540, 120, 80, L"8", 80),
		num9(690, 540, 120, 80, L"9", 80),
		numdelete(350, 640, 120, 80, L"<-", 80),
		num0(520, 640, 120, 80, L"0", 80),
		numok(690, 640, 120, 80, L"ok", 80) {}
	int run();
};

