#include"mod2.h"

struct graph {
	int num;
	int type;
	int x[199];
};
graph graphs[20];
void mod2(int ylist, int xinstr, int screen_bottom, int* react_ifdraw, int* react_draw, int screen_right, int react_fileread,int operating_mode, int xperbutton, int xline1, int yline1, int xline2, int yline2, int arcbegin, int arcend, int rcir, int* flag_menu,int* ordinal_num) {
	int pt[200];
	int n = 0; int xin = 0; int yin = 0;
	if (operating_mode == KEYBOARD) {
		for (int j = 1; j == 1;) {//j!=1ʱ�˳�
			write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ���:\n1.�����Ļ\n2.����\n3.�˳�\na.�ļ�\nb.��ͼ\nc.�鿴", ylist, xinstr, screen_bottom);

			*react_ifdraw = getch();
			switch (*react_ifdraw) {
				//case 't':clear_list(ylist, screen_right); break;//����
			case 'a':
				*flag_menu = 0;
				setmenu(screen_right, xperbutton, ylist, screen_bottom);
				break;
			case 'b':
				*flag_menu = 1;
				setdraw(screen_right, xperbutton, ylist, screen_bottom);
				break;
			case 'c':
				setview(screen_right, xperbutton, ylist, screen_bottom);
				*flag_menu = 2;
				break;
			case '1':
				clear_board(ylist, screen_right, screen_bottom, xinstr, react_fileread, operating_mode, xperbutton, flag_menu);
				write_instr(1, L"������", ylist, xinstr, screen_bottom);
				write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.�����Ļ\n2.����\n3�˳�\na.�ļ�\nb.��ͼ\nc.�鿴", ylist, xinstr, screen_bottom);
				break;

			case '2':
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"������Ϸ���ָ���ѡ����Ҫ����ͼ�Σ���0������ɫ����9������", ylist, xinstr, screen_bottom);
				*react_draw = getch();
				clear_instr(ylist, xinstr, screen_bottom);
				switch (*react_draw) {
				case '1':
					write_instr(1, L"��ֱ��", ylist, xinstr, screen_bottom);
					write_instr(20, L"�������һ���������:(��entern����)", ylist, xinstr, screen_bottom);
					xline1 = coordinate(60, ylist);
					write_instr(80, L"�������һ���������꣺", ylist, xinstr, screen_bottom);
					yline1 = coordinate(100, ylist);
					write_instr(120, L"������ڶ���������꣺", ylist, xinstr, screen_bottom);
					xline2 = coordinate(140, ylist);
					write_instr(160, L"������ڶ����������꣺", ylist, xinstr, screen_bottom);
					yline2 = coordinate(180, ylist);
					line(xline1 + xinstr, yline1 + ylist, xline2 + xinstr, yline2 + ylist);
					clear_instr(ylist, xinstr, screen_bottom);
					write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);

					graphs[*ordinal_num].num = *ordinal_num;
					graphs[*ordinal_num].type = 1;
					graphs[*ordinal_num].x[0] = xline1;
					graphs[*ordinal_num].x[1] = yline1;
					graphs[*ordinal_num].x[2] = xline2;
					graphs[*ordinal_num].x[3] = yline2;
					*ordinal_num+=1;

					break;

				case '2':
					write_instr(1, L"������", ylist, xinstr, screen_bottom);
					write_instr(20, L"�������һ���������:(��entern����)", ylist, xinstr, screen_bottom);
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

					graphs[*ordinal_num].num = *ordinal_num;
					graphs[*ordinal_num].type = 2;
					graphs[*ordinal_num].x[0] = xline1;
					graphs[*ordinal_num].x[1] = yline1;
					graphs[*ordinal_num].x[2] = xline2;
					graphs[*ordinal_num].x[3] = yline2;
					*ordinal_num+=1;

					break;


				case '3':
					write_instr(1, L"��Բ��", ylist, xinstr, screen_bottom);
					write_instr(20, L"������Բ�������:(��entern����)", ylist, xinstr, screen_bottom);
					xline1 = coordinate(60, ylist);
					write_instr(80, L"������Բ�������꣺", ylist, xinstr, screen_bottom);
					yline1 = coordinate(100, ylist);
					write_instr(120, L"������뾶��", ylist, xinstr, screen_bottom);
					rcir = coordinate(140, ylist);
					circle(xline1 + xinstr, yline1 + ylist, rcir);
					clear_instr(ylist, xinstr, screen_bottom);
					write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);

					graphs[*ordinal_num].num = *ordinal_num;
					graphs[*ordinal_num].type = 3;
					graphs[*ordinal_num].x[0] = xline1;
					graphs[*ordinal_num].x[1] = yline1;
					graphs[*ordinal_num].x[2] = rcir;
					*ordinal_num+=1;

					break;

				case '4':
					write_instr(1, L"��Բ��", ylist, xinstr, screen_bottom);
					write_instr(20, L"������Բ�������:(��entern����)", ylist, xinstr, screen_bottom);
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

					graphs[*ordinal_num].num = *ordinal_num;
					graphs[*ordinal_num].type = 4;
					graphs[*ordinal_num].x[0] = xline1;
					graphs[*ordinal_num].x[1] = yline1;
					graphs[*ordinal_num].x[2] = arcbegin;
					graphs[*ordinal_num].x[3] = arcend;
					graphs[*ordinal_num].x[4] = rcir;
					*ordinal_num+=1;

					break;

				case '5':
				start5:
					write_instr(1, L"���������", ylist, xinstr, screen_bottom);
					write_instr(20, L"���������α���:(��entern����)", ylist, xinstr, screen_bottom);
					n = coordinate(40, ylist);
					if (n > 10) {
						write_instr(60, L"����̫�࣬����������", ylist, xinstr, screen_bottom);
						goto start5;
					}
					write_instr(60, L"���������ζ˵����꣨�Ⱥ����꣬�������꣬��entern������", ylist, xinstr, screen_bottom);
					for (int i = 0; i < 2 * n; i++) {
						if (i % 2 == 1) {
							xin = 80;
							yin = (i / 2) * 20;
							pt[i] = coordinate(100 + yin, ylist, xin) + ylist;
						}
						if (i % 2 == 0) {
							xin = 0;
							yin = (i / 2) * 20;
							pt[i] = coordinate(100 + yin, ylist, xin) + xinstr;
						}
					}
					fillpoly(n, pt);
					clear_instr(ylist, xinstr, screen_bottom);
					write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);

					graphs[*ordinal_num].num = *ordinal_num;
					graphs[*ordinal_num].type = 5;
					graphs[*ordinal_num].x[0] = n;
					for (int i = 1; i < 199; i++) {
						graphs[*ordinal_num].x[i] = pt[i-1];
					}
					*ordinal_num+=1;

					break;

				case'9':
					clear_board(ylist, screen_right, screen_bottom, xinstr, react_fileread, operating_mode, xperbutton, flag_menu);
					revocation(xinstr, ylist, screen_bottom,ordinal_num);
					break;

				case '0':
					setfillcolor(get_color());
					break;
				}

				break;


			case '3':
				j = 0;
				break;
			}
		}
	}
	if (operating_mode == MOUSE) {
		for (int j = 1; j == 1;) {//j!=1ʱ�˳�
			write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ���:\n1.�����Ļ\n2.����\n3.�˳�\na.�ļ�\nb.��ͼ\nc.�鿴", ylist, xinstr, screen_bottom);
			
			
			*react_ifdraw = getmousevalue();
			switch (*react_ifdraw) {
				//case 't':clear_list(ylist, screen_right); break;//����
			case 'a':
				*flag_menu = 0;
				setmenu(screen_right, xperbutton, ylist, screen_bottom);
				break;
			case 'b':
				*flag_menu = 1;
				setdraw(screen_right, xperbutton, ylist, screen_bottom);
				break;
			case 'c':
				setview(screen_right, xperbutton, ylist, screen_bottom);
				*flag_menu = 2;
				break;
			case '1':
				clear_board(ylist, screen_right, screen_bottom, xinstr, react_fileread, operating_mode, xperbutton, flag_menu);
				write_instr(1, L"������", ylist, xinstr, screen_bottom);
				write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.�����Ļ\n2.����\n3�˳�\na.�ļ�\nb.��ͼ\nc.�鿴", ylist, xinstr, screen_bottom);
				break;

			case '2':
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"������Ϸ���ָ���ѡ����Ҫ����ͼ�Σ���0������ɫ��", ylist, xinstr, screen_bottom);
				*react_draw = getmousevalue();
				clear_instr(ylist, xinstr, screen_bottom);
				switch (*react_draw) {
				case '1':
					write_instr(1, L"��ֱ��", ylist, xinstr, screen_bottom);
					write_instr(20, L"�������һ���������:(��entern����)", ylist, xinstr, screen_bottom);
					xline1 = coordinate(60, ylist);
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
					write_instr(20, L"�������һ���������:(��entern����)", ylist, xinstr, screen_bottom);
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
					write_instr(20, L"������Բ�������:(��entern����)", ylist, xinstr, screen_bottom);
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
					write_instr(20, L"������Բ�������:(��entern����)", ylist, xinstr, screen_bottom);
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
				start5e:
					write_instr(1, L"���������", ylist, xinstr, screen_bottom);
					write_instr(20, L"���������α���:(��entern����)", ylist, xinstr, screen_bottom);
					n = coordinate(40, ylist);
					if (n > 10) {
						write_instr(60, L"����̫�࣬����������", ylist, xinstr, screen_bottom);
						goto start5e;
					}
					write_instr(60, L"���������ζ˵����꣨�Ⱥ����꣬�������꣬��entern������", ylist, xinstr, screen_bottom);
					for (int i = 0; i < 2 * n; i++) {
						if (i % 2 == 1) {
							xin = 80;
							yin = (i / 2) * 20;
							pt[i] = coordinate(100 + yin, ylist, xin) + ylist;
						}
						if (i % 2 == 0) {
							xin = 0;
							yin = (i / 2) * 20;
							pt[i] = coordinate(100 + yin, ylist, xin) + xinstr;
						}
					}
					fillpoly(n, pt);
					clear_instr(ylist, xinstr, screen_bottom);
					write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
					break;

				case '0':
					setfillcolor(get_color());
					break;
				}

				break;


			case '3':
				j = 0;
				break;
			}
		}
	}
}

//����ȡ�ļ�����ѡ������/����/�˳�
/*void mod2(int ylist, int xinstr, int screen_bottom,int* react_ifdraw,int* react_draw,int screen_right, int react_fileread, int xperbutton,int xline1,int yline1,int xline2,int yline2,int arcbegin,int arcend,int rcir,int* flag_menu) {
	int pt[200];
	int n = 0; int xin = 0; int yin = 0;
	for (int j = 1; j == 1;) {//j!=1ʱ�˳�
		write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ���:\n1.�����Ļ\n2.����\n3.�˳�\na.�ļ�\nb.��ͼ\nc.�鿴", ylist,  xinstr,  screen_bottom);

		*react_ifdraw = getch();
		switch (*react_ifdraw) {
		//case 't':clear_list(ylist, screen_right); break;//����
		case 'a':
			*flag_menu = 0;
			setmenu(screen_right, xperbutton, ylist, screen_bottom);
			break;
		case 'b':
			*flag_menu = 1;
			setdraw(screen_right, xperbutton, ylist, screen_bottom);
			break;
		case 'c':
			setview(screen_right, xperbutton, ylist, screen_bottom);
			*flag_menu = 2;
			break;
		case '1':
			clear_board(ylist, screen_right,  screen_bottom,  xinstr,  react_fileread,  xperbutton,flag_menu);
			write_instr(1, L"������", ylist, xinstr, screen_bottom);
			write_instr(20, L"��ӭ������Chasel���壬����ݲ˵�ѡ��������еĲ�����\n1.�����Ļ\n2.����\n3�˳�\na.�ļ�\nb.��ͼ\nc.�鿴", ylist, xinstr, screen_bottom);
			break;

		case '2':
			clear_instr( ylist, xinstr, screen_bottom);
			write_instr(1, L"������Ϸ���ָ���ѡ����Ҫ����ͼ�Σ���0������ɫ��", ylist, xinstr, screen_bottom);
			*react_draw = getch();
			clear_instr(ylist, xinstr, screen_bottom);
			switch (*react_draw) {
			case '1':
				write_instr(1, L"��ֱ��", ylist, xinstr, screen_bottom);
				write_instr(20, L"�������һ���������:(��entern����)", ylist, xinstr, screen_bottom);
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
				write_instr(20, L"�������һ���������:(��entern����)", ylist, xinstr, screen_bottom);
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
				write_instr(20, L"������Բ�������:(��entern����)", ylist, xinstr, screen_bottom);
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
				write_instr(20, L"������Բ�������:(��entern����)", ylist, xinstr, screen_bottom);
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
			start5:
				write_instr(1, L"���������", ylist, xinstr, screen_bottom);
				write_instr(20, L"���������α���:(��entern����)", ylist, xinstr, screen_bottom);
				n = coordinate(40,ylist);
				if (n > 10) {
					write_instr(60, L"����̫�࣬����������", ylist, xinstr, screen_bottom);
					goto start5;
				}
				write_instr(60, L"���������ζ˵����꣨�Ⱥ����꣬�������꣬��entern������", ylist, xinstr, screen_bottom);
				for (int i = 0; i < 2*n; i++) {
					if (i % 2 == 1) {
						xin = 80;
						yin = (i / 2)*20;
						pt[i] = coordinate(100 + yin, ylist, xin) + ylist;
					}
					if (i % 2 == 0) {
						xin = 0;
						yin = (i / 2) * 20;
						pt[i] = coordinate(100 + yin, ylist, xin) + xinstr;
					}
				}
				fillpoly(n, pt);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
				break;

			case '0':
				setfillcolor(get_color());
				break;
			}

			break;


		case '3':
			j = 0;
			break;
		}
	}
}
*/



