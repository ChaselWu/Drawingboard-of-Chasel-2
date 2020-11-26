#include"function.h"
//��������
int coordinate(int y,int ylist) {
	int coord[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		int c = getch();
		if (c == 0x0d) {
			break;
		}
		else if (47 < c < 57) {
			coord[i] = c;
			xyprintf(8 * i, y + ylist, "%d", c - 48);
		}
		else {
			xyprintf(0, y + ylist, "�����ʽ��������������");
			i = 0;
			for (int j = 0; j < 5; j++) {
				coord[j] = 0;
			}
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
}


//���ɻ�������
void setbasicboard(int ylist,int screen_right,int screen_bottom,int xinstr,int react_fileread,int xperbutton) {

	//����
	line(0, ylist, screen_right, ylist);
	line(xinstr, ylist, xinstr, screen_bottom);

	//��Ϣ��
	xyprintf(0, screen_bottom - 20, "��ǰ��Ļ������Ϊ��%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "��ǰ��ͼ��������Ϊ��%dx%d", screen_right - xinstr, screen_bottom - ylist);
	if (react_fileread == '1') {
		xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:%s", "�Ѷ�ȡ");
	}
	else if (react_fileread == '2') {
		xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:%s", "δ��ȡ");
	}
	else {
		xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:%s", "��ָ��");
	}

	//�˵���
	rectangle(0, 0, screen_right / 15, screen_bottom / 30);
	rectangle(2 * screen_right / 15, 0, screen_right / 15, screen_bottom / 30);
	rectangle(2 * screen_right / 15, 0, 3 * screen_right / 15, screen_bottom / 30);






	//ָ����
		//ͼ��ѡ��
	for (int i = 1; i < 5; i++) {
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
		}

	}
	//��ɫѡ��
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 2; j++) {
			rectangle(screen_right * 39 / 40 - i * ylist / 4, ylist * 3 / 10 + j * ylist / 4, screen_right * 39 / 40 - (ylist / 4) - i * ylist / 4, ylist * 3 / 10 + ylist / 4 + j * ylist / 4);
		}
	}


}

//��ָ�����д��
void write_instr(int y, LPCWSTR s,int ylist,int xinstr,int screen_bottom) {
	outtextrect(0, ylist + y, xinstr, screen_bottom - 60, s);

}

//��ָ������д��
void write_list(int x, LPCWSTR s,int xperbutton,int ylist) {
	outtextrect(x, 20, x + xperbutton, ylist, s);
}

//�����������������ҳ��
void clear_board(int ylist, int screen_right, int screen_bottom, int xinstr, int react_fileread, int xperbutton) {
	cleardevice();
	setbasicboard( ylist, screen_right, screen_bottom, xinstr, react_fileread, xperbutton);
}

//���ָ���
void clear_instr(int ylist, int xinstr, int screen_bottom) {
	write_instr(1, L"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ", ylist, xinstr, screen_bottom);
}