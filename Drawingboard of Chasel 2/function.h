#pragma once
#include<graphics.h>
//��������
int coordinate(int y, int ylist);
//���ɻ�������
void setbasicboard(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int xperbutton);
//���ɲ˵���

//���ɲ鿴��

//��ָ�����д��
void write_instr(int y, LPCWSTR s, int ylist, int xinstr, int screen_bottom);
//��ָ������д��
void write_list(int x, LPCWSTR s, int xperbutton, int ylist);
//�����������������ҳ��
void clear_board(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int xperbutton);
//���ָ���
void clear_instr(int ylist, int xinstr, int screen_bottom);
//���ָ����

