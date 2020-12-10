#pragma once
#include<graphics.h>
//��������
int coordinate(int y, int ylist);
int coordinate(int y, int ylist,int x);
//���ɻ�������
void setbasicboard(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread,int operating_mode, int xperbutton, int* flag_menu);
//���ɲ˵���
void setmenu(int screen_right, int xperbutton, int ylist, int screen_bottom);
//���ɻ�ͼ��
void setdraw(int screen_right, int xperbutton, int ylist, int screen_bottom);
//���ɲ鿴��
void setview(int screen_right, int xperbutton, int ylist, int screen_bottom);
//��ָ�����д��
void write_instr(int y, LPCWSTR s, int ylist, int xinstr, int screen_bottom);
//��ָ������д��
void write_list(int x, LPCWSTR s, int xperbutton, int ylist);
//�����������������ҳ��
void clear_board(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int operating_mode,int xperbutton,int* flag_menu);
//���ָ���
void clear_instr(int ylist, int xinstr, int screen_bottom);
//���ָ����
void clear_list(int ylist, int screen_right,int screen_bottom);
//ö�ٲ�������ɫֵ
color_t get_color();
color_t get_color(int value);
//�������
int getmousevalue();