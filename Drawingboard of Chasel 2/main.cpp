#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream>
#include"mod1.h"
#include"mod2.h"
#include"function.h"
using namespace std;
int react_fileread, react_ifdraw, react_draw;
int screen_left, screen_top, screen_right, screen_bottom, ylist, xinstr, xperbutton, yperbutton;
int coord[5] = { 0 };
LOGFONT typeface;
int xline1, xline2, yline1, yline2, xrec1, yrec1, xrec2, yrec2, xcir, ycir, rcir, arcbegin, arcend;

color_t white = EGERGB(255, 255, 255);


//���벢��ʼ������
void init();


int main() {
	init();
	mod1(&react_fileread,screen_bottom, screen_right, xinstr, ylist);
	mod2(ylist,  xinstr,  screen_bottom, &react_ifdraw, &react_draw,  screen_right,  react_fileread,  xperbutton,  xline1,  yline1,  xline2, yline2,  arcbegin, arcend, rcir);
	closegraph();
	return 0;
}


//���벢��ʼ������
void init() {


	//չ��һ��ȫ����ɫ����
	initgraph(-1, -1, 0x1);
	setbkcolor(WHITE);


	//��ʾ�û��л����뷨����ֹ����
	for (int j = 1; j == 1;) {
		xyprintf(0, 0, "��ӭ������Chasel����,����ȷ���������뷨�л�ΪӢ��ģʽ,Ȼ���ٰ��س����뻭��");
		if (getch() == 0x0d) {
			cleardevice();
			j = 0;
		}
	}

	//��ȡ����Ļ��Ϣ���ҵ���ʾ����1280x720�����ص㣩
	getviewport(&screen_left, &screen_top, &screen_right, &screen_bottom, NULL, NULL);
	ylist = screen_bottom / 6;
	//xinstr = screen_right * 200 / 1000;
	xinstr = screen_right * 200 / 1000;
	yperbutton = 20;
	xperbutton = screen_right / 10;


	//�����������
	setbasicboard(ylist,  screen_right,  screen_bottom, xinstr,  react_fileread,  xperbutton);
	xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:");

}

