#include"mod2.h"

//����ȡ�ļ�����ѡ������/����/�˳�
void mod2(int ylist, int xinstr, int screen_bottom,int* react_ifdraw,int* react_draw,int screen_right, int react_fileread, int xperbutton,int xline1,int yline1,int xline2,int yline2,int arcbegin,int arcend,int rcir) {
	for (int j = 1; j == 1;) {//j!=1ʱ�˳�
		write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.�����Ļ\n2.����\n3.�˳�", ylist,  xinstr,  screen_bottom);

		*react_ifdraw = getch();
		switch (*react_ifdraw) {

		case '1':
			clear_board(ylist, screen_right,  screen_bottom,  xinstr,  react_fileread,  xperbutton);
			write_instr(1, L"������", ylist, xinstr, screen_bottom);
			write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.�����Ļ\n2.����\n3.�˵�\n4.�˳�", ylist, xinstr, screen_bottom);
			break;

		case '2':
			clear_instr( ylist, xinstr, screen_bottom);
			write_instr(1, L"������Ϸ���ָ���ѡ����Ҫ����ͼ��", ylist, xinstr, screen_bottom);
			*react_draw = getch();
			clear_instr(ylist, xinstr, screen_bottom);
			switch (*react_draw) {

			case '1':
				write_instr(1, L"��ֱ��", ylist, xinstr, screen_bottom);
				write_instr(20, L"�������һ���������:(��enter����)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60,ylist);
				write_instr(80, L"�������һ���������꣺", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"������ڶ���������꣺", ylist, xinstr, screen_bottom);
				xline2 = coordinate(140, ylist);
				write_instr(160, L"������ڶ����������꣺", ylist, xinstr, screen_bottom);
				yline2 = coordinate(180, ylist);
				line(xline1 + xinstr, yline1 + ylist, xline2 + xinstr, yline2 + ylist);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
				break;

			case '2':
				write_instr(1, L"������", ylist, xinstr, screen_bottom);
				write_instr(20, L"�������һ���������:(��enter����)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60, ylist);
				write_instr(80, L"�������һ���������꣺", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"������ڶ���������꣺", ylist, xinstr, screen_bottom);
				xline2 = coordinate(140, ylist);
				write_instr(160, L"������ڶ����������꣺", ylist, xinstr, screen_bottom);
				yline2 = coordinate(180, ylist);
				rectangle(xline1 + xinstr, yline1 + ylist, xline2 + xinstr, yline2 + ylist);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
				break;


			case '3':
				write_instr(1, L"��Բ��", ylist, xinstr, screen_bottom);
				write_instr(20, L"������Բ�������:(��enter����)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60, ylist);
				write_instr(80, L"������Բ�������꣺", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"������뾶��", ylist, xinstr, screen_bottom);
				rcir = coordinate(140, ylist);
				circle(xline1 + xinstr, yline1 + ylist, rcir);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
				break;

			case '4':
				write_instr(1, L"��Բ��", ylist, xinstr, screen_bottom);
				write_instr(20, L"������Բ�������:(��enter����)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60, ylist);
				write_instr(80, L"������Բ�������꣺", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"������뾶��", ylist, xinstr, screen_bottom);
				rcir = coordinate(140, ylist);
				write_instr(160, L"������Բ����ʼ�ǣ�", ylist, xinstr, screen_bottom);
				arcbegin = coordinate(180, ylist);
				write_instr(200, L"������Բ����ֹ�ǣ�", ylist, xinstr, screen_bottom);
				arcend = coordinate(220, ylist);
				arc(xline1 + xinstr, yline1 + ylist, arcbegin, arcend, rcir);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
				break;

			case '5':

				break;
			}



			break;

		case '3':

			break;
		case '4':
			j = 0;
			break;
		}
	}
}
