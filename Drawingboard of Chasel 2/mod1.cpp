#include "mod1.h"

void mod1(int* react_fileread, int* operating_mode, int screen_bottom, int screen_right, int xinstr, int ylist) {

	write_instr(1, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.��ȡ�ļ�\n2.����ȡ�ļ�", ylist, xinstr, screen_bottom);
	*react_fileread = getch();
	clear_instr(ylist, xinstr, screen_bottom);

	xyprintf(0, screen_bottom - 20, "��ǰ��Ļ������Ϊ��%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "��ǰ��ͼ��������Ϊ��%dx%d", screen_right - xinstr, screen_bottom - ylist);
	if (*react_fileread == '1') {
		xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:%s", "�Ѷ�ȡ");
	}
	if (*react_fileread == '2') {
		xyprintf(0, screen_bottom - 100, "�ļ���ȡ���:%s", "δ��ȡ");
	}

	write_instr(1, L"��ѡ�����ĳ�ʼ���뷽ʽ��\n1.����\n2.���", ylist, xinstr, screen_bottom);
	*operating_mode = getch()-49;
	clear_instr(ylist, xinstr, screen_bottom);
	if (*operating_mode== 0) {
		xyprintf(0, screen_bottom - 60, "��ǰ�����:%s", "����");
	}
	if (*operating_mode == 1) {
		xyprintf(0, screen_bottom - 60, "��ǰ�����:%s", "���");
	}
	else {
		xyprintf(0, screen_bottom - 60, "��ǰ�����:%s", "����");
		*operating_mode = 0;
	}
}


//ѯ���Ƿ��ȡ�ļ�
/*void mod1(int* react_fileread,int screen_bottom,int screen_right,int xinstr,int ylist) {

	write_instr(1, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.��ȡ�ļ�\n2.����ȡ�ļ�", ylist,xinstr, screen_bottom);
	*react_fileread = getch();
	clear_instr(ylist,  xinstr,  screen_bottom);

	xyprintf(0, screen_bottom - 20, "��ǰ��Ļ������Ϊ��%dx%d", screen_right, screen_bottom);
	xyprintf(0, screen_bottom - 40, "��ǰ��ͼ��������Ϊ��%dx%d", screen_right - xinstr, screen_bottom - ylist);
	if (*react_fileread == '1') {
		xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:%s", "�Ѷ�ȡ");
	}
	if (*react_fileread == '2') {
		xyprintf(0, screen_bottom - 60, "�ļ���ȡ���:%s", "δ��ȡ");
	}
}*/