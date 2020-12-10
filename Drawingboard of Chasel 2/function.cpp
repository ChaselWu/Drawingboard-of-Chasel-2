#include"function.h"

//��������
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
			xyprintf(0, y + ylist, "�����ʽ��������������");
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
//��������2
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
			xyprintf(0, y + ylist, "�����ʽ��������������");
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

//���ɻ�������
void setbasicboard(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int operating_mode,int xperbutton, int* flag_menu) {

	//����
	line(0, ylist, screen_right, ylist);
	line(xinstr, ylist, xinstr, screen_bottom);

	//��Ϣ��
	xyprintf(0, screen_bottom - 20, "��ǰ��Ļ������Ϊ��%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "��ǰ��ͼ��������Ϊ��%dx%d", screen_right - xinstr, screen_bottom - ylist);
	
	if (operating_mode == 0) {
		xyprintf(0, screen_bottom - 60, "��ǰ�����:%s", "����");
	}
	if (operating_mode == 1) {
		xyprintf(0, screen_bottom - 60, "��ǰ�����:%s", "���");
	}
	
	if (react_fileread == '1') {
		xyprintf(0, screen_bottom - 100, "�ļ���ȡ���:%s", "�Ѷ�ȡ");
	}
	else if (react_fileread == '2') {
		xyprintf(0, screen_bottom - 100, "�ļ���ȡ���:%s", "δ��ȡ");
	}
	else {
		xyprintf(0, screen_bottom - 100, "�ļ���ȡ���:%s", "��ָ��");
	}

	//�˵�����ͼ���鿴
	xyprintf(0, 0, "a.�˵�");
	rectangle(0, 0, screen_right / 15, screen_bottom / 30);
	xyprintf(screen_right / 15, 0, "b.��ͼ");
	rectangle(2 * screen_right / 15, 0, screen_right / 15, screen_bottom / 30);
	xyprintf(2 * screen_right / 15, 0, "c.�鿴");
	rectangle(2 * screen_right / 15, 0, 3 * screen_right / 15, screen_bottom / 30);

	//�˵�
	if (*flag_menu == 0) {
		clear_list(ylist, screen_right, screen_bottom);
		for (int i = 1; i < 6; i++) {
			xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
			switch (i) {
			case 1:
				line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "�½�");
				break;
			case 2:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "��");
				break;
			case 3:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "����");
				break;
			case 4:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "���Ϊ");
				break;

			case 5:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "�˳�");
				break;
			}
		}
	}

	//��ͼ
	if (*flag_menu == 1) {
		for (int i = 1; i < 6; i++) {
			xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
			switch (i) {
			case 1:
				line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "ֱ��");
				break;
			case 2:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "����");
				break;
			case 3:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "Բ��");
				break;
			case 4:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "Բ��");
				break;

			case 5:
				xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "�������");
				break;
			}
		}
		//��ɫ��
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
//���ɲ˵���
void setmenu(int screen_right,int xperbutton,int ylist,int screen_bottom) {
	clear_list(ylist, screen_right,screen_bottom);
	for (int i = 1; i < 6; i++) {
		xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
		switch (i) {
		case 1:
			line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "�½�");
			break;
		case 2:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "��");
			break;
		case 3:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "����");
			break;
		case 4:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "���Ϊ");
			break;

		case 5:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "�˳�");
			break;
		}
	}
}

//���ɻ�ͼ��
void setdraw(int screen_right, int xperbutton, int ylist, int screen_bottom) {
	clear_list(ylist,screen_right, screen_bottom);

	for (int i = 1; i < 6; i++) {
		xyprintf(screen_right / 40 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%d.", i);
		switch (i) {
		case 1:
			line(screen_right / 40 + 10 + (i - 1) * xperbutton, (ylist + 60) / 4 + (ylist - 20) / 3, screen_right / 20 + 20 + (i - 1) * xperbutton, (ylist + 60) / 4);
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "ֱ��");
			break;
		case 2:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "����");
			break;
		case 3:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "Բ��");
			break;
		case 4:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "Բ��");
			break;

		case 5:
			xyprintf(screen_right / 20 + 20 + (i - 1) * xperbutton, (20 + ylist) / 2 - 20, "%s", "�������");
			break;
		}
	}

	//��ɫ��
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

//���ɲ鿴��
void setview(int screen_right, int xperbutton, int ylist, int screen_bottom) {
	clear_list(ylist,screen_right,  screen_bottom);
}

//��ָ�����д��
void write_instr(int y, LPCWSTR s, int ylist, int xinstr, int screen_bottom) {
	outtextrect(0, ylist + y, xinstr, screen_bottom - 60, s);

}

//��ָ������д��
void write_list(int x, LPCWSTR s,int xperbutton,int ylist) {
	outtextrect(x, 20, x + xperbutton, ylist, s);
}

//�����������������ҳ��
void clear_board(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int operating_mode,int xperbutton,int* flag_menu) {
	cleardevice();
	setbasicboard( ylist, screen_right, screen_bottom, xinstr, react_fileread, operating_mode,xperbutton,flag_menu);
}

//���ָ���
void clear_instr(int ylist, int xinstr, int screen_bottom) {
	write_instr(1, L"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ", ylist, xinstr, screen_bottom);
}

//���ָ����
void clear_list(int ylist,int screen_right,int screen_bottom) {
	write_list(0,  L"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ",screen_right, ylist);
	line(0, ylist, screen_right, ylist);
	line(0, screen_bottom / 30,screen_right / 5, screen_bottom / 30);
}

//��ɫֵ����//��д��ʱ��ûѧö�٣��������ɣ�
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

//�������
int getmousevalue() {
	int x, y = 0;
	mousepos(&x, &y);
	return 0;
}

