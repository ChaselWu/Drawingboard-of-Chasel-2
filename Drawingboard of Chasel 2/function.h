#pragma once
#include<graphics.h>
//坐标输入
int coordinate(int y, int ylist);
//生成基本画面
void setbasicboard(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int xperbutton);
//生成菜单栏

//生成查看栏

//在指令框内写入
void write_instr(int y, LPCWSTR s, int ylist, int xinstr, int screen_bottom);
//在指令表框内写入
void write_list(int x, LPCWSTR s, int xperbutton, int ylist);
//清屏并保留画板基本页面
void clear_board(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int xperbutton);
//清除指令框
void clear_instr(int ylist, int xinstr, int screen_bottom);
//清除指令表框

