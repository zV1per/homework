#include "screen.h"

IMAGE* QG ;
LPCTSTR reminder{ L"链表为空，请先添加节点" };
TCHAR t[100],s[100];
int input = 0;
int state = 0;
int numm = 0, dataa = 0;

void screen::init()
{
	setbkcolor(RGB(230, 230, 230));
	draw_line();
	draw();
}

void screen::draw_line()
{
	LINESTYLE bigline;
	bigline.thickness = 60;
	setlinestyle(&bigline);
	setlinecolor(RGB(150, 150, 150));
	line(310, 0 , 310, 750 );
	line(850, 0, 850, 750);
	line(310, 300, 850, 300);
	bigline.thickness = 1;
	setlinestyle(&bigline);
}

void screen::draw_list()
{
	TCHAR w[20];
	settextstyle(40, 0, _T("Consolas"));
	for (int i = 1; i <= a.Getlength(); i++)
	{
		_sntprintf_s(w, _countof(w), _T("#%d\t->%d"), i, a.Getdata(i));
		outtextxy(900, 20+(i-1)*50, w);
	}
	settextstyle(80, 0, _T("Consolas"));
}

void screen::draw()
{
	cleardevice();
	loadimage(QG, L"QG.jpg", 1200, 750, 0);
	addpiont.draw();
	deletepiont.draw();
	invert.draw();
	upsidedown.draw();
	search.draw();
	num1.draw();
	num2.draw();
	num3.draw();
	num4.draw();
	num5.draw();
	num6.draw();
	num7.draw();
	num8.draw();
	num9.draw();
	num0.draw();
	numok.draw();
	numdelete.draw();
	draw_line();
	draw_list();
	settextstyle(40, 0, _T("Consolas"));
	outtextxy(350, 20, reminder);
	outtextxy(350, 60, t);
	settextstyle(80, 0, _T("Consolas"));
	FlushBatchDraw();
}

int screen::run()
{
	init();
	ExMessage m;
	BeginBatchDraw();
	while (true)
	{
		if (peekmessage(&m, EX_MOUSE))
		{
			switch (m.message)
			{
			case WM_MOUSEMOVE:

				addpiont.checkMouseOver(m.x, m.y);
				deletepiont.checkMouseOver(m.x, m.y);
				invert.checkMouseOver(m.x, m.y);
				upsidedown.checkMouseOver(m.x, m.y);
				search.checkMouseOver(m.x, m.y);
				num1.checkMouseOver(m.x, m.y);
				num2.checkMouseOver(m.x, m.y);
				num3.checkMouseOver(m.x, m.y);
				num4.checkMouseOver(m.x, m.y);
				num5.checkMouseOver(m.x, m.y);
				num6.checkMouseOver(m.x, m.y);
				num7.checkMouseOver(m.x, m.y);
				num8.checkMouseOver(m.x, m.y);
				num9.checkMouseOver(m.x, m.y);
				numdelete.checkMouseOver(m.x, m.y);
				num0.checkMouseOver(m.x, m.y);
				numok.checkMouseOver(m.x, m.y);
				break;
			case WM_LBUTTONDOWN:
				if (addpiont.checkClick(m.x, m.y)) { reminder = L"插入的数据："; state = 1; }
				else if (deletepiont.checkClick(m.x, m.y)) { reminder = L"删除的节点序号："; state = 3; }
				else if (invert.checkClick(m.x, m.y)) { if (a.Invert()) { reminder = L"调换成功"; } else { reminder = L"没链表咋调换啊哥"; }; state = 0; }
				else if (upsidedown.checkClick(m.x, m.y)) { if (a.Upsidedown()) { reminder = L"颠倒成功"; } else { reminder = L"没链表咋颠倒啊哥"; }; state = 0; }
				else if (search.checkClick(m.x, m.y)) { reminder = L"查找的数据"; state = 4; }
				else if (num1.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 1); } }
				else if (num2.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 2); } }
				else if (num3.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 3); } }
				else if (num4.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 4); } }
				else if (num5.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 5); } }
				else if (num6.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 6); } }
				else if (num7.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 7); } }
				else if (num8.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 8); } }
				else if (num9.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input = input * 10 + 9); } }
				else if (numdelete.checkClick(m.x, m.y)) { _sntprintf_s(t, _countof(t), _T("%d"), input ? input /= 10 : input); }
				else if (num0.checkClick(m.x, m.y)) { if (input >= 99999999) { _sntprintf_s(t, _countof(t), _T("哥我没开long,再打就爆了")); input = 0; } else { _sntprintf_s(t, _countof(t), _T("%d"), input ? input *= 10 : input); } }
				else if (numok.checkClick(m.x, m.y)) {
					switch (state)
					{
					case 1:
						dataa = input;
						state = 2;
						reminder = L"插入位置(x表示第x个前面)";
						break;
					case 2:

						if (a.Addpiont(dataa, input))
						{
							reminder = L"插入成功";
						}
						else
						{
							reminder = L"你往哪插啊";
						}
						state = 0;
						break;
					case 3:
						if (a.Deletepiont(input))
						{
							reminder = L"删除成功";
						}
						else
						{
							reminder = L"你删空气啊";
						}
						state = 0;
						break;
					case 4:
						if (a.Searchdata(input))
						{
							_sntprintf_s(s, _countof(s), _T("位置%d为%d"), a.Searchdata(input), input);
							reminder = LPCTSTR(s);
						}
						else
						{
							reminder = L"没找到";
						}
						state = 0;
						break;
					default:
						break;
					}
					_sntprintf_s(t, _countof(t), _T("%d"), input = 0);
				}
				break;
			}
		}
		draw();
	}
	EndBatchDraw();
	return -1;
}

