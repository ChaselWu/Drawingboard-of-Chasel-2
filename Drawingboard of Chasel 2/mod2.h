#pragma once
#include"function.h"

enum operating_mode
{
	KEYBOARD, MOUSE
};


void revocation(int xinstr, int ylist, int screen_bottom,int* ordinal_num);
//（读取文件并）选择清屏/作画/退出
void mod2(int ylist, int xinstr, int screen_bottom, int* react_ifdraw, int* react_draw, int screen_right, int react_fileread,int operating_mode, int xperbutton, int xline1, int yline1, int xline2, int yline2, int arcbegin, int arcend, int rcir,int* falg_menu, int* ordinal_num);