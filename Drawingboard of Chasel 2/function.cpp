#include"function.h"

//坐标输入
int coordinate(int y, int ylist) {
startcoord1:
	int coord[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		int c = getch();
		if (c == 0x0d) {
			xyprintf(8 * i, y + ylist, "(done)");
			break;
		}
		else if (47 < c && c < 58) {
			coord[i] = c;
			xyprintf(8 * i, y + ylist, "%d", c - 48);
		}
		else {
			xyprintf(0, y + ylist, "输入格式错误，请重新输入");
			goto startcoord1;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (coord[4] == 0) {
			for (int i = 0; i < 4; i++) {
				coord[4 - i] = coord[3 - i];
				coord[3 - i] = '0';
			}
		}
	}
	int ans = (coord[0] - 48) * 10000 + (coord[1] - 48) * 1000 + (coord[2] - 48) * 100 + (coord[3] - 48) * 10 + coord[4] - 48;
	xyprintf(0, y + ylist, "%d", ans);
	return ans;
};
//坐标输入2
int coordinate(int y, int ylist, int x) {
startcoord2:
	int coord[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		int c = getch();
		if (c == 0x0d) {
			xyprintf(x + 8 * i, y + ylist, "(done)");
			break;
		}
		else if (47 < c && c < 58) {
			coord[i] = c;
			xyprintf(x + 8 * i, y + ylist, "%d", c - 48);
		}
		else {
			xyprintf(0, y + ylist, "输入格式错误，请重新输入");
			goto startcoord2;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (coord[4] == 0) {
			for (int i = 0; i < 4; i++) {
				coord[4 - i] = coord[3 - i];
				coord[3 - i] = '0';
			}
		}
	}
	int ans = (coord[0] - 48) * 10000 + (coord[1] - 48) * 1000 + (coord[2] - 48) * 100 + (coord[3] - 48) * 10 + coord[4] - 48;
	xyprintf(x, y + ylist, "%d", ans);
	return ans;
}

//生成基本画面
void setbasicboard(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int operating_mode,int xperbutton, int* flag_menu) {

	//划线
	line(0, ylist, screen_right, ylist);
	line(xinstr, ylist, xinstr, screen_bottom);

	//信息栏
	xyprintf(0, screen_bottom - 20, "当前屏幕的像素为：%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "当前绘图区的像素为：%dx%d", screen_right - xinstr, screen_bottom - ylist);
	
	if (operating_mode == 0) {
		xyprintf(0, screen_bottom - 60, "当前输入端:%s", "键盘");
	}
	if (operating_mode == 1) {
		xyprintf(0, screen_bottom - 60, "当前输入端:%s", "鼠标");
	}
	
	if (react_fileread == '1') {
		xyprintf(0, screen_bottom - 100, "文件读取情况:%s", "已读取");
	}
	else if (react_fileread == '2') {
		xyprintf(0, screen_bottom - 100, "文件读取情况:%s", "未读取");
	}
	else {
		xyprintf(0, screen_bottom - 100, "文件读取情况:%s", "无指令");
	}

	//菜单、绘图、查看
	xyprintf(0, 0, "a.菜单");
	rectangle(0, 0, screen_right / 15, screen_bottom / 30);
	xyprintf(screen_right / 15, 0, "b.绘图");
	rectangle(2 * screen_right / 15, 0, screen_right / 15, screen_bottom / 30);
	xyprintf(2 * screen_right / 15, 0, "c.查看");
	rectangle(2 * screen_right / 15, 0, 3 * screen_right / 15, screen_bottom / 30);

	//菜单
	if (*flag_menu == 0) {
		clear_list(ylist, screen_right, screen_bottom);
		for (int i = 1; i < 6; i++) {
			xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
			switch (i) {
			case 1:
				line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "新建");
				break;
			case 2:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "打开");
				break;
			case 3:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "保存");
				break;
			case 4:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "另存为");
				break;

			case 5:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "退出");
				break;
			}
		}
	}

	//绘图
	if (*flag_menu == 1) {
		for (int i = 1; i < 6; i++) {
			xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
			switch (i) {
			case 1:
				line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "直线");
				break;
			case 2:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "矩形");
				break;
			case 3:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "圆形");
				break;
			case 4:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "圆弧");
				break;

			case 5:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "填充多边形");
				break;
			}
		}
		//颜色栏
		int value_color = 16;
		for (int i = 0; i < 8; i++) {
			for (int j = 1; j >= 0; j--) {
				setfillcolor(get_color(--value_color));
				bar(screen_right * 39 / 40 - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + ylist / 4 + j * ylist / 4);
				setfontbkcolor(get_color(value_color));
				if (value_color < 10) {
					xyprintf(screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, "0%d", value_color);
				}
				else {
					xyprintf(screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, "%2d", value_color);
				}
				rectangle(screen_right * 39 / 40 - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + ylist / 4 + j * ylist / 4);
				setfontbkcolor(WHITE);
			}
		}
	}
}
//生成菜单栏
void setmenu(int screen_right,int xperbutton,int ylist,int screen_bottom) {
	clear_list(ylist, screen_right,screen_bottom);
	for (int i = 1; i < 6; i++) {
		xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
		switch (i) {
		case 1:
			line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "新建");
			break;
		case 2:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "打开");
			break;
		case 3:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "保存");
			break;
		case 4:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "另存为");
			break;

		case 5:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "退出");
			break;
		}
	}
}

