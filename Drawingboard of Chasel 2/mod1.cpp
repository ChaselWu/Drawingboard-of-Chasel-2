#include "mod1.h"

void mod1(int* react_fileread, int* operating_mode, int screen_bottom, int screen_right, int xinstr, int ylist) {

	write_instr(1, L"欢迎您进入Chasel画板，请根据菜单选择您想进行的操作：\n1.读取文件\n2.不读取文件", ylist, xinstr, screen_bottom);
	*react_fileread = getch();
	clear_instr(ylist, xinstr, screen_bottom);

	xyprintf(0, screen_bottom - 20, "当前屏幕的像素为：%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "当前绘图区的像素为：%dx%d", screen_right - xinstr, screen_bottom - ylist);
	if (*react_fileread == '1') {
		xyprintf(0, screen_bottom - 60, "文件读取情况:%s", "已读取");
	}
	if (*react_fileread == '2') {
		xyprintf(0, screen_bottom - 100, "文件读取情况:%s", "未读取");
	}

	write_instr(1, L"请选择您的初始输入方式：\n1.键盘\n2.鼠标", ylist, xinstr, screen_bottom);
	*operating_mode = getch()-49;
	clear_instr(ylist, xinstr, screen_bottom);
	if (*operating_mode== 0) {
		xyprintf(0, screen_bottom - 60, "当前输入端:%s", "键盘");
	}
	if (*operating_mode == 1) {
		xyprintf(0, screen_bottom - 60, "当前输入端:%s", "鼠标");
	}
	else {
		xyprintf(0, screen_bottom - 60, "当前输入端:%s", "键盘");
		*operating_mode = 0;
	}
}


//询问是否读取文件
/*void mod1(int* react_fileread,int screen_bottom,int screen_right,int xinstr,int ylist) {

	write_instr(1, L"欢迎您进入Chasel画板，请根据菜单选择您想进行的操作：\n1.读取文件\n2.不读取文件", ylist,xinstr, screen_bottom);
	*react_fileread = getch();
	clear_instr(ylist,  xinstr,  screen_bottom);

	xyprintf(0, screen_bottom - 20, "当前屏幕的像素为：%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "当前绘图区的像素为：%dx%d", screen_right - xinstr, screen_bottom - ylist);
	if (*react_fileread == '1') {
		xyprintf(0, screen_bottom - 60, "文件读取情况:%s", "已读取");
	}
	if (*react_fileread == '2') {
		xyprintf(0, screen_bottom - 60, "文件读取情况:%s", "未读取");
	}
}*/