//����������ǰ����������
void revocation(int xinstr, int ylist, int screen_bottom,int* ordinal_num) {
	*ordinal_num -= 1;
	for (int i = 0; i < *ordinal_num; i++) {
		switch (graphs[i].type) {
		case 1:
			line(graphs[i].x[0] + xinstr, graphs[i].x[1] + ylist, graphs[i].x[2] + xinstr, graphs[i].x[3] + ylist);
			clear_instr(ylist, xinstr, screen_bottom);
			write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
			break;

		case 2:

			rectangle(graphs[i].x[0] + xinstr, graphs[i].x[1] + ylist, graphs[i].x[2] + xinstr, graphs[i].x[3] + ylist);
			clear_instr(ylist, xinstr, screen_bottom);
			write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
			break;


		case 3:
			circle(graphs[i].x[0] + xinstr, graphs[i].x[1] + ylist, graphs[i].x[2]);
			clear_instr(ylist, xinstr, screen_bottom);
			write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
			break;

		case 4:

			arc(graphs[i].x[0] + xinstr, graphs[i].x[1] + ylist, graphs[i].x[2], graphs[i].x[3], graphs[i].x[4]);
			clear_instr(ylist, xinstr, screen_bottom);
			write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
			break;

		case 5:
			fillpoly(graphs[i].x[0], &graphs[i].x[1]);
			clear_instr(ylist, xinstr, screen_bottom);
			write_instr(1, L"����ͼ", ylist, xinstr, screen_bottom);
		}
	}
}