//生成绘图栏
void setdraw(int screen_right, int xperbutton, int ylist, int screen_bottom) {
	clear_list(ylist,screen_right, screen_bottom);

	for (int i = 1; i < 6; i++) {
		xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
		switch (i) {
		case 1:
			line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "直线");
			break;
		case 2:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "矩形");
			break;
		case 3:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "圆形");
			break;
		case 4:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "圆弧");
			break;

		case 5:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "填充多边形");
			break;
		}
	}

	//颜色栏
	int value_color1 = 16;
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j >= 0; j--) {
			setfillcolor(get_color(--value_color1));
			bar(screen_right * 39 / 40 - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + ylist / 4 + j * ylist / 4);
			setfontbkcolor(get_color(value_color1));
			if (value_color1 < 10) {
				xyprintf(screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, "0%d", value_color1);
			}
			else {
				xyprintf(screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, "%2d", value_color1);
			}
			rectangle(screen_right * 39 / 40 - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + ylist / 4 + j * ylist / 4);
			setfontbkcolor(WHITE);
		}
	}
}

//生成查看栏
void setview(int screen_right, int xperbutton, int ylist, int screen_bottom) {
	clear_list(ylist,screen_right,  screen_bottom);
}

//在指令框内写入
void write_instr(int y, LPCWSTR s, int ylist, int xinstr, int screen_bottom) {
	outtextrect(0, ylist + y, xinstr, screen_bottom - 60, s);

}

//在指令表框内写入
void write_list(int x, LPCWSTR s,int xperbutton,int ylist) {
	outtextrect(x, 20, x + xperbutton, ylist, s);
}

//清屏并保留画板基本页面
void clear_board(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int operating_mode,int xperbutton,int* flag_menu) {
	cleardevice();
	setbasicboard( ylist, screen_right, screen_bottom, xinstr, react_fileread, operating_mode,xperbutton,flag_menu);
}

//清除指令框
void clear_instr(int ylist, int xinstr, int screen_bottom) {
	write_instr(1, L"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ", ylist, xinstr, screen_bottom);
}

//清除指令表框
void clear_list(int ylist,int screen_right,int screen_bottom) {
	write_list(0,  L"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ",screen_right, ylist);
	line(0, ylist, screen_right, ylist);
	line(0, screen_bottom / 30,screen_right / 5, screen_bottom / 30);
}

//颜色值定义//（写的时候还没学枚举，就这样吧）
color_t get_color() {
	int input1 = getch();
	int input2 = getch();
	int input = input1*10 + input2;
	return get_color(input-48);
}
color_t get_color(int value) {
	switch (value) {
	case 0:return WHITE;
	case 1:return LIGHTGRAY;
	case 2:return YELLOW;
	case 3:return BROWN;
	case 4:return LIGHTMAGENTA;
	case 5:return MAGENTA;
	case 6:return LIGHTRED;
	case 7:return RED;
	case 8:return LIGHTCYAN;
	case 9:return CYAN;
	case 10:return LIGHTGREEN;
	case 11:return GREEN;
	case 12:return LIGHTBLUE;
	case 13:return BLUE;
	case 14:return DARKGRAY;
	case 15:return BLACK;
	}
	return BLACK;
}

//鼠标输入
int getmousevalue() {
	int x, y = 0;
	mousepos(&x, &y);
	return 0;
}

